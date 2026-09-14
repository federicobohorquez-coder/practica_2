#ifndef LIBRERIA_1_H
#define LIBRERIA_1_H

//problema 2
void generarArreglo(char *arreglo, const int *tamano);
void imprimirArreglo(const char *arreglo, const int *tamano);
void contarFrecuencias(const char *arreglo, const int *tamano);

//problema 4
int cadenaAEntero(const char *cadena);

//problema 6
void convertirAMayusculas(const char *origen, char *destino);

//problema 8
void separarTextoYNumeros(const char *origen, char *texto, char *numeros);


// Separa la cadena en bloques de n cifras, completa con ceros a la izquierda y suma sus valores
void sumarBloques(const char *cadena, const int *n, int *sumaTotal);
#endif // LIBRERIA_1_H
