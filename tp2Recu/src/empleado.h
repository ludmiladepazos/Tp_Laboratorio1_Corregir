/*
 * empleado.h
 *
 *  Created on: 2021
 *   ludmila
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define LIBRE 0
#define OCUPADO 1
#define UP 1
#define DOWN 0

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
} Empleado;

#endif /* EMPLEADO_H_ */

/// @brief menu con las opciones para mostrar los diferentes filtros
///
/// @return retorna opcion del usuario
int menuInformes();


/// @brief menu principal con las opciones del ABM
///
/// @return devuelve la opcion elegida por el usuario
int editMenu();

/// @brief Inicializa a todos los elementos del array en estado LIBRE para poder ser cargados
///
/// @param list lista de empleados
/// @param len tamaño de la lista
/// @return retorna 1 en caso correcto 0 en caso de error
int initEmployees(Empleado list[], int len);

/// @brief Se piden el ingreso de datos del cliente
///
/// @param list lista array de empleados
/// @param len tamaño de la lista
/// @param id se genera un id autoincremental
/// @return 0 en caso de error 1 en caso ok
int uploadEmployee(Empleado list[], int len, int *id);

/// @brief los datos ingresados por el usuario ahora son cargados a la estructura empleado en sus respectivos campos
///
/// @param lista lista array de empleados
/// @param len tamaño del array
/// @param id es autoincremental
/// @param nombre dato ingresado por el usuario
/// @param apellido dato ingreesado por el usuario
/// @param salario dato ingreesado por el usuario
/// @param sector dato ingresado por el usuario
/// @return 0 en caso de error, 1 en caso ok
int addEmployee(Empleado lista[], int len, int* id, char nombre[], char apellido[], float salario, int sector);

/// @brief Encuentra en que posicion del array se encuentra un determinado empleado a partir del datos de su id
///
/// @param list lista empleados
/// @param len tamaño de la lista
/// @param id
/// @return indice (posicion en el array) del empleado buscado
int findEmployeeById(Empleado list[], int len, int id);


/// @brief imprime un empleado
///
/// @param unEmpleado
void printAEmployee(Empleado unEmpleado);

/// @brief Imprime la lista de empleados
///
/// @param lista array empleados
/// @param len tamanio array
void printEmployees(Empleado lista[], int len);

/// @brief Edita los distintos campos del empleado
///
/// @param lista array empleado
/// @param len tamanio lista empleados
/// @return 0 en caso de error, 1 en caso ok
int editEmployee(Empleado lista[], int len);


/// @brief Realiza la baja logica del empleado a cambiar su estado de OCUPADO a LIBRE
///
/// @param list array empleado
/// @param len tamanio lista
/// @param id
/// @return retorna 0 en error, 1 en acierto
int removeEmployee(Empleado list[], int len, int id);

/// @brief Ordena la lista de empleados por nombre-sector, de manera ascendente o descendente
///
/// @param list array empleados
/// @param len tamanio lista
/// @param order criterio de ordenamiento, si es ascendente o descendente
/// @return 0 en caso de error, 1 en ok
int sortEmployees(Empleado list[], int len, int order);

/// @brief Calcula el salario total de los empleados
///
/// @param list array empleados
/// @param len tamanio lista
/// @return total salario
int calcularTotalSalario(Empleado *list, int len);

/// @brief Calcula el promedio de los salarios
///
/// @param list array empleados
/// @param len tamanio lista
/// @param promedioSalario
/// @return 0 en caso de error, 1 en estado ok
int calcularPromedioSalario(Empleado *list, int len, float *promedioSalario);

/// @brief Es un contador de la cantidad de empleados totales
///
/// @param list array empleados
/// @param len tamanio lista
/// @param empleadoTotalCantidad
/// @return 0 en caso de error, 1 en caso de ok
int calcularEmpleadoCantidad(Empleado *list, int len,int *empleadoTotalCantidad);

/// @brief Calcula la cantidad de empleados que superan el salario promedio
///
/// @param list array empleados
/// @param len tamanio lista
/// @param cantidadSuperanSalarioPromedio
/// @return 0 en caso de error, 1 en caso ok
int cantidadEmpleadosSuperanSalarioPromedio(Empleado *list, int len,int *cantidadSuperanSalarioPromedio);

/// @brief Accede a un menu con los distintos filtros a informar
///
/// @param list array empleados
/// @param len tamanio lista
void informar(Empleado list[], int len);

