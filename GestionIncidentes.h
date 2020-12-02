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

struct nodo_{
    int corre;
    char codigoRequerimiento[10]; 
	char codigoAsignacion[10];
	char descripcionIncidente[90];
	char fechaActual[100];
    struct nodo *sig;
};


typedef struct nodo_ *Lista_;
Lista_ k, head;
Lista_ getnodo_();

void agregarIncidente(Lista_ k, char codigoRequerimiento[10], char codigoAsignacion[10], char descripcionIncidente[90], char fechaActual[100], int i);
void buscarIncidentePorRequerimiento(char consultaRequerimiento[10]);
void buscarIncidentePorFecha(char consultaFecha[100]);

//Agregar incidentes nuevos

Lista_ getnodo_(){
    Lista_ k;
    k = (Lista_)malloc(sizeof(struct nodo_));
    if(k == NULL){
		printf("Memoria Insuficiente\a\n");
 	}
    return k;
}

void agregarIncidente(Lista_ k, char codigoRequerimiento[10], char codigoAsignacion[10], char descripcionIncidente[90], char fechaActual[100], int i){
	Lista_ z;

	if(k == NULL) //En caso de p vacia
    	printf("ERROR, lista vacia\n\a");
	else{
		k = getnodo_();
		strcpy(k->codigoRequerimiento, codigoRequerimiento);
		strcpy(k->codigoAsignacion, codigoAsignacion);
		strcpy(k->descripcionIncidente, descripcionIncidente);
		strcpy(k->fechaActual, fechaActual);
		
		// Persistencia de datos de nuevo miembro en listaMiembros.csv
		FILE *fp;
		fp = fopen("listaIncidentes.csv", "a");
		
		if(fp == NULL){ //En caso de no exixtir el archivo listaMiembros.csv
			printf("El archivo no existe, por lo cual no se procedio al guardado en memoria\n");
		}
		
		else{
			fprintf(fp, "%s, %s, %s, %s\n", k->codigoRequerimiento, k->codigoAsignacion, k->descripcionIncidente, k->fechaActual);
		
			fclose(fp); //cierra el archivo y finaliza el guardado en memoria
			fp = 0;
			
			printf("\nIncidente reportado exitosamente");
		}
		
		//z->corre = i;
		//z->sig = k->sig;
		//k->sig = z;
		//k = k->sig;
	}
}

// Consultar incidentes ya existentes

void buscarIncidentePorRequerimiento(char consultaRequerimiento[10]){
	
	int incidentesEncontrados = 0;
	
	FILE *fp;
	fp = fopen("listaIncidentes.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		
		char *token;
		
		token = strtok(line, ",");
		
		if(strcmp(token, consultaRequerimiento) == 0){
		
			while(token != NULL){
				printf("%12s", token);
				token = strtok(NULL, ",");
			}
			incidentesEncontrados++;
			printf("\n");
		}
	}
	
	if(incidentesEncontrados == 0){
		printf("Lo sentimos, el codigo del requerimiento que ingreso no registra incidentes asociados\n\n");
	}
	
}

void buscarIncidentePorFecha(char consultaFecha[100]){
	
	int incidentesEncontrados = 0;
	
	FILE *fp;
	fp = fopen("listaIncidentes.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		while(fgets(line, sizeof(line), fp)){
			
			char *token;
			
			token = strtok(line, ",");
			
			if(strcmp(token, consultaFecha) == 0){
				
				token = strtok(NULL, ",");
				
				while(token != NULL){
					printf("%12s", token);
					token = strtok(NULL, ",");
				}
				incidentesEncontrados++;
				printf("\n");
			}
		}
	}
	
	if(incidentesEncontrados == 0){
		printf("Lo sentimos, la fecha que ingreso no presenta incidentes registrados\n\n");
	}
	
}

