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

void menu();
void q_init();
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
            break;

        case 4:
            break;

        case 5:
            system("clear");
            printf("SALIENDO DEL PROGRAMA ... \n");
            break;

        default:
            system("clear");
            printf("Opcion invalida (1~5)\n");
            break;
        }
    } while (opcion != 5);
}

void q_init(cola *cola_impresion)
{
    int i = 0;
    char agreg[42];
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