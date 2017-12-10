#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaracao de structs
typedef struct Cadastro{
	char nome[201];
	int num1;
	int num2;
	struct Aluno *proximo;
	struct Aluno *anterior;
} Cadastro;

typedef struct {
	Cadastro *primeiro;
	Cadastro *ultimo;
} lista;


int main()
{
	lista l;
	//Inicializar(&l);
	Cadastro *aluno;
	
	int num1,num2;
	char nome[201] = "";
	
    int opcao = 1;
    while(opcao != 0)
    {
		//Menu Interativo
		printf(
		"\n0 - Liberar memoria"
		"\n1 - Inserir(RA,nome,ano)"
		"\n2 - Procurar(RA): Nome/Ano"
		"\n3 - Procurar(nome): RAs"
		"\n4 - Procurar(RA): Posicaoo"
		"\n5 - Remover(RA)"
		"\n6 - Imprimir()\n\n");
		
		//Scaneia a opcao
		scanf("%d",&opcao);
		
		//Aciona a opcao selecionada
		switch(opcao)
		{
			case 0://limpar
				Limpar(&l);			
			break;
			case 1://inserir
				scanf("%d %200[^\n] %d", &ra, nome, &ano);
				Inserir(&l, ra, nome, ano);
			break;
			case 2://procura ra: nome/ano
				scanf("%d", &ra);
				aluno = ProcurarRA(&l, ra);
				if(aluno)
				{
					printf("%s %d\n", aluno->nome, aluno->ano);
				}
				else
				{
					printf("INEXISTENTE\n");
				}
			break;
			case 3://procura nome: ras
				getchar();
				scanf("%200[^\n]", nome);
				int achou = ProcurarNome(&l, nome);
				if(achou)
				{
					printf("\n");
				}
				else
				{
					printf("INEXISTENTE\n");
				}
			break;
			case 4://procura ra: posicao
				scanf("%d", &ra);
				int a = ProcurarRA_posi(&l, ra);
				if(a)
					printf("%d\n", a);
				else
					printf("INEXISTENTE\n");	
			break;
			case 5://remover
				scanf("%d", &ra);
				Remover(&l, ra);
			break;
			case 6://Imprimir
				Imprimir(&l);
			break;
		}
	}
}
