#include <stdio.h>
struct tConta
{
	int conta;
	int agencia;
	float saldo;
} c;

void atualizaSaldo(tConta *c, float vet[quant], int quant)
{
	for(i = 0; i < quant; i++)
	{
		c.saldo = c.saldo + vet[i];
	}
	printf("Valor do saldo atualizado: %f", c.saldo);
}
