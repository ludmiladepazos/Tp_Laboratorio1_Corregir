/*
 * empleado.c
 *
 *  Created on: 2021
 *      Author: ludmila
 */


#include "empleado.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menuEmpleados()
{

	int opcion;

	printf("*****MENU OPCIONES*****\n\n");
	printf("1. Alta empleado\n");
	printf("2. Modificar empleado\n");
	printf("3. Baja empleado\n");
	printf("4. Listar empleado\n");
	printf("5. Salir\n\n");
	printf("Ingrese opcion deseada: ");

	scanf("%d",&opcion);

	return opcion;

}

int initEmployees(Empleado list[], int len)
{
	int retorno;
	retorno = 0;

	if(list != NULL && len > 0)
	{
		for(int i=0 ; i<len; i++ )
		{
			list[i].isEmpty= LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}



int uploadEmployee(Empleado list[], int len, int* id)
{
	int retorno = 0;
	Empleado buffer;
	float salario;
	int sector;

	if(list != NULL && len > 0 && id != NULL)
	{
		if(utn_getCadena(buffer.nombre,51,3,"Ingrese su nombre: ","Nombre no valido. Reingrese\n")== 0 &&
		   utn_getCadena(buffer.apellido,51,3,"Ingrese su apellido: ","Apellido no valido. Reingrese\n") == 0 &&
		   utn_getFlotante(&salario,3,"Ingrese salario: ", "Salario no valido. Reigrese\n",1,999999999) == 0 &&
		   utn_getEntero(&sector,3,"Ingrese sector: ","Sector no valido. Reingrese\n",0,999999999) == 0)
		{

			buffer.id = *id;
			buffer.salario = salario;
			buffer.sector = sector;

			if(addEmployee(list, len, id, buffer.nombre, buffer.apellido, buffer.salario, buffer.sector) == 1)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int addEmployee(Empleado lista[], int len, int* id, char nombre[], char apellido[], float salario, int sector)
{
	int retorno = 0;


	if(lista != NULL && len > 0 && id > 0 && nombre != NULL && apellido != NULL && salario > 0 && sector > 0)
	{
		for(int i=0 ; i<len; i++ )
		{
			if(lista[i].isEmpty == LIBRE )
			{


				strncpy(lista[i].nombre, nombre, 51);
				strncpy(lista[i].apellido, apellido, 51);
				lista[i].salario = salario;
				lista[i].sector = sector;
				lista[i].isEmpty = OCUPADO;
				lista[i].id = *id;
				id++;


				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int findEmployeeById(Empleado list[], int len, int id)
{
	int retorno = 0;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



void printAEmployee(Empleado unEmpleado)
{
	printf("%d      %s     %s     %.2f     %d     \n\n",unEmpleado.id,unEmpleado.nombre,unEmpleado.apellido,unEmpleado.salario,unEmpleado.sector);
}

void printEmployees(Empleado lista[], int len)
{

	printf("LISTA DE EMPLEADOS\n\n");
	printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");

	if(lista!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].isEmpty== OCUPADO)
			{
				printAEmployee(lista[i]);

			}

		}
	}

}


int editEmployee(Empleado lista[], int len)
{
	int indice;
	char confirma;
	int id;
	char auxChar[51];
	int auxInt;
	float auxFloat;
	int retorno;
	retorno = 0;

	printEmployees(lista,len);
	printf("Ingrese ID de empleado: ");
	scanf("%d",&id);

	indice = findEmployeeById(lista,len,id);

	if (indice == -1)
	{
		printf("No hay ningun empleado con el id:%d ",id);
	}
	else
	{
		printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");
		printAEmployee(lista[indice]);
		printf("Desea modificar este empleado? (s/n): ");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma =='s')
		{
			switch(editMenu())
			{
				case 1:
					utn_getCadena(auxChar,51,3,"Ingrese nuevo nombre: ","Nombre no valido. Reingrese\n");
					strcpy(lista[indice].nombre,auxChar);
					printf("Se actualizo el nombre\n");
					break;
				case 2:
					utn_getCadena(auxChar,51,3,"Ingrese nuevo apellido: ","Apellido no valido. Reingrese\n");
					strcpy(lista[indice].apellido,auxChar);
					printf("Se actualizo el apellido\n");
					break;
				case 3:
					utn_getFlotante(&auxFloat,3,"Ingrese nuevo salario: ", "Salario no valido. Reingrese\n",1,999999999);
					lista[indice].salario=auxFloat;
					system("cls");
					printf("Se actualizo el salario\n");
					break;
				case 4:
					utn_getEntero(&auxInt,3,"Ingrese nuevo sector: ","Sector no valido. Reingrese\n",0,999999999);
					lista[indice].sector=auxInt;
					system("cls");
					printf("Se actualizo el sector\n");
					break;
				case 5:
					confirma = 'n';
					break;
				default:
					printf("Opcion incorrecta\n");
					break;
			}
			retorno = 1;
		}
	}
	return retorno;
}

int editMenu()
{
	int opcion;
	printf("1. Modificar nombre\n");
	printf("2. Modificar apellido\n");
	printf("3. Modificar salario\n");
	printf("4. Modificar sector\n\n");
	printf("5. Salir\n\n");
	printf("Ingrese opcion deseada: ");
	fflush(stdin);
	scanf("%d",&opcion);

	return opcion;
}

int removeEmployee(Empleado list[], int len, int id)
{
	int retorno;
	int indice;
	char confirma;
	retorno = 0;

	if(list != NULL && len > 0)
	{
		printEmployees(list, len);
		printf("Ingrese ID de empleado a eliminar: ");
		scanf("%d",&id);

		indice = findEmployeeById(list, len, id);

		if(list[indice].isEmpty == OCUPADO)
		{
			if (indice == -1)
			{
				printf("No hay ningun empleado con el id:%d ",id);
			}
			else
			{
				printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");
				printAEmployee(list[indice]);
				printf("Desea eliminar este empleado? (s/n): ");
				fflush(stdin);
				scanf("%c",&confirma);
				if(confirma=='s')
				{
					list[indice].isEmpty= LIBRE;
					retorno = 1;
				}
				else
				{
					printf("\nSe cancelo la operacion\n\n");
				}
			}
		}
	}
	return retorno;
}

int sortEmployees(Empleado list[], int len, int order)
{
	int retorno;
	int flagSwap;
	int nuevoLimite;
	Empleado buffer;
	retorno = 0;
	flagSwap = 1;


		if(list != NULL && len > 0 && (order == UP || order == DOWN))
		{

			nuevoLimite = len-1;
			do{

				flagSwap = 0;
				for(int i = 0; i < nuevoLimite ; i++)
				{

					if((order == UP && (strcmp(list[i].apellido, list[i + 1].apellido)>0 ||
						(strcmp(list[i].apellido, list[i + 1].apellido)==0 && list[i].sector > list[i + 1].sector))) ||
						(order == DOWN && (strcmp(list[i].apellido, list[i + 1].apellido)<0 ||
						(strcmp(list[i].apellido, list[i + 1].apellido)==0 && list[i].sector < list[i + 1].sector))))
					{

						flagSwap = 1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}

				nuevoLimite--;
			}while(flagSwap);

			retorno = 1;
		}
		printEmployees(list, len);

		return retorno;


}

int calcularTotalSalario(Empleado* list, int len)
{
	int retorno = -1;
	float totalSalario = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				totalSalario += list[i].salario;
			}
		}
		retorno = totalSalario;
	}
	return retorno;
}

int calcularPromedioSalario(Empleado* list, int len, float* promedioSalario)
{
	int retorno = 0;
	float totalSalario;
	int empleadoCantidad;
	float promedioAux;

	if(list != NULL && len > 0)
	{
		totalSalario = calcularTotalSalario(list, len);
		if(calcularEmpleadoCantidad(list, len, &empleadoCantidad))
		{	promedioAux = totalSalario / empleadoCantidad;
			*promedioSalario = promedioAux;
			retorno = 1;
		}
	}

	return retorno;
}


int calcularEmpleadoCantidad(Empleado* list, int len, int* empleadoTotalCantidad)
{
	int retorno = 0;
	int empleadoCantidad = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				empleadoCantidad++;
			}
		}

		*empleadoTotalCantidad = empleadoCantidad;
		retorno = 1;
	}

		return retorno;
}

int cantidadEmpleadosSuperanSalarioPromedio(Empleado* list, int len, int* cantidadSuperanSalarioPromedio)
{
	int retorno = 0;
	float salarioPromedio;
	int empleadoCantidad = 0;

	if(list != NULL && len > 0)
	{
		calcularPromedioSalario(list, len, &salarioPromedio);

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].salario > salarioPromedio)
			{
				empleadoCantidad++;
			}
		}
		*cantidadSuperanSalarioPromedio = empleadoCantidad;
		retorno = 1;
	}

		return retorno;
}

