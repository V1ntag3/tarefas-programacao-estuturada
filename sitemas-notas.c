#include <stdio.h>
#include <string.h>
int main()
{
	int x, nota_abaixo, total, total_7;
	float soma, a , soma_7, media, media_7, nota_menor, nota_maior;
	char resp[3], resps[] = "sim";
	nota_menor = 10;
	nota_maior = 0;
	nota_abaixo = 0;
	total = 0;
	total_7 = 0;
	x = 1;

	while(x == 1)
	{
		printf("Digite sua nota: ");
		scanf("%f", &a);

		if(a >= 0 && a <= 10)
		{
			if(nota_maior < a)
			{
				nota_maior = a;
			}
			if(nota_menor > a)
			{
				nota_menor = a;
			}
			if(a < 4)
			{
				nota_abaixo = nota_abaixo + 1;
			}
			if(a >= 7 )
			{
				soma_7 = soma_7 + a;
				total_7 = total_7 + 1;
			}
			if(a >= 9)
			{
				printf("Nota Excelente!\n");
			}
			else if(a < 7)
			{
				printf("Estude mais!\n");
			}
			soma = soma + a;
			total = total + 1;
			printf("Deseja digitar mais uma nota? sim ou nao\n");
			scanf(" %s", &resp);
			if(strcmp(resp, resps) == 0)
			{
				x = 1;
			}
			else
			{
				x = 0;
			}
		}
	}
	media = soma / total;
	media_7 = soma_7 / total_7;
	printf("Notas abaixo de 4: %d\n", nota_abaixo);
	printf("Maior nota: %.2f\n", nota_maior);
	printf("Menor nota: %.2f\n", nota_menor);
	printf("Media de todas as notas: %.2f\n", media);
	printf("Media de todas as notas maiores que 7: %.2f\n", media_7);

	return 0;
}
