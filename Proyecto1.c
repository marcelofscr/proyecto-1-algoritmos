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
#include <ctype.h>
#include "GestionMiembros.h"
#include "GestionRequerimientos.h"
//#include "GestionAsignaciones.h"
#include "GestionIncidentes.h"

int main(){
    char cedula [8];//Elementos de consula al usuario para registro de miembros
	char nombre[50]; 
    char apellido[50];
    char telefono[10];
    char correo[50];
    char acceso[10];
    
    int cedulaEncontrada; //Variable para determinar si una cedula de miembro ya fue registrada 
    char cedulaConsulta[8]; //Numero de cedula consultada al usuario para consultar miembros
	
	char identificador[10]; //Elementos de consula al usuario para agregar requerimientos
	char evaluacion[60] = "N/EVAL"; // Estado "No evaluado" al crear un nuevo requerimiento
	char tipo[10];
	char descripcion[100];
	char riesgo[20];
	char dependencia[100];
	char recursos[70];
	char estado[60] = "Activa"; //Estado del requerimiento por omision
	char esfuerzo [6];
	
	int requerimientoEncontrados; //Variable para determinar si un cidentificador de requerimiento ya fue registrado
	char requerimientoPorCalificar[10]; //Consulta identificador de requerimiento que desea calificar
	char calificacionRequerimiento[10]; //Consulta calificacion otorgada por usuario del requerimiento
	char requerimientoConsulta[8]; //Elementos de consula al usuario para consultar 
	
	char fecha[15]; //Elementos de consula al usuario para agregar asignaciones
	char prioridad[20];
	char horaInicio[10];
	char horaFinal[10];
	char recurso[30];
	
	char codigoRequerimiento[10]; //Elementos de consula al usuario para agregar incidentes
	char codigoAsignacion[10];
	char descripcionIncidente[90];
	
	int tipoBusquedaIncidente;
	char consultaRequerimiento[10]; //Elemento para consulta de incidentes por codigo requerimiento
	char consultaFecha[100]; //Elemento para consulta de incidentes por fecha
	
//	Pila *P;
//	P = pilaNueva();

    int r, opc = 8, i = 0;
    
    p = getnodo();
    cabeza = p;
    
    R = getnodoRequerimientos();
    cabezaR = R;
    
    k = getnodo_();
    head = k;
    //r=obtenerNodo();
    //head=r;
    while(opc  != 0){
    	printf("\t\t\nMENU PRINCIPAL\n\n\n");
    	printf ("\t\t\nOpciones\n\n\n");
    	printf("\t\t1. Registrar Nuevos Miembros\n");
    	printf("\t\t2. Consultar miembros del equipo\n");
    	printf("\t\t3. Agregar Requerimiento\n");
    	printf("\t\t4. Modificar datos de un requerimiento\n");
    	printf("\t\t5. Calificar Requerimiento\n");
    	printf("\t\t6. Consultar Requerimiento\n");
    	printf("\t\t7. Crear una asignacion\n");
    	printf("\t\t8. Consultar una asignacion\n");
    	printf("\t\t9. Cancelar una asignacion\n");
    	printf("\t\t10. Atencion asignaciones\n");
    	printf("\t\t11. Registrar Incidente \n");
    	printf("\t\t12. Consultar Incidente \n");
    	printf("\t\t13. Analisis de datos\n");
    	printf("\t\t0. Salir\n");
    	printf("\nDigite una opcion para continuar: ");
		scanf("%d", &opc);
    	
		switch(opc){
  			case 1: //Registrar nuevos miembros
				printf("\n\nREGISTRAR NUEVO MIEMBRO\n\n");
				printf("Ingrese la cedula: "); 
				scanf("%s", &cedula);
				printf("Ingrese el nombre: ");
				scanf("%s", &nombre);
				printf("Ingrese el primer apellido: ");
				scanf("%s", &apellido);
				printf("Ingrese el telefono: ");
				scanf("%s", &telefono);
				printf("Ingrese el correo: ");
				scanf("%s", &correo);
				printf("Ingrese el acceso: ");
				scanf("%s", &acceso);
				
				i++;
				
				cedulaEncontrada = buscarCedula(cedula); //Permite conocer si existen miembros ya registrados con cedula ingresada

				if(cedulaEncontrada == 0){
					agregarMiembro(p, cedula, nombre, apellido, telefono, correo, acceso, i);
				}
				else{
					printf("El miembro no se puede ingresar porque la cedula ya fue registrada anteriormente\n");
				}
				system("pause");
				system("cls");
				break;
			
			case 2: //Consulta miembro del equipo
				printf("\n\nCONSULTAR MIEMBRO DEL EQUIPO\n\n");
				printf("Ingrese la cedula que desea consultar (nueve numeros, sin espacios ni guiones): ");
				scanf("%s", &cedulaConsulta);
				printf("\n");
				
				consultarMiembro(cedulaConsulta);
				system("pause");
				system("cls");
				break;
				
			case 3:
				printf("\n\nAGREGAR REQUERIMIENTO\n\n");
<<<<<<< HEAD
				printf("Ingrese el identificador: "); 
				scanf("%s", &identificador);
				printf("Ingrese el tipo: "); 
				scanf("%s", &tipo);
				printf("Ingrese la descripcion: "); 
				scanf("%s", &descripcion);
				printf("Ingrese el riesgo: "); 
				scanf("%s", &riesgo);
				printf("Ingrese la dependencia: "); 
				scanf("%s", &dependencia);
				printf("Ingrese los recursos: "); 
				scanf("%s", &recursos);
				printf("Ingrese el esfuerzo: "); 
				scanf("%s", &esfuerzo);
				
				requerimientoEncontrados = buscarIdentificador(identificador);
				if(requerimientoEncontrados == 0){
					agregarRequerimiento(R, identificador, evaluacion, tipo, descripcion, riesgo, dependencia, recursos, estado, esfuerzo, i);
				}
				else{
					printf("El requerimiento no se puede ingresar porque el identificador ya fue registrado anteriormente\n");
				}
=======
				agregarReque();
>>>>>>> c0bb511243fb5958d1367d054b4c250b6f6c9bfe
				system("pause");
				system("cls");
				break;
				
			case 4:
				printf("\n\nMODIFICAR DATOS DE UN REQUERIMIENTO\n\n");
				printf("not ready\n");
				system("pause");
				system("cls");
				break;
				
			case 5:
				printf("\n\nCALIFICAR REQUERIMIENTO\n\n");
				printf("Ingrese la calificacion del requerimiento(1 a 100): ");
				scanf("%s", &calificacionRequerimiento);
				printf("Ingrese el identificador dek requerimiento que desea calificar (formato RQ-001): ");
				scanf("%s", &requerimientoPorCalificar);
				
				system("pause");
				system("cls");
				break;
				
			case 6:
				printf("\n\nCONSULTAR REQUERIMIENTO\n\n");
				printf("Ingrese el codigo del requerimiento que desea consultar (Formato RQ-001): ");
				scanf("%s", &requerimientoConsulta);
				
				consultarRequerimiento(requerimientoConsulta);
				system("pause");
				system("cls");
				break;
			
			case 7:
				printf("\n\nCREAR UNA ASIGNACION\n\n");
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
				
				/*push(P, fecha, prioridad, horaInicio, horaFinal, recurso);
				
				printf("\nAsignacion creada:\n");
				system("pause");
				system("cls");
				top(P);*/
				
			case 8:
				printf("\n\nCONSULTAR ASIGNACIONES PARA UN MIEMBRO DEL EQUIPO\n\n");
				printf("not ready\n");
				system("pause");
				system("cls");
				break;
				
			case 9:
				printf("\n\nCANCELAR ASIGNACION\n\n");
				printf("not ready\n");
				system("pause");
				system("cls");
				break;
				
			case 10:
				printf("\n\nATENCION DE ASIGNACIONES\n\n");
				printf("not ready\n");
				system("pause");
				system("cls");
				break;
				
			case 11: //Registrar nuevo incidente
				printf("\n\nREGISTRAR INCIDENTE\n\n");
				printf("Ingrese el codigo del requerimiento asociado: ");
				scanf("%s", &codigoRequerimiento);
				printf("Ingrese el codigo de la asignacion asociada: ");
				scanf("%s", &codigoAsignacion);
				printf("ingrese una descripcion corta del incidente(maximo 90 caracteres): " );
				scanf("%s", &descripcionIncidente);
				
				time_t t; //Almacena hora actual del sistema
				struct tm *tm; //struct obtenidas de libreria time.h
				char fechayhora[100];
				
				t = time(NULL);
				tm = localtime(&t);
				strftime(fechayhora, 100, "%d/%m/%Y", tm); //Hora se almacena en variable fechayhora formato DD/MM/AAAA
				
				agregarIncidente(k, codigoRequerimiento, codigoAsignacion, descripcionIncidente, fechayhora, i);
				system("pause");
				system("cls");
				break;
			
			case 12:
				printf("\n\nCONSULTAR INCIDENTE\n\n");
				printf("1. Consultar por requerimiento\n2. Consultar por fecha\n");
				printf("Ingrese el tipo de consutta que desea realizar: ");
				scanf("%d", &tipoBusquedaIncidente);
				
				if(tipoBusquedaIncidente == 1){
					printf("Ingrese el codigo del requerimiento que desea consultar: ");
					scanf("%s", &consultaRequerimiento);
					buscarIncidentePorRequerimiento(consultaRequerimiento);
					
				}
				
				if(tipoBusquedaIncidente == 2){
					printf("Ingrese la fecha que desea consultar (formato DD/MM/AAAA): ");
					scanf("%s", &consultaFecha);
					buscarIncidentePorFecha(consultaFecha);
				}
				
				system("pause");
				system("cls");
				break;
				
			case 13:
				printf("\n\nANALISIS DE DATOS\n\n");
				printf("not ready\n");
				system("pause");
				system("cls");
				break;
				
			case 0:
				printf("\t\t\t\t\t\n\n\n\n\nGRACIAS POR PREFERIRNOS!!!\n");
				break;			
		}
	}
    return 0;
}

