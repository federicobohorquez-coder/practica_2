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
//problema 6
void convertirAMayusculas(const char *origen, char *destino) {
    int i = 0;
    while (*(origen + i) != '\0') {
        char caracter = *(origen + i);

        // Si el caracter esta en el rango minúsculo ('a' - 'z')
        if (caracter >= 'a' && caracter <= 'z') {
            *(destino + i) = caracter - ('a' - 'A');
        } else {
            *(destino + i) = caracter;
        }

        i = i + 1;
    }
    // Agregar el caracter nulo de fin de cadena
    *(destino + i) = '\0';
}
//problema 8
void separarTextoYNumeros(const char *origen, char *texto, char *numeros) {
    int i = 0;
    int j = 0; // Apuntador/Indice para la cadena de texto
    int k = 0; // Apuntador/Indice para la cadena de numeros

    while (*(origen + i) != '\0') {
        char caracter = *(origen + i);

        // Si el caracter es un digito ASCII entre '0' y '9'
        if (caracter >= '0' && caracter <= '9') {
            *(numeros + k) = caracter;
            k = k + 1;
        } else {
            *(texto + j) = caracter;
            j = j + 1;
        }

        i = i + 1;
    }

    // Cierre explicito de ambas cadenas en memoria RAM
    *(texto + j) = '\0';
    *(numeros + k) = '\0';
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