#include <iostream>
#include "libreria_1.h"

using namespace std;

int main() {
    int opcion = -1;

    while (opcion != 0) {
        cout << "1. Problema 1" << endl;
        cout <<"2. problema 3" << endl;
        cout <<"3. problema 5" << endl;
        cout <<"4. problema 7" << endl;
        cout <<"5. problema 9" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int monto = 0;
            const int tamano = 10;

            // Arreglo de denominaciones fijas
            int denominaciones[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
            int cantidades[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int faltante = 0;

            cout << "\nIngrese la cantidad de dinero: ";
            cin >> monto;

            // Paso por direccion de memoria (&)
            calcularDesglose(&monto, denominaciones, cantidades, &tamano, &faltante);

            int i = 0;
            while (i < tamano) {
                cout << *(denominaciones + i) << " : " << *(cantidades + i) << endl;
                i = i + 1;
            }
            cout << "Faltante: " << faltante << endl;
            break;
        }
        case 2: {
            const int MAX_TAM = 100;
            char cadena1[MAX_TAM];
            char cadena2[MAX_TAM];

            cout << "\nIngrese la primera cadena: ";
            cin >> cadena1;
            cout << "Ingrese la segunda cadena: ";
            cin >> cadena2;

            // Se pasa la direccion base del arreglo como puntero
            if (compararCadenas(cadena1, cadena2)) {
                cout << "Resultado: Las cadenas son IGUALES." << endl;
            } else {
                cout << "Resultado: Las cadenas son DIFERENTES." << endl;
            }
            break;

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