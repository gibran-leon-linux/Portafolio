// Practica 1: Cola de impresion en C
// Inicio:  19/02/2026
// Entrega: 13/03/2026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ts_cola
{
    int id;             // Numero autoincremental
    char usuario[32];   // Nombre del usuario que mando a imprimir
    char documento[42]; // Titulo del documento
    int total_pgs;      // Numero total de paginas
    int restante_pgs;   // Paginas restantes por imprimir
    int copias;         // Copias por imprimir
    int prioridad;      // NORMAL, URGENTE
    int estado;         // EN_COLA, IMPRIMIENDO, COMPLETADO, CANCELADO
} cola;

void menu();
void q_init(cola cola_impresion, int llena);
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
    int llena = 0;
    cola cola_impresion[10];

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
                q_init(*cola_impresion, llena);
            }

            break;
        case 4:
            q_print(cola_impresion);
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

void q_init(cola cola_impresion, int llena)
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
            strcpy(cola_impresion.documento, agreg);
            printf("Se agrego el titulo a la cola N. %d\n", i);
            i++;
        }
        else
        {
            printf("LA LISTA YA TIENE ELEMENTOS\n");
            printf("Ingrese el nombre del documento: ");
            scanf("%s", agreg);
            strcpy(cola_impresion.documento, agreg);
            printf("Se agrego el titulo a la cola N. %d", i);
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