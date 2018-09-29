#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX = 3;
const int ELEMENTO_VACIO = 0;
const int COLA_LLENA = -1;

struct Alumno{
    char nombre[64];
    int edad;
    int siguiente;
};

void inicializar(struct Alumno *);
void crear(struct Alumno *, int );
Alumno  dequeue(struct Alumno *, int );
Alumno frontEstatico(struct Alumno *, int );
Alumno backEstatico(struct Alumno *, int);
int vacia(struct Alumno *, int);
int numeroElementos();

int main()
{
    int indice_raiz = MAX-1, i, filaVacia;
    struct Alumno fila[MAX];
    struct Alumno nodoSacado;

    nodoSacado.edad = 0;
    strcpy(nodoSacado.nombre,"NULL");

    inicializar (fila);

    filaVacia = vacia(fila,indice_raiz);
    printf("\n%d",filaVacia);

    for(i = 0; i < MAX; ++i)
        crear(fila,indice_raiz);

    //nodoSacado = dequeue(fila,indice_raiz);
    //nodoSacado = frontEstatico(fila,indice_raiz);
    //nodoSacado = backEstatico(fila,indice_raiz);

    filaVacia = vacia(fila,indice_raiz);
    printf("\n%d",filaVacia);

    printf("\nNumero de elementos: %d", numeroElementos());

    return 0;
}

int numeroElementos()
{
    return MAX;
}

int vacia(struct Alumno *fila, int indice_raiz)
{
    for(int i = 0; i < MAX; ++i)
    {
        if(fila[indice_raiz].siguiente != 0)
        return 1;
        break;
    }
    return 0;

}

Alumno backEstatico(struct Alumno *fila, int indice_raiz)
{
    if(fila[indice_raiz].siguiente == -1 || fila[indice_raiz].siguiente == COLA_LLENA)
    {
        return fila[indice_raiz];
    }
    else
    {
        backEstatico(fila, indice_raiz-1);
    }
}

Alumno frontEstatico(struct Alumno *fila, int indice_raiz)
{
    return fila[indice_raiz];
}

Alumno  dequeue(struct Alumno *fila, int indice_raiz)
{
    return fila[indice_raiz];

    fila[0].siguiente = 0;

    for(int i = indice_raiz; i >= 0; --i)
    {
        strcpy(fila[indice_raiz].nombre,fila[indice_raiz-1].nombre);
        fila[i].edad = fila[i-1].edad;
    }
}

void crear(struct Alumno *fila, int indice_raiz)
{
    if(fila[indice_raiz].siguiente == ELEMENTO_VACIO)
    {
        printf("\nNombre ");
        scanf("%s",&fila[indice_raiz].nombre);
        printf("Edad ");
        scanf("%d",&fila[indice_raiz].edad);
        fila[indice_raiz].siguiente = indice_raiz;
        if(indice_raiz == ELEMENTO_VACIO)
            fila[indice_raiz].siguiente = COLA_LLENA;
    }
    else
    {
        crear(fila, indice_raiz-1);
    }
}

void inicializar(struct Alumno *fila)
{
    int i;
    for(i = 0; i < MAX; ++i)
        fila[i].siguiente = ELEMENTO_VACIO;
}
