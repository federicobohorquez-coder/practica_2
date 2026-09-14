#include <iostream>
#include "libreria_1.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int opcion = -1;

    while (opcion != 0) {
        cout << "1. Problema 2" << endl;
        cout <<"2. problema 3" << endl;
        cout <<"3. problema 5" << endl;
        cout <<"4. problema 7" << endl;
        cout <<"5. problema 9" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:{
            srand(time(0));

            const int TAMANO = 200;
            char arreglo[TAMANO];

            generarArreglo(arreglo, &TAMANO);

            cout << "Arreglo generado:" << endl;
            imprimirArreglo(arreglo, &TAMANO);

            cout << "Frecuencias de aparicion:" << endl;
            contarFrecuencias(arreglo, &TAMANO);
        }
        case 2: {
            char cadena[100];

            cout << "Ingrese una cadena de caracteres numericos: ";
            cin >> cadena;

            int numero = cadenaAEntero(cadena);

            cout << "El numero entero convertido es: " << numero << endl;


        }
        case 3:{
            int numero = 0;
            const int MAX_TAM = 50;
            char resultado[MAX_TAM];

            cout << "\nIngrese un numero entero: ";
            cin >> numero;

            // Se pasa la dirección de 'numero' y la dirección base del arreglo 'resultado'
            enteroACadena(&numero, resultado);

            cout << "Cadena resultante: \"" << resultado << "\"" << endl;
            break;
        }


        case 4:{
            const int MAX_TAM = 100;
            char original[MAX_TAM];
            char sinRepetidos[MAX_TAM];

            cout << "Ingrese una cadena de caracteres: ";
            cin >> original;

            eliminarRepetidos(original, sinRepetidos);

            cout << "Original: " << original << ". Sin repetidos: " << sinRepetidos << endl;
            break;
        }
        case 5:{
            int n = 0;
            const int MAX_TAM = 100;
            char original[MAX_TAM];
            int sumaResultante = 0;

            cout << "\nIngrese la cifra n: ";
            cin >> n;
            cout << "Ingrese la cadena de caracteres numericos: ";
            cin >> original;

            sumarBloques(original, &n, &sumaResultante);

            cout << "Original: " << original << "." << endl;
            cout << "Suma: " << sumaResultante << "." << endl;
            break;


        }
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
        }
    }

    return 0;
}