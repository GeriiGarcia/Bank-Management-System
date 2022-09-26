#include "banco.h"

void banco::crearCuenta(bool tarjeta)
{
    Cuenta nueva;
    int n;
    nueva.setNumCuenta(nueva.generarNumCuenta());

    cout << "Introduzca el numero secreto que desee: " << endl;
    cin >> n;
    nueva.setNumSecreto(n);

    if(tarjeta)
        nueva.setNumTarjeta(nueva.generarNumTarjeta());    
    
    m_cuentas->resize(m_cuentas->size() + 1);
    m_cuentas->push_back(nueva);
}

bool banco::comprovarNumeroCuenta(string num)
{
    bool trobat = false;

    for (int i = 0; i < m_cuentas->size(); i++)
    {
        if(m_cuentas->at(i).getNumCuenta() == num)
            trobat = true;
    }

    return trobat;
}

Cuenta* banco::buscarCuenta(string num)
{
    Cuenta *pt = nullptr;

    for (int i = 0; i < m_cuentas->size(); ++i)
    {
        if(m_cuentas->at(i).getNumCuenta() == num)
            return &m_cuentas->at(i);
            
    }

    return pt;
}

void banco::eliminarCuenta(string num)
{
    vector<Cuenta>::iterator it = m_cuentas->begin();

    for (num = num; it < m_cuentas->end(); ++it)
    {
        if(it->getNumCuenta() == num)
            m_cuentas->erase(it);
            
    }
}

void banco::iniciarTodo()
{
    ifstream fitxer("datos.txt");
    fitxer.open("datos.txt");

    int primer, contador = 0;

    //variables del vector
    string nC;
    int nT;
    float sal;
    int nS;   

    fitxer.open("datos.txt");


    if(fitxer.is_open())
    {
        fitxer >> primer;

        if(primer == 0)
        {
            ofstream uno("datos.txt");
            uno.open("datos.txt");

            if(uno.is_open())
            {
                uno << "1";
            }
        }
        else
        {
            while (!fitxer.eof())
            {
                contador = 0;
                
                fitxer >> nC;
                fitxer >> nT;
                fitxer >> sal;
                fitxer >> nS;
                contador++;
                
                Cuenta aux(nC,nT,sal,nS);

                m_cuentas->push_back(aux);
                
            }
            
        }

        fitxer.close();
    }
    else
        throw runtime_error("Fitxer no obert");


}

void banco::guardarTodo()
{

}