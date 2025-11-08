#include "GraphicsHelper.h"

namespace SGELProdAutomView {

    void GraphicsHelper::DibujarEjes(Graphics^ g, Control^ control) {
        Pen^ penEjes = gcnew Pen(Color::Black, 2);
        Pen^ penGrid = gcnew Pen(Color::LightGray, 1);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        Font^ fontEjes = gcnew Font("Arial", 8);

        float ancho = static_cast<float>(control->Width);
        float alto = static_cast<float>(control->Height);

        float escalaX = CalcularEscalaX(control, X_MIN, X_MAX);
        float escalaY = CalcularEscalaY(control, Y_MIN, Y_MAX);

        // Dibujar ejes principales
        g->DrawLine(penEjes, 0.0f, alto, ancho, alto);  // Eje X
        g->DrawLine(penEjes, 0.0f, 0.0f, 0.0f, alto);   // Eje Y

        // Grid y marcas en eje X
        for (int x = 0; x <= 100; x += 10) {
            float px = static_cast<float>((x - X_MIN) * escalaX);
            g->DrawLine(penGrid, px, 0.0f, px, alto);

            if (x % 20 == 0) {
                String^ texto = x.ToString();
                g->DrawString(texto, fontEjes, brushTexto, px - 10.0f, alto + 5.0f);
                g->DrawLine(penEjes, px, alto - 5.0f, px, alto + 5.0f);
            }
        }

        // Grid y marcas en eje Y
        for (int y = 0; y <= 100; y += 10) {
            float py = static_cast<float>(alto - ((y - Y_MIN) * escalaY));
            g->DrawLine(penGrid, 0.0f, py, ancho, py);

            if (y % 20 == 0) {
                String^ texto = y.ToString() + "%";
                g->DrawString(texto, fontEjes, brushTexto, 5.0f, py - 8.0f);
                g->DrawLine(penEjes, -5.0f, py, 5.0f, py);
            }
        }

        // Etiquetas de ejes
        Font^ fontEtiquetas = gcnew Font("Arial", 10, FontStyle::Bold);
        g->DrawString(ObtenerEtiquetaEjeX(), fontEtiquetas, brushTexto, ancho / 2.0f - 50.0f, alto + 25.0f);

        StringFormat^ formatoVertical = gcnew StringFormat();
        formatoVertical->FormatFlags = StringFormatFlags::DirectionVertical;
        g->DrawString(ObtenerEtiquetaEjeY(), fontEtiquetas, brushTexto, 5.0f, alto / 2.0f - 50.0f, formatoVertical);

        // Liberar recursos
        delete penEjes;
        delete penGrid;
        delete brushTexto;
        delete fontEjes;
        delete fontEtiquetas;
        delete formatoVertical;
    }

    void GraphicsHelper::DibujarSigmoide(Graphics^ g, Control^ control, RendimientoSigmoide^ modelo) {
        if (modelo == nullptr || modelo->getPuntos()->Count == 0) return;

        // Crear lápiz para la curva
        Pen^ penCurva = gcnew Pen(Color::FromArgb(0, 100, 200), 3);

        // Dibujar la curva
        List<PuntoRendimiento^>^ puntos = modelo->getPuntos();
        array<PointF>^ puntosGrafico = gcnew array<PointF>(puntos->Count);

        for (int i = 0; i < puntos->Count; i++) {
            puntosGrafico[i] = ConvertirCoordenadas(puntos[i]->getX(), puntos[i]->getY(), control);
        }

        if (puntos->Count >= 2) {
            g->DrawLines(penCurva, puntosGrafico);
        }

        // Dibujar punto de inflexión
        PuntoRendimiento^ inflexion = modelo->ObtenerPuntoInflexion();
        PointF puntoInf = ConvertirCoordenadas(inflexion->getX(), inflexion->getY(), control);

        SolidBrush^ brushInfleccion = gcnew SolidBrush(Color::Red);
        g->FillEllipse(brushInfleccion, puntoInf.X - 4.0f, puntoInf.Y - 4.0f, 8.0f, 8.0f);

        // Etiqueta del punto de inflexión
        Font^ fontInfleccion = gcnew Font("Arial", 8, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Red);
        String^ textoInfleccion = String::Format("Inflección ({0:F1}h, {1:F1}%)", inflexion->getX(), inflexion->getY());
        g->DrawString(textoInfleccion, fontInfleccion, brushTexto, puntoInf.X + 10.0f, puntoInf.Y - 15.0f);

        // Leyenda
        String^ leyenda = String::Format("Sigmoide - k={0:F3}, x₀={1:F1}", modelo->getK(), modelo->getX0());
        Font^ fontLeyenda = gcnew Font("Arial", 10, FontStyle::Bold);
        SolidBrush^ brushLeyenda = gcnew SolidBrush(Color::FromArgb(0, 100, 200));

        float posXLeyenda = static_cast<float>(control->Width - 200);
        g->DrawString(leyenda, fontLeyenda, brushLeyenda, posXLeyenda, 20.0f);

        // Liberar recursos
        delete penCurva;
        delete brushInfleccion;
        delete fontInfleccion;
        delete brushTexto;
        delete fontLeyenda;
        delete brushLeyenda;
    }

    PointF GraphicsHelper::ConvertirCoordenadas(double x, double y, Control^ control) {
        float ancho = static_cast<float>(control->Width);
        float alto = static_cast<float>(control->Height);

        float areaUtilAncho = ancho - 2 * MARGEN;
        float areaUtilAlto = alto - 2 * MARGEN;

        float escalaX = areaUtilAncho / (X_MAX - X_MIN);
        float escalaY = areaUtilAlto / (Y_MAX - Y_MIN);

        float px = MARGEN + static_cast<float>((x - X_MIN) * escalaX);
        float py = MARGEN + static_cast<float>(areaUtilAlto - ((y - Y_MIN) * escalaY));

        return PointF(px, py);
    }

    void GraphicsHelper::LimpiarGrafico(Graphics^ g, Control^ control) {
        g->Clear(Color::White);
        DibujarEjes(g, control);
    }

    float GraphicsHelper::CalcularEscalaX(Control^ control, double xMin, double xMax) {
        return (control->Width - 10) / static_cast<float>(xMax - xMin);
    }

    float GraphicsHelper::CalcularEscalaY(Control^ control, double yMin, double yMax) {
        return (control->Height - 10) / static_cast<float>(yMax - yMin);
    }

    Color GraphicsHelper::ObtenerColorPorRendimiento(double rendimiento) {
        if (rendimiento < 20) return Color::Red;
        else if (rendimiento < 40) return Color::Orange;
        else if (rendimiento < 60) return Color::Yellow;
        else if (rendimiento < 80) return Color::LightGreen;
        else return Color::Green;
    }

    String^ GraphicsHelper::ObtenerEtiquetaEjeX() {
        return "Horas Operativas";
    }

    String^ GraphicsHelper::ObtenerEtiquetaEjeY() {
        return "Rendimiento (%)";
    }
}