#include "libreria_1.h"

void calcularDesglose(const int *monto, const int *denominaciones, int *cantidades, const int *tamano, int *faltante) {
    int restante = *monto;
    int i = 0;

    // Recorrido de denominaciones usando aritmetica de punteros explícita
    while (i < *tamano) {
        int denomActual = *(denominaciones + i);

        // Division entera para obtener cantidad de billetes/monedas
        *(cantidades + i) = restante / denomActual;

        restante = restante % denomActual;

        i = i + 1;
    }

    *faltante = restante;
}

bool compararCadenas(const char *cadena1, const char *cadena2) {
    int i = 0;

    // Recorrido simultáneo hasta encontrar el fin de alguna cadena
    while (*(cadena1 + i) != '\0' && *(cadena2 + i) != '\0') {
        if (*(cadena1 + i) != *(cadena2 + i)) {
            return false;
        }
        i = i + 1;
    }

    // Ambas cadenas deben finalizar en el mismo indice '\0'
    if (*(cadena1 + i) == '\0' && *(cadena2 + i) == '\0') {
        return true;
    }

    return false;
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