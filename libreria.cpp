#include "libreria_1.h"
#include <iostream>
#include <cstdlib>

using namespace std;
//problema 2
// Algoritmo LCG para sustituir rand()
int generarNumeroAleatorio(unsigned int *semilla) {
    *semilla = (*semilla * 1103515245 + 12345) % 2147483648;
    int residuo = *semilla % 26;
    if (residuo < 0) {
        residuo = residuo * -1;
    }
    return residuo;
}

void generarArregloAleatorio(char *arreglo, int tamano, unsigned int *semilla) {
    int i = 0;
    while (i < tamano) {
        int aleatorio = generarNumeroAleatorio(semilla);
        *(arreglo + i) = 'A' + aleatorio;
        i = i + 1;
    }
}

void imprimirArreglo(const char *arreglo, int tamano) {
    int i = 0;
    while (i < tamano) {
        cout << *(arreglo + i);
        i = i + 1;
    }
    cout << endl;
}

void contarFrecuenciaLetras(const char *arreglo, int tamano) {
    int conteo[26];
    int i = 0;

    // Inicializar frecuencias en 0
    while (i < 26) {
        *(conteo + i) = 0;
        i = i + 1;
    }

    // Contar apariciones mediante punteros
    i = 0;
    while (i < tamano) {
        char letra = *(arreglo + i);
        int indice = letra - 'A';
        *(conteo + indice) = *(conteo + indice) + 1;
        i = i + 1;
    }

    // Imprimir frecuencias existentes
    i = 0;
    while (i < 26) {
        if (*(conteo + i) > 0) {
            char letra = 'A' + i;
            cout << letra << ": " << *(conteo + i) << endl;
        }
        i = i + 1;
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

int valorRomano(char c) {
    int valor = 0;
    if (c == 'M' || c == 'm') valor = 1000;
    if (c == 'D' || c == 'd') valor = 500;
    if (c == 'C' || c == 'c') valor = 100;
    if (c == 'L' || c == 'l') valor = 50;
    if (c == 'X' || c == 'x') valor = 10;
    if (c == 'V' || c == 'v') valor = 5;
    if (c == 'I' || c == 'i') valor = 1;
    return valor;
}

int romanoAArabigo(const char *romano) {
    int total = 0;
    int i = 0;

    while (*(romano + i) != '\0') {
        int actual = valorRomano(*(romano + i));
        int siguiente = valorRomano(*(romano + i + 1));

        // Regla: si el caracter actual es menor al siguiente, se resta
        if (actual < siguiente) {
            total = total - actual;
        } else {
            total = total + actual;
        }

        i = i + 1;
    }

    return total;
}

void leerMatriz(int *matriz, int n) {
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            cout << "Ingrese elemento [" << i << "][" << j << "]: ";
            cin >> *(matriz + i * n + j);
            j = j + 1;
        }
        i = i + 1;
    }
}

void imprimirMatriz(const int *matriz, int n) {
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            cout << *(matriz + i * n + j) << "\t";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}

