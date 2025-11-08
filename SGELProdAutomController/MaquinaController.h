#pragma once
#include "BaseController.h" // 1.- Incluyendo la clase base para conectarme a la BD

namespace SGELProdAutomController {
    using namespace System;
    using namespace Collections::Generic;
    using namespace SGELProdAutomModel;

	public ref class MaquinaController : public BaseController { // 2.- Herencia de BaseController
    private:
        List<Maquina^>^ listaMaquinas;
        //Manejo de archivos binarios:
        String^ archivo;

    public:
        MaquinaController();
        // Operaciones CRUD
        List<Maquina^>^ ObtenerTodosMaquinas();
        bool AgregarMaquina(Maquina^ maquina);
        bool ExisteMaquina(int id);
        Maquina^ ConsultarMaquinaPorId(int id);
        void escribirArchivo();
        List<Maquina^>^ ConsultarMaquinaPorIdNombre(int id, String^ nombre);
        bool ModificarMaquina(int id, String^ nombre, String^ tipo, String^ estado, String^ ubicacion);
        bool EliminarMaquina(int id);
        // Ultima acción para liberar memoria, conexiones
        void CloseMaquina();
        
        //Para los archivos BIN
        void escribirArchivoBIN();
    };
}