//Marcelo Fernández Solano
//Steven Vega Zuñiga
//TEC-Requerimientos
/* Descripción: TEC-Requerimientos es una solucion computacional creada con el fin de gestionar los miembros y 
				requerimientos de un proyecto, asi mismo permite la creacion de asignaciones asiciadas con un 
				miembro y un recurso, y el registro de incidentes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
		
			fclose(fp); //cierra el archivo y finaliza el guardado en memoria
			fp = 0;
			
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
		
		if(strcmp(token,requerimientoConsulta) == 0){
		
			while(token != NULL){
				printf("%12s", token);
				token = strtok(NULL, ",");
			}
			requerimientosEncontrados++;
			printf("\n");
		}
	}
	
	if(requerimientosEncontrados == 0){
		printf("Lo sentimos, el codigo que ingreso no se encuentra registrada\n\n");
	}
}


