#pragma once
#include "BaseController.h" // 1.- Incluyendo la clase base para conectarme a la BD

namespace SGELProdAutomController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SGELProdAutomModel;

	public ref class MantenimientoController : public BaseController {
		private:
			List<Mantenimiento^>^ listaMantenimientos;
	public:
		MantenimientoController();
		List<Mantenimiento^>^ ObtenerTodosMantenimientos();
		List<Mantenimiento^>^ buscarxMaquina(int codigo);
		bool AgregarMantenimiento(Mantenimiento^ mantenimiento);
		bool ExisteMantenimiento(int id);
		Mantenimiento^ ConsultarMantenimientoPorId(int id);
		bool ModificarMantenimiento(int id, Maquina^ maquina, String^ tipo, String^ fecha, String^ estado, String^ descripcion, Decimal costo);
		bool EliminarMantenimiento(int id);
		void CloseMantenimiento();

		bool spAgregarMantenimiento(Mantenimiento^ mantenimiento);
	};	
}