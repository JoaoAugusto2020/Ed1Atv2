#include<iostream>
#include<bits/stdc++.h>
#include<ctime>

//#define diaAtual 07
//#define mesAtual 03
//#define anoAtual 2024

using namespace std;

int hojeDia(){
	//PEGAR DATA ATUAL
	time_t timer;
  	struct tm *horarioLocal;
  	
  	time(&timer); // Obtem informações de data e hora
  	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
  	
	return horarioLocal->tm_mday;
}

int hojeMes(){
	//PEGAR DATA ATUAL
	time_t timer;
  	struct tm *horarioLocal;
  	
  	time(&timer); // Obtem informações de data e hora
  	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
  	
	return horarioLocal->tm_mon + 1;
}

int hojeAno(){
	//PEGAR DATA ATUAL
	time_t timer;
  	struct tm *horarioLocal;
  	
  	time(&timer); // Obtem informações de data e hora
  	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
  	
	return horarioLocal->tm_year + 1900;
}
	
struct CalcularIdade {
	int idade;
	int diaAtual = hojeDia();
	int mesAtual = hojeMes();
	int anoAtual = hojeAno();
    int dataDia;
    int dataMes;
    int dataAno;
	
    int calcular(){
    	printf("Data de nascimento: \n");
    	printf("\tDia ");
		scanf("%d%*c",&dataDia);
    	printf("\tMes ");
		scanf("%d%*c",&dataMes);
    	printf("\tAno ");
		scanf("%d%*c",&dataAno);

        if(mesAtual<=dataMes){
        	if(diaAtual<dataDia){
        		//Ainda não fez aniversário
        		idade=(anoAtual-dataAno)-1;
			}else{
				//Já fez aniversário
				idade=anoAtual-dataAno;
			}
		}else{
			//Já fez aniversário
			idade=anoAtual-dataAno;
		}

		return idade;
    }
    
    void hoje(){
    	cout<<"Data: "<<diaAtual<<"/"<< mesAtual<<"/"<< anoAtual<<endl;
	}
};

struct Cliente{
	char nome[100];
	int idade;
    CalcularIdade calcId;
    char sexo[1];
	
    void novoCliente(){
    	printf("Nome: ");
		scanf("%[^\n]%*c", nome);
		//fflush(stdin); (não é necessário)
		
		idade = calcId.calcular();
		
		printf("Sexo: ");
		scanf("%[^\n]%*c", sexo);
		//fflush(stdin); (não é necessário)
	}
};

struct Sistema{
	Cliente clientes[50];
    int contador=0;
    int quantidade=0;
	
	void zerar(){
		for(int i=0; i<50; i++){
			strcpy(clientes[i].nome, "");
			clientes[i].idade = 0;
			strcpy(clientes[i].sexo, "");
		}
	}
	
	void cadastrar(){
		if(contador<50){
			printf("Quantos clientes voce deseja cadastrar? ");
			scanf("%d%*c",&quantidade);
			printf("\n");
    	
    		while(quantidade-- && contador<50){
    			printf("Indice = %d\n", contador+1);
				clientes[contador].novoCliente();
				contador++;
				printf("\n");

    			if(contador==50){
    				printf("Voce ja cadastrou muitos clientes!\n");
    				printf("\n");
    				break;
				}
			}
		}else{
			printf("Voce ja cadastrou muitos clientes!\n");
			printf("\n");
		}
	}

	void listar(){
		if(contador==0){
			printf("Voce nao tem clientes cadastrados!\n");
			printf("\n");
			return;
		}
		
		for(int i=0; i<contador; i++){
			printf("Indice = %d\n", i+1);
			printf("Nome = %s\n", clientes[i].nome);
			printf("Idade = %d\n", clientes[i].idade);
			printf("Sexo = %s\n", clientes[i].sexo);
			printf("\n");
		}
	}
};

int main(){
	int escolha=0;
	Sistema s;
	
	//zerando os valores (não é necessário)
	s.zerar();
	
	while(escolha!=3){
		//MENU
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //cadastrar
            s.cadastrar();
        }else if(escolha==2){
            //listar
            s.listar();
        }else if(escolha==3){
            //sair
            printf("Aluno: Joao Augusto Marciano Silva\n");
            printf("\n");

            return 0;
        }else{
            printf("\n");
            printf("Opcao invalida!\n");
            printf("\n");
        }

        system("pause");
        system("cls");
    }

	return 0;
}

