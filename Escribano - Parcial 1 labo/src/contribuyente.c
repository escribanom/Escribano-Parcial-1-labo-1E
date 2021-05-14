#define TXT 20
#define SIZE 5
#define SIZER 5
#define SIZET 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "contribuyente.h"
#include "Recaudacion.h"
int init(Contribuyente lista[],int size)
{
	int retorno =-1;
	if(lista != NULL && SIZE>0)
	{
	for(int i=0;i<SIZE;i++)
	{

		lista[i].isEmpty=1;
	}
	retorno =0;
	}

	return retorno;
}

int searchForSpace(Contribuyente lista[],int size,int* position)
{
	int retorno=-1;
		int i =0;
		if(lista!=NULL && SIZE >=0 && position!=NULL)
		{
			for(i=0;i<SIZE;i++)
			{
				if(lista[i].isEmpty==1)
				{
					retorno=0;
					*position=i;
					break;
				}
			}
		}
		return retorno;
}
int altaContribuyente(Contribuyente lista[],int* nextId, int size)
{
	int ret=-1;
	int position;
	if(lista!=NULL && SIZE>0)
	{

		if(searchForSpace(lista,SIZE,&position)==-1)
		{
			printf("NO HAY ESPACIO DISPONIBLE\n");
		}
		else
		{
			(*nextId)++;
			lista[position].id= *nextId;
			get_Entero(&lista[position].cuil,1,"\n ingrese cuil:","\n ERROR:ingrese cuil:",1,100000000);
			get_Cadena(lista[position].nombre,TXT,1,"\n ingrese nombre: ","\n Error: reingrese nombre: ");
			get_Cadena(lista[position].apellido,TXT,1,"\n ingrese apellido: ","\n Error: reingrese apellido: ");
			lista[position].isEmpty=0;

		}
		ret=0;
	}
	return ret;
}
int findContribuyenteById(Contribuyente* lista, int size, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(lista!= NULL && SIZE >=0)
	    {
	        for(i=0;i<SIZE;i++)
	        {
	            if(lista[i].isEmpty==1)
	                continue;
	            else if(lista[i].id==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
void printContribuyente(Contribuyente lista, int size)
{

	printf("%d     %-20s   %-20s %d   \n",lista.id, lista.nombre,lista.apellido, lista.cuil);
}
int printContribuyentes(Contribuyente lista[], int size)
{
	int ret=-1;
	int i;
	printf("***************************Lista de Contribuyentes***************************\n");
	printf("Id  Nombre  Apellido  Cuil\n");
	if(lista!=NULL && SIZE >0){
		for(i=0;i<SIZE;i++)
		{
			if(lista[i].isEmpty==0)
				{
				printContribuyente(lista[i],SIZE);
				ret=0;
				}
		}

	}
		return ret;
}
int modifContrib(Contribuyente* lista, int size)
{
    int retorno=-1;
	int position;
	int auxId;
	int opModif=0;
	char continuar='s';

	if(lista!=NULL && SIZE>0)
	  {
		printContribuyentes(lista, SIZE);
		get_Entero(&auxId,1,"\n id a modificar ","\n Error: reingrese id a modificar: ",1,9999);
	    		        if(findContribuyenteById(lista,SIZE, auxId, &position)==-1)
	    		        {
	    		            printf("ID inexistente\n");
	    		        }
	    		        else
	    		        {
	    do{
	    	printf("1-Cambiar nombre\n");
	    	printf("2-Cambiar apellido\n");
	    	printf("3-Cambiar cuil\n");
	    	get_Entero(&opModif,1,"Indique opcion a modificar ","\n Error: reingrese opcion a modificar: ",1,3);
	    	switch(opModif){
	    	case 1://nombre
	    		get_Cadena(lista[position].nombre,TXT,1,"\n ingrese nombre: ","\n Error: reingrese nombre: ");
	    		break;
	    	case 2://apellido
	    		get_Cadena(lista[position].apellido,TXT,1,"\n ingrese apellido: ","\n Error: reingrese apellido: ");
	    		break;
	    	case 3://cuil
	    		get_Entero(&lista[position].cuil,1,"Ingrese nuevo cuil\n","Error.Ingrese nuevo cuil valido\n",1,100000000);
	    		break;
	    	default:
	    		printf("No es una opcion valida\n");
	    	}
	    	printf("Desea volver al menu? s/n : \n");
	    				        fflush(stdin);
	    				        scanf("%c", &continuar);
	    }while(continuar=='s');
	    		        }
	    		        retorno=0;
	  }
	    return retorno;
}
int removeContribuyente(Contribuyente* lista, int size)
{
	int retorno =-1;
	//-1 if error 0 if ok
	int position;
	int auxId;
    if(lista!=NULL && SIZE>0)
	    {
    	printContribuyentes(lista, SIZE);
	       get_Entero(&auxId,1,"\n id a dar de baja ","\n Error: reingrese id a dar de baja: ",1,9999);

	        if(findContribuyenteById(lista, SIZE,auxId, &position)==-1)
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	        	lista[position].isEmpty=1;


	            retorno=0;
	        }
	    }
	return retorno;
}
