#include "Mantenimiento.h"

using namespace SGELProdAutomModel;
using namespace System;
Mantenimiento::Mantenimiento() {
	this->idMantenimiento = 0;
	this->maquina = gcnew Maquina();
	this->tipo = "";
	this->fecha = "";
	this->estado = "";
	this->descripcion = "";
	this->costo = 0;
}
Mantenimiento::Mantenimiento(int idMantenimiento, Maquina^ maquina, String^ tipo, String^ fecha, String^ estado, String^ descripcion, Decimal costo) {
	this->idMantenimiento = idMantenimiento;
	this->maquina = maquina;
	this->tipo = tipo;
	this->fecha = fecha;
	this->estado = estado;
	this->descripcion = descripcion;
	this->costo = costo;
}
int Mantenimiento::getIdMantenimiento() {
	return this->idMantenimiento;
}
void Mantenimiento::setIdMantenimiento(int id) {
	this->idMantenimiento = id;
}
Maquina^ Mantenimiento::getMaquina() {
	return this->maquina;
}
void Mantenimiento::setMaquina(Maquina^ maquina) {
	this->maquina = maquina;
}
String^ Mantenimiento::getTipo() {
	return this->tipo;
}
void Mantenimiento::setTipo(String^ tipo) {
	this->tipo = tipo;
}
String^ Mantenimiento::getFecha() {
	return this->fecha;
}
void Mantenimiento::setFecha(String^ fecha) {
	this->fecha = fecha;
}
String^ Mantenimiento::getEstado() {
	return this->estado;
}
void Mantenimiento::setEstado(String^ estado) {
	this->estado = estado;
}
String^ Mantenimiento::getDescripcion() {
	return this->descripcion;
}
void Mantenimiento::setDescripcion(String^ descripcion) {
	this->descripcion = descripcion;
}
Decimal Mantenimiento::getCosto() {
	return this->costo;
}
void Mantenimiento::setCosto(Decimal costo) {
	this->costo = costo;
}
String^ Mantenimiento::ToString() {
	return "Mantenimiento [ID=" + this->idMantenimiento + ", Maquina=" + this->maquina->ToString() +
		", Tipo=" + this->tipo + ", Fecha=" + this->fecha + ", Estado=" + this->estado +
		", Descripcion=" + this->descripcion + ", Costo=" + this->costo + "]";
}