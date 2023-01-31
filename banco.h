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

    void transferencia(string c1, string c2, float dinero);

private:
    vector<Cuenta> m_cuentas;

};


