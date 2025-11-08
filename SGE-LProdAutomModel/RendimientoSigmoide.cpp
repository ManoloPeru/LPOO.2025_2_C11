#include "RendimientoSigmoide.h"
#include <math.h>

namespace SGELProdAutomModel {

    // Implementación de PuntoRendimiento
    PuntoRendimiento::PuntoRendimiento() {
        this->x = 0.0;
        this->y = 0.0;
    }

    PuntoRendimiento::PuntoRendimiento(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double PuntoRendimiento::getX() {
        return this->x;
    }

    void PuntoRendimiento::setX(double x) {
        this->x = x;
    }

    double PuntoRendimiento::getY() {
        return this->y;
    }

    void PuntoRendimiento::setY(double y) {
        this->y = y;
    }

    String^ PuntoRendimiento::ToString() {
        return String::Format("(x: {0:F2}, y: {1:F2}%)", this->x, this->y);
    }

    // Implementación de RendimientoSigmoide
    RendimientoSigmoide::RendimientoSigmoide() {
        this->k = 0.1;
        this->x0 = 50.0;
        this->puntos = gcnew List<PuntoRendimiento^>();
    }

    RendimientoSigmoide::RendimientoSigmoide(double k, double x0) {
        this->k = k;
        this->x0 = x0;
        this->puntos = gcnew List<PuntoRendimiento^>();
    }

    double RendimientoSigmoide::getK() {
        return this->k;
    }

    void RendimientoSigmoide::setK(double k) {
        this->k = k;
    }

    double RendimientoSigmoide::getX0() {
        return this->x0;
    }

    void RendimientoSigmoide::setX0(double x0) {
        this->x0 = x0;
    }

    List<PuntoRendimiento^>^ RendimientoSigmoide::getPuntos() {
        return this->puntos;
    }

    double RendimientoSigmoide::CalcularY(double x) {
        // 𝑦 = 100/(1 + Exp(-k * (x - x0)))
        double exponente = -this->k * (x - this->x0);
        double denominador = 1.0 + Math::Exp(exponente);
        return 100.0 / denominador;
    }

    void RendimientoSigmoide::GenerarPuntos(double xInicio, double xFin, int numeroPuntos) {
        this->puntos->Clear();

        if (numeroPuntos < 2) numeroPuntos = 2;
        double incremento = (xFin - xInicio) / (numeroPuntos - 1);

        for (int i = 0; i < numeroPuntos; i++) {
            double x = xInicio + (i * incremento);
            double y = CalcularY(x);
            PuntoRendimiento^ punto = gcnew PuntoRendimiento(x, y);
            this->puntos->Add(punto);
        }
    }

    void RendimientoSigmoide::GenerarPuntos(double xInicio, double xFin, double incremento) {
        this->puntos->Clear();

        if (incremento <= 0) incremento = 1.0;

        double x = xInicio;
        while (x <= xFin) {
            double y = CalcularY(x);
            PuntoRendimiento^ punto = gcnew PuntoRendimiento(x, y);
            this->puntos->Add(punto);
            x += incremento;
        }
    }

    double RendimientoSigmoide::ObtenerRendimientoMaximo() {
        if (this->puntos->Count == 0) return 0.0;

        double maximo = this->puntos[0]->getY();
        for each (PuntoRendimiento ^ punto in this->puntos) {
            if (punto->getY() > maximo) {
                maximo = punto->getY();
            }
        }
        return maximo;
    }

    double RendimientoSigmoide::ObtenerRendimientoMinimo() {
        if (this->puntos->Count == 0) return 0.0;

        double minimo = this->puntos[0]->getY();
        for each (PuntoRendimiento ^ punto in this->puntos) {
            if (punto->getY() < minimo) {
                minimo = punto->getY();
            }
        }
        return minimo;
    }

    PuntoRendimiento^ RendimientoSigmoide::ObtenerPuntoInflexion() {
        // El punto de inflexión ocurre cuando x = x0, y = 50%
        double y = CalcularY(this->x0);
        return gcnew PuntoRendimiento(this->x0, y);
    }

    List<PuntoRendimiento^>^ RendimientoSigmoide::ObtenerPuntosPorEncimaDe(double porcentaje) {
        List<PuntoRendimiento^>^ puntosFiltrados = gcnew List<PuntoRendimiento^>();

        for each (PuntoRendimiento ^ punto in this->puntos) {
            if (punto->getY() >= porcentaje) {
                puntosFiltrados->Add(punto);
            }
        }
        return puntosFiltrados;
    }

    void RendimientoSigmoide::LimpiarPuntos() {
        this->puntos->Clear();
    }

    int RendimientoSigmoide::ObtenerCantidadPuntos() {
        return this->puntos->Count;
    }

    String^ RendimientoSigmoide::ObtenerResumen() {
        return String::Format(
            "Sigmoide - k: {0:F3}, x0: {1:F1}, Puntos: {2}, Rango Y: [{3:F1}% - {4:F1}%]",
            this->k, this->x0, this->puntos->Count,
            ObtenerRendimientoMinimo(), ObtenerRendimientoMaximo()
        );
    }
}