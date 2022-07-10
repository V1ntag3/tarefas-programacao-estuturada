#include <stdio.h>
#include <string.h>
#define MAX 20
struct carro
{
	int ano;
	char cor[11];
	float preco;
	char placa[9];
	char marca[16];
};
void verificarplaca(struct carro vetcar[MAX], int i)
{
	int j;
	for(j = 0; j < i; j++)
	{
		if(strcmp(vetcar[i].placa, vetcar[j].placa) == 0)
		{
			printf("Placa invalida digite novamente: ");
			scanf("%s", vetcar[i].placa);
			j = -1;
		}
	}
}

void leitura(struct carro vetcar[MAX])
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		printf("Carro %d\n", i + 1);
		printf("Qual a marca do carro? ");
		scanf("%s", vetcar[i].marca);
		printf("Qual o ano?");
		scanf("%d", &vetcar[i].ano);
		printf("Qual a cor do carro? ");
		scanf("%s", vetcar[i].cor);
		printf("Qual o preco? ");
		scanf("%f", &vetcar[i].preco);
		printf("Qual a placa?");
		scanf("%s", vetcar[i].placa);
		verificarplaca(vetcar, i);
		printf("\n");

	}
}
void imprime(struct carro vetcar[MAX])
{
	int i;
	printf("CARROS CADASTRADOS: \n[");
	for(i = 0; i < MAX; i++)
	{
		printf("Carro %d\n", i + 1);
		printf("%s\n", vetcar[i].marca);
		printf("%d\n", vetcar[i].ano);
		printf("%s\n", vetcar[i].cor);
		printf("%f\n", vetcar[i].preco);
		printf("%s\n", vetcar[i].placa);
		printf("\n");
	}
}
void precoimprime(struct carro vetcar[MAX])
{
	int i;
	int preco;
	printf("Qual preço quer utilizar? ");
	scanf("%d", &preco);
	for(i = 0; i < MAX; i++)
	{
		if(preco >= vetcar[i].preco)
		{
			printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\n", vetcar[i].marca, vetcar[i].ano, vetcar[i].cor, vetcar[i].preco);
		}
	}
}

void placateste(struct carro vetcar[MAX])
{
	int i;
	char placa[123];
	printf("Qual a placa quer utilizar? ");
	scanf("%s", placa);
	for(i = 0; i < MAX; i++)
	{
		if(strcmp(placa, vetcar[i].placa) == 0)
		{
			printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\n", vetcar[i].marca, vetcar[i].ano, vetcar[i].cor, vetcar[i].preco);
		}
		else
		{
			printf("Nao existe carro com essa placa");
		}
	}
}
int main()
{
	struct carro vetcar[MAX];
	leitura(vetcar);
	imprime(vetcar);
	precoimprime(vetcar);
	placateste(vetcar);
	return 0;
}
