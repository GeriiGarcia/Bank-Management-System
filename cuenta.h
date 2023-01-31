#pragma once
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include<string>
#include <string.h>

using namespace std;



class Cuenta
{
public:
    Cuenta();
    Cuenta(string nC, int nT, float sal, int nS, vector<float> m) {numCuenta=nC; numTarjeta=nT; saldo = sal; numSecreto = nS; movimientos = m;}
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
    void ingresar(float ingresar) {saldo += ingresar; movimientos.push_back(ingresar);}
    bool retirar(float retiro);
    string generarNumCuenta();
    int generarNumTarjeta();

    friend ofstream& operator<< (ofstream& out, Cuenta const& cu) {out << cu.numCuenta << endl; out << cu.numTarjeta << endl; out << cu.saldo << endl; out << cu.numSecreto <<endl; 
                                                                    for(auto a : cu.movimientos){out << a << " ";} out << endl; return out;}
    bool entrarCuenta();
    void mostrarMovimientos() const;

private:
    string numCuenta; //los numeros de cuenta tienen 4 digitos
    int numTarjeta; //los numeros de tarjeta tienen 3 digitos //si no tiene tarjeta sera 0
    float saldo;
    int numSecreto;   
    vector<float> movimientos;
};



