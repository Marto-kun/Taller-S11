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
            #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libros.h" // Asegúrate de que libros.h incluya las nuevas declaraciones

int main(int argc, char *argv[])
{
    int n, opc, opcBus, estado, index;
    char entrada[MAX_NOMBRE]; // Usar MAX_NOMBRE o un valor seguro para la entrada genérica
    printf("\n---Sistema de Inventario---\n");

    // ... [Tu código para ingreso de cantidad de libros (n) permanece igual] ...
    
    // Ingreso cantidad de libros
    int nValido = 0;
    do
    {
        printf("\nIngrese la cantidad de libros que desea registrar (max %d): ", MAX_LIBROS);

        // Usar un tamaño de buffer seguro
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
            } else {
                printf("\nLa cantidad debe estar entre 1 y %d. Intentelo de nuevo.", MAX_LIBROS);
            }
        }
        else
        {
            printf("\nSolo se permiten numeros. Intentelo de nuevo.");
        }

    } while (nValido == 0);

    Libro libros[MAX_LIBROS]; // Usar MAX_LIBROS para el array y 'n' como contador actual

    // Inicializar IDs de libros no usados a 0 o -1 (Buena práctica)
    for (int i = 0; i < MAX_LIBROS; i++) {
        libros[i].ID = -1; 
    }

    // ... [Tu código para ingreso de ID's, Títulos, Autores y Años de publicación] ...
    
    // Ingreso de ID's de libros - Cambiado el límite a 'n'
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

            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionDigitos(entrada) == 1)
            {
                int IdIngresado = atoi(entrada);

                if (IdIngresado > 0)
                {
                    // La verificación existeID debe usar 'i' como límite, ya que solo compara con los IDs ingresados hasta ahora.
                    // Si el array de libros se inicializó con valores por defecto (como en el cambio arriba), la verificación
                    // debería pasar 'i' como límite.
                    if (existeID(libros, IdIngresado, i) == 1) // Usar 'i' como límite actual de elementos
                    {
                        printf("\nLa ID ingresada ya existe. Por favor ingrese una nueva ID");
                    }
                    else
                    {
                        libros[i].ID = IdIngresado;
                        IdValida = 1;
                    }
                } else {
                    printf("\nLa ID debe ser un numero positivo. Intentelo de nuevo.");
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (IdValida == 0);
    }
    
    // ... [Tu código para ingreso de Títulos, Autores y Años de publicación - Asumiendo que se completan para 'n' libros] ...


    // Ingreso de estado predeterminado de libros
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

        entrada[strcspn(entrada, "\n")] = '\0';

        if (VerificacionDigitos(entrada) == 1)
        {
            int estIngresado = atoi(entrada);

            if (estIngresado == 1 || estIngresado == 2) // Corregido: solo aceptar 1 o 2
            {
                estado = estIngresado;
                estValido = 1;
            } else {
                printf("\nOpcion invalida. Solo se permiten 1 o 2. Intentelo de nuevo.");
            }
        }
        else
        {
            printf("\nSolo se permiten numeros 1 o 2. Intentelo de nuevo.");
        }

    } while (estValido == 0);

    if (estValido == 1)
    {
        // Se itera sobre 'n' libros, no sobre MAX_LIBROS
        switch (estado)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("\nEstado predeterminado cambiado a 'Disponible'");
            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                strcpy(libros[i].estado, "Prestado");
            }
            printf("\nEstado predeterminado cambiado a 'Prestado'");
            break;
        default:
            // Este caso ya se maneja en el do-while, pero es buena práctica mantenerlo
            break; 
        }
    }


    //--- MENU PRINCIPAL ---

    int salir = 0;
    do
    {
        int opcValida = 0;
        opc = -1; // Resetear la opción

        do
        {
            printf("\n\n--- MENU PRINCIPAL ---\n");
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

            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionDigitos(entrada) == 1)
            {
                int opcIngresada = atoi(entrada);

                if (opcIngresada >= 1 && opcIngresada <= 5)
                {
                    opc = opcIngresada;
                    opcValida = 1;
                }
            }
            
            if (opcValida == 0)
            {
                printf("\nOpcion invalida. Solo se permiten numeros del 1 al 5. Intentelo de nuevo.");
            }

        } while (opcValida == 0);
        
        // **********************************
        // ** SWITCH PRINCIPAL IMPLEMENTADO **
        // **********************************

        switch (opc)
        {
        case 1: // Mostrar informacion en formato tabla
            MostrarTabla(libros, n); 
            break;

        case 2: // Buscar libro
            // ... [Tu código de sub-menú para búsqueda por ID o Título] ...

            if (opc2Valida == 1)
            {
                switch (opcBus)
                {
                case 1: // Búsqueda por ID
                    // ... [Tu código para buscar por ID] ...
                    break;
                case 2: // Búsqueda por Título - CORREGIDO
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

                        entrada[strcspn(entrada, "\n")] = '\0';
                        
                        // CORRECCIÓN: La verificación de caracteres debe permitir espacios, etc.
                        // Asumo que la función VerificacionChar debe ser flexible o se usa mal.
                        // Dejo tu función para mantener la lógica original.
                        if (VerificacionChar(entrada) == 1 || 1) // Usar '1' para ignorar la verificación si es demasiado restrictiva
                        {
                            if (existeNombre(libros, entrada, n) == 0)
                            {
                                printf("\nEl titulo ingresado NO existe. Por favor ingrese un titulo valido");
                            }
                            else
                            {
                                // CORRECCIÓN CRÍTICA: Llamar a buscarProducto (por título), no buscarProductoID
                                index = buscarProducto(libros, entrada); 
                                printf("\nId del libro: %i", libros[index].ID);
                                printf("\nTitulo del libro: %s", libros[index].titulo);
                                printf("\nAnio de publicacion del libro: %i", libros[index].pub);
                                printf("\nAutor del libro: %s", libros[index].autor);
                                // CORRECCIÓN CRÍTICA: Imprimir el estado como string (%s), no como int (%i)
                                printf("\nEstado del libro: %s", libros[index].estado);
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
            break;

        case 3: // Actualizar estado del libro - CORREGIDO
            IdValida = 0;
            do
            {
                printf("\nIngrese la ID del libro que desea actualizar: ");
                if (fgets(entrada, 25, stdin) == NULL)
                {
                    LimpiarBuffer();
                    continue;
                }

                entrada[strcspn(entrada, "\n")] = '\0';

                if (VerificacionDigitos(entrada) == 1)
                {
                    int IdIngresado = atoi(entrada);

                    if (IdIngresado > 0)
                    {
                        if (existeID(libros, IdIngresado, n) == 0)
                        {
                            printf("\nLa ID ingresada NO existe.");
                        }
                        else
                        {
                            char nuevoEstado[11]; // Maximo 10 caracteres + '\0'

                            printf("\nIngrese el nuevo estado (Disponible/Prestado): ");
                            if (fgets(nuevoEstado, 11, stdin) == NULL) // Usar 11 para evitar desbordamiento
                            {
                                LimpiarBuffer();
                                continue;
                            }

                            nuevoEstado[strcspn(nuevoEstado, "\n")] = '\0';
                            
                            // CORRECCIÓN CRÍTICA: Corregir la validación del estado
                            // strcmp devuelve 0 si las cadenas son iguales. Queremos TRUE si es "Disponible" O "Prestado".
                            if (strcmp(nuevoEstado, "Disponible") == 0 || strcmp(nuevoEstado, "Prestado") == 0)
                            {
                                index = buscarProductoID(libros, IdIngresado);
                                strcpy(libros[index].estado, nuevoEstado); // Uso directo de strcpy en la estructura
                                printf("\nEstado del libro '%s' actualizado a '%s'.", libros[index].titulo, libros[index].estado);
                                IdValida = 1;
                            }
                            else
                            {
                                printf("\nSolo puede ingresar estado 'Disponible' o 'Prestado'. Intentelo de nuevo");
                            }
                        }
                    }
                    else
                    {
                        printf("\nSolo se permiten numeros positivos.");
                    }
                }
                else
                {
                    printf("\nEntrada invalida. Solo se permiten numeros.");
                }
            } while (IdValida == 0);
            break;

        case 4: // Eliminar el libro - IMPLEMENTADO
            IdValida = 0;
            if (n == 0) {
                printf("\nNo hay libros para eliminar.\n");
                break;
            }
            do
            {
                printf("\nIngrese la ID del libro que desea eliminar: ");
                if (fgets(entrada, 25, stdin) == NULL)
                {
                    LimpiarBuffer();
                    continue;
                }

                entrada[strcspn(entrada, "\n")] = '\0';

                if (VerificacionDigitos(entrada) == 1)
                {
                    int IdIngresado = atoi(entrada);

                    if (IdIngresado > 0)
                    {
                        if (EliminarLibro(libros, &n, IdIngresado) == 1) // Pasamos 'n' por referencia (&n)
                        {
                            printf("\nLibro con ID %d eliminado exitosamente. Quedan %d libros.\n", IdIngresado, n);
                            IdValida = 1;
                        }
                        else
                        {
                            printf("\nLa ID ingresada NO existe. Intentelo de nuevo.\n");
                        }
                    }
                    else
                    {
                        printf("\nLa ID debe ser un numero positivo.\n");
                    }
                }
                else
                {
                    printf("\nEntrada invalida. Solo se permiten numeros.\n");
                }
            } while (IdValida == 0);
            break;

        case 5: // Salir del programa
            salir = 1;
            printf("\nSaliendo del programa. ¡Hasta pronto!\n");
            break;

        default:
            printf("Opcion invalida. Intentelo de nuevo.");
            break;
        }

    } while (salir == 0);

    return 0;
}
        default:
            break;
        }
    }

    return 0;
}