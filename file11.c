#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
	int codigo;
	char nome[50];
	float preco;
};

typedef struct produto produto;


void le_produtos  (produto* lista, int tam) ;
void grava_produtos (produto *lista, int tam ) ;
void le_produtos_arq ( produto *lista, int tam) ;
void imprime_produtos  (produto* lista, int tam) ;
char * produto_mais_caro(produto* lista, int tam) ;
char * produto_mais_barato(produto* lista, int tam) ;
float calculo_media(produto *lista, float tam) ;

int main( ) {

	produto* lista = malloc(5 * sizeof(produto));

	//le_produtos(lista, 3);
   //grava_produtos (lista , 3 );
	le_produtos_arq ( lista, 3) ; 
  imprime_produtos(lista, 3);
     
     
	printf("o produto mais caro eh %s \n", produto_mais_caro(lista, 3));
	printf("o produto mais barato eh %s \n", produto_mais_barato(lista, 3));
    printf("a media dos produtos eh %f \n", calculo_media(lista, 3)); 

}



void le_produtos(produto* lista, int tam) {



	int i;
	for(i = 0; i < tam; i++) {
	
		printf("Digite o codigo:\n ");
		scanf("%i", &lista->codigo);
		fflush(stdin);


		printf("Digite o nome: \n");
		gets(lista->nome);


		printf("Digite o preco:\n ");
		scanf("%f", &lista->preco);
		fflush(stdin);




	     lista ++ ;

	     system("cls");


	}

  

}

    void grava_produtos (produto *lista, int tam ) {

 	int i;
 	FILE *f = fopen ("grr.txt", "w");

 	 for (i=0; i< tam; i++) {
 	    	fprintf(f, "%d ", lista->codigo);
 	    	fputc('\n', f);

 	 		fprintf(f, "%s", lista->nome);
 	 	    fputc('\n', f);

 	 		fprintf(f, "%f", lista->preco);
            fputc('\n', f);

 	 	  lista ++ ;
	  }


 	fclose(f);


 }


void le_produtos_arq ( produto *lista, int tam) {


	FILE *f = fopen  ("grr.txt", "r");
int i;
	for(i = 0; i < tam; i++)
	{
		fscanf(f, "%d", &lista->codigo);
		fscanf(f, "%s", &lista->nome);
		fscanf(f, "%f", &lista->preco);
		lista++;


	}
	
	   	fclose(f);

}
	//localizar o produto mais caro


char * produto_mais_caro(produto* lista, int tam) {

	int i;
	float preco_mais_caro = lista->preco;
	char* nome_mais_caro = malloc(50 * sizeof(char));
	strcpy(nome_mais_caro, lista->nome);
	
	for(i = 0; i < tam; i++) {
	
		if (lista->preco > preco_mais_caro) {
			
		
			preco_mais_caro = lista->preco;
			strcpy(nome_mais_caro, lista->nome);
		}
		lista++;
	}
	return nome_mais_caro;
}




//localizar o produto mais barato

char *produto_mais_barato(produto* lista, int tam) {

	int i;
	float preco_mais_barato = lista->preco;
	char* nome_mais_barato = malloc(50 * sizeof(char));
	strcpy(nome_mais_barato, lista->nome);
	
	for(i = 0; i < tam; i++) {
	
		if (lista->preco < preco_mais_barato) {
			
		
			preco_mais_barato = lista->preco;
			strcpy(nome_mais_barato, lista->nome);
		}
		lista++;
	}
	return nome_mais_barato;
}


float calculo_media(produto *lista, float tam) {

int i;
float media, somatorio = 0;
 
for(i=0; i<tam; i++) {

 somatorio = somatorio + lista->preco;
 lista++;
 
 printf("%.2f\n", somatorio);
}
media = (somatorio/tam);
printf("%.2f\n", media);

    return media;
}



void imprime_produtos(produto* lista, int tam) {


	int i;
	for(i = 0; i <tam; i++) {

		printf("codigo do produto : %d   nome do produto:  %s  preco do produto:   %.2f  \n ", lista->codigo,  lista->nome , lista->preco);
	    printf("\n") ;


           lista ++ ;
	}

}