int menuInformes()
{
	int opcion;
	printf("1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
	printf("2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n\n");
	printf("3.Salir: \n");
	printf("Ingrese opcion deseada: \n");
	scanf("%d",&opcion);

	return opcion;
}

void informar(Empleado list[],int len)
{
	char salir ='n';
	int opcion;
	float totalSalario;
	float promedioSalario;
	int cantidadSuperanSalarioPromedio;
	printEmployees(list,len);

	do{
			switch(menuInformes())
			{
				case 1:
					do{
						if(utn_getEntero(&opcion, 5, "\n1.Ordenar de forma ascendente \n2.Ordenar de forma descendente \n"
								"3-Volver al menu", "Opcion incorrecta\n", 1, 3) == 0)
						{
							switch(opcion)
							{
								case 1:
									sortEmployees(list, len, UP);
									break;
								case 2:
									sortEmployees(list, len, DOWN);
									break;
							}
						}
					}while(opcion !=3);
					break;
				case 2:
					totalSalario = calcularTotalSalario(list, len);
					if(totalSalario!= -1 && calcularPromedioSalario(list, len, &promedioSalario) && cantidadEmpleadosSuperanSalarioPromedio(list, len, &cantidadSuperanSalarioPromedio))
					{
						printf("\nSalario total: %.2f \nSalario promedio: %.2f \nCantidad de empleados que superan el salario "
								"promedio: %d", totalSalario, promedioSalario, cantidadSuperanSalarioPromedio);
					}
					break;
				case 3:
					printf("Confirma salida s/n:\n");
					fflush(stdin);
					scanf("%c",&salir);
					break;
				default:
					printf("Opcion no valida \n\n");
					break;
			}
	}while(salir !='s');
}







