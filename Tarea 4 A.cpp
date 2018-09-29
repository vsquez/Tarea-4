#include<stdio.h>
#include<stdlib.h>

/****/

struct Alumno{
    char nombre[64];
    int edad;
    Alumno *adelante;
};

struct Alumno *raiz = NULL;

void insertar(struct Alumno *, struct Alumno *);
Alumno * crearNodo();
Alumno * dequeue(struct Alumno *);
Alumno * buscarFront(struct Alumno *);
Alumno * buscarBack(struct Alumno *);
bool comprobarVacio(struct Alumno *);
void tamanioFila(struct Alumno *, int *);

int main ()
{
    int tamanio = 0;
    bool vacia;
    struct Alumno *nodoEncontrado = NULL;

    for(int i = 0; i < 3; ++i)
    {
        Alumno *nuevo = crearNodo();
        if(raiz == NULL)
        {
            raiz = nuevo;
        }
        else
        {
            insertar(raiz,nuevo);
        }
    }

    nodoEncontrado = dequeue(raiz);
    nodoEncontrado = buscarBack(raiz);
    nodoEncontrado = buscarFront(raiz);
    tamanioFila(raiz,&tamanio);
    vacia = comprobarVacio(raiz);
    printf("\nTamanio de la fila: %d",tamanio);
    printf("\nVacia?---%s",vacia);
}

void tamanioFila(struct Alumno *fila, int *contador)
{
    if(fila->adelante != NULL)
        tamanioFila(fila->adelante,contador);

    ++*contador;
}

bool comprobarVacio(struct Alumno *fila)
{
    if(fila->adelante == NULL)
        return true;
    else
        return false;
}

Alumno * buscarBack(struct Alumno *fila)
{
    if(fila->adelante == NULL)
    {
        printf("\nBack: %s",fila->nombre);
        return fila;
    }
    else
        buscarBack(fila->adelante);
}

Alumno * buscarFront(struct Alumno *fila)
{
    printf("\nFront: %s",fila->nombre);
    return fila;
}

Alumno * dequeue(struct Alumno *fila)
{
    if(fila->adelante == NULL)
    {
        printf("\n%s",fila->nombre);
        return fila;
        free(fila);
    }
    else
        dequeue(fila->adelante);
}

void insertar(struct Alumno *fila, struct Alumno *nuevo)
{
    if(fila->adelante == NULL)
        fila->adelante = nuevo;
    else
        insertar(fila->adelante,nuevo);
}

Alumno * crearNodo()
{
    Alumno *nuevo = new Alumno;
    printf("\nInserte nombre: ");
    scanf("%s",&nuevo->nombre);
    printf("Inserte edad: ");
    scanf("%d",&nuevo->edad);
    nuevo->adelante = NULL;
    return nuevo;
}
