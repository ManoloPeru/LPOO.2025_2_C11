#pragma once

namespace SGELProdAutomView {
    using namespace System;
    using namespace System::Text;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;
    using namespace SGELProdAutomModel;

    public ref class ExportHelper {
    public:
        // Métodos de exportación
        static String^ ExportarRendimientoCSV(RendimientoSigmoide^ modelo, String^ maquina, double k, double x0);
        static String^ ExportarRendimientoTexto(RendimientoSigmoide^ modelo, String^ maquina, double k, double x0);
        static bool GuardarArchivo(String^ contenido, String^ filtro, String^ titulo, String^ nombreBase);

        // Métodos de utilidad para datos
        static String^ ClasificarRendimiento(double rendimiento);
        static String^ FormatearParametros(String^ maquina, double k, double x0);
        static String^ GenerarEncabezadoCSV();
        static String^ GenerarLineaDatos(PuntoRendimiento^ punto);

    private:
        static const int PRECISION_X = 1;
        static const int PRECISION_Y = 2;
        static const int PRECISION_PARAMETROS = 3;
    };
}