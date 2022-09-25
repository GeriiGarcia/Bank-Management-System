#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Cuenta
{
public:
    Cuenta();
    ~Cuenta();

    //setters
    void setNumCuenta(string num) {numCuenta = num;}
    void setNumTarjeta(int num) {numTarjeta = num;}
    void setNumSecreto(int num) {numSecreto = num;}

    //getters
    float getSaldo() {return saldo;}
    int getNumTarjeta() {return numTarjeta;}
    string getNumCuenta() {return numCuenta;}
    int getNumSecreto() {return numSecreto;}

    //metodos
    void ingresar(int ingresar) {saldo += ingresar;}
    bool retirar(int retiro);
    string generarNumCuenta();
    int generarNumTarjeta();

private:
    string numCuenta; //los numeros de cuenta tienen 4 digitos
    int numTarjeta; //los numeros de tarjeta tienen 3 digitos
    float saldo;
    int numSecreto;
};



