#include "BaseController.h"

using namespace SGELProdAutomController;
using namespace System::IO;

BaseController::BaseController() {
	this->objConexion = gcnew SqlConnection();
}

SqlConnection^ BaseController::getObjConexion() {
	return this->objConexion;
}

void BaseController::abrirConexion() {
	/*Paso 1, establecer la cadena de conexion*/
	/*LOCAL*/
	this->objConexion->ConnectionString = "Server=192.168.1.35;DataBase=lpoo_2025_2;User id=sa;Password=Passw0rd";
	
	/*PUCP*/
	//this->objConexion->ConnectionString = "Server={IP};DataBase={BD};User id={User};Password={PWD}";
	
	/*AWS*/
	//this->objConexion->ConnectionString = "Server=lpoo2024.c1uehfrpd23g.us-east-1.rds.amazonaws.com;DataBase=lpoo2024;User id=lpoo2024;Password=Passw0rd2024#";
	
	/*Paso 2, abrir la conexion*/
	this->objConexion->Open();
}

int BaseController::insertSql(String^ sSql) {
	try {
		abrirConexion();
		String^ sSqlPK = sSql + "; SELECT SCOPE_IDENTITY();"; // SCOPE_IDENTITY(): Permite obtener el valor del IdPK generado
		SqlCommand^ comando = gcnew SqlCommand(sSqlPK, this->getObjConexion());
		int idPK = Convert::ToInt32(comando->ExecuteScalar()); // ExecuteScalar(): Ejecuta la consulta y devuelve la primera columna de la primera fila del conjunto de resultados
		this->cerrarConexion();
		return idPK;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar SQL: " + ex->Message);
		return 0;
	}
}

bool BaseController::executeSql(String^ sSql) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		comando->ExecuteNonQuery(); // ExecuteNonQuery(): Ejecuta una sentencia SQL que no devuelve filas (como UPDATE o DELETE)
		this->cerrarConexion();
		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar SQL: " + ex->Message);
		return false;
	}
}

void BaseController::cerrarConexion() {
	//Paso 3, cerrar la conexion
	this->objConexion->Close();
}

// Metodo para ejecutar procedimientos almacenados que devuelven un SqlDataReader
SqlDataReader^ BaseController::executeStoredProcedureReader(String^ procedureName, array<SqlParameter^>^ parameters) {
	//procedureName: Nombre del procedimiento almacenado
	//parameters: Arreglo de parámetros para el procedimiento almacenado
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(procedureName, this->getObjConexion());
		comando->CommandType = CommandType::StoredProcedure;

		if (parameters != nullptr) {
			for each (SqlParameter ^ param in parameters) {
				comando->Parameters->Add(param);
			}
		}

		return comando->ExecuteReader();
		// Nota: La conexión se cierra después de usar el DataReader
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return nullptr;
	}
}

// Metodo para ejecutar procedimientos almacenados que no devuelven resultados
bool BaseController::executeStoredProcedure(String^ procedureName, array<SqlParameter^>^ parameters) {
	//procedureName: Nombre del procedimiento almacenado
	//parameters: Arreglo de parámetros para el procedimiento almacenado
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(procedureName, this->getObjConexion());
		comando->CommandType = CommandType::StoredProcedure;

		// Agregar parámetros si existen
		if (parameters != nullptr) {
			for each (SqlParameter ^ param in parameters) {
				comando->Parameters->Add(param);
			}
		}

		comando->ExecuteNonQuery();
		cerrarConexion();
		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return false;
	}
}

// Metodo para ejecutar procedimientos almacenados que devuelven un valor escalar (int)
int BaseController::executeStoredProcedureScalar(String^ procedureName, array<SqlParameter^>^ parameters) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(procedureName, this->getObjConexion());
		comando->CommandType = CommandType::StoredProcedure;

		if (parameters != nullptr) {
			for each (SqlParameter ^ param in parameters) {
				comando->Parameters->Add(param);
			}
		}

		Object^ result = comando->ExecuteScalar();
		cerrarConexion();

		if (result != nullptr && result != DBNull::Value) {
			return Convert::ToInt32(result);
		}
		return 0;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return 0;
	}
}