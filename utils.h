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