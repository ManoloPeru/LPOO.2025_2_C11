#pragma once

namespace SGELProdAutomModel {
    using namespace System;
    using namespace Collections::Generic;
	// Clase que representa un punto en la curva de rendimiento
    public ref class PuntoRendimiento {
    private:
        double x;
        double y;

    public:
        PuntoRendimiento();
        PuntoRendimiento(double x, double y);

        double getX();
        void setX(double x);

        double getY();
        void setY(double y);

        String^ ToString() override;
    };

	// Clase que modela el rendimiento utilizando una función sigmoide
    public ref class RendimientoSigmoide {
    private:
        double k;           // Tasa de crecimiento
        double x0;          // Punto de inflexión
        List<PuntoRendimiento^>^ puntos;

    public:
        RendimientoSigmoide();
        RendimientoSigmoide(double k, double x0);

        double getK();
        void setK(double k);

        double getX0();
        void setX0(double x0);

        List<PuntoRendimiento^>^ getPuntos();

        // Métodos para cálculo de la función sigmoide
        double CalcularY(double x);
        void GenerarPuntos(double xInicio, double xFin, int numeroPuntos);
        void GenerarPuntos(double xInicio, double xFin, double incremento);

        // Métodos de análisis
        double ObtenerRendimientoMaximo();
        double ObtenerRendimientoMinimo();
        PuntoRendimiento^ ObtenerPuntoInflexion();
        List<PuntoRendimiento^>^ ObtenerPuntosPorEncimaDe(double porcentaje);

        // Métodos de utilidad
        void LimpiarPuntos();
        int ObtenerCantidadPuntos();
        String^ ObtenerResumen();
    };
}