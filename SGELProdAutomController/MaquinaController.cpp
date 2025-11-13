#pragma once
#include "MaquinaController.h"
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace SGELProdAutomController;

MaquinaController::MaquinaController() {
    this->listaMaquinas = gcnew List<Maquina^>();
	
    /* 
    //TXT: Leer el archivo de texto y cargar los datos en la lista
    if (!File::Exists("maquina.txt")) {
        File::WriteAllText("maquina.txt", "");
    }
    array<String^>^ lineas = File::ReadAllLines("maquina.txt");
    String^ separadores = ";";
    for each(String ^ linea in lineas) {
        array<String^>^ campos = linea->Split(separadores->ToCharArray());
        int id = Convert::ToInt32(campos[0]);
        String^ nombre = campos[1];
        String^ tipo = campos[2];
        String^ turno = campos[3];
        String^ ubicacion = campos[4];

        Maquina^ maquina = gcnew Maquina(id, nombre, tipo, turno, ubicacion);
        this->listaMaquinas->Add(maquina);
    }
    */

    /* 
    //BIN: Leer el archivo binario y cargar los datos en la lista
    this->archivo = "maquina.bin";
    try {
        if (File::Exists(this->archivo)) {
            // El archivo existe, proceder con la lectura
            Stream^ stream = File::Open(this->archivo, FileMode::Open);
            BinaryFormatter^ formateador = gcnew BinaryFormatter();
            this->listaMaquinas = dynamic_cast<List<Maquina^>^>(formateador->Deserialize(stream));
            stream->Close();
        }
        else {
            // El archivo no existe, crear lista vacía
            Console::WriteLine("Archivo no encontrado. Creando nueva lista vacía.");
            this->listaMaquinas = gcnew List<Maquina^>();

            // Opcional: guardar lista vacía inmediatamente
            Stream^ stream = File::Create(this->archivo);
            BinaryFormatter^ formateador = gcnew BinaryFormatter();
            formateador->Serialize(stream, this->listaMaquinas);
            stream->Close();
        }
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error: " + ex->Message);
        // En caso de cualquier error, crear lista vacía
        this->listaMaquinas = gcnew List<Maquina^>();
    }
	*/

    /*
	//BD: Leer desde la base de datos y cargar los datos en la lista
	try {
        // Paso1: Establecer la conexion
        abrirConexion();
		// Paso2: Crear el comando SQL
        String^ sSql = "SELECT MachineId, Name, Type, State, Location ";
        sSql += " FROM Machine ";
		// Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
		SqlCommand^ comando = gcnew SqlCommand(sSql, getObjConexion()); 
		// Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
        // Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader
		SqlDataReader^ objData = comando->ExecuteReader();
        // Paso5: Leer los registros de la tabla
        while (objData->Read()) {
            int id = objData->GetInt32(0); // MachineId
            String^ nombre = objData->GetString(1); // Name
            String^ tipo = objData->GetString(2); // Type
            String^ estado = objData->GetString(3); // State
            String^ ubicacion = objData->GetString(4); // Location
            Maquina^ maquina = gcnew Maquina(id, nombre, tipo, estado, ubicacion);
            this->listaMaquinas->Add(maquina);
		}
        // Paso6: Cerrar el DataReader y la conexion
        objData->Close();
		cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
        // En caso de cualquier error, crear lista vacía
        this->listaMaquinas = gcnew List<Maquina^>();
	}
    */

	//BD con procedimiento almacenado: Leer desde la base de datos y cargar los datos en la lista
    try {
		// Paso1: Establecer la conexion
		SqlDataReader^ objData = executeStoredProcedureReader("usp_QueryAllMachines", nullptr); //Nombre del procedimiento almacenado y parámetros
		// Paso2: Leer los registros de la tabla
        if (objData != nullptr) {
            while (objData->Read()) {
				// Usamos el índice o el nombre de la columna para obtener los valores
                int id = safe_cast<int>(objData["MachineId"]); 
                String^ nombre = safe_cast<String^>(objData["Name"]);
                String^ tipo = safe_cast<String^>(objData["Type"]);
                String^ estado = safe_cast<String^>(objData["State"]);
                String^ ubicacion = safe_cast<String^>(objData["Location"]);
				// Crear el objeto Maquina y agregarlo a la lista
                Maquina^ maquina = gcnew Maquina(id, nombre, tipo, estado, ubicacion);
                this->listaMaquinas->Add(maquina);
            }
            objData->Close();
        }
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al cargar máquinas: " + ex->Message);
        this->listaMaquinas = gcnew List<Maquina^>();
    }
}

