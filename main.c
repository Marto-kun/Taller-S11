#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libros.h"

int main(int argc, char *argv[])
{
    int n;
    char entrada[MAX_LIBROS];
    printf("\n---Sistema de Inventario---\n");

    int nValido = 0;
    do
    {
        printf("\nIngrese la cantidad de libros que desea registrar (<10): ");

        if (fgets(entrada, MAX_AUTOR, stdin) == NULL)
        {
            LimpiarBuffer();
            continue;
        }

        entrada[strcspn(entrada, "\n")] = '\0';

        if (VerificacionDigitos(entrada))
        {
            int nIngresado = atoi(entrada);
            if (nIngresado > 0 && nIngresado <= MAX_LIBROS)
            {
                n = nIngresado;
                nValido = 1;
            }
        }
        else
        {
            printf("\nSolo se permiten numeros del 1 al 10. Intentelo de nuevo.");
        }

    } while (nValido == 0);

    Libro libros[n];

    // Ingreso de ID's de libros
    for (int i = 0; i < n; i++)
    {
        int IdValida = 0;
        do
        {
            printf("\nIngrese el precio de %s: ", libros[i]);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionDigitos(entrada) == 1)
            {
                int IdIngresado = atoi(entrada);

                if (IdIngresado > 0)
                {
                    libros[i].ID = IdIngresado;
                    IdValida = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (IdValida == 0);
    }

    // Ingreso de titulos de libros
    for (int i = 0; i < n; i++)
    {

        int nombreValido = 0;
        do
        {
            printf("\nIngresar el titulo del libro #%i: ", i + 1);
            if (fgets(entrada, MAX_NOMBRE, stdin) == NULL)
            {
                LimpiarBuffer();
                nombreValido = 0;
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionChar(entrada) == 1)
            {
                strcpy(libros[i].titulo, entrada);
                nombreValido = 1;
            }
            else
            {
                printf("\nSolo se permiten letras. Intentelo de nuevo.");
                nombreValido = 0;
            }

        } while (nombreValido == 0);
    }

    // Ingreso de autores de libros
    for (int i = 0; i < n; i++)
    {
        int autValido = 0;

        do
        {
            printf("\nIngrese el autor del libro %s: ", libros[i].titulo);

            if (fgets(entrada, MAX_AUTOR, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            //Eliminar salto de linea
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionChar(entrada)==1)
            {
                strcpy(libros[i].autor, entrada);
                autValido =1;
            }else{
                printf("\nSolo se permiten letras. Intentelo de nuevo.");
                autValido = 0;
            }
            

        } while (autValido == 0);
    }

    return 0;
}