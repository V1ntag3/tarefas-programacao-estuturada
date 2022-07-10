#include <stdio.h>
struct tcandidato
{
	int id;
	int quest[10];
};
void cadastro(struct tcandidato vet[], int j)
{
	int i, k;
	for(k = 0; k < j; k++)
	{
		printf("Qual o id: ");
		scanf("%d", &vet[k].id);
		for(i = 0; i < 10; i++)
		{
			printf("Questao %d: ", i + 1 );
			scanf("%d", &vet[k].quest[i]);
		}
	}
}
int somaPontuacao(struct tcandidato vet[], int j )
{
	int i, soma = 0;
	for(i = 0; i < 10; i++)
	{
		soma = soma + vet[j].quest[i];
	}
	return soma;
}
void imprimirCandidato(struct tcandidato vet[], int j)
{
	int i;
	printf("Id do candidato: %d\n", vet[j].id);
	for(i = 0; i < 10; i++)
	{
		printf("Nota da questao %d: %d\n", i + 1, vet[j].quest[i]);
	}
}
void listarCandidatos (struct tcandidato vet[], int j)
{
	int k;
	for(k = 0; k < j; k++)
	{
		imprimirCandidato(vet, k);
		printf("Soma da pontuacao: %d\n", somaPontuacao(vet, k));
	}
}

int main()
{
	int j;
	printf("Quantos candidatos participaracao dessa prova?\n");
	scanf("%d", &j);
	while(j > 100 || j < 0)
	{
		printf("Valor invalido coloque novamente: ");
		scanf("%d", &j);
	}
	struct tcandidato vet[j];
	cadastro(vet, j);
	listarCandidatos (vet, j);

	return 0;
}
