#include <stdio.h>
#include <string.h>
#define MAX 12000
struct carro
{
	int ano;
	char cor[11];
	float preco;
	char placa[9];
	char marca[16];
	int mes;
	int dia;
	int anoano;
};
void option1(struct carro vetcar[MAX], int i)
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
	printf("Qual a data de aquisição do veiculo(Em dd mm aa:)");
	scanf("%d%d%d", &vetcar[i].dia, &vetcar[i].mes, &vetcar[i].anoano);
	printf("\n");
}
void option2(struct carro vetcar[MAX], int i)
{
	int j;
	char placa[123];
	printf("Qual a placa quer utilizar? ");
	scanf("%s", placa);
	for(j = 0; j < i; j++)
	{
		if(strcmp(placa, vetcar[j].placa) == 0)
		{
			printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
		}
		else
		{
			printf("Nao existe carro com essa placa");
		}
	}
}
void option3(struct carro vetcar[MAX], int i)
{
	int escolha;
	printf("Qual carro deseja remover?");
	scanf("%d", &escolha);
	for(; escolha - 1 < i; escolha++)
	{
		vetcar[escolha - 1].ano = vetcar[escolha].ano;
		vetcar[escolha - 1].preco = vetcar[escolha].preco;
		strcpy( vetcar[escolha - 1].placa, vetcar[escolha].placa);
		strcpy( vetcar[escolha - 1].marca, vetcar[escolha].marca);
		strcpy( vetcar[escolha - 1].cor, vetcar[escolha].cor);
		vetcar[escolha - 1].dia = vetcar[escolha].dia;
		vetcar[escolha - 1].mes = vetcar[escolha].mes;
		vetcar[escolha - 1].anoano = vetcar[escolha].anoano;
	}
}
void option4(struct carro vetcar[MAX], int i)
{
	int escolha, j;
	float preco;
	int ano;
	char marca[20100];
	int x = 1;
	while(x == 1)
	{
		printf("1 - Listar carros\n2 - Listar carros por limite de preco\n3 - Listar carros por limite de ano\n4 - Listar carros de uma marca\n5 - Listar carros de marca e ano\n0 - Sair\n");
		scanf("%d", &escolha);
		switch(escolha)
		{
		case 1:
			printf("CARROS CADASTRADOS: \n");
			for(j = 0; j < i; j++)
			{
				printf("Carro %d\n", i);
				printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
				printf("\n");
			}
			break;

		case 2:
			printf("Qual preço quer utilizar? ");
			scanf("%f", &preco);
			for(j = 0; j < i; j++)
			{
				if(preco >= vetcar[i].preco)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
					printf("\n");
				}
			}
			break;

		case 3:
			printf("Qual ano quer utilizar? ");
			scanf("%d", &ano);
			for(j = 0; j < i; j++)
			{
				if(ano >= vetcar[i].ano)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
					printf("\n");
				}
			}
			break;

		case 4:
			printf("Qual marca quer utilizar? ");
			scanf("%s", marca);
			for(j = 0; j < i; j++)
			{
				if(strcmp(marca, vetcar[i].marca) == 0)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
					printf("\n");
				}
			}
			break;
		case 5:
			printf("Qual marca quer utilizar? ");
			scanf("%s", marca);
			for(j = 0; j < i; j++)
			{
				if(strcmp(marca, vetcar[i].marca) == 0)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
					printf("\n");
				}
			}
			printf("Qual ano quer utilizar? ");
			scanf("%d", &ano);
			for(j = 0; j < i; j++)
			{
				if(ano == vetcar[i].ano)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, vetcar[i].dia, vetcar[i].mes, vetcar[i].anoano);
					printf("\n");
				}
			}
		default:
			x = 0;
			break;
		}
	}
}
int main()
{
	struct carro vetcar[MAX];
	int escolha, i = 0;
	while(1)
	{
		printf(" MENU\n1 - Cadartrar carro\n2 - Localizar carro\n3 - Remover carro\n4 - Relatorios\n0 - Sair\n");
		scanf("%d", &escolha);
		switch(escolha)
		{
		case 1:
			printf("OPCAO 1 DO MENU\n");
			option1(vetcar, i);
			i++;
			break;
		case 2:
			printf("OPCAO 2 DO MENU\n");
			option2(vetcar, i);
			break;
		case 3:
			printf("OPCAO 3 DO MENU\n");
			option3(vetcar, i);
			break;
		case 4:
			printf("OPCAO 4 DO MENU\n");
			option4(vetcar, i);
			break;
		default:
			return 0;
		}
	}
	return 0;
}
