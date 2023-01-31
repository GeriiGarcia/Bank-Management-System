#pragma once
#include "cuenta.h"

class banco
{
public:
    banco() {m_cuentas.resize(0);}
    ~banco() {}

    void crearCuenta(bool tarjeta);
    bool comprovarNumeroCuenta(string num);
    Cuenta *buscarCuenta(string num);
    void eliminarCuenta(string num);

    void iniciarTodo();
    void guardarTodo();

private:
    vector<Cuenta> m_cuentas;

};


