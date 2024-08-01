#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de comunica��o de aloca��o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//Fun��o de cadastrar os usu�rios
{
	//inicio de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando info do usu�rio
	scanf("%s", cpf);//%s string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria��o do arquivo
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
		printf("N�o foi poss�vel abrir o arquivo, n�o encontrado!.");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
    char cpf[40];
    
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado!.\n");
		system("pause");
	}
	
}


int main()
    {
	int opcao=0; //Definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    system("cls");//responsavel por limpar a tela
	
	    printf("### Cart�rio WW ###\n\n"); //inicio do menu
	    printf ("Escolher a op��o:\n\n");
	    printf ("\t1 - Registrar Usu�rio\n");
	    printf ("\t2 - Consultar Usu�rio\n");
        printf ("\t3 - Deletar Usu�rio\n\n"); 
        printf("Op��o: ");//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();	//chamada de fun��es
    	    break;
    	    
    	    case 2:
    	    consulta();
    	    break;
    	    
    	    case 3:
    	    deletar(); //
	        break;
	        
	        default:
	        printf("Essa op��o n�o est� dispon�vel!\n");
    	    system("pause");
    	    break;
    	    //fim da sele��o
	
		}
	}			  
}
	