bool esCuadradoMagico(const int *matriz, int n) {
    // 1. Validar que no haya números repetidos
    int total = n * n;
    int i = 0;
    while (i < total) {
        int j = i + 1;
        while (j < total) {
            if (*(matriz + i) == *(matriz + j)) {
                return false;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // 2. Suma de referencia (primera fila)
    int sumaObjetivo = 0;
    int col = 0;
    while (col < n) {
        sumaObjetivo = sumaObjetivo + *(matriz + 0 * n + col);
        col = col + 1;
    }

    // 3. Comprobar restates filas
    int fila = 1;
    while (fila < n) {
        int sumaFila = 0;
        int c = 0;
        while (c < n) {
            sumaFila = sumaFila + *(matriz + fila * n + c);
            c = c + 1;
        }
        if (sumaFila != sumaObjetivo) {
            return false;
        }
        fila = fila + 1;
    }

    // 4. Comprobar columnas
    int c = 0;
    while (c < n) {
        int sumaCol = 0;
        int f = 0;
        while (f < n) {
            sumaCol = sumaCol + *(matriz + f * n + c);
            f = f + 1;
        }
        if (sumaCol != sumaObjetivo) {
            return false;
        }
        c = c + 1;
    }

    // 5. Diagonal principal
    int sumaDiag1 = 0;
    int d1 = 0;
    while (d1 < n) {
        sumaDiag1 = sumaDiag1 + *(matriz + d1 * n + d1);
        d1 = d1 + 1;
    }
    if (sumaDiag1 != sumaObjetivo) {
        return false;
    }

    // 6. Diagonal secundaria
    int sumaDiag2 = 0;
    int d2 = 0;
    while (d2 < n) {
        sumaDiag2 = sumaDiag2 + *(matriz + d2 * n + (n - 1 - d2));
        d2 = d2 + 1;
    }
    if (sumaDiag2 != sumaObjetivo) {
        return false;
    }

    return true;
}

void llenarMatriz5x5(int *matriz) {
    int valor = 1;
    int i = 0;
    while (i < 5) {
        int j = 0;
        while (j < 5) {
            *(matriz + i * 5 + j) = valor;
            valor = valor + 1;
            j = j + 1;
        }
        i = i + 1;
    }
}

void imprimirMatriz5x5(const int *matriz) {
    int i = 0;
    while (i < 5) {
        int j = 0;
        while (j < 5) {
            cout << *(matriz + i * 5 + j) << "\t";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    cout << endl;
}

void rotar90(const int *origen, int *destino) {
    int i = 0;
    while (i < 5) {
        int j = 0;
        while (j < 5) {
            *(destino + i * 5 + j) = *(origen + (4 - j) * 5 + i);
            j = j + 1;
        }
        i = i + 1;
    }
}

void rotar180(const int *origen, int *destino) {
    int i = 0;
    while (i < 5) {
        int j = 0;
        while (j < 5) {
            *(destino + i * 5 + j) = *(origen + (4 - i) * 5 + (4 - j));
            j = j + 1;
        }
        i = i + 1;
    }
}

void rotar270(const int *origen, int *destino) {
    int i = 0;
    while (i < 5) {
        int j = 0;
        while (j < 5) {
            *(destino + i * 5 + j) = *(origen + j * 5 + (4 - i));
            j = j + 1;
        }
        i = i + 1;
    }
}

long long contarCaminos(const int *n) {
    long long caminos = 1;
    int i = 1;

    // Formula combinatoria: (2n)! / (n! * n!)
    // Se calcula iterativamente para evitar desbordamientos de memoria
    while (i <= *n) {
        caminos = caminos * (*n + i);
        caminos = caminos / i;
        i = i + 1;
    }

    return caminos;
}

long long calcularFactorial(int n) {
    long long fact = 1;
    int i = 1;
    while (i <= n) {
        fact = fact * i;
        i = i + 1;
    }
    return fact;
}

void obtenerPermutacionLexicografica(long long n, char *resultado) {
    char digitos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool usados[10] = {false, false, false, false, false, false, false, false, false, false};

    // Ajuste a indice base 0
    long long k = n - 1;

    int posRes = 0;
    int posFact = 9; // Inicia en 9! hasta 0!

    while (posFact >= 0) {
        long long fact = calcularFactorial(posFact);
        int indiceElegido = k / fact;
        k = k % fact;

        // Buscar el digito disponible en la posicion 'indiceElegido'
        int contadorNoUsados = 0;
        int j = 0;
        while (j < 10) {
            if (*(usados + j) == false) {
                if (contadorNoUsados == indiceElegido) {
                    *(resultado + posRes) = *(digitos + j);
                    *(usados + j) = true;
                    j = 10; // Terminar la busqueda
                } else {
                    contadorNoUsados = contadorNoUsados + 1;// lleva la cuenta de numeros no usados
                }
            }
            j = j + 1;
        }

        posRes = posRes + 1;
        posFact = posFact - 1;
    }

    *(resultado + posRes) = '\0';
}