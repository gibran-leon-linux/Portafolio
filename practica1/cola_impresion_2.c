#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_USER 32
#define MAX_DOC 48

typedef enum
{
    NORMAL = 0,
    URGENTE = 1
} Prioridad_t;

typedef enum
{
    EN_COLA = 0,
    IMPRIMIENDO = 1,
    COMPLETADO = 2,
    CANCELADO = 3
} Estado_t;

typedef struct
{
    int id;
    char usuario[MAX_USER];
    char documento[MAX_DOC];
    int paginas_total;
    int copias;
    Prioridad_t prioridad;
    Estado_t estado;
    int ms_por_pagina;
} PrintJob_t;

// Nodo
typedef struct Nodo
{
    PrintJob_t data;
    struct Nodo *next;
} Nodo_t;

// Lista
typedef struct
{
    Nodo_t *frente;
    Nodo_t *final;
    int contador;
} QueueDynamic_t;

void menu(QueueDynamic_t *q);
void qs_enqueue_input(QueueDynamic_t *q);
int qs_dequeue(QueueDynamic_t *q, PrintJob_t *out);
int qs_peek(const QueueDynamic_t *q, PrintJob_t *out);
void qs_print(const QueueDynamic_t *q);
void pausa();
const char *texto_prioridad(Prioridad_t p);
const char *texto_estado(Estado_t e);
void liberar_cola(QueueDynamic_t *q);

int main()
{
    QueueDynamic_t imprimir;
    imprimir.frente = NULL;
    imprimir.final = NULL;
    imprimir.contador = 0;

    menu(&imprimir);
    liberar_cola(&imprimir); // Limpiar memoria antes de salir
    return 0;
}

void menu(QueueDynamic_t *q)
{
    int opcion;
    PrintJob_t temp;

    do
    {
        system("clear");
        printf("|COLA DE IMPRESION DINAMICA|\n");
        printf("1. Agregar Trabajo\n");
        printf("2. Peek\n");
        printf("3. Dequeue\n");
        printf("4. Listar Todos\n");
        printf("5. Salir\n");
        printf("Eliga una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
            system("clear");
            qs_enqueue_input(q);
            pausa();
            break;
        case 2:
            system("clear");
            if (qs_peek(q, &temp))
            {
                printf("--- AL FRENTE ---\nID: %d | User: %s | Doc: %s", temp.id, temp.usuario, temp.documento);
                printf("Estado: %s\n", texto_estado(temp.estado));
            }
            else
                printf("Cola vacia.\n");
            pausa();
            break;
        case 3:
            system("clear");
            if (qs_dequeue(q, &temp))
            {
                printf("\nTrabajo finalizado y memoria liberada.\n");
            }
            else
                printf("Nada para procesar.\n");
            pausa();
            break;
        case 4:
            system("clear");
            qs_print(q);
            pausa();
            break;
        case 5:
            system("clear");
            printf("Saliendo del programa ...");
            pausa();
            break;
        default:
            system("clear");
            printf("Opcion invalida (1~5) ...");
            pausa();
            break;
        }
    } while (opcion != 5);
}

void qs_enqueue_input(QueueDynamic_t *q)
{
    Nodo_t *nuevo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if (nuevo == NULL)
    {
        printf("Error: No hay memoria suficiente.\n");
        return;
    }

    char n_paginas[10], n_copias[10];

    nuevo->data.id = q->contador + 1;

    printf("Usuario: ");
    fgets(nuevo->data.usuario, MAX_USER, stdin);
    printf("Documento: ");
    fgets(nuevo->data.documento, MAX_DOC, stdin);
    printf("N. Paginas: ");
    fgets(n_paginas, 10, stdin);
    nuevo->data.paginas_total = strtol(n_paginas, NULL, 10);
    printf("Copias: ");
    fgets(n_copias, 10, stdin);
    nuevo->data.copias = strtol(n_copias, NULL, 10);

    nuevo->data.prioridad = NORMAL;
    nuevo->data.estado = EN_COLA;
    nuevo->data.ms_por_pagina = 3000;
    nuevo->next = NULL;

    if (q->final == NULL)
    {
        q->frente = nuevo;
        q->final = nuevo;
    }
    else
    {
        q->final->next = nuevo;
        q->final = nuevo;
    }
    q->contador++;
    printf("\nTrabajo agregado\n");
}

int qs_dequeue(QueueDynamic_t *q, PrintJob_t *out)
{
    if (q->frente == NULL)
    {
        return 0;
    }

    Nodo_t *temp_nodo = q->frente;
    *out = temp_nodo->data;

    printf("Imprimiendo: %s", out->documento);

    for (int c = 1; c <= out->copias; c++)
    {
        printf("--- Copia %d de %d ---\n", c, out->copias);

        for (int p = 1; p <= out->paginas_total; p++)
        {
            printf("Pagina %d/%d...\n", p, out->paginas_total);
            usleep(out->ms_por_pagina * 1000);
        }
    }

    q->frente = q->frente->next;

    if (q->frente == NULL)
    {
        q->final = NULL;
    }

    free(temp_nodo);
    return 1;
}

int qs_peek(const QueueDynamic_t *q, PrintJob_t *out)
{
    if (q->frente == NULL)
    {
        return 0;
    }

    *out = q->frente->data;
    return 1;
}

void qs_print(const QueueDynamic_t *q)
{
    if (q->frente == NULL)
    {
        printf("Cola vacia.\n");
        return;
    }

    Nodo_t *actual = q->frente;

    printf("--- LISTADO (%d trabajos) ---\n", q->contador);

    while (actual != NULL)
    {
        printf("[%d] %s | Doc: %s | Estado: %s\n",
               actual->data.id, actual->data.usuario, actual->data.documento, texto_estado(actual->data.estado));
        actual = actual->next;
    }
}

const char *texto_prioridad(Prioridad_t p) { return (p == URGENTE) ? "URGENTE" : "NORMAL"; }
const char *texto_estado(Estado_t e)
{
    const char *estados[] = {"EN COLA", "IMPRIMIENDO", "COMPLETADO", "CANCELADO"};
    return estados[e];
}

void pausa()
{
    printf("\nPresiona Enter para continuar...");
    while (getchar() != '\n')
        ;
    system("clear");
}

void liberar_cola(QueueDynamic_t *q)
{
    Nodo_t *actual = q->frente;
    while (actual != NULL)
    {
        Nodo_t *sig = actual->next;
        free(actual);
        actual = sig;
    }
}