#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [60];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando inf do user
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / "w" = write(escrevrer)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: "); //Recebendo o usu�rio a ser consultado
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Esse CPF n�o foi encontrado! \n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	
	if(file == NULL)
	{
		printf("Este CPF n�o existe no sistema!.\n");
		system("pause");
	}
	
	while(file != NULL)
	{
		printf("O usu�rio foi deletado com sucesso!\n\n");
		system("pause");
	}
}




int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("---Cart�rio da EBAC---\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		
		for(laco=1;laco=1;)
		{
	
			system("cls"); //limpa a tela
	
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf(" ### Cart�rio da EBAC ### \n\n");
			printf("Escolha a op��o desejada no menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando informa��es
	
			system("cls");
		
		
			switch(opcao)
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();	
				break;
			
				case 3:
				deletar();	
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");	
				return 0;
				break; 
			
				default:
					printf("Essa opcao nao existe!\n");
					system("pause");
				break;
			}
		}
	}
	else
		printf("Senha incorreta!");
}
