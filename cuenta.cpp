#include "cuenta.h"


Cuenta::Cuenta()
{
    numCuenta = "";
    numTarjeta = 0;
    saldo = 0;
    numSecreto = 0000;
}

Cuenta::~Cuenta()
{
    
}

bool Cuenta::retirar(int retiro)
{
    bool retirado = false;
    if(saldo - retiro >= 0)
    {
        retirado = true;
        saldo -= retiro;
    }
    else
        cout << "No tienes saldo suficiente" << endl;

    return retirado;
}

string Cuenta::generarNumCuenta()
{
    string numero = "ES";
    int n;
    string aux;

    srand(time(NULL));

    n=1000+rand()%(10000-1000);

    aux = to_string(n);
    numero += aux;

    return numero;
}

int Cuenta::generarNumTarjeta()
{
    srand(time(NULL));

    return 100+rand()%(1000-100);
}