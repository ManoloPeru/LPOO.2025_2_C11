#pragma once
#include "Maquina.h"

namespace SGELProdAutomModel {
    using namespace System;

    public ref class Mantenimiento {
    private:
        int idMantenimiento;
        Maquina^ maquina; /*Se da por la asociacion*/
        String^ tipo;
        String^ fecha;
        String^ estado;
        String^ descripcion;
        Decimal costo;

    public:
        Mantenimiento();
        Mantenimiento(int idMantenimiento, Maquina^ maquina, String^ tipo, String^ fecha, String^ estado, String^ descripcion, Decimal costo);

        int getIdMantenimiento();
        void setIdMantenimiento(int id);

        Maquina^ getMaquina();
        void setMaquina(Maquina^ maquina);

        String^ getTipo();
        void setTipo(String^ tipo);

        String^ getFecha();
        void setFecha(String^ fecha);

        String^ getEstado();
        void setEstado(String^ estado);

        String^ getDescripcion();
        void setDescripcion(String^ descripcion);

		Decimal getCosto();
		void setCosto(Decimal costo);

        String^ ToString() override;
    };
}