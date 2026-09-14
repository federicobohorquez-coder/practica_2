#include <iostream>
#include "libreria_1.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int opcion = -1;

    while (opcion != 0) {
        cout << "1. Problema 2" << endl;
        cout <<"2. problema 4" << endl;
        cout <<"3. problema 6" << endl;
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
            break;
        }
        case 2: {
            char cadena[100];

            cout << "Ingrese una cadena de caracteres numericos: ";
            cin >> cadena;

            int numero = cadenaAEntero(cadena);

            cout << "El numero entero convertido es: " << numero << endl;
            break;


        }
        case 3:{
            char original[25];
            char mayuscula[25];

            cout << "\nIngrese la cadena de texto: ";
            cin >> original;

            convertirAMayusculas(original, mayuscula);

            cout << "Original: " << original << ". En mayuscula: " << mayuscula << "." << endl;
            break;
        }


        case 4:{
            char original[30];
            char texto[30];
            char numeros[30];

            cout << "\nIngrese la cadena de texto: ";
            cin >> original;

            separarTextoYNumeros(original, texto, numeros);

            cout << "Original: " << original << "." << endl;
            cout << "Texto: " << texto << ". Numero: " << numeros << "." << endl;
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