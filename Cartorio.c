#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/strings
      char arquivo[40];
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //Final da cria��o de vari�veis/strings
      
      printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
      scanf("%s", cpf); //%s refere-se a string
      
      strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
      
      FILE *file; //cria o arquivo
      file = fopen(arquivo, "w"); //cria o arquivo e o"W" significa escrever
      fprintf(file,cpf); // salvo o valor da variavel
      fclose(file); // fecha o arquivo
      
      file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
      fprintf(file,","); 
      fclose(file); //Fecha o arquivo
      
      printf("Digite o nome a ser cadastrado: "); //Mensagem para o usu�rio
      scanf("%s",nome); //Salvando nome
      
      file = fopen(arquivo, "a"); //Abre arquivo e atualiza
      fprintf(file,nome); //Salva valor da vari�vel
      fclose(file);//Fecha arquivo
      
      file = fopen(arquivo, "a"); //Abre arquivo e atualiza
      fprintf(file,","); //Salva valor da vari�vel
      fclose(file); //Fecha arquivo
      
      printf("Digite o sobrenome a ser cadastrado: "); //Mensagem para o usu�rio
      scanf("%s",sobrenome); //Armazena valor da vari�vel
      
      file = fopen(arquivo, "a"); //Abre arquivo e atualiza
      fprintf(file,sobrenome); //Armazena valor da vari�vel
      fclose(file); //Fecha arquivo
	  
	  file = fopen(arquivo, "a"); //Abre arquivo e atualiza
	  fprintf(file,","); //Salva valor da vari�vel
	  fclose(file); //Salva valor da vari�vel
	  
	  printf("Digite o cargo a ser cadastrado: "); //Mensagem para o usu�rio
	  scanf("%s",cargo); //Armazena valor da vari�vel
	  
	  file = fopen(arquivo, "a"); //Abre arquivo e atualiza
	  fprintf(file,cargo); //Salva valor da vari�vel
	  fclose(file); //Fecha o arquivo
	  
	  system("pause"); //Pausa a tela para o usu�rio ler a mensagem
	          	
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem
	
	//In�cio da cria��o de vari�veis/string
     char cpf[40];
     char conteudo[200];
     //Final da cria��o de vari�veis/string
     
     printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
     scanf("%s",cpf); //%s refere-se a string
     
     FILE *file; //Cria o arquivo
     file = fopen(cpf,"r"); //Abre e le o arquivo/ "r" significa ler
     
     if(file == NULL) //Se resultado do arquivo for inexistente manda mensagem para o usu�rio
     {
     	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //Mensagem para o usu�rio
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
	//In�cio da cria��o das vari�veis
	char cpf[40];
	//Final da cria��o das vari�veis
	
	printf("Digte o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	remove(cpf); //Removendo usu�rio
	
	FILE *file; //Cria arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e l�
	
	if(file == NULL) //Se n�o houver arquivo
    {
	printf("O usu�rio n�o se encontra no sistema!.\n"); //Mensagem para usu�rio inexistente
	system("pause"); //Pausa para o usu�rio ler a mensagem
    }
		
}

int main()
{
   int opcao=0; //Definindo Vari�veis
   
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   	
   	system("cls");
   
    	setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem
	                            
		printf("!!! Cart�rio da EBAC !!!\n\n");//In�cio do menu	                            
		printf("Escolha a op��o desejada:\n\n");
 		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		
	switch(opcao) //Inicio da sele��o do menu
		{
			case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
            consulta(); //Chamada de fun��es
			break;
			
			case 3:
			deletar(); //Chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
	}
	
}
