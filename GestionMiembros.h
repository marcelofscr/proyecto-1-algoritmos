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

struct nodo{
    int corre;
    char cedula [10];
    char nombre[50];
    char apellido[50];
    char telefono[10];
    char correo[50];
    char acceso [4];
    struct nodo *sig;
};


typedef struct nodo *Lista;
Lista p, cabeza;
Lista getnodo();

int buscarCedula(char cedula[10]);
void agregarMiembro(Lista p,char cedula[10], char nombre[50], char apellido[50], char telefono[10], char correo[50], char acceso [4], int i);
void consultarMiembro(char cedulaConsulta[8]);

Lista getnodo(){
    Lista p;
    p = (Lista)malloc(sizeof(struct nodo));
    if(p == NULL){
		printf("Memoria Insuficiente\a\n");
 	}
    return p;
}

int buscarCedula(char cedula[10]){
	
	int resultado = 0;
	
	FILE *fp;
	fp = fopen("listaMiembros.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		
		char *token;
		
		token = strtok(line, ",");
		
		if(strcmp(token, cedula) == 0){
			resultado++;
		}
	}
	return resultado;
}

void agregarMiembro(Lista p, char cedula [10], char nombre[50], char  apellido[50], char telefono[10], char correo[50], char acceso [4], int i){
	Lista q;

	if(p == NULL) //En caso de p vacia
    	printf("ERROR, lista vacia\n\a");
	else{
		q = getnodo();
		strcpy(q->cedula, cedula);
		strcpy(q->nombre, nombre);
		strcpy(q->apellido, apellido);
		strcpy(q->telefono, telefono);
		strcpy(q->correo, correo);
		strcpy(q->acceso, acceso);
		
		// Persistencia de datos de nuevo miembro en listaMiembros.csv
		FILE *fp;
		fp = fopen("listaMiembros.csv", "a");
		
		if(fp == NULL){ //En caso de no exixtir el archivo listaMiembros.csv
			printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
		}
		
		else{
			fprintf(fp, "%s, %s, %s, %s, %s, %s\n", q->cedula, q->nombre, q->apellido, q->telefono, q->correo, q->acceso);
		
			fclose(fp); //cierra el archivo y finaliza el guardado en memoria
			fp = 0;
			
			printf("\nMiembro ingresado exitosamente\n");
		}
		
		q->corre = i;
		q->sig = p->sig;
		p->sig = q;
		p = p->sig;
	}
}

char cedulaConsulta[8];

void consultarMiembro(char cedulaConsulta[10]){
	
	int miembrosEncontrados = 0;
	
	FILE *fp;
	fp = fopen("listaMiembros.csv", "r");
	
	if(fp == NULL){
		printf("Error al cargar el archivo, intente verificar si el archivo existe o permanece abierto\n");
	}
	
	char line[998];
	
	while(fgets(line, sizeof(line), fp)){
		
		char *token;
		
		token = strtok(line, ",");
		
		if(strcmp(token,cedulaConsulta) == 0){
		
			while(token != NULL){
				printf("%12s", token);
				token = strtok(NULL, ",");
			}
			miembrosEncontrados++;
			printf("\n");
		}
	}
	
	if(miembrosEncontrados == 0){
		printf("Lo sentimos, la cedula que ingreso no se encuentra registrada\n\n");
	}
}

