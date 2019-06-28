#include <stdio.h>
#include <stdlib.h>
#define ZHODA 1
#define NEZHODA 0

typedef struct {
	int *pole;
	unsigned int dlzka;
}MNC;
	
void nacitaj_pole(MNC *A)
{
	int i;
	printf("zadaj dlzku pola\n");		
	scanf("%d",&A->dlzka);
	A->pole=malloc(A->dlzka*sizeof(int));
	printf("zadaj prvky pola\n");
	for(i=0;i<A->dlzka;i++)
	{
		scanf("%d",&A->pole[i]);
	}
	printf("\n");
}
	
int zhoda(MNC *A, int b)
{
	int i;
		
	for(i=0;i<A->dlzka;i++)
	{
		if(b==A->pole[i])
		{
			return ZHODA;
		}
	}
	return NEZHODA;
}
	
void zjednotenie(MNC *A, MNC *B, MNC *C)
{
	int i,k=0,aux,base=A->dlzka; 
	
	C->pole=malloc((A->dlzka+B->dlzka)*sizeof(int));
		
	for(i=0;i<A->dlzka;i++)
	{
		C->pole[i]=A->pole[i];
	}
		
	for(i=0;i<B->dlzka;i++)
	{	
		aux=zhoda(A,B->pole[i]);
		if(aux==NEZHODA)
		{	
			C->pole[base+k]=B->pole[i];
			k++;
		}
	}
	C->dlzka=A->dlzka+k;
		
	printf ("zjednotenie je ");
	for(i=0;i<C->dlzka;i++)
	{
		printf("%d  ",C->pole[i]);
	}
}
	
void prienik(MNC *A, MNC *B, MNC *D)
{
	int i, aux,k=0;
	D->pole=malloc(A->dlzka*sizeof(int));
		
	for(i=0;i<B->dlzka;i++)
	{
		aux=zhoda(A, B->pole[i]);
		
		if(aux==ZHODA)
		{
			D[k]=B[i];
			k++;
		}
	}
	D->dlzka=k;
		
	printf("\n prienik je  : \n");
	for(i=0;i<D->dlzka;i++)
	{
		printf("%d  ",D->pole[i]);
	}
		
		
}
	
int main()
{
	MNC A,B,C,D;
		
	nacitaj_pole(&A);
	nacitaj_pole(&B);
		
	zjednotenie(&A,&B,&C);
	prienik(&A,&B,&D);
}
