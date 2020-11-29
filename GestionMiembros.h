#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo{
    int corre;
    char nombre[80];
    char telefono[10];
    char correo[50];
    char acceso [4];
    char cedula [8];
    struct nodo *sig;
};


typedef struct nodo *Lista;
Lista p, cabeza;
Lista getnodo();

/*typedef struct servicio *Lista1;
Lista1 r, head;
Lista1 obtenernodo();*/

void insafter(Lista p, char nombre[80], char telefono[10], char correo[50], char acceso [4],char cedula [8], int i);
//void insertar(Lista1 reque,char requisito [60],char tipo [10],char descripcion [100],char riesgo [20],char dependencia [100], int j);


Lista getnodo(){
    Lista p;
    p = (Lista)malloc(sizeof(struct nodo));
    if(p == NULL){
		printf("Memoria Insuficiente\a\n");
 	}
    return p;
}

void insafter(Lista p, char nombre[80], char telefono[10], char correo[50], char acceso [4],char cedula [8], int i){
   Lista q;

	if(p == NULL)
    	printf("ERROR, lista vacia\n\a");
	else{
		q = getnodo();
		strcpy(q->nombre, nombre);
		strcpy(q->telefono, telefono);
		strcpy(q->correo, correo);
		strcpy(q->acceso, acceso);
		strcpy(q->cedula,cedula);
		q->corre = i;
		q->sig = p->sig;
		p->sig = q;
		p = p->sig;
	}
}

