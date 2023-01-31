#include "cuenta.h"


Cuenta::Cuenta()
{
    numCuenta = "";
    numTarjeta = 0;
    saldo = 0.0;
    numSecreto = 0000;
    movimientos.resize(1, 0.0);
}

Cuenta::~Cuenta()
{
    
}

bool Cuenta::retirar(float retiro)
{
    bool retirado = false;
    if(saldo - retiro >= 0)
    {
        retirado = true;
        saldo -= retiro;
        movimientos.push_back(-retiro);
    }
    else
        cout << "No tienes saldo suficiente." << endl;

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

bool Cuenta::entrarCuenta()
{
    cout << "Introduce tu numero secreto de tu cuenta" << endl;
    int pin, vegades = 0;
    bool correcte = false;

    while(!correcte && vegades < 3)
    {
        cin >> pin;

        if(pin == this->getNumSecreto())
        {
            correcte = true;
            return true;
        }
        else if(3-vegades != 1)
        {
            cout << "Te quedan: " << 3-vegades << " intentos." << endl;
        }
        vegades++;
        
    }
    cout << "Lo siento, no le quedan intentos." << endl;
    return false;
    

}

void Cuenta::mostrarMovimientos() const
{
    cout << "Movimientos: ";

    for(auto a : movimientos)
    {
        if(a != 0.0)
        {
            if(a > 0)
                cout << "+" << a << " ";
            else
                cout << a << " ";
        }
            
    }
    cout << endl;
}