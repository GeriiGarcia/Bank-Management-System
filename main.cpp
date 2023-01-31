#include "banco.h"

void Menu()
{
    cout << "¿Qué quieres hacer?" << endl;
    cout << "1. Entrar en mi cuenta." << endl;
    cout << "2. Crear una cuenta." << endl; 
    cout << "3. Salir." << endl;  
}

void MenuCuenta()
{
    cout << "¿Qué quieres hacer?" << endl;
    cout << "1. Consultar saldo." << endl;
    cout << "2. Consultar PIN Tarjeta." << endl;
    cout << "3. Ingresar dinero." << endl;
    cout << "4. Retirar dinero." << endl;
    cout << "5. Transferencia bancaria." << endl;
    cout << "6. Mostrar movimientos." << endl;
    cout << "7. Salir." << endl;  
}

int main()
{
    banco MiBanco;
    MiBanco.iniciarTodo();

    cout << "Hola, Bienvenido a tu banco de confianza." << endl;


    Menu();

    int opcion;
    cin >> opcion;

    while(opcion <=0 || opcion >=4)
    {
        cout << "Opción no válida" << endl;
        Menu();
        cin >> opcion;
    }

    while (opcion != 3)
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
                float dinero = -1.0;
                int opcionCuenta = 0;
                string cuentaBeneficiaria;

                while(opcionCuenta != 7)
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
                    case 7: 
                        cout << "Hasta Luego." << endl;
                        break;

                    case 3:
                        
                        cout << "Escribe cuanto dinero quieres ingresar: ";
                        cin >> dinero;
                        while(dinero < 0)
                        {
                            cout << "No puedes ingresar dinero negativo, intentelo de nuevo." << endl;
                            cout << "Escribe cuanto dinero quieres ingresar: "; 
                            cin >> dinero;
                        }

                        MiBanco.buscarCuenta(cuenta)->ingresar(dinero);
                        cout << "Ingresado con exito. Ahora su saldo es de: " << MiBanco.buscarCuenta(cuenta)->getSaldo() << "€." << endl;
                        break;

                    case 4: //retirar
                        
                        cout << "Escribe cuanto dinero quieres retirar: ";
                        cin >> dinero;
                        while(dinero < 0)
                        {
                            cout << "No puedes retirar dinero negativo, intentelo de nuevo." << endl;
                            cout << "Escribe cuanto dinero quieres retirar: "; 
                            cin >> dinero;
                        }

                        if(MiBanco.buscarCuenta(cuenta)->retirar(dinero))
                        {
                            cout << "Retirado con exito." << endl;
                        }
         
                        break;

                    case 5:
                        cout << "Introduce el numero de cuenta al que quieres hacer la transferencia: ";
                        cin>>cuentaBeneficiaria;
                        cout << "Introduce la cantidad de dinero que quieres transferir: ";
                        cin >> dinero;


                        MiBanco.transferencia(cuenta,cuentaBeneficiaria, dinero);
                        break;

                    case 6:
                        MiBanco.buscarCuenta(cuenta)->mostrarMovimientos();
                        break;
                    
                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                    }
                }
                    
            }
            break;

        //entrar en la cuenta y pedir a q cuenta hacer la transeferencia, si esta en mi banco sumar y restar a las 2, si no esta en mi banco restar a la que hace la transferencia
       

        case 2:
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

        while(opcion <=0 || opcion >=5)
        {
            cout << "Opción no válida" << endl;
            cin >> opcion;
        }
    }

    MiBanco.guardarTodo();

    return 0;
}