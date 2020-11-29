#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pila Pila;
typedef struct Nodo Nodo;

struct Nodo
{
	char fecha[15];
	char asignacion[20];
	char horaInicio[10];
	char horaFinal[10];
	char recurso[30];
	Nodo *siguiente;
};

struct Pila
{
	Nodo *tope;
	int tamano;
};

Pila *pilaNueva(void);
Nodo* crearNodo(char fecha[], char asignacion[], char horaInicio[], char horaFinal[], char recurso[]);
void push(Pila *P, char fecha[], char asignacion[], char horaInicio[], char horaFinal[], char recurso[]);
void pop(Pila *P);
void top(Pila *P);
void size(Pila *P);
void mostrarPila(const Pila *P);
int isEmpty(Pila *P);
void clear(Pila *P);

Pila *pilaNueva(void)
{
	Pila *P;
	P = (Pila *) malloc(sizeof(Pila));
	P->tope = NULL;
	P->tamano = 0;
	return P;
}

Nodo* crearNodo(char fecha[], char asignacion[], char horaInicio[], char horaFinal[], char recurso[])
{
	Nodo *nuevo;
	nuevo = (Nodo *) malloc(sizeof(Nodo));
	nuevo->siguiente = NULL;
	strcpy(nuevo->fecha, fecha);	
	strcpy(nuevo->asignacion, asignacion);
	strcpy(nuevo->horaInicio, horaInicio);
	strcpy(nuevo->horaFinal, horaFinal);
	strcpy(nuevo->recurso, recurso);

	return nuevo;
}

void push(Pila *P, char fecha[], char asignacion[], char horaInicio[], char horaFinal[], char recurso[])  //Siempre al hacer push se inserta al inicio de la pila
{
	Nodo *nuevo = crearNodo(fecha, asignacion, horaInicio, horaFinal, recurso);
	
	nuevo->siguiente = P->tope;
	P->tope = nuevo;
	P->tamano = P->tamano + 1; 

	return;
}

void pop(Pila *P)  //Siempre al hacer push se inserta al inicio de la pila
{
	Nodo *eliminado = P->tope;
	
	if(P->tope == NULL)
	{
		printf("La pila esta vacia\n");
	}
	else
	{
		P->tope = P->tope->siguiente;
		P->tamano = P->tamano - 1;
		printf("La asignacion eliminada corresponde a:\n");	
		printf("------------------------------------------------- \n");
		printf("Fecha: %s \n", eliminado->fecha);
		printf("Asignacion: %s \n", eliminado->asignacion);
		printf("Horan de inicio: %s \n", eliminado->horaInicio);
		printf("Hora de finalizacion: %s \n", eliminado->horaFinal);
		printf("Recurso: %s \n", eliminado->recurso);
		printf("------------------------------------------------- \n");
		free(eliminado);
	}
	return;	
}

void top(Pila *P)
{
	if(P->tope == NULL)
		printf("No hay asignaciones\n");	
	else
		printf("El ultimo registro corresponde a: \n");
		printf("------------------------------------------------- \n");
		printf("Fecha: %s \n", P->tope->fecha);
		printf("Asignacion: %s \n", P->tope->asignacion);
		printf("Horan de inicio: %s \n", P->tope->horaInicio);
		printf("Hora de finalizacion: %s \n", P->tope->horaFinal);
		printf("Recurso: %s \n", P->tope->recurso);
		printf("------------------------------------------------- \n");
	return;	
}

void size(Pila *P)
{
	printf("La cantidad de asignaciones corresponde a %d\n", P->tamano);
	return;	
}


void mostrarPila(const Pila *P)
{
	Nodo *i;
	printf("Actualmente existen %d asignaciones en el sistema\n", P->tamano);
	printf("La lista de asignaciones es la siguiente: \n");
	for(i = P->tope; i!= NULL; i = i->siguiente){
		printf("------------------------------------------------- \n");
		printf("Fecha: %s \n", i->fecha);
		printf("Asignacion: %s \n", i->asignacion);
		printf("Hora de inicio: %s \n", i->horaInicio);
		printf("Hora de finalizacion: %s\n", i->horaFinal);
		printf("Recurso: %s \n", i->recurso);
		printf("-------------------------------------------------\n");
		printf(" \n");
	}
	printf("\n");

}

void clear(Pila *P)
{
	Nodo *n, *aux;
	if(P->tope == NULL)
		return;
	if(P->tope->siguiente == NULL)
		return;		
	n = P->tope;
	
	while(n != NULL)
	{
		aux = n;
		n = n->siguiente;
		free(aux);
	}
	
}

int isEmpty(Pila *P)
{
	if(P->tope == NULL)
		return 1;
	else
		return 0;
}
