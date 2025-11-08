#pragma once

namespace SGELProdAutomView {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;
    using namespace System::Collections::Generic;
    using namespace SGELProdAutomModel;

    public ref class GraphicsHelper {
    public:
        // Métodos estáticos para reutilización
        static void DibujarEjes(Graphics^ g, Control^ control);
        static void DibujarSigmoide(Graphics^ g, Control^ control, RendimientoSigmoide^ modelo);
        static PointF ConvertirCoordenadas(double x, double y, Control^ control);
        static void LimpiarGrafico(Graphics^ g, Control^ control);

        // Métodos para escalas y conversiones
        static float CalcularEscalaX(Control^ control, double xMin, double xMax);
        static float CalcularEscalaY(Control^ control, double yMin, double yMax);

        // Métodos de utilidad
        static Color ObtenerColorPorRendimiento(double rendimiento);
        static String^ ObtenerEtiquetaEjeX();
        static String^ ObtenerEtiquetaEjeY();

    private:
        // Constantes para el gráfico
        static const double X_MIN = -10.0;
        static const double X_MAX = 110.0;
        static const double Y_MIN = -10.0;
        static const double Y_MAX = 110.0;
        static const float MARGEN = 20.0f;
    };
}
