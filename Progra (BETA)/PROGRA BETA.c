#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define DATA_SIZE 1000
// Estructuras a utilizar del proyecto //

struct node{
    char dia[20];
    int horaInicio;
	int minutoInicio;
	int horaFin;
	int minutoFin;
	int priority;
    struct node *next;
};

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


// ***************************************************************** COLA PRIORIDAD CREAR ASIGNACION***************************************************************** //
struct node* head = NULL;
struct node* tail = NULL;
struct node* temp;

char dia[20];
int horaInicio;
int minutoInicio;
int horaFin;
int minutoFin;
int pri;
char priority[10];

struct node* crearAsignacion(char dia[], int horaInicio,int minutoInicio, int horaFin,int minutoFin,int priority)
{
    struct node* nuevaAsignacion = (struct node*)malloc(sizeof(struct node));
    strcpy(nuevaAsignacion->dia, dia);
    nuevaAsignacion->horaInicio = horaInicio;
    nuevaAsignacion->minutoInicio = minutoInicio;
    nuevaAsignacion->horaFin = horaFin;
    nuevaAsignacion->minutoFin = minutoFin;
    nuevaAsignacion->priority = priority;
    nuevaAsignacion->next = NULL;

    return nuevaAsignacion;
};

void enQueueAsignacion(char dia[], int horaInicio,int minutoInicio, int horaFin,int minutoFin,int priority)
{
    struct node* asignacion = crearAsignacion(dia, horaInicio, minutoInicio, horaFin, minutoFin, priority);
    //if we have no node, we create head and tail node here
    if(head == NULL && tail == NULL)
    {
        head = asignacion;
        tail = asignacion;
    }
    else
    {
        //if new person priority equal or smaller than head node, we should make it first node
        if(asignacion->priority <= head->priority)
        {
            temp = head;
            head = asignacion;
            asignacion->next = temp;
            return;
        }
        //if new persons priority is equal or bigger than tail node, we should make it tail.
        if(asignacion->priority >= tail->priority)
        {
            tail->next = asignacion;
            tail = asignacion;
        }

        //this is general algoritm for priority queues
        temp = head;
        while(temp->next != NULL)
        {
            if(asignacion->priority < temp->next->priority)
            {
                struct node* newy;
                newy = temp->next;
                temp->next = asignacion;
                asignacion->next = newy;
            }
            temp = temp->next;
        }
    }
}

void deQueue()
{
    temp = head;
    if(head == NULL)
    {
        printf("\nQueue is empty, pls Enqueue");
        return;
    }

    if(head == tail)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    head = temp->next;
    free(temp);
}

struct node* whoNext()
{
    if(head == NULL)
    {
        printf("\nThere is no item in queue...");
        return 0;
    }

    return head;
}

void checkPri(int x)
{

    if(x == 1)
            strcpy(priority, "Alta");
        else if(x == 2)
            strcpy(priority, "Normal");
        else
            strcpy(priority, "Baja");
}
void printQueue()
{

    int i = 1;
    if(head == NULL)
    {
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        checkPri(temp->priority);
        printf("\n%d. Position => %s %s %d priority ==> %s ", i,temp->dia, temp->horaInicio,temp->minutoInicio,temp->horaFin, temp->minutoFin, priority);
        temp = temp->next;
        i++;
    }
    checkPri(temp->priority);
    printf("\n%d. Position => %s %s %d priority ==> %s ", i, temp->dia, temp->horaInicio,temp->minutoInicio,temp->horaFin, temp->minutoFin, priority);
}
void agregaCola(void){
	
			printf("\n Ingrese el dia ... ");
            scanf("%s", &dia);
            printf("\n Ingrese la hora de inicio ... ");
            scanf("%d", &horaInicio);
            printf("\n Ingrese el minuto de inicio ... ");
            scanf("%d", &minutoInicio);
            printf("\n Ingrese la hora de finalizacion ... ");
            scanf("%d", &horaFin);
            printf("\n Ingrese el minuto de finalizacion ... ");
            scanf("%d", &minutoFin);
            printf("\n Digite el nivel de prioridad... (1 es Alto | 2 es Normal | 3 es Bajo) ");
            scanf("%d", &pri);
            enQueueAsignacion(dia, horaInicio,minutoInicio, horaFin, minutoFin, pri);
            //printQueue();
           
}
// ***************************************************************** LISTA ENLAZADA ***************************************************************** //

