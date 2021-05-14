
#define SIZE 5
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

int main(void) {
	setbuf(stdout,NULL);
		char continuar = 's';
		int opcion;
		int nextId=1000;
		int nextIdRec=100;
		Contribuyente lista[SIZE];
		Recaudacion recauda[SIZER];
		Tipo tipos[SIZET]={
				{1,"ARBA",0},
				{2,"IIBB",0},
				{3,"GANANCIAS",0}
		};
		init(lista,SIZE);
		initRecauda(recauda,SIZER);
		do
			    {
			        printf("1-Alta Contribuyente\n");
			        printf("2-Modificar Contribuyente\n");
			        printf("3-Baja Contribuyente\n");
			        printf("4-Recaudacion\n");
			        printf("5-Refinanciar recaudacion\n");
			        printf("6-Saldar recaudacion\n");
			        printf("7-Imprimir contribuyentes\n");
			        printf("8-Imprimir recaudacion\n");
			        get_Entero(&opcion,1,"Indique opcion:","\n Error: Ingrese opcion valida:\n",1,8);
			        switch(opcion)
			        {
			        case 1:
			        	altaContribuyente(lista,&nextId,SIZE);
			        	break;
			        case 2:
			        	modifContrib(lista, SIZE);
			        	break;
			        case 3:
			        	removeContribuyente(lista,SIZE);
			        	break;
			        case 4:
			        	altaRecaudacion(recauda,&nextIdRec,SIZER,tipos,SIZET,lista,SIZE);
			        	break;
			        case 5:
			        	refinanciar(recauda,SIZER,tipos,SIZET,lista, SIZE);
			        	break;
			        case 6:
			        	saldar(recauda,SIZER,tipos,SIZET,lista, SIZE);
			            break;
			        case 7:

			        	break;
			        case 8:

			        	break;
			        default:
			            printf("No es una opcion valida\n");
			        }
			        printf("Desea volver al menu? s/n : \n");
			        fflush(stdin);
			        scanf("%c", &continuar);
			       	    }
			    while(continuar =='s');
			    return opcion;
}
