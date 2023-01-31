#include "banco.h"

void Menu()
{
    cout << "¿Qué quieres hacer?" << endl;
    cout << "1. Entrar en mi cuenta." << endl;
    cout << "2. Hacer una transferencia." << endl;
    cout << "3. Crear una cuenta." << endl; 
    cout << "4. Salir." << endl;  
}

void MenuCuenta()
{
    cout << "¿Qué quieres hacer?" << endl;
    cout << "1. Consultar saldo." << endl;
    cout << "2. Consultar PIN Tarjeta." << endl;
    cout << "3. Salir." << endl;  
}

int main()
{
    banco MiBanco;
    MiBanco.iniciarTodo();

    cout << "Hola, Bienvenido a tu banco de confianza." << endl;


    Menu();

    int opcion;
    cin >> opcion;


    while(opcion <=0 && opcion >=5)
    {
        cout << "Opción no válida" << endl;
        cin >> opcion;
    }

    while (opcion != 4)
    {
        string cuenta;

        switch (opcion)
        {
        case 1: //entrar en la cuenta
            cout << "Escribe el código de tu cuenta: ";
            cin >> cuenta;

            while(MiBanco.buscarCuenta(cuenta) == nullptr)
            {
                cout << "Código de cuenta no valido, vuelva a intentarlo o escriba x para salir" << endl;
                cout << "Escribe el código de tu cuenta: ";
                cin >> cuenta;

                if(cuenta == "x")
                    break;
            }
            
            //mostrar cuenta, otro menu para consultar saldo, consultar pin
            //si el numero secreto es correcto 
            //Que tenga 3 intentos para entrar
            if(cuenta != "x" && MiBanco.buscarCuenta(cuenta)->entrarCuenta())
            {
                int opcionCuenta = 0;
                while(opcionCuenta != 3)
                {
                    MenuCuenta();
                    cin >> opcionCuenta;
                    switch (opcionCuenta)
                    {
                    case 1:
                        cout << "Tu saldo es: " << MiBanco.buscarCuenta(cuenta)->getSaldo() << "€." << endl;
                        break;
                    case 2:
                        cout << "Tu numero de tarjeta es: " << MiBanco.buscarCuenta(cuenta)->getNumTarjeta() << "." << endl;
                        break;
                    case 3: 
                        cout << "Hasta Luego." << endl;
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                    }
                }
                    
            }
            break;

        case 2: //entrar en la cuenta y pedir a q cuenta hacer la transeferencia, si esta en mi banco sumar y restar a las 2, si no esta en mi banco restar a la que hace la transferencia
            break;

        case 3:
            cout << "Perfecto, vamos a crear la cuenta." << endl;
            cout << "¿Quiere tarjeta de credito asociada a la cuenta?" << endl << "Si/No" << endl;
            bool tarjeta;

            cin >> cuenta;
            if(cuenta == "Si" || cuenta == "si" || cuenta == "SI")
                tarjeta = true;
            else if(cuenta == "No" || cuenta == "no" || cuenta == "NO")
                tarjeta = false;

            MiBanco.crearCuenta(tarjeta);
            break;


        default:
            break;
        }

        Menu();

        cin >> opcion;

        while(opcion <=0 && opcion >=5)
        {
            cout << "Opción no válida" << endl;
            cin >> opcion;
        }
    }

    MiBanco.guardarTodo();

    return 0;
}