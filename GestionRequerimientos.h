//Marcelo Fernández Solano
//Steven Vega Zuñiga
//TEC-Requerimientos
/* Descripción: TEC-Requerimientos es una solucion computacional creada con el fin de gestionar los miembros y 
				requerimientos de un proyecto, asi mismo permite la creacion de asignaciones asiciadas con un 
				miembro y un recurso, y el registro de incidentes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

<<<<<<< HEAD
struct nodoRequerimientos{
    int corre;
    char identificador[10];
    char evaluacion[60];
	char tipo [10];
	char descripcion[100];
	char riesgo[20];
	char dependencia[100];
	char recursos[70];
	char estado[60];
	char esfuerzo[6];
    struct nodo *sig;
};


typedef struct nodoRequerimientos *ListaRequerimientos;
ListaRequerimientos R, cabezaR;
ListaRequerimientos getnodoRequerimientos();

int buscarIndentificador(char identificador[10]);
void agregarRequerimiento(ListaRequerimientos R, char identificador[10], char evaluacion[60], char tipo[10], char descripcion [100], char riesgo [20], char dependencia [100], char recursos [70], char estado [60], char esfuerzo [6], int i);
void consultarRequerimiento(char requerimientoConsulta[10]);
void calificarRequerimiento(char requerimientoPorCalificar[10], char calificacionRequerimiento[10]);

ListaRequerimientos getnodoRequerimientos(){
    ListaRequerimientos R;
    R = (ListaRequerimientos)malloc(sizeof(struct nodoRequerimientos));
    if(R == NULL){
		printf("Memoria Insuficiente\a\n");
 	}
    return R;
}

int buscarIdentificador(char identificador[10]){
	
	int resultado = 0;
	
	FILE *fp;
	fp = fopen("listaRequerimientos.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		
		char *token;
		
		token = strtok(line, ",");
		
		if(strcmp(token, identificador) == 0){
			resultado++;
		}
	}
	return resultado;
}

void agregarRequerimiento(ListaRequerimientos R, char identificador[10], char evaluacion[60], char tipo[10], char descripcion[100], char riesgo[20], char dependencia[100], char recursos[70], char estado[60], char esfuerzo[6], int i){
	ListaRequerimientos C;

	if(C == NULL) //En caso de p vacia
    	printf("ERROR, lista vacia\n\a");
	else{
		C = getnodoRequerimientos();
		
		strcpy(C->identificador, identificador);
		strcpy(C->evaluacion, evaluacion);
		strcpy(C->tipo, tipo);
		strcpy(C->descripcion, descripcion);
		strcpy(C->riesgo, riesgo);
		strcpy(C->dependencia, dependencia);
		strcpy(C->recursos, recursos);
		strcpy(C->estado, estado);
		strcpy(C->esfuerzo, esfuerzo);
		
		// Persistencia de datos de nuevo miembro en listaRequerimientos.csv
		FILE *fp;
		fp = fopen("listaRequerimientos.csv", "a");
		
		if(fp == NULL){ //En caso de no exixtir el archivo listaMiembros.csv
			printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
		}
		
		else{
			fprintf(fp, "%s, %s, %s, %s, %s, %s, %s, %s, %s\n", C->identificador, C->evaluacion, C->tipo, C->descripcion, C->riesgo, C->dependencia, C->recursos, C->estado, C->esfuerzo);
=======
struct requerimientos{
    int corre;
  	char requisito [60]; //Elementos de consulta al usuario para agregar requerimientos
	char tipo [10];
	char descripcion [100];
	char riesgo [20];
	char dependencia [100];
	char recursos [70];
	char estado [60];
	char esfuerzo [6];
    struct requerimientos *sig;
};
typedef struct requerimientos *ListaRequerimientos;
ListaRequerimientos reque, cabezareque;
ListaRequerimientos getnodoRequerimientos();

void insertarReque(ListaRequerimientos reque, char requisito [60],char tipo [10], char descripcion [100],char riesgo [20],char dependencia [100],char recursos [70],char estado [60],char esfuerzo [6], int ii);
void eliminar (ListaRequerimientos reque, int k);
void imprimir(ListaRequerimientos reque);
void buscarRequerimientoporFecha (char consultaRequerimiento[10])

ListaRequerimientos getnodoRequerimientos(){
    ListaRequerimientos reque;
    reque = (ListaRequerimientos)malloc(sizeof(struct requerimientos));
    if(reque == NULL){
		printf("Memoria Insuficiente\a\n");
 	}
    return reque;
}

void insertarReque(ListaRequerimientos reque,char requisito [60],char tipo [10], char descripcion [100],char riesgo [20],char dependencia [100],char recursos [70],char estado [60],char esfuerzo [6],int ii){
   ListaRequerimientos q2;

	if(reque == NULL)
    	printf("ERROR, lista vacia\n\a");
	else{
		reque = getnodoRequerimientos();
		strcpy(q2->requisito,requisito);
		strcpy(q2->tipo,tipo);
		strcpy(q2->descripcion,descripcion);
		strcpy(q2->riesgo,riesgo);
		strcpy(q2->dependencia,dependencia);
		strcpy(q2->recursos,recursos);
		strcpy(q2->estado,estado);
		strcpy(q2->esfuerzo,esfuerzo);
		q2->corre = ii;
		reque->sig = reque->sig;
		reque->sig = q2;
		reque = reque->sig;
	}
}

void imprimir(ListaRequerimientos reque)
{	
   ListaRequerimientos dir;
   reque = reque->sig;
   for(dir = reque; dir != NULL; dir = dir->sig){
       printf("\n\t***********************************\n");
       printf("\t Descripcion requisito : %s \n", dir->requisito);
       printf("\t Descripcion requisito : %s \n", dir->tipo);
	   printf("\t Descripcion requisito : %s \n", dir->descripcion);
       printf("\t Riesgo : %s \n", dir->riesgo);
       printf("\t Dependendencia : %s \n", dir->dependencia);
       printf("\t Recursos : %s \n", dir->recursos);
       printf("\t Estado : %s \n", dir->estado);
       printf("\t Estado : %s \n", dir->esfuerzo);
       printf("\n\t***********************************\n");
       getch();
   }

}
void eliminar(ListaRequerimientos reque, int q2){
    ListaRequerimientos indice;
    cabezareque = reque;

    for(indice = cabezareque; indice != NULL; indice = indice->sig){
		if(indice->corre == q2 ){
    		cabezareque = cabezareque->sig;
    		printf("%s esta  siendo eliminado\n", indice->requisito,indice->tipo,indice->descripcion,indice->riesgo,indice->dependencia,indice->recursos,indice->estado,indice->esfuerzo);
    		getch();

    	if(reque == NULL || reque->sig == NULL)
     		printf("ERROR, ya no hay mas datos\n");
    	else{
    		cabezareque->sig = indice->sig;
    		free(indice);
			}
 		}
    }
     getch();
 }
 void agregarReque(){
 	reque = getnodoRequerimientos();
    			cabezareque = reque;
    			int k,ch,ii=0;
    			char requisito [60]; //Elementos de consula al usuario para agregar requerimientos
				char tipo [10];
				char descripcion [100];
				char riesgo [20];
				char dependencia [100];
				char recursos [70];
				char estado [60];
				char esfuerzo [6];
				printf("\n\nAGREGAR REQUERIMIENTO\n\n");
				printf("Ingrese el requisito: ");
				scanf("%s", &requisito);
				printf("Ingrese el tipo: ");
				scanf("%s", &tipo);
				printf("Ingrese la descripcion: ");
				scanf("%s", &descripcion);
				printf("Ingrese el riesgo asociado ");
				scanf("%s", &riesgo);
				printf("Ingrese la dependencia: ");
				scanf("%s", &dependencia);
				printf("Ingrese el recurso: ");
				scanf("%s", &recursos);
				printf("Ingrese el estado del requerimiento: ");
				scanf("%s", &estado);
				printf("Ingrese el esfuerzo: ");
				scanf("%s", &esfuerzo);
				ii++;
				insertarReque (reque,requisito,tipo,descripcion,riesgo,dependencia,recursos,estado,esfuerzo,ii);
 }
void agregarRequerimiento(ListaRequerimientos reque,char requisito [60],char tipo [10], char descripcion [100],char riesgo [20],char dependencia [100],char recursos [70],char estado [60],char esfuerzo [6],int ii){
	ListaRequerimientos q2;

	if(q2 == NULL) //En caso de p vacia
    	printf("ERROR, lista vacia\n\a");
	else{
		q2 = getnodoRequerimientos();
		strcpy(q2->requisito,requisito);
		strcpy(q2->tipo,tipo);
		strcpy(q2->descripcion,descripcion);
		strcpy(q2->riesgo,riesgo);
		strcpy(q2->dependencia,dependencia);
		strcpy(q2->recursos,recursos);
		strcpy(q2->estado,estado);
		strcpy(q2->esfuerzo,esfuerzo);
		
		// Persistencia de datos de nuevo miembro en listaMiembros.csv
		FILE *fp;
		fp = fopen("listaIncidentes.csv", "a");
		
		if(fp == NULL){ //En caso de no existir el archivo listaMiembros.csv
			printf("El archivo no existe, por lo cual no se procedio al guardado en memoria\n");
		}
		
		else{
			fprintf(fp, "%s, %s, %s, %s\n", q2->requisito, q2->tipo,q2->descripcion,q2->riesgo,q2->dependencia,q2->recursos, q2->estado, q2->esfuerzo);
>>>>>>> c0bb511243fb5958d1367d054b4c250b6f6c9bfe
		
			fclose(fp); //cierra el archivo y finaliza el guardado en memoria
			fp = 0;
			
<<<<<<< HEAD
			printf("\nMiembro ingresado exitosamente\n");
		}
		
		//C->corre = i;
		//C->sig = R->sig;
		//R->sig = C;
		//C = C->sig;
	}
}

char requerimientoConsulta[8];

void consultarRequerimiento(char requerimientoConsulta[10]){
=======
			printf("\nIncidente reportado exitosamente");
		}
		

}

// Consultar requerimiento ya creado

void buscarRequerimientoporFecha (char consultaRequerimiento[10])
{
>>>>>>> c0bb511243fb5958d1367d054b4c250b6f6c9bfe
	
	int requerimientosEncontrados = 0;
	
	FILE *fp;
	fp = fopen("listaRequerimientos.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		
		char *token;
		
		token = strtok(line, ",");
		
<<<<<<< HEAD
		if(strcmp(token,requerimientoConsulta) == 0){
=======
		if(strcmp(token, consultaRequerimiento) == 0){
>>>>>>> c0bb511243fb5958d1367d054b4c250b6f6c9bfe
		
			while(token != NULL){
				printf("%12s", token);
				token = strtok(NULL, ",");
			}
			requerimientosEncontrados++;
			printf("\n");
		}
	}
	
	if(requerimientosEncontrados == 0){
<<<<<<< HEAD
		printf("Lo sentimos, el codigo que ingreso no se encuentra registrada\n\n");
=======
		printf("Lo sentimos, el codigo del requerimiento que ingreso no registra incidentes asociados\n\n");
	}
	
}

void buscarRequerimientoPorFecha(char consultaFechaReque[100]){
	
	int requerimientosEncontrados = 0;
	
	FILE *fp;
	fp = fopen("listaRequerimientos.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		while(fgets(line, sizeof(line), fp)){
			
			char *token;
			
			token = strtok(line, ",");
			
			if(strcmp(token, consultaFechaReque) == 0){
				
				token = strtok(NULL, ",");
				
				while(token != NULL){
					printf("%12s", token);
					token = strtok(NULL, ",");
				}
				requerimientosEncontrados++;
				printf("\n");
			}
		}
	}
	
	if(requerimientosEncontrados == 0){
		printf("Lo sentimos, la fecha que ingreso no presenta incidentes registrados\n\n");
>>>>>>> c0bb511243fb5958d1367d054b4c250b6f6c9bfe
	}
}


