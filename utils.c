#include <string.h>
#include "libros.h"


int existeNombre(Libro libro, char nombre[]){
    for(int i = 0; i < MAX_NOMBRE; i++){
        if(strcmp(libro.titulo, nombre) == 0){
            return 1;
        }
    }
    return 0;
}

int existeNombre(Libro libro, int ID){
    for(int i = 0; i < MAX_NOMBRE; i++){
        if(libro.ID, ID == 0){
            return 1;
        }
    }
    return 0;
}