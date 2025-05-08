#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/strings
      char arquivo[40];
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //Final da criação de variáveis/strings
      
      printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
      scanf("%s", cpf); //%s refere-se a string
      
      strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
      
      FILE *file; //cria o arquivo
      file = fopen(arquivo, "w"); //cria o arquivo e o"W" significa escrever
      fprintf(file,cpf); // salvo o valor da variavel
      fclose(file); // fecha o arquivo
      
      file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
      fprintf(file,","); 
      fclose(file); //Fecha o arquivo
      
      printf("Digite o nome a ser cadastrado: "); //Mensagem para o usuário
      scanf("%s",nome); //Salvando nome
      
      file = fopen(arquivo, "a"); //Abre arquivo e atualiza
      fprintf(file,nome); //Salva valor da variável
      fclose(file);//Fecha arquivo
      
      file = fopen(arquivo, "a"); //Abre arquivo e atualiza
      fprintf(file,","); //Salva valor da variável
      fclose(file); //Fecha arquivo
      
      printf("Digite o sobrenome a ser cadastrado: "); //Mensagem para o usuário
      scanf("%s",sobrenome); //Armazena valor da variável
      
      file = fopen(arquivo, "a"); //Abre arquivo e atualiza
      fprintf(file,sobrenome); //Armazena valor da variável
      fclose(file); //Fecha arquivo
	  
	  file = fopen(arquivo, "a"); //Abre arquivo e atualiza
	  fprintf(file,","); //Salva valor da variável
	  fclose(file); //Salva valor da variável
	  
	  printf("Digite o cargo a ser cadastrado: "); //Mensagem para o usuário
	  scanf("%s",cargo); //Armazena valor da variável
	  
	  file = fopen(arquivo, "a"); //Abre arquivo e atualiza
	  fprintf(file,cargo); //Salva valor da variável
	  fclose(file); //Fecha o arquivo
	  
	  system("pause"); //Pausa a tela para o usuário ler a mensagem
	          	
}

int consulta() //Função responsável por consultar os usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem
	
	//Início da criação de variáveis/string
     char cpf[40];
     char conteudo[200];
     //Final da criação de variáveis/string
     
     printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
     scanf("%s",cpf); //%s refere-se a string
     
     FILE *file; //Cria o arquivo
     file = fopen(cpf,"r"); //Abre e le o arquivo/ "r" significa ler
     
     if(file == NULL) //Se resultado do arquivo for inexistente manda mensagem para o usuário
     {
     	printf("Não foi possível abrir o arquivo, não localizado!.\n"); //Mensagem para o usuário
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	}
	
	system("pause");


}

int deletar()
{
	//Início da criação das variáveis
	char cpf[40];
	//Final da criação das variáveis
	
	printf("Digte o CPF do usuário a ser deletado: "); //Coletando informação do usuário
	scanf("%s", cpf);
	
	remove(cpf); //Removendo usuário
	
	FILE *file; //Cria arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e lê
	
	if(file == NULL) //Se não houver arquivo
    {
	printf("O usuário não se encontra no sistema!.\n"); //Mensagem para usuário inexistente
	system("pause"); //Pausa para o usuário ler a mensagem
    }
		
}

int main()
{
   int opcao=0; //Definindo Variáveis
   
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   	
   	system("cls");
   
    	setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem
	                            
		printf("!!! Cartório da EBAC !!!\n\n");//Início do menu	                            
		printf("Escolha a opção desejada:\n\n");
 		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		
	switch(opcao) //Inicio da seleção do menu
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
            consulta(); //Chamada de funções
			break;
			
			case 3:
			deletar(); //Chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
	}
	
}
