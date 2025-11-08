#include "ValidationHelper.h"

namespace SGELProdAutomView {

    bool ValidationHelper::ValidarParametrosSigmoide(double k, double x0) {
        if (k <= 0 || x0 <= 0) {
            MostrarErrorValidacion("Los valores de k y x₀ deben ser mayores que cero.");
            return false;
        }
        return true;
    }

    bool ValidationHelper::ValidarSeleccionMaquina(ComboBox^ comboBox) {
        if (comboBox->SelectedItem == nullptr) {
            MostrarErrorValidacion("Debe seleccionar una Máquina.");
            return false;
        }
        return true;
    }

    bool ValidationHelper::ValidarTextBoxNoVacio(TextBox^ textBox, String^ nombreCampo) {
        if (String::IsNullOrWhiteSpace(textBox->Text)) {
            MostrarErrorValidacion(nombreCampo + " no puede estar vacío.");
            return false;
        }
        return true;
    }

    void ValidationHelper::MostrarErrorValidacion(String^ mensaje) {
        MessageBox::Show(mensaje, "Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }

    void ValidationHelper::MostrarErrorFormato(String^ nombreCampo) {
        MessageBox::Show("Por favor ingrese un valor numérico válido para " + nombreCampo + ".",
            "Error de Formato", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    void ValidationHelper::MostrarExito(String^ mensaje) {
        MessageBox::Show(mensaje, "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    bool ValidationHelper::TryParseDouble(String^ texto, double% resultado) {
        return Double::TryParse(texto, resultado);
    }

    String^ ValidationHelper::FormatearDouble(double valor, int decimales) {
        return valor.ToString("F" + decimales);
    }
}