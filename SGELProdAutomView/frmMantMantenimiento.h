#pragma once
#include "frmNuevoMantenimiento.h"

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmMantMantenimiento
	/// </summary>
	public ref class frmMantMantenimiento : public System::Windows::Forms::Form
	{
	public:
		frmMantMantenimiento(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmMantMantenimiento(Maquina^ objMaquina)
		{
			InitializeComponent();
			this->objMaquina = objMaquina;
			this->listaMantenimientos = gcnew List<Mantenimiento^>();
			this->mantenimientoController = gcnew MantenimientoController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantMantenimiento()
		{
			if (components)
			{
				delete components;
			}
		}
	

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtUbicacion;
	private: System::Windows::Forms::TextBox^ txtTipo;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: Maquina^ objMaquina;
	private: List<Mantenimiento^>^ listaMantenimientos;
	private: MantenimientoController^ mantenimientoController;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDescripcion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCosto;


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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtUbicacion = (gcnew System::Windows::Forms::TextBox());
			this->txtTipo = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCosto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(356, 94);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 24);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Ubicación:";
			// 
			// txtUbicacion
			// 
			this->txtUbicacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->txtUbicacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUbicacion->Location = System::Drawing::Point(465, 94);
			this->txtUbicacion->Margin = System::Windows::Forms::Padding(5);
			this->txtUbicacion->Name = L"txtUbicacion";
			this->txtUbicacion->Size = System::Drawing::Size(201, 29);
			this->txtUbicacion->TabIndex = 13;
			// 
			// txtTipo
			// 
			this->txtTipo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->txtTipo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTipo->Location = System::Drawing::Point(118, 91);
			this->txtTipo->Margin = System::Windows::Forms::Padding(5);
			this->txtTipo->Name = L"txtTipo";
			this->txtTipo->Size = System::Drawing::Size(201, 29);
			this->txtTipo->TabIndex = 10;
			// 
			// txtNombre
			// 
			this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(118, 45);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(548, 29);
			this->txtNombre->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(20, 94);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 24);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Tipo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(20, 48);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 24);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Maquina:";
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(742, 525);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(98, 34);
			this->btnEliminar->TabIndex = 17;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(524, 525);
			this->btnEditar->Margin = System::Windows::Forms::Padding(4);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(98, 34);
			this->btnEditar->TabIndex = 16;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(310, 525);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(4);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(98, 34);
			this->btnNuevo->TabIndex = 15;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantMantenimiento::btnNuevo_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colId, this->colTipo,
					this->colFecha, this->colEstado, this->colDescripcion, this->colCosto
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLista->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvLista->Location = System::Drawing::Point(24, 145);
			this->dgvLista->Margin = System::Windows::Forms::Padding(4);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1065, 357);
			this->dgvLista->TabIndex = 18;
			// 
			// colId
			// 
			this->colId->HeaderText = L"Id";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->MinimumWidth = 6;
			this->colTipo->Name = L"colTipo";
			this->colTipo->Width = 120;
			// 
			// colFecha
			// 
			this->colFecha->HeaderText = L"Fecha";
			this->colFecha->Name = L"colFecha";
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 120;
			// 
			// colDescripcion
			// 
			this->colDescripcion->HeaderText = L"Descripción";
			this->colDescripcion->Name = L"colDescripcion";
			this->colDescripcion->Width = 350;
			// 
			// colCosto
			// 
			this->colCosto->HeaderText = L"Costo";
			this->colCosto->Name = L"colCosto";
			// 
			// frmMantMantenimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1131, 619);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtUbicacion);
			this->Controls->Add(this->txtTipo);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Name = L"frmMantMantenimiento";
			this->Text = L"frmMantMantenimiento";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMantMantenimiento::frmMantMantenimiento_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmMantMantenimiento::frmMantMantenimiento_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMantMantenimiento_Load(System::Object^ sender, System::EventArgs^ e) {
		this->txtNombre->Text = this->objMaquina->getNombre();
		this->txtTipo->Text = this->objMaquina->getTipo();
		this->txtUbicacion->Text = this->objMaquina->getUbicacion();
		this->listaMantenimientos = this->mantenimientoController->buscarxMaquina(this->objMaquina->getIdMaquina());
		mostrarGrilla(listaMantenimientos);
	}


    /*METODOSPERSONALES*/
	public:	void mostrarGrilla(List<Mantenimiento^>^ listaMantenimientos)
	{
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaMantenimientos->Count; i++)
		{
			Mantenimiento^ mantenimiento = listaMantenimientos[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(mantenimiento->getIdMantenimiento());
			filaGrilla[1] = mantenimiento->getTipo();
			filaGrilla[2] = mantenimiento->getFecha();
			filaGrilla[3] = mantenimiento->getEstado();
			filaGrilla[4] = mantenimiento->getDescripcion();
			filaGrilla[5] = Convert::ToString(mantenimiento->getCosto());
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
		this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
	frmNuevoMantenimiento^ nuevoMantenimientoForm = gcnew frmNuevoMantenimiento(this->mantenimientoController, this->objMaquina);
	nuevoMantenimientoForm->ShowDialog(this);
	// Llamar al método para cargar la lista de Mantenimiento por Maquina nuevamente
	this->listaMantenimientos = this->mantenimientoController->buscarxMaquina(this->objMaquina->getIdMaquina());
	mostrarGrilla(listaMantenimientos);
}
private: System::Void frmMantMantenimiento_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	// Cerrar la conexión al controlador de Mantenimiento
	this->mantenimientoController->CloseMantenimiento();
}
};
}