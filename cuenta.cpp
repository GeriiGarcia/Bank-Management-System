#include "cuenta.h"


cuenta::cuenta()
{
    numCuenta = "";
    numTarjeta = 0;
    saldo = 0;
}

cuenta::~cuenta()
{
    
}

bool cuenta::retirar(int retiro)
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