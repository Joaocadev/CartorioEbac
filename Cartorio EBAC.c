#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por registrar novos usu�rios
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Informe o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Armazena os dados informados pelo usu�rio, dados tipo string
	//%s � usado toda vez que preciso salvar uma string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Acessa o arquivo FILE e cria um arquivo file
	file = fopen(arquivo, "w"); //w = write
	fprintf(file,cpf); //Salvar no arquivo a vari�vel cpf
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Vai abrir o arquivo existente 
	fprintf(file, ","); //O comando vai separar os arquivos para n�o ficarem todos juntos na mesma linha
	fclose(file); //Fecha o arquivo
	
	printf("Informe o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Informe o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Informe o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
		
}

int consultar() //Fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40]; //Char = caracteres do tipo string
	char conteudo[200];
	
	printf("Informe o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Comando para ler o arquivo, r = reading
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	fclose(file);
}

int deletar() //Fun��o respons�vel por deletar os usu�rios
{
	//In�cio da vari�vel
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf); //Comando para exclus�o de dado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado! \n");
		system("pause");
	}
}

int main()//Fun��o
{
	int opcao=0; //definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); //Comando para deletar a tela
	   
	   setlocale(LC_ALL, "Portuguese");//Definindo a linguaguem
	
	   printf("Cart�rio da EBAC\n\n");
//Tela de in�cio	
	   printf("Ol�! Seja bem-vindo ao Cart�rio da EBAC!\n\n");
	   printf("Para continuar, escolha uma das op��es abaixo.\n\n");
//Menu de escolhas
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Op��o: ");
	
		//scanf = scanear a op��o que o usu�rio colocar
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		//O sistema deleta todas as mensagens anteriores
		system("cls");
		
		switch(opcao)//Sele��o dispon�vel para o usu�rio
		{
			case 1: //Chamada de fun��es
			registro();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por acessar o sistema!\n");
			return 0;
			break;	
			
			default:
			printf("Op��o inv�lida.\n");
			system("pause");
			break;
			//Fim da sele��o
		}
		
	}
	printf("Este software � de uso exclusivo de Jo�o Carlos Pereira Alves\n");
	
}
