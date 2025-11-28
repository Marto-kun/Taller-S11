#ifndef LIBROS_H
#define LIBROS_H

#define MAX_LIBROS 10
#define MAX_NOMBRE 100
#define MAX_AUTOR 50
typedef struct 
{
    int ID;
    char titulo[MAX_NOMBRE];
    char autor[MAX_AUTOR];
    int pub;
    char estado[10];
}Libro;


#endif