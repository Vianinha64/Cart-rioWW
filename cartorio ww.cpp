#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de comunicação de alocação em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//Função de cadastrar os usuários
{
	//inicio de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando info do usuário
	scanf("%s", cpf);//%s string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //criação do arquivo
	file = fopen(arquivo, "w");
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()//consulta de info 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não encontrado!.");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
    char cpf[40];
    
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado!.\n");
		system("pause");
	}
	
}


int main()
    {
	int opcao=0; //Definindo variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    system("cls");//responsavel por limpar a tela
	
	    printf("### Cartório WW ###\n\n"); //inicio do menu
	    printf ("Escolher a opção:\n\n");
	    printf ("\t1 - Registrar Usuário\n");
	    printf ("\t2 - Consultar Usuário\n");
        printf ("\t3 - Deletar Usuário\n\n"); 
        printf("Opção: ");//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();	//chamada de funções
    	    break;
    	    
    	    case 2:
    	    consulta();
    	    break;
    	    
    	    case 3:
    	    deletar(); //
	        break;
	        
	        default:
	        printf("Essa opção não está disponível!\n");
    	    system("pause");
    	    break;
    	    //fim da seleção
	
		}
	}			  
}
	



