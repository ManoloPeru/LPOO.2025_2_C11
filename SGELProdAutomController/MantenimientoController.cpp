#include "MantenimientoController.h"

using namespace SGELProdAutomController;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace SGELProdAutomModel;

MantenimientoController::MantenimientoController() {
	this->listaMantenimientos = gcnew List<Mantenimiento^>();
	//BD: Leer desde la base de datos y cargar los datos en la lista
	try {
		this->abrirConexion();
		String^ sSql = "SELECT m.MaintenanceiD, m.Type, m.Date, m.State, m.Description, m.Cost, "
					   "ma.MachineId, ma.Name, ma.Type AS tipoMaquina, ma.State AS estadoMaquina, ma.Location "
					   "FROM Maintenance m "
					   "JOIN Machine ma ON m.MachineId = ma.MachineId";
		SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		SqlDataReader^ lector = comando->ExecuteReader();
		while (lector->Read()) {
			int idMantenimiento = lector->GetInt32(0);
			String^ tipo = lector->GetString(1);
			String^ fecha = lector->GetString(2);
			String^ estado = lector->GetString(3);
			String^ descripcion = lector->GetString(4);
			Decimal costo = lector->GetDecimal(5);
			int idMaquina = lector->GetInt32(6);
			String^ nombre = lector->GetString(7);
			String^ tipoMaquina = lector->GetString(8);
			String^ estadoMaquina = lector->GetString(9);
			String^ ubicacion = lector->GetString(10);
			Maquina^ maquina = gcnew Maquina(idMaquina, nombre, tipoMaquina, estadoMaquina, ubicacion);
			Mantenimiento^ mantenimiento = gcnew Mantenimiento(idMantenimiento, maquina, tipo, fecha, estado, descripcion, costo);
			this->listaMantenimientos->Add(mantenimiento);
		}
		lector->Close();
		this->cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al cargar mantenimientos: " + ex->Message);
	}
}

List<Mantenimiento^>^ MantenimientoController::buscarxMaquina(int codigoMaquina) {
	List<Mantenimiento^>^ listaMantenimientos = ObtenerTodosMantenimientos();
	List<Mantenimiento^>^ listMantenimientoxMaquina = gcnew List<Mantenimiento^>();
	for (int i = 0; i < listaMantenimientos->Count; i++) {
		Mantenimiento^ mantenimiento = listaMantenimientos[i];
		if (mantenimiento->getMaquina()->getIdMaquina() == codigoMaquina) {
			listMantenimientoxMaquina->Add(mantenimiento);
		}
	}
	return listMantenimientoxMaquina;
}

List<Mantenimiento^>^ MantenimientoController::ObtenerTodosMantenimientos() {
	return this->listaMantenimientos;
}

bool MantenimientoController::AgregarMantenimiento(Mantenimiento^ mantenimiento) {
	try
	{
		// Preparamos el SQL para Insertar en la Base de Datos
		String^ sSql = "INSERT INTO Maintenance (MachineId, Type, Date, State, Description, Cost) VALUES (";
		sSql += mantenimiento->getMaquina()->getIdMaquina() + ", ";
		sSql += "'" + mantenimiento->getTipo() + "', ";
		sSql += "'" + mantenimiento->getFecha() + "', ";
		sSql += "'" + mantenimiento->getEstado() + "', ";
		sSql += "'" + mantenimiento->getDescripcion() + "', ";
		sSql += mantenimiento->getCosto() + ")";
		// Ejecutamos el SQL y obtenemos el ID generado
		int idMantenimiento = insertSql(sSql);
		// Asignamos el ID al objeto 
		mantenimiento->setIdMantenimiento(idMantenimiento);
		// Lo agregamos a la lista
		this->listaMantenimientos->Add(mantenimiento);
		return true;

	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Error al AgregarMantenimiento: " + ex->Message);
		return 0;
	}
}

bool MantenimientoController::ExisteMantenimiento(int id) {
	for each (Mantenimiento^ mantenimiento in this->listaMantenimientos) {
		if (mantenimiento->getIdMantenimiento() == id) {
			return true;
		}
	}
	return false;
}

Mantenimiento^ MantenimientoController::ConsultarMantenimientoPorId(int id) {
	for each (Mantenimiento^ mantenimiento in this->listaMantenimientos) {
		if (mantenimiento->getIdMantenimiento() == id) {
			return mantenimiento;
		}
	}
	return nullptr;
}

bool MantenimientoController::ModificarMantenimiento(int id, Maquina^ maquina, String^ tipo, String^ fecha, String^ estado, String^ descripcion, Decimal costo) {
	Mantenimiento^ mantenimiento = ConsultarMantenimientoPorId(id);
	if (mantenimiento != nullptr) {
		mantenimiento->setMaquina(maquina);
		mantenimiento->setTipo(tipo);
		mantenimiento->setFecha(fecha);
		mantenimiento->setEstado(estado);
		mantenimiento->setDescripcion(descripcion);
		mantenimiento->setCosto(costo);
		// Preparamos el SQL para Actualizar en la Base de Datos
		String^ sSql = "UPDATE Maintenance SET ";
		sSql += "MachineId = " + maquina->getIdMaquina() + ", ";
		sSql += "Type = '" + tipo + "', ";
		sSql += "Date = '" + fecha + "', ";
		sSql += "State = '" + estado + "', ";
		sSql += "Description = '" + descripcion + "', ";
		sSql += "Cost = " + costo + " ";
		sSql += "WHERE idMaintenance = " + id;
		return executeSql(sSql);
	}
	return false;
}

bool MantenimientoController::EliminarMantenimiento(int id) {
	Mantenimiento^ mantenimiento = ConsultarMantenimientoPorId(id);
	if (mantenimiento != nullptr) {
		this->listaMantenimientos->Remove(mantenimiento);
		// Preparamos el SQL para Eliminar en la Base de Datos
		String^ sSql = "DELETE FROM Maintenance WHERE idMaintenance = " + id;
		return executeSql(sSql);
	}
	return false;
}

void MantenimientoController::CloseMantenimiento() {
	this->cerrarConexion();
}