List<Maquina^>^ MaquinaController::ObtenerTodosMaquinas() {
    return this->listaMaquinas;
}

bool MaquinaController::AgregarMaquina(Maquina^ maquina) {
    if (!ExisteMaquina(maquina->getIdMaquina())) {
        this->listaMaquinas->Add(maquina);
        //escribirArchivo();
        //escribirArchivoBIN();

		// Preparamos el SQL para Insertar en la Base de Datos
        String^ sSql = "INSERT INTO Machine (MachineId, Name, Type, State, Location) ";
		sSql += " VALUES(" + maquina->getIdMaquina() + ", "; // Suponiendo que MachineId es de tipo INT
		sSql += " '" + maquina->getNombre() + "', "; // Suponiendo que Name es de tipo VARCHAR
		sSql += " '" + maquina->getTipo() + "', ";  // Suponiendo que Type es de tipo VARCHAR
		sSql += " '" + maquina->getEstado() + "', "; // Suponiendo que State es de tipo VARCHAR
		sSql += " '" + maquina->getUbicacion() + "')"; // Suponiendo que Location es de tipo VARCHAR
        int idMaquina = executeSql(sSql);
		if (idMaquina > 0)
            return true;
        else
			return false;
        
    }
    return false; // Si ya existe la máquina
}

bool MaquinaController::ExisteMaquina(int id) {
    return ConsultarMaquinaPorId(id) != nullptr;
}

Maquina^ MaquinaController::ConsultarMaquinaPorId(int id) {
    for each (Maquina ^ maquina in this->listaMaquinas) {
        if (maquina->getIdMaquina() == id) {
            return maquina;
        }
    }
    return nullptr;
}

void MaquinaController::escribirArchivo() {
    array<String^>^ lineasArchivo = gcnew array<String^>(this->listaMaquinas->Count);
    for (int i = 0; i < this->listaMaquinas->Count; i++) {
        Maquina^ maquina = this->listaMaquinas[i];
        lineasArchivo[i] = maquina->getIdMaquina() + ";" + maquina->getNombre() + ";" +
            maquina->getTipo() + ";" + maquina->getEstado() + ";" + maquina->getUbicacion();
    }
    File::WriteAllLines("maquina.txt", lineasArchivo);
}

List<Maquina^>^ MaquinaController::ConsultarMaquinaPorIdNombre(int id, String^ nombre)
{
    List<Maquina^>^ resultados = gcnew List<Maquina^>();
    for each(Maquina ^ maquina in this->listaMaquinas) {
        bool coincideId = (id == 0 || maquina->getIdMaquina() == id); // 0 significa "cualquier ID"
        bool coincideNombre = (String::IsNullOrEmpty(nombre) || maquina->getNombre()->Contains(nombre));

        if (coincideId && coincideNombre) {
            resultados->Add(maquina);
        }
    }
    return resultados;
}

