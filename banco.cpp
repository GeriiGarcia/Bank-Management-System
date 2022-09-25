#include "banco.h"

void banco::crearCuenta(bool tarjeta)
{
    Cuenta nueva;
    nueva.setNumCuenta(nueva.generarNumCuenta());
    if(tarjeta)
    {
        
    }
    m_cuentas->resize(m_cuentas->capacity() + 1);
    m_cuentas->push_back(nueva);
}

bool banco::comprovarNumeroCuenta(string num)
{

    return false;
}

void banco::crearNumeroTarjeta(string num)
{

}

Cuenta* banco::buscarCuenta(string num)
{
    Cuenta hola;

    Cuenta *pt = &hola;



    return pt;
}

void banco::eliminarCuenta()
{

}