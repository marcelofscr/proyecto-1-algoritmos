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
    char requisito [60];
	char tipo [10];
	char descripcion [100];
	char riesgo [20];
	char dependencia [100];
	char recursos [70];
	char estado [60];
    char esfuerzo [6];
    struct nodo *sig;
};

/*struct servicio{
	int registro;
	char requisito [60];
	char tipo [10];
	char descripcion [100];
	char riesgo [20];
	char dependencia [100];
	char recursos [70];
	char estado [60];
	int esfuerzo;	
	struct servicio *next;
};*/

typedef struct nodo *Lista;
Lista p, cabeza;
Lista getnodo();

/*typedef struct servicio *Lista1;
Lista1 r, head;
Lista1 obtenernodo();*/

void insafter(Lista p, char nombre[80], char telefono[10], char correo[50], char acceso [4],char cedula [8],char requisito [60],char tipo [10], char descripcion [100],char riesgo [20],
				char dependencia [100],char recursos [70],char estado [60],char esfuerzo [6], int i);
//void insertar(Lista1 reque,char requisito [60],char tipo [10],char descripcion [100],char riesgo [20],char dependencia [100], int j);
void eliminar (Lista p, int k);
void imprimir(Lista p);
main(){
    char nombre[80];
    char telefono[10];
    char correo[50];
    char acceso[10];
    char cedula [8];
	char requisito [60];
	char tipo [10];
	char descripcion [100];
	char riesgo [20];
	char dependencia [100];
	char recursos [70];
	char estado [60];
	char esfuerzo [6];

    int k, opc = 8, i = 0;
    p = getnodo();
    cabeza = p;
    //r=obtenerNodo();
    //head=r;
    while(opc!=4){
    	printf("\t\t\nMENU PRINCIPAL\n\n\n");
    	printf ("\t\t\nDigite una opcion para continuar\n\n\n");
    	printf("\t\t1. Registrar Nuevos Datos\n");
    	printf("\t\t2. Imprime todos los registros\n");
    	printf("\t\t3. Eliminar Datos\n");
    	printf("\t\t4. Salir\n");
    	scanf("%d", &opc);
    	switch(opc){
  			case 1: 
				printf("Ingrese el Nombre:");
				scanf("%s", &nombre);
				printf("Ingrese el telefono:");
				scanf("%s", &telefono);
				printf("Ingrese el correo:");
				scanf("%s", &correo);
				printf ("Ingrese el Requisito: ");
				scanf ("%s", &requisito);
				printf ("Ingrese el nivel de acceso: ");
				scanf ("%s", &acceso);
				printf ("Ingrese el tipo: ");
				scanf ("%s", &tipo);
				printf ("Ingrese la descripcion: ");
				scanf ("%s", &descripcion);
				printf ("Ingrese el riesgo: ");
				scanf ("%s", &riesgo);
				printf ("Ingrese la dependencia: ");
				scanf ("%s", &dependencia);
				printf ("Ingrese los recursos: ");
				scanf ("%s", &recursos);
				printf ("Ingrese el estado: ");
				scanf ("%s", &estado);
				printf ("Ingrese el esfuerzo: ");
				scanf ("%s", &esfuerzo);
				
				i++;
				insafter(p, nombre, telefono, correo, acceso,cedula,requisito,tipo,descripcion,riesgo,dependencia,recursos,estado,esfuerzo,i);
				break;
  			case 2:
				printf("Listado de todos los registros\n\n");
				imprimir(p);
				break;
			case 3:
				printf("¨A quien desea eliminar? (ingrese el numero de registro)\n");
				scanf("%d", &k);
				eliminar(p, k);
				break;
		}
	}
    return 0;
}

Lista getnodo(){
    Lista p;
    p = (Lista)malloc(sizeof(struct nodo));
    if(p == NULL){
		printf("Memoria Insuficiente\a\n");
 	}
    return p;
}

void insafter(Lista p, char nombre[80], char telefono[10], char correo[50], char acceso [4],char cedula [8],char requisito [60],char tipo [10], char descripcion [100],char riesgo [20],
				char dependencia [100],char recursos [70],char estado [60],char esfuerzo [6],int i){
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
		strcpy(q->requisito,requisito);
		strcpy(q->tipo,tipo);
		strcpy(q->descripcion,descripcion);
		strcpy(q->riesgo,riesgo);
		strcpy(q->dependencia,dependencia);
		strcpy(q->recursos,recursos);
		strcpy(q->estado,estado);
		strcpy(q->esfuerzo,esfuerzo);
		q->corre = i;
		q->sig = p->sig;
		p->sig = q;
		p = p->sig;
	}
}
/*Lista1 obtenerNodo()
{
    Lista1 r;
    r=(Lista1)malloc(sizeof(struct servicio));
    if(r==NULL)
 printf("Memoria Insuficiente\a\n");
    return r;
}
void insertar(Lista1 r ,char requisito [60],char tipo [10],char descripcion [100],char riesgo [20],char dependencia [100], int j)
{
   Lista1 a;

   if(r==NULL)
       printf("ERROR, lista vacia\n\a");
   else
   {
 a=obtenerNodo();
 strcpy(a->requisito, requisito);
 strcpy(a->tipo, tipo);
 strcpy(a->descripcion, descripcion);
 strcpy(a->riesgo, riesgo);
 strcpy(a->dependencia, dependencia);
 a->registro=j;
 a->next=r->next;
 r->next=a;
 r=r->next;
   }
}*/
void imprimir(Lista p)
{
   Lista dir;
   p = p->sig;
   for(dir = p; dir != NULL; dir = dir->sig){
       printf("\n\t***********************************\n");
       printf("\t Registro #%d \n", dir->corre);
       printf("\t Nombre %s \n", dir->nombre);
       printf("\t Telefono: %s \n", dir->telefono);
       printf("\t Correo: %s \n", dir->correo);
       printf("\t Cedula: %s \n", dir->cedula);
       printf("\t Descripcion requisito : %s \n", dir->requisito);
       printf("\t Riesgo : %s \n", dir->riesgo);
       printf("\t Dependendencia : %s \n", dir->dependencia);
       printf("\t Recursos : %s \n", dir->recursos);
       printf("\t Estado : %s \n", dir->estado);
       printf("\t Estado : %s \n", dir->esfuerzo);
       printf("\n\t***********************************\n");
       getch();
   }

}
void eliminar(Lista p, int k){
    Lista indice;
    cabeza = p;

    for(indice = cabeza; indice != NULL; indice = indice->sig){
		if(indice->corre == k ){
    		cabeza = cabeza->sig;
    		printf("%s esta  siendo eliminado\n", indice->nombre);
    		getch();

    	if(p == NULL || p->sig == NULL)
     		printf("ERROR, ya no hay mas datos\n");
    	else{
    		cabeza->sig = indice->sig;
    		free(indice);
			}
 		}
    }
}
