# Bank-Management-System
Bank Management System in C++

Lo primero que se vera será un menú 
Que diga si quieres operar con tarjeta 
O sin tarjeta.

Si quieres operar con tarjeta: deberás inteoducir
El numero de la tarjeta y el código secreto de 4 digitos.
Luego podrás introducir o sacar dinero, consultar el saldo de la cuenta
Y también podria consultar los movimientos de la cuenta
Puedes pagar un recibo 



Si quieres operar sin tarjeta: puedes introducir 
Dinero en una cuenta ( comprovar si la cuenta es real)


-----------------------------------------------------------------------------------------
Necesito:

class cuenta:
tendra un string para el numero de cuenta (que sera el nombre del .txt de los datos de la cuenta)

-creara el archivo para guardar los datos de la cuenta
-mirará los datos de la cuenta



class banco:
el banco tendra un array de cuentas

-comprovara que los numeros de cuenta sean validos
-metodo banco.cuenta(numCuenta).consultarSaldo()
-buscara si hay un numero de cuenta, si no, se crea despues de comprovar si es valido
-creara un numero de tarjeta para la cuenta
-metodo buscarCuenta(numCuenta) que devuelva un puntero a la cuenta


Al finalizar el programa imprimir todos los datos en sus correspondientes fixeros