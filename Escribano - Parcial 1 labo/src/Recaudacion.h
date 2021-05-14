/*
 * Recaudacion.h
 *
 *  Created on: 13 may. 2021
 *      Author: Adm-Periodismo
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_
typedef struct{
	int idTipo;
	char descripcion[TXT];
	int isEmpty;//1=libre 0=lleno

}Tipo;
typedef struct{
	int idRec;
	int mes;
	Tipo tipo;
	int importe;
	int isEmpty;//1=libre 0=lleno
	int idContribuyente;
	char status[TXT];
}Recaudacion;

int initRecauda(Recaudacion recauda[],int size);
int searchForSpaceRec(Recaudacion recauda[],int size,int* position);
int altaRecaudacion(Recaudacion recauda[],int* nextIdRec, int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
void printRecaudacion(Recaudacion recauda, int size,Tipo tipos[],int sizeT);
int printRecaudaciones(Recaudacion recauda[], int size, Tipo tipos[],int sizeT);
int getDescripcionTipo(Tipo tipos[],int sizeT, int buscar, char descripcion[]);
void printTipo(Tipo tipos,int sizeT);
int printTipos(Tipo tipos[],int sizeT);
int findRecaudacionById(Recaudacion* recauda, int size, int valor, int* position);
int refinanciar(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
int saldar(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
#endif /* RECAUDACION_H_ */
