#include "banco.h"

vector<float> strTOvint(const string s)
{
    vector<float> nums;
    vector<string> numsS;
    
    char buffer[50];
    strcpy(buffer,s.c_str());
    
    char *ptr;
    ptr = strtok(buffer, " ");
    
    while (ptr != NULL)  
    {  
        //cout << ptr  << endl; 
        numsS.push_back(ptr);
        ptr = strtok(NULL, " ");  
    }
    
    //pasamos de numsS a nums
    
    for(int i = 0; i < numsS.size(); i++)
    {
        nums.push_back(stof(numsS[i]));
    }
    
    return nums;
}

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
        for(int i = 0; i < linias.size()-1; i += 5)
        {
            //variables del vector
            string nC = linias[i];
            int nT = stoi(linias[i+1]);
            float sal = stof(linias[i+2]);
            int nS = stoi(linias[i+3]);
            vector<float> m = strTOvint(linias[i+4]);

            Cuenta aux(nC,nT,sal,nS,m);
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


void banco::transferencia(string c1, string c2, float dinero)
{
    //tengo que ver si el que da tiene suficiente dinero
    //Tengo que ver si el que recibe esta en el banco
    //Si esta en el banco restar y sumar a quien convenga, si no, solo restar a quien da

    Cuenta *C1 = buscarCuenta(c1);
    Cuenta *C2 = buscarCuenta(c2);

    if(C1->getSaldo() >= dinero)
    {
        if(C2 == nullptr)
        {
            C1->retirar(dinero);
        }
        else
        {
            C1->retirar(dinero);
            C2->ingresar(dinero);
        }
        cout << "Transferencia relaizada con exito." << endl;
    }
    else
    {
        cout << "Lo siento. No tienes saldo suficiente." << endl;
    }
}