#ifndef LIBRERIA_1_H
#define LIBRERIA_1_H

//problema 2
void generarArregloAleatorio(char *arreglo, int tamano, unsigned int *semilla);
void imprimirArreglo(const char *arreglo, int tamano);
void contarFrecuenciaLetras(const char *arreglo, int tamano);

//problema 4
int cadenaAEntero(const char *cadena);

//problema 6
void convertirAMayusculas(const char *origen, char *destino);

//problema 8
void separarTextoYNumeros(const char *origen, char *texto, char *numeros);

//problema 10
int valorRomano(char c);
int romanoAArabigo(const char *romano);

//problema 12
void leerMatriz(int *matriz, int n);
void imprimirMatriz(const int *matriz, int n);
bool esCuadradoMagico(const int *matriz, int n);

//problema 14
void llenarMatriz5x5(int *matriz);
void imprimirMatriz5x5(const int *matriz);
void rotar90(const int *origen, int *destino);
void rotar180(const int *origen, int *destino);
void rotar270(const int *origen, int *destino);

//problema 16
long long contarCaminos(const int *n);

//problema 18
long long calcularFactorial(int n);
void obtenerPermutacionLexicografica(long long n, char *resultado);



#endif
