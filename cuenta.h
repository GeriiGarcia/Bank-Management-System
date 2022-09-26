#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include <fstream>

using namespace std;

class Cuenta
{
public:
    Cuenta();
    Cuenta(string nC, int nT, float sal, int nS) {numCuenta=nC; numTarjeta=nT; saldo = sal; numSecreto = nS;}
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

    friend ofstream& operator<< (ofstream& out, Cuenta const& cu) {out << cu.numCuenta << endl; out << cu.numTarjeta << endl; out << cu.saldo << endl; out << cu.numSecreto <<endl; }

private:
    string numCuenta; //los numeros de cuenta tienen 4 digitos
    int numTarjeta; //los numeros de tarjeta tienen 3 digitos //si no tiene tarjeta sera 0
    float saldo;
    int numSecreto;   
};



