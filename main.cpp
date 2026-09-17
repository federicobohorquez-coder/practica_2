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
        cout <<"4. problema 8" << endl;
        cout <<"5. problema 10" << endl;
        cout <<"6. problema 12" << endl;
        cout <<"7. problema 14" << endl;
        cout <<"8. problema 16" << endl;
        cout <<"9. problema 18" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:{
            unsigned int semilla = 0;
            cout << "\nIngrese un numero entero (semilla) para generar las letras: ";
            cin >> semilla;

            int tamano = 200;
            char arreglo[200];

            generarArregloAleatorio(arreglo, tamano, &semilla);

            cout << "\nArreglo generado de " << tamano << " letras:\n";
            imprimirArreglo(arreglo, tamano);

            cout << "\nFrecuencia de cada letra:\n";
            contarFrecuenciaLetras(arreglo, tamano);
            break;
        }
        case 2: {
            char cadena[25];

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
            char romano[25];

            cout << "\nIngrese un numero en sistema romano: ";
            cin >> romano;

            int arabigo = romanoAArabigo(romano);

            cout << "El numero ingresado fue: " << romano << endl;
            cout << "Que corresponde a: " << arabigo << "." << endl;
            break;
        }
        case 6:{
            int n = 0;
            cout << "\nIngrese la dimension n de la matriz (maximo 5): ";
            cin >> n;

            if (n <= 0) {
                cout << "La dimension debe ser mayor que 0." << endl;
                break;
            }

            // Arreglo contiguo de tamaño n*n mapeado linealmente en memoria
            int matriz[25];

            cout << "Ingrese los elementos de la matriz:" << endl;
            leerMatriz(matriz, n);

            cout << "\nMatriz ingresada:" << endl;
            imprimirMatriz(matriz, n);

            if (esCuadradoMagico(matriz, n)) {
                cout << "\nLa matriz ES un cuadrado magico." << endl;
            } else {
                cout << "\nLa matriz NO es un cuadrado magico." << endl;
            }
            break;
        }
        case 7:{
            int original[25];
            int rotada[25];

            llenarMatriz5x5(original);

            cout << "\nMatriz Original:" << endl;
            imprimirMatriz5x5(original);

            rotar90(original, rotada);
            cout << "Matriz Rotada 90 grados:" << endl;
            imprimirMatriz5x5(rotada);

            rotar180(original, rotada);
            cout << "Matriz Rotada 180 grados:" << endl;
            imprimirMatriz5x5(rotada);

            rotar270(original, rotada);
            cout << "Matriz Rotada 270 grados:" << endl;
            imprimirMatriz5x5(rotada);

            break;
        }

        case 8:{
            int n = 0;
            cout << "\nIngrese la dimension n de la malla (nxn): ";
            cin >> n;

            if (n <= 0) {
                cout << "La dimension debe ser mayor que 0." << endl;
                break;
            }

            long long caminos = contarCaminos(&n);

            cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
            break;
        }
        case 9:{

            long long n = 0;
            cout << "\nIngrese un numero n: ";
            cin >> n;

            // 10! = 3,628,800 permutaciones posibles
            if (n <= 0 || n > 3628800) {
                cout << "El numero n debe estar entre 1 y 3628800." << endl;
                break;
            }

            char resultado[11];
            obtenerPermutacionLexicografica(n, resultado);

            cout << "La permutacion numero " << n << " es: " << resultado << "." << endl;
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