bool MaquinaController::ModificarMaquina(int id, String^ nombre, String^ rol, String^ turno, String^ ubicacion) {
    Maquina^ maquina = ConsultarMaquinaPorId(id);
    if (maquina != nullptr) {
        maquina->setNombre(nombre);
        maquina->setTipo(rol);
        maquina->setEstado(turno);
        maquina->setUbicacion(ubicacion);
        //escribirArchivo();
        //escribirArchivoBIN();
		// Preparamos el SQL para Actualizar en la Base de Datos
		String^ sSql = "UPDATE Machine SET ";
		sSql += " Name = '" + nombre + "', ";
		sSql += " Type = '" + rol + "', ";
		sSql += " State = '" + turno + "', ";
		sSql += " Location = '" + ubicacion + "' ";
		sSql += " WHERE MachineId = " + id;
        return executeSql(sSql);
    }
    return false;

}

bool MaquinaController::EliminarMaquina(int id) {
    Maquina^ maquina = ConsultarMaquinaPorId(id);
    if (maquina != nullptr) {
        this->listaMaquinas->Remove(maquina);
        //escribirArchivo();
        //escribirArchivoBIN();
		// Preparamos el SQL para Eliminar en la Base de Datos
		String^ sSql = "DELETE FROM Machine WHERE MachineId = " + id;
        return executeSql(sSql);
    }
    return false;
}

void MaquinaController::CloseMaquina() {
    this->listaMaquinas = nullptr;
}

// Método para escribir en el archivo BIN
void MaquinaController::escribirArchivoBIN() {
    //Creamos el archivo
    Stream^ stream = File::Open(this->archivo, FileMode::Create);
    BinaryFormatter^ formateador = gcnew BinaryFormatter();
    formateador->Serialize(stream, this->listaMaquinas);
    stream->Close();
}

// Método para ejecutar el procedimiento almacenado de agregar máquina
bool MaquinaController::spAgregarMaquina(Maquina^ maquina) {
    if (!ExisteMaquina(maquina->getIdMaquina())) {
        this->listaMaquinas->Add(maquina);

		// Asignando los valores a cada atributo de la tabla Machine
        array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@MachineId", maquina->getIdMaquina()),
                gcnew SqlParameter("@Name", maquina->getNombre()),
                gcnew SqlParameter("@Type", maquina->getTipo()),
                gcnew SqlParameter("@State", maquina->getEstado()),
                gcnew SqlParameter("@Location", maquina->getUbicacion())
        };
		// Llamar al procedimiento almacenado
        bool resultado = executeStoredProcedure("usp_AddMachine", parameters);
		// Verificar el resultado
        if (resultado) {
            return true;
        }
        else {
            this->listaMaquinas->Remove(maquina);
            return false;
        }
    }
    return false;
}

// Método para ejecutar el procedimiento almacenado de modificar máquina
bool MaquinaController::spModificarMaquina(int id, String^ nombre, String^ rol, String^ turno, String^ ubicacion) {
    Maquina^ maquina = ConsultarMaquinaPorId(id);
	// Actualizar los valores en el objeto Maquina
    if (maquina != nullptr) {
        maquina->setNombre(nombre);
        maquina->setTipo(rol);
        maquina->setEstado(turno);
        maquina->setUbicacion(ubicacion);

        // Crear parámetros para el procedimiento almacenado
        array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@MachineId", id),
                gcnew SqlParameter("@Name", nombre),
                gcnew SqlParameter("@Type", rol),
                gcnew SqlParameter("@State", turno),
                gcnew SqlParameter("@Location", ubicacion)
        };
		// Llamar al procedimiento almacenado
        bool resultado = executeStoredProcedure("usp_UpdateMachine", parameters);

        return resultado;
    }
    return false;
}

bool MaquinaController::spEliminarMaquina(int id) {
    Maquina^ maquina = ConsultarMaquinaPorId(id);
    if (maquina != nullptr) {
        this->listaMaquinas->Remove(maquina);

        // Crear parámetro para el procedimiento almacenado
        array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@MachineId", id)
        };
		// Llamar al procedimiento almacenado
        bool resultado = executeStoredProcedure("usp_DeleteMachine", parameters);

        return resultado;
    }
    return false;
}