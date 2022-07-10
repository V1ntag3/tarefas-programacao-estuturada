#include <stdio.h>
#include <string.h>
void estoque0(int estoque[3][4])
{
	int n, m;
	printf("1.1)\n");
	printf("Digite o estoque:\n");
	for(n = 0; n < 3; n = n + 1)
	{
		printf("ARMAZEM %d:\n", n + 1);
		for(m = 0; m < 4; m = m + 1)
		{
			printf("Produto %d: ", m + 1);
			scanf("%d", &estoque[n][m]);
		}
	}
}
void custo0(float custo[4])
{
	int m;
	printf("1.2\n");
	printf("Digite o custo de cada produto:\n");
	for(m = 0; m < 4; m = m + 1)
	{
		printf("Produto %d: R$ ", m + 1);
		scanf("%f", &custo[m]);
	}
}
void option1(int estoque[3][4])
{
	int n = 0, m;
	for(n = 0; n < 4; n = n + 1)
	{
		printf("PRODUTO %d:\n", n + 1);
		for(m = 0; m < 3; m = m + 1)
		{
			printf("ARMAZEM %d: %d\n", m + 1, estoque[m][n]);
		}
	}
}
void option2(int estoque[3][4])
{
	int n = 0, m;
	for(n = 0; n < 3; n = n + 1)
	{
		printf("ARMAZEM %d:\n", n + 1);
		for(m = 0; m < 4; m = m + 1)
		{
			printf("PRODUTO %d: %d\n", m + 1, estoque[n][m]);
		}
	}
}
void option3(int estoque[3][4])
{
	int n = 0, m, soma1 = 0, soma2 = 0, soma3 = 0;
	for(n = 0; n < 3; n = n + 1)
	{
		for(m = 0; m < 4; m = m + 1)
		{
			switch(n)
			{
			case 0:
				soma1 = soma1 + estoque[n][m];
				break;
			case 1:
				soma2 = soma2 + estoque[n][m];
				break;
			case 2:
				soma3 = soma3 + estoque[n][m];
				break;
			}
		}
	}
	printf("Total de produtos por armazem:\nARMAZEM 1: %d\nARMAZEM 2: %d\nARMAZEM 3: %d\n", soma1, soma2, soma3);
}
void option4(int estoque[3][4])
{
	int n = 0, m, soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0;
	for(n = 0; n < 4; n = n + 1)
	{
		for(m = 0; m < 3; m = m + 1)
		{
			switch(n)
			{
			case 0:
				soma1 = soma1 + estoque[m][n];
				break;
			case 1:
				soma2 = soma2 + estoque[m][n];
				break;
			case 2:
				soma3 = soma3 + estoque[m][n];
				break;
			case 3:
				soma4 = soma4 + estoque[m][n];
			}
		}
	}
	printf("Total de produtos por armazem:\nPRODUTO 1: %d\nPRODUTO 2: %d\nPRODUTO 3: %d\nPRODUTO 4: %d\n", soma1, soma2, soma3, soma4);
}
void option5(int estoque[3][4], float custo[4])
{
	int n = 0, m;
	float soma1 = 0, soma2 = 0, soma3 = 0, produto;
	for(n = 0; n < 3; n = n + 1)
	{
		for(m = 0; m < 4; m = m + 1)
		{
			produto = custo[m] * estoque[n][m];
			switch(n)
			{
			case 0:
				soma1 = soma1 + produto;
				break;
			case 1:
				soma2 = soma2 + produto;
				break;
			case 2:
				soma3 = soma3 + produto;
				break;
			}
		}
	}
	printf("Custo total por armazem:\nARMAZEM 1: R$ %.2f\nARMAZEM 2: R$ %.2f\nARMAZEM 3: R$ %.2f\n", soma1, soma2, soma3);
}
void option6(int estoque[3][4], float custo[4])
{
	int n = 0, m;
	float soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0;
	for(n = 0; n < 4; n = n + 1)
	{
		for(m = 0; m < 3; m = m + 1)
		{
			switch(n)
			{
			case 0:
				soma1 = soma1 + estoque[m][n];
				break;
			case 1:
				soma2 = soma2 + estoque[m][n];
				break;
			case 2:
				soma3 = soma3 + estoque[m][n];
				break;
			case 3:
				soma4 = soma4 + estoque[m][n];
			}
		}
	}
	printf("Custo total por produto:\nPRODUTO 1: R$ %.2f\nPRODUTO 2: R$ %.2f\nPRODUTO 3: R$ %.2f\nPRODUTO 4: R$ %.2f\n", soma1 * custo[0], soma2 * custo[1], soma3 * custo[2], soma4 * custo[3]);
}
int option7(int estoque[3][4])
{
	int p, a;
	char res[10], c1[5] = "s";
	printf("Digite o numero do produto: ");
	scanf("%d", &p);
	while(p < 1 || p > 4)
	{
		printf("Valor invalido, digite novamente: ");
		scanf("%d", &p);
	}
	printf("Digite o numero do armazem: ");
	scanf("%d", &a);
	while(a < 1 || a > 3)
	{
		printf("Valor invalido, digite novamente: ");
		scanf("%d", &a);
	}
	printf("Quantidade: %d\n", estoque[a - 1][p - 1]);
	printf("Deseja alterar a quantidade?\n");
	scanf("%s", res);
	if(strcmp(res, c1) == 0)
	{
		printf("Nova quantidade: ");
		scanf("%d", &estoque[a - 1][p - 1]);
		while(estoque[a - 1][p - 1] < 0)
		{
			printf("Valor invalido, digite novamente: ");
			scanf("%d", &estoque[a - 1][p - 1]);
		}
		return estoque[a - 1][p - 1];
	}
	else
	{
		return 0;
	}
}
int option8(float custo[4])
{
	int p;
	char res[32], c1[5] = "s";
	printf("Digite o numero do produto: ");
	scanf("%d", &p);
	while(p < 1 || p > 4)
	{
		printf("Valor invalido, digite novamente: ");
		scanf("%d", &p);
	}
	printf("Valor: R$ %f\n", custo[p - 1]);
	printf("Deseja alterar o valor?\n");
	scanf("%s", res);
	if(strcmp(res, c1) == 0)
	{
		printf("Novo valor: R$ ");
		scanf("%f", &custo[p - 1]);
		while(custo[p - 1] < 0)
		{
			printf("Valor invalido, digite novamente: R$");
			scanf("%f", &custo[p - 1]);
		}
		return custo[p - 1];
	}
	else
	{
		return 0;
	}
}
int main()
{
	int escolha
	while(1)
	{
		printf(" MENU\n1 - Estoque por produto\n2 - Estoque por armazem\n3 - Total em cada armazem\n4 - Total de cada produto\n5 - Custo total por armazem\n6 - Custo total por produto\n7 - Alterar quantidade de um produto\n8 - Alterar custo de um produto\n0 - Sair\n");
		scanf("%d", &escolha);
		switch(escolha)
		{
		case 1:
			printf("OPCAO 1 DO MENU\n");
			option1(estoque);
			break;
		case 2:
			printf("OPCAO 2 DO MENU\n");
			option2(estoque);
			break;
		case 3:
			printf("OPCAO 3 DO MENU\n");
			option3(estoque);
			break;
		case 4:
			printf("OPCAO 4 DO MENU\n");
			option4(estoque);
			break;
		case 5:
			printf("OPCAO 5 DO MENU\n");
			option5(estoque, custo);
			break;
		case 6:
			printf("OPCAO 6 DO MENU\n");
			option6(estoque, custo);
			break;
		case 7:
			printf("OPCAO 7 DO MENU\n");
			option7(estoque);
			break;
		case 8:
			printf("OPCAO 8 DO MENU\n");
			option8(custo);
			break;
		default:
			return 0;
		}
	}
}
