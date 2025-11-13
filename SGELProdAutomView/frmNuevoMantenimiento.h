#pragma once

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmNuevoMantenimiento
	/// </summary>
	public ref class frmNuevoMantenimiento : public System::Windows::Forms::Form
	{
	public:
		frmNuevoMantenimiento(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmNuevoMantenimiento(MantenimientoController^ mantenimientoController, Maquina^ objMaquina)
		{
			InitializeComponent();
			this->objMaquina = objMaquina;
			this->mantenimientoController = mantenimientoController;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoMantenimiento()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	protected:
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtDescripcion;

	private: System::Windows::Forms::TextBox^ txtEstado;
	private: System::Windows::Forms::TextBox^ txtTipo;
	private: System::Windows::Forms::TextBox^ txtCosto;
	private: System::Windows::Forms::TextBox^ txtMaquina;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::Label^ label3;

	private: Maquina^ objMaquina;
	private: MantenimientoController^ mantenimientoController;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
			this->txtEstado = (gcnew System::Windows::Forms::TextBox());
			this->txtTipo = (gcnew System::Windows::Forms::TextBox());
			this->txtCosto = (gcnew System::Windows::Forms::TextBox());
			this->txtMaquina = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Controls->Add(this->dtpFecha);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtDescripcion);
			this->grpBoxPrincipal->Controls->Add(this->txtEstado);
			this->grpBoxPrincipal->Controls->Add(this->txtTipo);
			this->grpBoxPrincipal->Controls->Add(this->txtCosto);
			this->grpBoxPrincipal->Controls->Add(this->txtMaquina);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(14, 14);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(578, 355);
			this->grpBoxPrincipal->TabIndex = 17;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Nuevo Mantenimientos de la Maquina";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 303);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 24);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Costo:";
			// 
			// dtpFecha
			// 
			this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFecha->Location = System::Drawing::Point(139, 156);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(150, 28);
			this->dtpFecha->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 211);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Descripción:";
			// 
			// txtDescripcion
			// 
			this->txtDescripcion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtDescripcion->Location = System::Drawing::Point(139, 208);
			this->txtDescripcion->Margin = System::Windows::Forms::Padding(5);
			this->txtDescripcion->MaxLength = 200;
			this->txtDescripcion->Multiline = true;
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(403, 65);
			this->txtDescripcion->TabIndex = 4;
			// 
			// txtEstado
			// 
			this->txtEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEstado->Location = System::Drawing::Point(392, 152);
			this->txtEstado->Margin = System::Windows::Forms::Padding(5);
			this->txtEstado->MaxLength = 10;
			this->txtEstado->Name = L"txtEstado";
			this->txtEstado->Size = System::Drawing::Size(150, 28);
			this->txtEstado->TabIndex = 3;
			// 
			// txtTipo
			// 
			this->txtTipo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtTipo->Location = System::Drawing::Point(139, 107);
			this->txtTipo->Margin = System::Windows::Forms::Padding(5);
			this->txtTipo->MaxLength = 20;
			this->txtTipo->Name = L"txtTipo";
			this->txtTipo->Size = System::Drawing::Size(403, 28);
			this->txtTipo->TabIndex = 1;
			// 
			// txtCosto
			// 
			this->txtCosto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCosto->Location = System::Drawing::Point(139, 300);
			this->txtCosto->Margin = System::Windows::Forms::Padding(5);
			this->txtCosto->Name = L"txtCosto";
			this->txtCosto->Size = System::Drawing::Size(150, 28);
			this->txtCosto->TabIndex = 5;
			this->txtCosto->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtCosto->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &frmNuevoMantenimiento::txtCosto_KeyPress);
			// 
			// txtMaquina
			// 
			this->txtMaquina->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->txtMaquina->Location = System::Drawing::Point(139, 54);
			this->txtMaquina->Margin = System::Windows::Forms::Padding(5);
			this->txtMaquina->Name = L"txtMaquina";
			this->txtMaquina->Size = System::Drawing::Size(403, 28);
			this->txtMaquina->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(313, 156);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 107);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Tipo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 156);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Fecha:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 57);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Maquina:";
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(115, 401);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 56);
			this->btnGrabar->TabIndex = 6;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevoMantenimiento::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(331, 401);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevoMantenimiento::btnCancelar_Click);
			// 
			// frmNuevoMantenimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 484);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Name = L"frmNuevoMantenimiento";
			this->Text = L"Gestión de Mantenimientos por Maquina";
			this->Load += gcnew System::EventHandler(this, &frmNuevoMantenimiento::frmNuevoMantenimiento_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void frmNuevoMantenimiento_Load(System::Object^ sender, System::EventArgs^ e) {
	this->txtMaquina->Text = this->objMaquina->getNombre();
	}

	private: System::Void txtCosto_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			   // Permitir teclas de control (backspace, delete, etc.)
			   if (Char::IsControl(e->KeyChar)) {
				   e->Handled = false;
				   return;
			   }

			   // Permitir números
			   if (Char::IsDigit(e->KeyChar)) {
				   e->Handled = false;
				   return;
			   }

			   // Permitir punto decimal
			   if (e->KeyChar == '.') {
				   // Verificar que no exista ya un punto en el texto
				   TextBox^ txt = (TextBox^)sender;
				   if (txt->Text->Contains(".")) {
					   e->Handled = true;
				   }
				   else {
					   e->Handled = false;
				   }
				   return;
			   }

			   // Permitir coma (para separadores de miles en formato peruano)
			   if (e->KeyChar == ',') {
				   e->Handled = false;
				   return;
			   }

			   // No permitir cualquier otro carácter
			   e->Handled = true;
	}

private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
	Mantenimiento^ nuevoMantenimiento = gcnew Mantenimiento();
	nuevoMantenimiento->setMaquina(this->objMaquina);
	nuevoMantenimiento->setTipo(this->txtTipo->Text);
	nuevoMantenimiento->setFecha(this->dtpFecha->Value.ToShortDateString());
	nuevoMantenimiento->setEstado(this->txtEstado->Text);
	nuevoMantenimiento->setDescripcion(this->txtDescripcion->Text);
	nuevoMantenimiento->setCosto(Convert::ToDecimal(this->txtCosto->Text));
	int exito = this->mantenimientoController->AgregarMantenimiento(nuevoMantenimiento);
	if (exito > 0) {
		MessageBox::Show("Mantenimiento agregado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close(); // Cerrar el formulario después de grabar
	}
	else {
		MessageBox::Show("Error al agregar el mantenimiento.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
