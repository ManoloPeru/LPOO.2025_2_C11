#pragma once

namespace SGELProdAutomView {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class ValidationHelper {
    public:
        // Validaciones de formulario
        static bool ValidarParametrosSigmoide(double k, double x0);
        static bool ValidarSeleccionMaquina(ComboBox^ comboBox);
        static bool ValidarTextBoxNoVacio(TextBox^ textBox, String^ nombreCampo);

        // Mensajes de error
        static void MostrarErrorValidacion(String^ mensaje);
        static void MostrarErrorFormato(String^ nombreCampo);
        static void MostrarExito(String^ mensaje);

        // Utilidades de formato
        static bool TryParseDouble(String^ texto, double% resultado);
        static String^ FormatearDouble(double valor, int decimales);
    };
}