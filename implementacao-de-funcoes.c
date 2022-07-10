#include <stdio.h>

void troca(int vet[], int n, int num, int novo)
{
	int j;
	//TROCA DO MENOR no vetor por novo
	for(j = 0; j < n; j++)
	{
		if (vet[j] == num)
			vet[j] = novo;
	}
}

int menorElemento(int v[], int n, int novo)
{
	int i, menor, j;
	int vet[50];

	for (i = 0; i < n; i++)
		vet[i] = v[i];

	i = 0;
	while (vet[i] == novo)
	{
		i++;
	}
	//DESCOBRIR O MENOR, diferente de novo
	menor = vet[i];
	for (j = i + 1; j < n; j++)
	{
		if ((vet[j] < menor) && (vet[j] != -1))
			menor = vet[j];
	}

	return menor;
}

void recentes (int vetA[], int vetB[], int n, int x)
{
	int menor;
	int i, j;

	for (j = 0; j < x; j++)
	{
		menor = menorElemento(vetB, n, -1);
		printf("Ha %d meses: ", menor);
		for (i = 0; i < n; i++)
		{
			if (vetB[i] == menor)
			{
				printf("%d ", vetA[i]);
			}
		}
		printf("\n");
		troca(vetB, n, menor, -1);
	}
}

int pertence (int vet[], int q, int m)
{
	int i;
	for(i = 0; i < q; i++)
	{
		if (vet[i] == m)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int A[50];
	int B[50];
	int quant, i;
	int mes;
	printf("Digite quantos funcionarios deseja informar: ");
	scanf("%d", &quant);
	if (quant > 50)
		return 0;
	for (i = 0; i < quant; i++)
	{
		printf("Digite a matricula do funcionario: ");
		scanf("%d", &A[i]);
		while(pertence(A, i, A[i]) == 1)  //chamada da função
		{
			printf("Matricula ja existe. Digite novamente:");
			scanf("%d", &A[i]);
		}
		printf("Digite o tempo de servico em meses: ");
		scanf("%d", &B[i]);//supoe que o usuario digitara corretamente
	}
	printf("Quantidade de meses a serem cosiderados:");
	scanf("%d", &mes);
	recentes(A, B, quant, mes);	//chamada da função
	return 0;
}
