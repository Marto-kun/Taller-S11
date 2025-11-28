#ifndef LIBROS_H
#define LIBROS_H
#include "libros.c"


// Declaracion de funciones
int existeNombre(Libro libro, char nombre[]);
int existeID(Libro libro, int ID);
void LimpiarBuffer();
int VerificacionDigitos(char string[]);
int VerificacionChar(char string[]);

#endif