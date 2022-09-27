#include "banco.h"

void Menu()
{
    cout << "¿Qué quieres hacer?" << endl;
    cout << "1. Entrar en mi cuenta." << endl;
    cout << "2. Hacer una transferencia." << endl;
    cout << "3. Crear una cuenta." << endl; 
    cout << "4. Salir." << endl;  
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


            break;

        case 2:
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

        int opcion;
        cin >> opcion;

        while(opcion <=0 && opcion >=5)
        {
            cout << "Opción no válida" << endl;
            cin >> opcion;
        }
    }

    return 0;
}