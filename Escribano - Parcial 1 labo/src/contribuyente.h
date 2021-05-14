

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_
#define TXT 20
#define SIZE 5
typedef struct{
	int id;
	int cuil;
	char nombre[TXT];
	char apellido[TXT];
	int isEmpty;//1=libre 0=lleno
}Contribuyente;

int init(Contribuyente lista[], int size);
int searchForSpace(Contribuyente lista[],int size,int* position);
int altaContribuyente(Contribuyente lista[],int* nextId, int size);
int modifContrib(Contribuyente* lista, int size);
int removeContribuyente(Contribuyente* lista, int size);
#endif /* CONTRIBUYENTE_H_ */
