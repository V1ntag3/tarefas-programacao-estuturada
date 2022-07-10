#include <stdio.h>
#define MAX 20

typedef struct data
{
	int dia;
	int mes;
	int ano;
} tdata;

tdata datas[MAX];
int pos = 0;

//char numstr[40];

int menu()
{
	int res;
	printf("1-Adicionar\n");
	printf("2-Imprimir todas as datas\n");
	printf("3-Gravar no arquivo\n");
	printf("4-Recupera do arquivo\n");
	printf("0-Sair\n");
	printf("Digite um opcao do menu: ");
	scanf("%d", &res);
	return res;
}

void novaData()
{
	if (pos < MAX)
	{
		printf("Digite o dia: ");
		scanf("%d", &datas[pos].dia);
		printf("Digite o mes: ");
		scanf("%d", &datas[pos].mes);
		printf("Digite o ano: ");
		scanf("%d", &datas[pos].ano);
		pos++;
	}
	else
		printf("CHEIO!!!\n");
}

void lista()
{
	int i;
	for(i = 0; i < pos; i++)
	{
		printf("%d/%d/%d\n", datas[i].dia, datas[i].mes, datas[i].ano);
	}
}

void gravaArq()
{
	FILE *arq;
	char nomeArquivo[100]; // guarda o nome do arquivo
	if (pos == 0)
	{
		printf("LISTA VAZIA!!!\n");
		return;
	}
	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);


	arq = fopen(nomeArquivo, "wb");
	if (arq == NULL   )
		printf ("O arquivo %s nao pode ser criado.\n", nomeArquivo);
	else
	{
		fwrite(datas, sizeof(tdata), pos, arq);/*Aqui todos os 'pos' registros
                   estão sendo gravados no arquivo indicado por 'arq'. Cada
                   registro tem o tamanho 'sizeof(tdata)'. O
                   endereço inicial onde estão esses registros está em 'datas'
                   (pois datas é o endereço inicial do vetor,
                   também poderíamos gravar os registros um a um através de um
                   'for', passando o endereço de cada registro a ser gravado,
                   &datas[i]...).
                   */

		fclose(arq);
		printf("Numero de registros gravados: %d\n", pos);
	}
}

void leArq()
{
	FILE *arq;
	char nomeArquivo[100]; // guarda o nome do arquivo
	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);
	arq = fopen(nomeArquivo, "rb");
	if (arq == NULL)
		printf ("O arquivo %s nao pode ser lido.\n", nomeArquivo);
	else
	{
		pos = 0;
		while ( pos < MAX )
		{
			// a função fread devolve o número de itens lidos, por isso que abaixo comparamos com 1
			// para verificar se realmente 1 elemento foi lido e não se chegou no final do arquivo.
			if (fread(&datas[pos], sizeof(tdata), 1, arq) != 1)
				break;
			pos++;
		}
		fclose(arq);
		printf("Arquivo lido!\n");
		printf("Numero total de datas: %d\n", pos);
	}


}
int main()
{
	int opcao;
	do
	{
		opcao = menu();
		switch(opcao)
		{
		case 1:
			novaData();
			break;
		case 2:
			lista();
			break;
		case 3:
			gravaArq();
			break;
		case 4:
			leArq();
			break;
		case 0:
			break;
		default:
			printf("Opcao invalida!\n");
		}
	}
	while(opcao != 0);

	return 0;
}


