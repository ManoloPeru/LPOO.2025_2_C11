#pragma once

namespace SGELProdAutomController {
    using namespace System;
    using namespace Collections::Generic;
    using namespace SGELProdAutomModel;

    public ref class RendimientoController {
    private:
        List<RendimientoSigmoide^>^ modelos;

    public:
        RendimientoController();

        // Gestión de modelos
        void AgregarModelo(RendimientoSigmoide^ modelo);
        bool RemoverModelo(int indice);
        RendimientoSigmoide^ ObtenerModelo(int indice);
        List<RendimientoSigmoide^>^ ObtenerTodosModelos();
        void LimpiarModelos();

        // Modelos predefinidos
        RendimientoSigmoide^ CrearModeloRapido();
        RendimientoSigmoide^ CrearModeloLento();
        RendimientoSigmoide^ CrearModeloModerado();
        RendimientoSigmoide^ CrearModeloPersonalizado(double k, double x0);

        // Análisis comparativo
        List<PuntoRendimiento^>^ CompararModelos(double x);
        Dictionary<String^, double>^ ObtenerComparativaEnPunto(double x);
        List<String^>^ GenerarReporteComparativo(double xInicio, double xFin, int puntos);

        // Exportación de datos
        String^ ExportarDatosCSV(RendimientoSigmoide^ modelo);
        String^ ExportarTodosDatosCSV();
        bool GuardarConfiguracion(String^ archivo);
        bool CargarConfiguracion(String^ archivo);
    };
}