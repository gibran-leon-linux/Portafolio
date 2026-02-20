// Practica 1: Cola de impresion en C
// Inicio: 02/19/2026
// Fin:    ##/##/####

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ts_cola
{
    int id;
    char usuario[32];
    char documento[42];
    int total_pgs;
    int restante_pgs;
    int copias;
    int prioridad;
    int estado;
} cola;

void menu();
void q_init(cola *cola_impresion, int n, int llena);
void q_is_empty();
void q_is_full();
void q_enqueue();
void q_dequeue();
void q_peek();
void q_print(cola *cola_impresion);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int n = 10;
    int llena = 0;
    cola *cola_impresion[n];

    int opcion;

    system("clear");
    do
    {

        printf("COLA DE IMPRESION\n");
        printf("1. Agregar\n");
        printf("2. Peek\n");
        printf("3. Dequeue\n");
        printf("4. Listar\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:

            if (llena == 1)
            {
                printf("LA LISTA ESTA LLENA Y NO SE PUEDEN AGREGAR DATOS");
                break;
            }
            else
            {
                q_init(*cola_impresion, n, llena);
            }

            break;
        case 4:
            q_print(*cola_impresion);
            break;
        case 5:
            printf("SALIENDO DEL PROGRAMA ... \n");
            break;

        default:
            system("clear");
            printf("Opcion invalida (1~5)\n");
            break;
        }
    } while (opcion != 5);
}

void q_init(cola *cola_impresion, int n, int llena)
{
    int i = 0;
    char agreg[42];
    do
    {
        if (i == 0)
        {
            printf("LA LISTA ESTA VACIA\n");
            printf("Ingrese el nombre del documento: ");
            scanf("%s", agreg);
            strcpy(cola_impresion[i].documento, agreg);
            printf("Se agrego el titulo a la cola N. %d\n", n);
            i++;
        }
        else
        {
            printf("LA LISTA YA TIENE ELEMENTOS\n");
            printf("Ingrese el nombre del documento: ");
            scanf("%s", agreg);
            strcpy(cola_impresion[i].documento, agreg);
            printf("Se agrego el titulo a la cola N. %d", n);
        }
        i++;
    } while (i < 10);
}

void q_print(cola *cola_impresion)
{
    int i;

    for (i = 0; i < 10; cola_impresion[i++])
    {
        printf("TITULO DEL DOCUMENTO N.%d\n", i);
        printf("%s\n\n", cola_impresion->documento);
    }
}