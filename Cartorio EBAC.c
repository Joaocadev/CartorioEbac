#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por registrar novos usuários
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Informe o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Armazena os dados informados pelo usuário, dados tipo string
	//%s é usado toda vez que preciso salvar uma string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Acessa o arquivo FILE e cria um arquivo file
	file = fopen(arquivo, "w"); //w = write
	fprintf(file,cpf); //Salvar no arquivo a variável cpf
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Vai abrir o arquivo existente 
	fprintf(file, ","); //O comando vai separar os arquivos para não ficarem todos juntos na mesma linha
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

int consultar() //Função responsável por consultar os usuários
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
		printf("Arquivo não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	fclose(file);
}

int deletar() //Função responsável por deletar os usuários
{
	//Início da variável
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf); //Comando para exclusão de dado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado! \n");
		system("pause");
	}
}

int main()//Função
{
	int opcao=0; //definindo variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); //Comando para deletar a tela
	   
	   setlocale(LC_ALL, "Portuguese");//Definindo a linguaguem
	
	   printf("Cartório da EBAC\n\n");
//Tela de início	
	   printf("Olá! Seja bem-vindo ao Cartório da EBAC!\n\n");
	   printf("Para continuar, escolha uma das opções abaixo.\n\n");
//Menu de escolhas
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Opção: ");
	
		//scanf = scanear a opção que o usuário colocar
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		//O sistema deleta todas as mensagens anteriores
		system("cls");
		
		switch(opcao)//Seleção disponível para o usuário
		{
			case 1: //Chamada de funções
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
			printf("Opção inválida.\n");
			system("pause");
			break;
			//Fim da seleção
		}
		
	}
	printf("Este software é de uso exclusivo de João Carlos Pereira Alves\n");
	
}
