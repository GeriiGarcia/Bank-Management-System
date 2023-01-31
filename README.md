# Bank-Management-System in C++

## ¿Cómo funciona?

En el main tenemos los menus con las opciones que podemos hacer dentro de nuestro banco.
Lo primero que nos saldrá al ejecutar el programa será un menú con 3 opciones.

Todos los datos se guardaran en el fichero datos.txt cuando se le de a la opción Salir.
Al abrir el programa se inicializará el banco con los datos que haya en datos.txt.

Cada cuenta tiene su numero de cuenta, su numero secreto para entrar a la cuenta, su lista de movimientos y una tarjeta opcional con su número y su PIN.

## ¿Cómo ejectuar?

Descargar el proyecto utilizando:

```

git clone https://github.com/GeriiGarcia/Bank-Management-System.git
cd Bank-Management-System
```

Compilar y ejecutar el proyecto desde la terminal utilizando:

`clear && g++ -o main main.cpp banco.cpp cuenta.cpp && ./main`

