#include "ExportHelper.h"

namespace SGELProdAutomView {

    String^ ExportHelper::ExportarRendimientoCSV(RendimientoSigmoide^ modelo, String^ maquina, double k, double x0) {
        StringBuilder^ sb = gcnew StringBuilder();

        // Encabezado
        sb->AppendLine(FormatearParametros(maquina, k, x0));
        sb->AppendLine();
        sb->AppendLine(GenerarEncabezadoCSV());

        // Datos
        List<PuntoRendimiento^>^ puntos = modelo->getPuntos();
        for each (PuntoRendimiento ^ punto in puntos) {
            sb->AppendLine(GenerarLineaDatos(punto));
        }

        return sb->ToString();
    }

    String^ ExportHelper::ExportarRendimientoTexto(RendimientoSigmoide^ modelo, String^ maquina, double k, double x0) {
        StringBuilder^ sb = gcnew StringBuilder();

        sb->AppendLine("REPORTE DE RENDIMIENTO SIGMOIDE");
        sb->AppendLine("================================");
        sb->AppendLine(FormatearParametros(maquina, k, x0));
        sb->AppendLine();
        sb->AppendLine("DATOS DE RENDIMIENTO:");
        sb->AppendLine("---------------------");

        List<PuntoRendimiento^>^ puntos = modelo->getPuntos();
        for each (PuntoRendimiento ^ punto in puntos) {
            sb->AppendLine(String::Format("  {0} -> {1}",
                GenerarLineaDatos(punto), ClasificarRendimiento(punto->getY())));
        }

        return sb->ToString();
    }

    bool ExportHelper::GuardarArchivo(String^ contenido, String^ filtro, String^ titulo, String^ nombreBase) {
        SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
        saveDialog->Filter = filtro;
        saveDialog->Title = titulo;
        saveDialog->FileName = nombreBase;

        if (saveDialog->ShowDialog() == DialogResult::OK) {
            System::IO::File::WriteAllText(saveDialog->FileName, contenido, Text::Encoding::UTF8);
            return true;
        }
        return false;
    }

    String^ ExportHelper::ClasificarRendimiento(double rendimiento) {
        if (rendimiento < 20) return "Muy Bajo";
        else if (rendimiento < 40) return "Bajo";
        else if (rendimiento < 60) return "Moderado";
        else if (rendimiento < 80) return "Alto";
        else return "Muy Alto";
    }

    String^ ExportHelper::FormatearParametros(String^ maquina, double k, double x0) {
        return String::Format("Máquina: {0}\nTasa de Crecimiento (k): {1:F3}\nPunto de Inflexión (x₀): {2:F1}",
            maquina, k, x0);
    }

    String^ ExportHelper::GenerarEncabezadoCSV() {
        return "Hora Operativa,Rendimiento (%),Estado";
    }

    String^ ExportHelper::GenerarLineaDatos(PuntoRendimiento^ punto) {
        return String::Format("{0:F1},{1:F2},{2}",
            punto->getX(), punto->getY(), ClasificarRendimiento(punto->getY()));
    }
}