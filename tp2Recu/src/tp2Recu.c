/*
 ============================================================================
 Name        : TP2.c
 Author      : LUDMILA
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define TAM_LIST 5
#define UP 1
#define DOWN 0
int main(void)
{
	setbuf(stdout,NULL);

	char salir;
	int id = 1;
	int flagAlta = 0;
	salir = 'n';


	Empleado listaEmpleados[TAM_LIST];

	initEmployees(listaEmpleados,TAM_LIST);

	do{
		switch(menuEmpleados())
		{
			case 1:
				if(uploadEmployee(listaEmpleados,TAM_LIST,&id))
				{
					flagAlta=1;
					id++;
					printf("se cargo el empleado\n");


				}
				else
				{
					printf(" no se cargo el empleado\n");
				}
				break;
			case 2:
				if(flagAlta && editEmployee(listaEmpleados, TAM_LIST))
				{
					printf("Editar ok");
				}
				else
				{
					printf("No hay existen empleados para modificar\n");
				}
				break;
			case 3:
				if(flagAlta && removeEmployee(listaEmpleados, TAM_LIST, id))
				{
					printf("Se ha realizado la baja con exito.\n");
				}
				else
				{
					printf("No existen empleados para eliminar\n");
				}

				break;
			case 4:
				if(flagAlta)
				{
					informar(listaEmpleados,TAM_LIST);
				}
				else
				{
					printf("Debe ingresar un empleado para poder listarlos\n");
				}
				break;
			case 5:
				printf("Confirma salida s/n:\n");
				fflush(stdin);
				scanf("%c",&salir);
				break;
			default:
				printf("Opciones invalidas.\n");
				break;
		}
	}while(salir!='s');

	return EXIT_SUCCESS;
}
