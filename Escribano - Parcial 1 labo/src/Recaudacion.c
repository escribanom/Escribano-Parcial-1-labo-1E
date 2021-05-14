
#define SIZER 5
#define SIZET 3
#define TXT 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "contribuyente.h"
#include "Recaudacion.h"

int initRecauda(Recaudacion recauda[],int size)
{
	int retorno =-1;
	if(recauda != NULL && SIZER>0)
	{
	for(int i=0;i<SIZER;i++)
	{

		recauda[i].isEmpty=1;
	}
	retorno =0;
	}

	return retorno;
}

int searchForSpaceRec(Recaudacion recauda[],int size,int* position)
{
	int retorno=-1;
		int i =0;
		if(recauda!=NULL && SIZER >=0 && position!=NULL)
		{
			for(i=0;i<SIZER;i++)
			{
				if(recauda[i].isEmpty==1)
				{
					retorno=0;
					*position=i;
					break;
				}
			}
		}
		return retorno;
}
int altaRecaudacion(Recaudacion recauda[],int* nextIdRec, int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC)
{
	int ret=-1;
	int position;
	if(recauda!=NULL && SIZE>0 && tipos!= NULL && SIZET>0)
	{

		if(searchForSpaceRec(recauda,SIZE,&position)==-1)
		{
			printf("NO HAY ESPACIO DISPONIBLE\n");
		}
		else
		{
			(*nextIdRec)++;
			recauda[position].idRec= *nextIdRec;
			get_Entero(&recauda[position].mes,1,"\n ingrese mes:","\n ERROR:ingrese mes:",1,12);
			printTipos(tipos,SIZET);
			get_Entero(&recauda[position].tipo.idTipo,1,"\n ingrese ID de tipo : ","\n ERROR: reingrese ID de tipo: ",1,3);

			get_Entero(&recauda[position].importe,1,"\n ingrese importe:","\n ERROR:ingrese importe:",1,9999999);
			strcpy(recauda[position].status," ");
			recauda[position].isEmpty=0;
			printContribuyentes(lista,SIZE);
			get_Entero(&recauda[position].idContribuyente,1,"\n ingrese ID de contribuyente : ","\n ERROR: reingrese ID de contribuyente: ",1000,2000);

		}
		ret=0;
	}
	return ret;
}
void printRecaudacion(Recaudacion recauda, int size,Tipo tipos[],int sizeT)
{
	char descripcion[20];
	getDescripcionTipo(tipos,SIZET, recauda.tipo.idTipo,descripcion);
	printf("***************************Lista de Recaudaciones***************************\n");
	printf("%d    %d   %s     %d     %s %d\n",recauda.idRec, recauda.mes ,descripcion, recauda.importe,recauda.status,recauda.idContribuyente);
}
int printRecaudaciones(Recaudacion recauda[], int size, Tipo tipos[],int sizeT)
{
	int ret=-1;
	int i;
	printf("***************************Lista de Recaudaciones***************************\n");
	printf("Id  Mes Tipo    Importe  Estado  ID contribuyente\n");
	if(recauda!=NULL && SIZER >0 && tipos!=NULL  && SIZET>0){
		for(i=0;i<SIZER;i++)
		{
			if(recauda[i].isEmpty==0)
				{
				printRecaudacion(recauda[i],SIZER,tipos,SIZET);
				ret=0;
				}
		}

	}
		return ret;
}
int getDescripcionTipo(Tipo tipos[],int sizeT, int buscar, char descripcion[])
{
	int ret=-1;
	int i;
	if(tipos!=NULL&& SIZET >0 && descripcion!=NULL)
	{
		for(i=0;i<SIZE;i++)
			{
				if(tipos[i].idTipo==buscar)
				{
					strcpy(descripcion,tipos[i].descripcion);
					ret=0;
					break;
				}

			}
	}

	return ret;
}
void printTipo(Tipo tipos,int sizeT)
{
	printf("  %d %20s  \n", tipos.idTipo, tipos.descripcion);
}
int printTipos(Tipo tipos[],int sizeT)
{
	int ret=-1;
	int i;
	printf("\n***** Lista de tipos *****\n");
	printf("ID de tipo        Tipo\n");
	if(tipos!=NULL && SIZET >0){
		for(i=0;i<SIZET;i++)
		{
			if(tipos[i].isEmpty==0)
				{
				printTipo(tipos[i],SIZET);
				ret=0;
				}
		}

	}
		return ret;
}
int findRecaudacionById(Recaudacion* recauda, int size, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(recauda!= NULL && SIZE >=0)
	    {
	        for(i=0;i<SIZE;i++)
	        {
	            if(recauda[i].isEmpty==1)
	                continue;
	            else if(recauda[i].idRec==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
int refinanciar(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC)
{
	int ret=-1;//pide id recaudacion ymuestra info contrib -pide confirm y pasa a refinancar
	int position;
		int auxId;
		char continuar='s';
		char op;
		if(lista!=NULL && SIZE>0)
		  {
			printRecaudaciones(recauda, SIZER,tipos,SIZET);
			get_Entero(&auxId,1,"\nIngrese id a refinanciar ","\n Error: reingrese id a refinanciar: ",1,9999);
		    		        if(findRecaudacionById(recauda,SIZER, auxId, &position)==-1)
		    		        {
		    		            printf("ID inexistente\n");
		    		        }
		    		        else
		    		        {
		    do{
		    	{
		    		printf("Desea refinanciar? s/n : \n");
		    		fflush(stdin);
		    		scanf("%c", &op);
		    		if(op=='s'||op=='S')
		    		{
		    		strcpy(recauda[position].status,"Refinanciar");
		    		}
		    	}
		    	printf("Desea volver al menu? s/n : \n");
		    				        fflush(stdin);
		    				        scanf("%c", &continuar);
		    }while(continuar=='s');
		    		        }
		    		        ret=0;
		  }

	return ret;
}
int saldar(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC)
{
	int ret=-1;//pide id recaudacion ymuestra info contrib -pide confirm y pasa a refinancar
		int position;
			int auxId;
			char continuar='s';
			char op;
			if(lista!=NULL && SIZE>0)
			  {
				printRecaudaciones(recauda, SIZER,tipos,SIZET);
				get_Entero(&auxId,1,"\nIngrese id a refinanciar ","\n Error: reingrese id a refinanciar: ",1,9999);
			    		        if(findRecaudacionById(recauda,SIZER, auxId, &position)==-1)
			    		        {
			    		            printf("ID inexistente\n");
			    		        }
			    		        else
			    		        {
			    do{
			    	{
			    		printf("Desea saldar? s/n : \n");
			    		fflush(stdin);
			    		scanf("%c", &op);
			    		if(op=='s'||op=='S')
			    		{
			    		strcpy(recauda[position].status,"Saldar");
			    		}
			    	}
			    	printf("Desea volver al menu? s/n : \n");
			    				        fflush(stdin);
			    				        scanf("%c", &continuar);
			    }while(continuar=='s');
			    		        }
			    		        ret=0;
			  }

		return ret;
}
