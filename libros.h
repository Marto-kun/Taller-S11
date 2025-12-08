#ifndef LIBROS_H
#define LIBROS_H
#include "libros.c"


// Declaracion de funciones
int existeNombre(Libro libros[], char nombre[], int n);
int existeID(Libro libros[], int ID, int n);
void LimpiarBuffer();
int VerificacionDigitos(char string[]);
int VerificacionChar(char string[]);
int buscarProductoID(Libro libros[], int entrada);
int buscarProducto(Libro libros[], char nombreBuscado[]);
void MostrarTabla(Libro libros[], int n);
int EliminarLibro(Libro libros[], int *n, int ID);
#endif