#ifndef LIBRERIA_1_H
#define LIBRERIA_1_H


// Punteros constantes para lectura de arreglos/monto; punteros simples para modificar resultados
void calcularDesglose(const int *monto, const int *denominaciones, int *cantidades, const int *tamano, int *faltante);

// Prototipo para comparar cadenas usando punteros constantes
bool compararCadenas(const char *cadena1, const char *cadena2);

// Convierte un número entero a una cadena de caracteres usando punteros
void enteroACadena(const int *numero, char *cadena);

// Elimina caracteres repetidos preservando el primer orden de aparicion
void eliminarRepetidos(const char *cadenaOriginal, char *cadenaSinRepetidos);

// Separa la cadena en bloques de n cifras, completa con ceros a la izquierda y suma sus valores
void sumarBloques(const char *cadena, const int *n, int *sumaTotal);
#endif // LIBRERIA_1_H
