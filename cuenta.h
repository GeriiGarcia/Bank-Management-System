#include<iostream>
#include<vector>

using namespace std;

class cuenta
{
public:
    cuenta();
    ~cuenta();

    void setNumCuenta(string num) {numCuenta = num;}
    void setNumTarjeta(int num) {numTarjeta = num;}

    int getSaldo() {return saldo;}
    int getNumTarjeta() {return numTarjeta;}
    string getNumCuenta() {return numCuenta;}

    void ingresar(int ingresar) {saldo += ingresar;}
    bool retirar(int retiro);


private:
    string numCuenta;
    int numTarjeta;
    int saldo;
};



