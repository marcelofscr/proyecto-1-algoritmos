#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestionMiembros.h"
#include "GestionAsignaciones.h"

int main(){
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
	
	char cedulaConsulta[8];
	
	char fecha[15];
	char prioridad[20];
	char horaInicio[10];
	char horaFinal[10];
	char recurso[30];
	
	Pila *P;
	P = pilaNueva();

    int k, opc = 8, i = 0;
    p = getnodo();
    cabeza = p;
    //r=obtenerNodo();
    //head=r;
    while(opc  != 4){
    	printf("\t\t\nMENU PRINCIPAL\n\n\n");
    	printf ("\t\t\nOpciones\n\n\n");
    	printf("\t\t1. Registrar Nuevos Miembros\n");
    	printf("\t\t2. Consultar miembros del equipo\n");
    	printf("\t\t7. Crear una asignacion\n");
    	printf("\nDigite una opcion para continuar: ");
		scanf("%d", &opc);
    	switch(opc){
  			case 1: 
				printf("Ingrese el Nombre: ");
				scanf("%s", &nombre);
				printf("Ingrese el telefono: ");
				scanf("%s", &telefono);
				printf("Ingrese el correo: ");
				scanf("%s", &correo);
				printf("Ingrese el acceso: ");
				scanf("%s", &acceso);
				printf("Ingrese la cedula: ");
				scanf("%s", &cedula);

				
				i++;
				insafter(p, nombre, telefono, correo, acceso, cedula, i);
				break;
			
			case 2:
				printf("Ingrese la cedula que desea consultar: ");
				scanf("%s", &cedulaConsulta);
			
			case 7:
				printf("Ingrese la fecha en formato DD-MM-AAAA: ");
				scanf("%s", &fecha);
				printf("Ingrese la prioridad de la asignacion: ");
				scanf("%s", &prioridad);
				printf("Ingrese la hora de inicio: ");
				scanf("%s", &horaInicio);
				printf("Ingrese la hora de finalizacion: ");
				scanf("%s", &horaFinal);
				printf("Ingrese el recurso asociado con la asignacion: ");
				scanf("%s", &recurso);
				
				//push(P, fecha, prioridad, horaInicio, horaFinal, recurso);
				push(P, fecha, prioridad, horaInicio, horaFinal, recurso);
				
				printf("\nAsignacion creada:\n");
				top(P);
				
		}
	}
    return 0;
}

