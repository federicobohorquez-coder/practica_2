#include "libreria_1.h"
#include <iostream>
#include <cstdlib>

using namespace std;
//problema 2
void generarArreglo(char *arreglo, const int *tamano) {
    int i = 0;
    while (i < *tamano) {
        *(arreglo + i) = 'A' + (rand() % 26);
        i = i + 1;
    }
}

void imprimirArreglo(const char *arreglo, const int *tamano) {
    int i = 0;
    while (i < *tamano) {
        cout << *(arreglo + i);
        i = i + 1;
    }
    cout << endl << endl;
}

void contarFrecuencias(const char *arreglo, const int *tamano) {
    int conteo[26];

    // Inicializar el arreglo de conteo en 0
    int c = 0;
    while (c < 26) {
        *(conteo + c) = 0;
        c = c + 1;
    }

    // Contar ocurrencias
    int i = 0;
    while (i < *tamano) {
        char letra = *(arreglo + i);
        int pos = letra - 'A';
        int actual = *(conteo + pos);
        *(conteo + pos) = actual + 1;
        i = i + 1;
    }

    // Imprimir frecuencias de letras presentes
    int k = 0;
    while (k < 26) {
        int cantidad = *(conteo + k);
        if (cantidad > 0) {
            char letra = 'A' + k;
            cout << letra << ": " << cantidad << endl;
        }
        k = k + 1;
    }
}
//prroblema 4
int cadenaAEntero(const char *cadena) {
    int resultado = 0;
    int i = 0;

    // Recorrer la cadena hasta encontrar el caracter nulo '\0'
    while (*(cadena + i) != '\0') {
        char caracter = *(cadena + i);

        // Convertir de codigo ASCII a digito numerico (ej: '3' - '0' = 3)
        int digito = caracter - '0';

        // Desplazar las cifras decimales a la izquierda
        resultado = resultado * 10 + digito;

        i = i + 1;
    }

    return resultado;
}

void enteroACadena(const int *numero, char *cadena) {
    int temp = *numero;
    int i = 0;
    bool esNegativo = false;

    if (temp < 0) {
        esNegativo = true;
        temp = temp * -1;
    }

    // Caso especial para el cero
    if (temp == 0) {
        *(cadena + 0) = '0';
        *(cadena + 1) = '\0';
        return;
    }

    // Extracción de dígitos en orden inverso
    while (temp > 0) {
        int digito = temp % 10;
        *(cadena + i) = digito + '0';
        temp = temp / 10;
        i = i + 1;
    }

    if (esNegativo) {
        *(cadena + i) = '-';
        i = i + 1;
    }

    *(cadena + i) = '\0'; // Terminador nulo de cadena

    // Inversion de la cadena para obtener el orden correcto
    int inicio = 0;
    int fin = i - 1;
    while (inicio < fin) {
        char aux = *(cadena + inicio);
        *(cadena + inicio) = *(cadena + fin);
        *(cadena + fin) = aux;
        inicio = inicio + 1;
        fin = fin - 1;
    }
}

void eliminarRepetidos(const char *cadenaOriginal, char *cadenaSinRepetidos) {
    int i = 0; //recorre la cadena original
    int j = 0; //escribir en la nueva cadena

    while (*(cadenaOriginal + i) != '\0') {
        char caracterActual = *(cadenaOriginal + i);
        bool yaExiste = false;

        // Verifica si el caracter ya fue guardado previamente en cadenaSinRepetidos
        int k = 0;
        while (k < j) {
            if (*(cadenaSinRepetidos + k) == caracterActual) {
                yaExiste = true;
            }
            k = k + 1;
        }

        // Si el caracter no ha sido registrado, se copia a la nueva posicion
        if (!yaExiste) {
            *(cadenaSinRepetidos + j) = caracterActual;
            j = j + 1;
        }

        i = i + 1;
    }

    *(cadenaSinRepetidos + j) = '\0'; // Terminador nulo de cadena
}

void sumarBloques(const char *cadena, const int *n, int *sumaTotal) {
    int tamano = 0;
    while (*(cadena + tamano) != '\0') {
        tamano = tamano + 1;
    }

    int tamBloque = *n;
    int residuo = tamano % tamBloque;
    int cerosFaltantes = 0;

    if (residuo != 0) {
        cerosFaltantes = tamBloque - residuo;
    }

    int suma = 0;
    int idx = 0;

    // Procesar el primer bloque (rellenando con ceros a la izquierda si aplica)
    int valorBloque = 0;
    int k = 0;
    while (k < cerosFaltantes) {
        valorBloque = valorBloque * 10;
        k = k + 1;
    }

    int digitosPrimerBloque = tamBloque - cerosFaltantes;
    k = 0;
    while (k < digitosPrimerBloque) {
        int digito = *(cadena + idx) - '0';
        valorBloque = valorBloque * 10 + digito;
        idx = idx + 1;
        k = k + 1;
    }
    suma = suma + valorBloque;

    // Procesar los bloques restantes completos de tamBloque cifras
    while (idx < tamano) {
        valorBloque = 0;
        k = 0;
        while (k < tamBloque) {
            int digito = *(cadena + idx) - '0';
            valorBloque = valorBloque * 10 + digito;
            idx = idx + 1;
            k = k + 1;
        }
        suma = suma + valorBloque;
    }

    *sumaTotal = suma;
}