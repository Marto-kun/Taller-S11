#ifndef LIBROS_H
#define LIBROS_H
#include "libros.c"


// Declaracion de funciones
int existeNombre(Libro libros[], char nombre[]);
int existeID(Libro libros[], int ID);
void LimpiarBuffer();
int VerificacionDigitos(char string[]);
int VerificacionChar(char string[]);

#endif