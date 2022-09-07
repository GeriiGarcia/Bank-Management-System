#include "cuenta.h"

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