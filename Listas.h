#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Declaracao de structs

typedef struct Onibus{
	char nome[201];
	int linha;
	Horarios primeiro;
	struct Onibus *proximo;
	struct Onibus *anterior;
} Onibus;

typedef struct Horarios{
	int hora;
	int minuto;
	struct Onibus *proximo;
	struct Onibus *anterior;
} Horarios;

typedef struct {
	Onibus *primeiro;
	Onibus *ultimo;
} lista;

void Inicializar( lista* l ) {
	l->primeiro = NULL;
	l->ultimo = NULL;
}

void Inserir(lista *l, int linha, char nome[], int hora, int min)
{
	//Verifica se ja temos uma linha de onibus cadastrado
	if(l->primeiro)
	{
		Onibus corredor = l->primeiro;
		//Verifica se ja tem o onibus
		while(corredor != NULL)
		{	
			//Verifica se existe o registro
			if(linha <= corredor->linha)
			{
				//Se ja tiver, basta inserir o horario
				if(linha == corredor->linha)
				{
					InserirHorario(corredor, hora, min);
					return;
				}
				//Se nao, paramos o while e adicionamos
				else
				{
					Onibus *oni = (Onibus*)malloc(sizeof(Onibus));		
					//Verifica se temos memória
					if(oni)
					{
						//Inserimos valores no onibus
						oni->linha = linha
						strcpy (oni->nome, nome);
						InserirHorario(oni, hora, min);
						//Verifica se ja podemos inserir
						//Ordena a lista
						oni->proximo = corredor;
						if(corredor->anterior != NULL)
						{
							oni->anterior = corredor->anterior;
							corredor->anterior->proximo = oni;
							corredor->anterior = oni;	
						}
						//Inserindo o primeiro registro;
						else
						{
							corredor->anterior = oni;
							oni->anterior = NULL;
							l->primeiro = oni;	
						}				
						return;
					}
				}			
			}
			else
			{
				corredor = corredor->proximo;
			}
		}//Fim While;	
		InserirFim(l, linha, nome, hora, min);
	}//Fim if(l);
	//Primeiro registro
	else
	{
		Onibus *oni = (Onibus*)malloc(sizeof(Onibus));		
		//Preenche Oni
		oni->linha = linha
		strcpy (oni->nome, nome);
		InserirHorario(oni, hora, min);
		//Ajusta lista
		oni->proximo = NULL;
		oni->anterior = NULL;
		//Ajusta Lista
		l->primeiro = oni;
	}
	return;
}

void InserirFim(lista *l, int linha, char nome[], int hora, int min)
{
	Onibus *oni = (Onibus*)malloc(sizeof(Onibus));
	oni->linha = linha;
	strcpy(oni->nome, nome);
	InserirHorario(oni, hora, min);
	
	oni->anterior = exUltimo;
	oni->proximo = NULL;;
	exUltimo->proximo = aluno;
	l->ultimo = oni;
}

void ProcuraLinha(lista *l, int linha)
{
	ListaLinha list;
	list = l->primeiro;
	while(list != l->primeiro)
	{
		if(list->linha == linha)
			return list;
		list = list->proximo;
	}
	
}

void InserirHorario(Onibus *oni,int hora,int min);
{
	//Verifica se ja tem horarios
	if(oni->primeiro)
	{
		Horarios corredor = oni->primeiro;
		//Verifica se ja tem o onibus
		while(corredor != NULL)
		{	
			//Verifica se existe o registro
			if(linha <= corredor->linha)
			{
				//Se ja tiver, basta inserir o horario
				if(linha == corredor->linha)
				{
					InserirHorario(corredor, hora, min);
					return;
				}
				//Se nao, paramos o while e adicionamos
				else
				{
					Onibus *oni = (Onibus*)malloc(sizeof(Onibus));		
					//Verifica se temos memória
					if(oni)
					{
						//Inserimos valores no onibus
						oni->linha = linha
						strcpy (oni->nome, nome);
						InserirHorario(oni, hora, min);
						//Verifica se ja podemos inserir
						//Ordena a lista
						oni->proximo = corredor;
						if(corredor->anterior != NULL)
						{
							oni->anterior = corredor->anterior;
							corredor->anterior->proximo = oni;
							corredor->anterior = oni;	
						}
						//Inserindo o primeiro registro;
						else
						{
							corredor->anterior = oni;
							oni->anterior = NULL;
							l->primeiro = oni;	
						}				
						return;
					}
				}			
			}
			else
			{
				corredor = corredor->proximo;
			}
		}//Fim While;	
		InserirFim(l, linha, nome, hora, min);
	}//Fim if(l);
	//Primeiro registro
	else
	{
		Horarios *horario = (Horarios*)malloc(sizeof(Horarios));		
		//Preenche o horario
		horario->hora = linha;
		horario->minuto = min;
		//Ajusta lista
		horario->proximo = horario;
		horario->anterior = horario;
		//Ajusta Lista
		oni->primeiro = oni;
	}
	return;

	
}

