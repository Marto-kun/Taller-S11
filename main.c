#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libros.h"

int main(int argc, char *argv[])
{
    int n, opc, opcBus, estado, index;
    char entrada[MAX_LIBROS];
    printf("\n---Sistema de Inventario---\n");

    // Ingreso cantidad de libros
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
            printf("\nIngrese la ID del libro %i: ", i + 1);
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
                    if (existeID(libros, IdIngresado, n) == 1)
                    {
                        printf("\nLa ID ingresada ya existe. Por favor ingrese una nueva ID");
                    }
                    else
                    {
                        libros[i].ID = IdIngresado;
                        IdValida = 1;
                    }
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
                if (existeNombre(libros, entrada, n) == 1)
                {
                    printf("\nEl titulo ingresado ya existe. Por favor ingrese un nuevo titulo");
                }
                else
                {
                    strcpy(libros[i].titulo, entrada);
                    nombreValido = 1;
                }
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

            // Eliminar salto de linea
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionChar(entrada) == 1)
            {
                strcpy(libros[i].autor, entrada);
                autValido = 1;
            }
            else
            {
                printf("\nSolo se permiten letras. Intentelo de nuevo.");
                autValido = 0;
            }

        } while (autValido == 0);
    }

    // Ingreso de anios de publicacion de libros
    for (int i = 0; i < n; i++)
    {
        int anioValido = 0;
        do
        {
            printf("\nIngrese el anio de publicacion del libro %i: ", i + 1);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionDigitos(entrada) == 1)
            {
                int anioIngresado = atoi(entrada);

                if (anioIngresado > 0)
                {

                    libros[i].pub = anioIngresado;
                    anioValido = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (anioValido == 0);
    }

    int estValido = 0;
    do
    {
        printf("\nIngrese el estado predeterminado de los libros: ");
        printf("\n1) Disponible");
        printf("\n2) Prestado");
        printf("\n>>");

        if (fgets(entrada, 25, stdin) == NULL)
        {
            LimpiarBuffer();
            continue;
        }

        // Eliminar el salto de línea al final de la cadena
        entrada[strcspn(entrada, "\n")] = '\0';

        if (VerificacionDigitos(entrada) == 1)
        {
            int estIngresado = atoi(entrada);

            if (estIngresado > 0)
            {
                estado = estIngresado;
                estValido = 1;
            }
        }
        else
        {
            printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
        }

    } while (estValido == 0);

    if (estValido == 1)
    {
        switch (estado)
        {
        case 1:
            for (int i = 0; i < MAX_LIBROS; i++)
            {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("\nEstado predeterminado cambiado a 'Disponible'");
            break;

        case 2:
            for (int i = 0; i < MAX_LIBROS; i++)
            {
                strcpy(libros[i].estado, "Prestado");
            }
            printf("\nEstado predeterminado cambiado a 'Prestado'");
            break;
        default:
            printf("Opcion invalida, intentelo de nuevo.");
            break;
        }
    }

    //--- MENU PRINCIPAL ---

    int opcValida = 0;
    do
    {
        printf("\nIngrese la opcion deseada: ");
        printf("\n1) Mostrar Tabla de Informacion");
        printf("\n2) Buscar libro por ID o Titulo");
        printf("\n3) Actualizar estado de un libro");
        printf("\n4) Eliminar libro");
        printf("\n5) Salir del programa");
        printf("\n>>");

        if (fgets(entrada, 25, stdin) == NULL)
        {
            LimpiarBuffer();
            continue;
        }

        // Eliminar el salto de línea al final de la cadena
        entrada[strcspn(entrada, "\n")] = '\0';

        if (VerificacionDigitos(entrada) == 1)
        {
            int opcIngresada = atoi(entrada);

            if (opcIngresada > 0)
            {
                opc = opcIngresada;
                opcValida = 1;
            }
        }
        else
        {
            printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
        }

    } while (opcValida == 0);

    if (opcValida == 1)
    {
        switch (opc)
        {
        case 1: // Mostrar informacion en formato tabla
            /* code */
            break;

        case 2:
            int opc2Valida = 0;
            do
            {
                printf("\nIngrese su método de búsqueda: ");
                printf("\n1) ID");
                printf("\n2) Titulo");
                printf("\n>>");

                if (fgets(entrada, 25, stdin) == NULL)
                {
                    LimpiarBuffer();
                    continue;
                }

                // Eliminar el salto de línea al final de la cadena
                entrada[strcspn(entrada, "\n")] = '\0';

                if (VerificacionDigitos(entrada) == 1)
                {
                    int opc2Ingresada = atoi(entrada);

                    if (opc2Ingresada > 0)
                    {
                        opcBus = opc2Ingresada;
                        opc2Valida = 1;
                    }
                }
                else
                {
                    printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
                }

            } while (opc2Valida == 0);

            if (opc2Valida == 1)
            {
                switch (opcBus)
                {
                case 1:
                    int IdValida = 0;
                    do
                    {
                        printf("\nIngrese la ID que desea buscar: ");
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
                                if (existeID(libros, IdIngresado, n) == 0)
                                {
                                    printf("\nLa ID ingresada NO existe. Por favor ingrese una nueva ID");
                                }
                                else
                                {
                                    index = buscarProductoID(libros, IdIngresado);
                                    printf("\nId del libro: %i", libros[index].ID);
                                    printf("\nTitulo del libro: %s", libros[index].titulo);
                                    printf("\nAnio de publicacion del libro: %i", libros[index].pub);
                                    printf("\nAutor del libro: %s", libros[index].autor);
                                    printf("\nEstado del libro: %i", libros[index].estado);
                                    IdValida = 1;
                                }
                            }
                        }
                        else
                        {
                            printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
                        }

                    } while (IdValida == 0);
                    break;
                case 2:
                    int nombreValido = 0;
                    do
                    {
                        printf("\nIngresar el titulo que desea buscar: ");
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
                            if (existeNombre(libros, entrada, n) == 0)
                            {
                                printf("\nEl titulo ingresado NO existe. Por favor ingrese un nuevo titulo");
                            }
                            else
                            {
                                index = buscarProductoID(libros, entrada);
                                printf("\nId del libro: %i", libros[index].ID);
                                printf("\nTitulo del libro: %s", libros[index].titulo);
                                printf("\nAnio de publicacion del libro: %i", libros[index].pub);
                                printf("\nAutor del libro: %s", libros[index].autor);
                                printf("\nEstado del libro: %i", libros[index].estado);
                                nombreValido = 1;
                            }
                        }
                        else
                        {
                            printf("\nSolo se permiten letras. Intentelo de nuevo.");
                            nombreValido = 0;
                        }

                    } while (nombreValido == 0);
                    break;
                default:
                    printf("Opcion invalida, intentelo de nuevo.");
                    break;
                }
            }
        case 3:
            int IdValida = 0;
            do
            {
                printf("\nIngrese la ID del libro que desea actualizar: ");
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
                        if (existeID(libros, IdIngresado, n) == 0)
                        {
                            printf("\nLa ID ingresada NO existe. Por favor ingrese una nueva ID");
                        }
                        else
                        {
                            char str[10];

                            printf("\nIngrese el nuevo estado: ");
                            if (fgets(str, 25, stdin) == NULL)
                            {
                                LimpiarBuffer();
                                continue;
                            }

                            // Eliminar el salto de línea al final de la cadena
                            str[strcspn(str, "\n")] = '\0';

                            if (VerificacionDigitos(entrada) == 1)
                            {
                                if (strcmp(str, "Disponible") || strcmp(str, "Prestado") == 0)
                                {
                                    index = buscarProductoID(libros, IdIngresado);
                                    ActualEstado(libros, str, index);
                                    IdValida = 1;
                                }
                            }
                            else
                            {
                                printf("\nSolo puede ingresar estado 'Disponible' o 'Prestado'. Intentelo de nuevo");
                            }
                        }
                    }
                }
                else
                {
                    printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
                }
            } while (IdValida == 0);
            break;

        case 4: // Eliminar el libro
        default:
            break;
        }
    }

    return 0;
}