typedef struct nodo *Lista;
Lista p, cabeza;
Lista getnodo();

void insafter(Lista p, char nombre[80], char telefono[10], char correo[50], char acceso [4],char cedula [8],char requisito [60],char tipo [10], char descripcion [100],char riesgo [20],
				char dependencia [100],char recursos [70],char estado [60],char esfuerzo [6], int i);
void eliminar (Lista p, int k);
void imprimir(Lista p);

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
    		printf("%s esta  siendo eliminado\n", indice->nombre, indice->cedula,indice->acceso,indice->correo,indice->dependencia,indice->descripcion,
					indice->esfuerzo,indice->estado,indice->recursos,indice->requisito,indice->riesgo,indice->telefono,indice->tipo);
    		getch();

    	if(p == NULL || p->sig == NULL)
     		printf("ERROR, ya no hay mas datos\n");
    	else{
    		cabeza->sig = indice->sig;
    		free(indice);
			}
 		}
    }
     getch();
}
void agregaEnlazada(){
	int k,ch, opc = 8, i = 0;
    p = getnodo();
    cabeza = p;
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
	
  
    		
    printf("Ingrese el Nombre:");
	scanf("%s", &nombre);
	printf("Ingrese el telefono:");
	scanf("%s", &telefono);
	printf("Ingrese el correo:");
	scanf("%s", &correo);
	printf("Ingrese la cedula:");
	scanf("%s", &cedula);
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
	insafter(p,nombre,telefono,correo,acceso,cedula,requisito,tipo,descripcion,riesgo,dependencia,recursos,estado,esfuerzo, i);
	//imprimir(p);
	
}
void borraEnlazada(){
	int k, opc = 8, i = 0;
    p = getnodo();
    cabeza = p;
	printf("¨A quien desea eliminar? (ingrese el numero de registro)\n");
	scanf("%d", &k);
	eliminar(p, k);
	printf ("El registro %d, ha sido eliminado satisfactoriamente", &k);
}
//****************************************************************** CREACION TXT ******************************************************************* //
void txt()
{
     /* Variable to store user content */
    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */
    FILE * fPtr;


    /* 
     * Open file in w (write) mode. 
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("data/pepe.txt", "a+");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Error al crear el archivo.\n");
        exit(EXIT_FAILURE);
    }


    /* Input contents from user to store in file */
    printf("Digite el dato a guardar : \n");
    fgets(data, DATA_SIZE, stdin);


    /* Write data to file */
    fputs(data, fPtr);


    /* Close file to save file data */
    fclose(fPtr);


    /* Success message */
    printf("Elemento creado satisfactoriamente. :) \n");


    //return 0;
}

// ***************************************************************** MENU PRINCIPAL ***************************************************************** //
void menu()
{
	int choise;
    //while( 1 == 1 )
    do
    {
    	printf ("\n BIENVENIDO");
        printf("\n 1- Encolar ... ");
        printf("\n 2- Sacar de cola ... ");
        printf("\n 3- Qué sigue ? ");
        printf("\n 4- Insertar ");
        printf ("\n 5- A quien desea borrar?");
        printf ("\n 6- Salir");
        printf ("\n 7- imprimir registro");
        printf ("\n 8- imprimir registro de cola");
        
        printf("\n Elija correctamente ");  
        scanf("%d", &choise);
        switch(choise){
    {
        case 1:
            agregaCola();
            break;
        case 2:
            deQueue();
            printQueue();
            break;
        case 3:
            temp = whoNext();
            printf("\n ****************** \n");
            if(temp != NULL)
            {
                printf("%s %d %d %d %d", temp->dia,temp->horaInicio, temp->minutoInicio, temp->horaFin, temp->minutoFin);
            }
            break;
        case 4:;
        	agregaEnlazada();
			break;
		case 5:;
			borraEnlazada();
			break;
		case 7:;
			imprimir(p);
			break;
		case 8:
			printQueue();
        	
    }
		}
        
    
    }while (choise!= 6);
}


/*void selection(int chosen)
{
    
}*/

int main()
{
	
    menu();
    return 0;
}
