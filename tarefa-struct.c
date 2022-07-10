#include <stdio.h>
struct conta
{
	int codigo;
	float preco;
	int quantidade;
};
struct pedido
{
	int codped;
	int quantped;
};

int main()
{
	struct conta p[100];
	struct pedido o;
	float valort;
	int i;
	for(i = 0; i < 100; i++)
	{
		printf("Digite o codigo: ");
		scanf("%d", &p[i].codigo);
		printf("Digite o preco: ");
		scanf("%f", &p[i].preco);
		printf("Digite a quantidade: ");
		scanf("%d", &p[i].quantidade);
	}
	o.codped = 1;
	while(o.codped >= 0)
	{
		printf("Digite o codigo do produto que voce deseja: ");
		scanf("%d", &o.codped);
		if(o.codped < 0)
		{
			return 0;
		}
		for(i = 0; p[i].codigo != o.codped; i++)
		{
		}
		printf("Digite a quantidade que voce deseja: ");
		scanf("%d", &o.quantped);
		if(o.quantped > p[i].quantidade)
		{
			printf("Desculpe porem não temos essa quantidade em estoque\n");
		}
		else
		{
			p[i].quantidade = p[i].quantidade - o.quantped;
			valort = o.quantped * p[i].preco;
			printf("Pedido realizado com sucesso.\n");
			printf("Valor total do pedido: %f\n ", valort);
		}
	}
	for(i = 0; i < 100; i++)
	{
		printf("Codigo do produto %d: %d" , i + 1, p[i].codigo);
		printf("Preco do produto %d: %f", i + 1, p[i].preco);
		printf("Quantidade do produto %d: %d", i + 1, p[i].quantidade);
	}

	return 0;
}








