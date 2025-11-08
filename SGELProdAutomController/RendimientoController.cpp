#include "RendimientoController.h"

using namespace SGELProdAutomController;


RendimientoController::RendimientoController() {
    this->modelos = gcnew List<RendimientoSigmoide^>();
    // Agregar algunos modelos por defecto
    this->modelos->Add(CrearModeloRapido());
    this->modelos->Add(CrearModeloModerado());
    this->modelos->Add(CrearModeloLento());
}

void RendimientoController::AgregarModelo(RendimientoSigmoide^ modelo) {
    this->modelos->Add(modelo);
}

bool RendimientoController::RemoverModelo(int indice) {
    if (indice >= 0 && indice < this->modelos->Count) {
        this->modelos->RemoveAt(indice);
        return true;
    }
    return false;
}

RendimientoSigmoide^ RendimientoController::ObtenerModelo(int indice) {
    if (indice >= 0 && indice < this->modelos->Count) {
        return this->modelos[indice];
    }
    return nullptr;
}

List<RendimientoSigmoide^>^ RendimientoController::ObtenerTodosModelos() {
    return this->modelos;
}

void RendimientoController::LimpiarModelos() {
    this->modelos->Clear();
}

RendimientoSigmoide^ RendimientoController::CrearModeloRapido() {
    // Crecimiento rápido - alta tasa k
    RendimientoSigmoide^ modelo = gcnew RendimientoSigmoide(0.2, 30.0);
    modelo->GenerarPuntos(0, 100, 50);
    return modelo;
}

RendimientoSigmoide^ RendimientoController::CrearModeloLento() {
    // Crecimiento lento - baja tasa k
    RendimientoSigmoide^ modelo = gcnew RendimientoSigmoide(0.05, 70.0);
    modelo->GenerarPuntos(0, 150, 50);
    return modelo;
}

RendimientoSigmoide^ RendimientoController::CrearModeloModerado() {
    // Crecimiento moderado - tasa media k
    RendimientoSigmoide^ modelo = gcnew RendimientoSigmoide(0.1, 50.0);
    modelo->GenerarPuntos(0, 100, 50);
    return modelo;
}

RendimientoSigmoide^ RendimientoController::CrearModeloPersonalizado(double k, double x0) {
    RendimientoSigmoide^ modelo = gcnew RendimientoSigmoide(k, x0);
    modelo->GenerarPuntos(0, 2 * x0, 50); // Rango automático basado en x0
    return modelo;
}

List<PuntoRendimiento^>^ RendimientoController::CompararModelos(double x) {
    List<PuntoRendimiento^>^ comparativa = gcnew List<PuntoRendimiento^>();

    for (int i = 0; i < this->modelos->Count; i++) {
        double y = this->modelos[i]->CalcularY(x);
        PuntoRendimiento^ punto = gcnew PuntoRendimiento(i, y);
        comparativa->Add(punto);
    }

    return comparativa;
}

Dictionary<String^, double>^ RendimientoController::ObtenerComparativaEnPunto(double x) {
    Dictionary<String^, double>^ comparativa = gcnew Dictionary<String^, double>();

    for (int i = 0; i < this->modelos->Count; i++) {
        String^ clave = String::Format("Modelo_{0}", i + 1);
        double valor = this->modelos[i]->CalcularY(x);
        comparativa->Add(clave, valor);
    }

    return comparativa;
}

List<String^>^ RendimientoController::GenerarReporteComparativo(double xInicio, double xFin, int puntos) {
    List<String^>^ reporte = gcnew List<String^>();

    reporte->Add("REPORTE COMPARATIVO DE MODELOS SIGMOIDES");
    reporte->Add("=========================================");
    reporte->Add(String::Format("Rango de X: {0:F1} a {1:F1}", xInicio, xFin));
    reporte->Add("");

    double incremento = (xFin - xInicio) / (puntos - 1);

    // Cabecera
    String^ cabecera = "X\t";
    for (int i = 0; i < this->modelos->Count; i++) {
        cabecera += String::Format("Modelo_{0}\t", i + 1);
    }
    reporte->Add(cabecera);

    // Datos
    for (int p = 0; p < puntos; p++) {
        double x = xInicio + (p * incremento);
        String^ linea = String::Format("{0:F1}\t", x);

        for (int i = 0; i < this->modelos->Count; i++) {
            double y = this->modelos[i]->CalcularY(x);
            linea += String::Format("{0:F2}%\t", y);
        }

        reporte->Add(linea);
    }

    return reporte;
}

String^ RendimientoController::ExportarDatosCSV(RendimientoSigmoide^ modelo) {
    String^ csv = "HorasOperativas,RendimientoPorcentaje\n";

    for each (PuntoRendimiento ^ punto in modelo->getPuntos()) {
        csv += String::Format("{0:F2},{1:F2}\n", punto->getX(), punto->getY());
    }

    return csv;
}

String^ RendimientoController::ExportarTodosDatosCSV() {
    String^ csv = "Modelo,HorasOperativas,RendimientoPorcentaje,k,x0\n";

    for (int i = 0; i < this->modelos->Count; i++) {
        RendimientoSigmoide^ modelo = this->modelos[i];

        for each (PuntoRendimiento ^ punto in modelo->getPuntos()) {
            csv += String::Format("Modelo_{0},{1:F2},{2:F2},{3:F3},{4:F1}\n",
                i + 1, punto->getX(), punto->getY(), modelo->getK(), modelo->getX0());
        }
    }

    return csv;
}

bool RendimientoController::GuardarConfiguracion(String^ archivo) {
    // Implementación básica - en producción se usaría serialización
    try {
        // Simulación de guardado
        return true;
    }
    catch (Exception^) {
        return false;
    }
}

bool RendimientoController::CargarConfiguracion(String^ archivo) {
    // Implementación básica - en producción se usaría deserialización
    try {
        // Simulación de carga
        return true;
    }
    catch (Exception^) {
        return false;
    }
}