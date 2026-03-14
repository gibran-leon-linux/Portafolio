#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_JOBS 10 // Cantidad de copias
#define MAX_USER 32 // Cantidad de caracteres para usuario
#define MAX_DOC 48  // Cantidad de caracteres para titulo de documentos

typedef enum // Prioridad
{
    NORMAL = 0,
    URGENTE = 1
} Prioridad_t;

typedef enum // Estado
{
    EN_COLA = 0,
    IMPRIMIENDO = 1,
    COMPLETADO = 2,
    CANCELADO = 3
} Estado_t;

typedef struct // Struct
{
    int id;                  // autoincremental
    char usuario[MAX_USER];  // quien imprime
    char documento[MAX_DOC]; // nombre del documento
    int paginas_total;       // total de paginas
    int paginas_restantes;   // para simular progreso
    int copias;              // opcional (>=1)
    Prioridad_t prioridad;   // normal/urgente
    Estado_t estado;         // en cola/imprimiendo/...
    int ms_por_pagina;       // opcional para simulacion
} PrintJob_t;

typedef struct // Struct total
{
    PrintJob_t data[MAX_JOBS];
    int size; // cantidad actual de elementos
} QueueStatic_t;

// Funciones Programa
void menu(QueueStatic_t *q);                          // Menu
void qs_init(QueueStatic_t *q);                       // Agregar
int qs_is_empty(const QueueStatic_t *q);              // Inicio
int qs_is_full(const QueueStatic_t *q);               // Final
int qs_enqueue(QueueStatic_t *q, PrintJob_t job);     // Enqueue (append)
int qs_peek(const QueueStatic_t *q, PrintJob_t *out); // Peek (consultar frente)
int qs_dequeue(QueueStatic_t *q, PrintJob_t *out);    // Dequeue (pop-front + shift)
void qs_print(const QueueStatic_t *q);                // Imprimir

// Funciones Complementarias
void pausa(); // Pausa esperando input
const char *texto_prioridad(Prioridad_t p);
const char *texto_estado(Estado_t e);

int main() // Main
{
    QueueStatic_t imprimir; // Declarar arreglo
    imprimir.size = 0;      // Inicializar tamano de arreglo como 0 en variable size
    menu(&imprimir);        // Pasar arreglo a menu
    return 0;               // Fin programa
}

void menu(QueueStatic_t *q)
{
    int opcion;
    PrintJob_t temp;

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
        getchar();

        switch (opcion)
        {
        case 1:
            system("clear");
            if (!qs_is_full(q))
                qs_init(q);
            else
                printf("La cola está llena.\n");
            pausa();
            break;
        case 2:
            system("clear");
            if (qs_peek(q, &temp))
            {
                // se imprime adentro de peek
            }
            pausa();
            break;
        case 3:
            system("clear");
            if (qs_dequeue(q, &temp))
            {
                printf("\nTrabajo finalizado y removido.\n");
            }
            else
            {
                printf("No hay trabajos para procesar.\n");
            }
            pausa();
            break;
        case 4:
            system("clear");
            qs_print(q);
            pausa();
            break;
        case 5:
            system("clear");
            printf("SALIENDO DEL PROGRAMA ...\n");
            pausa();
            break;
        default:
            system("clear");
            printf("OPCION INVALIDA (1~5)\n");
            pausa();
            break;
        }
    } while (opcion != 5);
}

void qs_init(QueueStatic_t *q) // Agregar
{
    char usuario[MAX_USER];
    char documento[MAX_DOC];
    char n_paginas[10], n_copias[10];

    // Autoincrementar
    q->data[q->size].id = q->size + 1;

    // Pedir
    printf("Usuario: ");
    fgets(usuario, MAX_USER, stdin);
    strcpy(q->data[q->size].usuario, usuario);

    printf("Documento: ");
    fgets(documento, MAX_DOC, stdin);
    strcpy(q->data[q->size].documento, documento);

    printf("N.Paginas: ");
    fgets(n_paginas, 10, stdin);
    q->data[q->size].paginas_total = strtol(n_paginas, NULL, 10);

    printf("Copias: ");
    fgets(n_copias, 10, stdin);
    q->data[q->size].copias = strtol(n_copias, NULL, 10);

    // No pedir
    q->data[q->size].prioridad = NORMAL;
    q->data[q->size].estado = EN_COLA;

    q->data[q->size].ms_por_pagina = 3000;
    q->size++;
}

int qs_is_empty(const QueueStatic_t *q) // Esta vacio
{
    return q->size == 0;
}

int qs_is_full(const QueueStatic_t *q) // Esta llena
{
    return q->size == MAX_JOBS;
}

int qs_enqueue(QueueStatic_t *q, PrintJob_t job) // Enqueue (append)
{
    if (q->size == MAX_JOBS)
        return 0; // cola llena
    q->data[q->size] = job;
    q->size++;
    return 1;
}

int qs_peek(const QueueStatic_t *q, PrintJob_t *out) // Peek (consultar frente)
{
    if (q->size == 0)
    {
        printf("La cola esta vacia\n");
        return 0;
    }

    *out = q->data[0];

    printf("--- TRABAJO AL FRENTE ---\n");
    printf("Id:        %d\n", out->id);
    printf("Usuario:   %s", out->usuario);
    printf("Documento: %s", out->documento);
    printf("N.Paginas: %d\n", out->paginas_total);
    printf("Copias:    %d\n", out->copias);

    printf("Prioridad: %s\n", texto_prioridad(out->prioridad));
    printf("Estado:    %s\n", texto_estado(out->estado));

    printf("Posicion:  1 de %d\n", q->size);
    return 1;
}

int qs_dequeue(QueueStatic_t *q, PrintJob_t *out)
{
    if (q->size == 0)
    {
        return 0;
    }

    *out = q->data[0];

    printf("Iniciando trabajo: %s", out->documento);

    for (int c = 1; c <= out->copias; c++)
    {
        printf("\n--- Copia %d de %d ---\n", c, out->copias);

        for (int p = 1; p <= out->paginas_total; p++)
        {
            printf("Imprimiendo: Pagina %d/%d...\n", p, out->paginas_total);
            usleep(q->data->ms_por_pagina * 1000);
        }
    }

    for (int i = 1; i < q->size; i++)
    {
        q->data[i - 1] = q->data[i];
    }
    q->size--;
    return 1;
}

const char *texto_prioridad(Prioridad_t p)
{
    return (p == URGENTE) ? "URGENTE" : "NORMAL";
}

const char *texto_estado(Estado_t e)
{
    switch (e)
    {
    case EN_COLA:
        return "EN COLA";
    case IMPRIMIENDO:
        return "IMPRIMIENDO";
    case COMPLETADO:
        return "COMPLETADO";
    case CANCELADO:
        return "CANCELADO";
    default:
        return "DESCONOCIDO";
    }
}

void qs_print(const QueueStatic_t *q)
{
    if (q->size == 0)
    {
        printf("Cola vacia.\n");
        return;
    }
    printf("--- TRABAJOS PENDIENTES (%d) ---\n", q->size);
    for (int i = 0; i < q->size; i++)
    {
        printf("[%d] ID: %d | User: %s | Doc: %s",
               i + 1, q->data[i].id, q->data[i].usuario, q->data[i].documento);
        printf("    Estado: %s | Prioridad: %s\n",
               texto_estado(q->data[i].estado),
               texto_prioridad(q->data[i].prioridad));
    }
}

void pausa()
{
    printf("Presione la tecla enter para continuar ...");
    while (getchar() != '\n')
    {
    };
    system("clear");
}