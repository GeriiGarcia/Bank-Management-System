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
    
    //m_cuentas->resize(m_cuentas->size() + 1);
    m_cuentas.push_back(nueva);

    cout << "Cuenta creada con éxito." << endl << "Los datos de su cuenta son: " << endl;
    cout << "Numero de cuenta: " << nueva.getNumCuenta() << "." << endl; 
    cout << "Numero secreto: " << nueva.getNumSecreto() << "."<< endl; 
    if(tarjeta)
        cout << "Numero de tarjeta: " << nueva.generarNumTarjeta() << "." << endl; 
    cout << "Saldo: " << nueva.getSaldo() << "."<< endl; 
    
}

bool banco::comprovarNumeroCuenta(string num)
{
    bool trobat = false;

    for (int i = 0; i < m_cuentas.size(); i++)
    {
        if(m_cuentas.at(i).getNumCuenta() == num)
            trobat = true;
    }

    return trobat;
}

Cuenta* banco::buscarCuenta(string num)
{
    Cuenta *pt = nullptr;

    for (int i = 0; i < m_cuentas.size(); ++i)
    {
        if(m_cuentas.at(i).getNumCuenta() == num)
            return &m_cuentas.at(i);
            
    }

    return pt;
}

void banco::eliminarCuenta(string num)
{
    vector<Cuenta>::iterator it = m_cuentas.begin();

    for (num = num; it < m_cuentas.end(); ++it)
    {
        if(it->getNumCuenta() == num)
            m_cuentas.erase(it);
            
    }
}

void banco::iniciarTodo()
{

    ifstream file("datos.txt");
	string  str;
    vector<string> linias;
    
    while(getline(file, str))
        linias.push_back(str);

    if(!linias.empty())
    {
        for(int i = 0; i < linias.size()-1; i += 4)
        {
            //variables del vector
            string nC = linias[i];
            int nT = stoi(linias[i+1]);
            float sal = stof(linias[i+2]);
            int nS = stoi(linias[i+3]);

            Cuenta aux(nC,nT,sal,nS);
            m_cuentas.push_back(aux);
        }
    }


}

void banco::guardarTodo()
{
    ofstream fitxer("datos.txt");
    fitxer.open("datos.txt");
    int i = 0;

    if(fitxer.is_open())
    {
        fitxer.clear();

        for (i = 0; i < m_cuentas.size(); ++i)
        {
            fitxer << m_cuentas.at(i);
        }

        fitxer.close();
    }
    else
        throw runtime_error("Fitxer no obert per guardad");


}
