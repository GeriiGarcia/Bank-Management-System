#include<iostream>

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

    void crearCuenta(); //esto en banco.h


private:
    string numCuenta;
    int numTarjeta;
    int saldo;
};

cuenta::cuenta()
{
    numCuenta = "";
    numTarjeta = 0;
    saldo = 0;
}
