#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct Conjunto{
	int valores[20];
	int tamanho;
	
	void novoConjunto(){
		printf("Qual o tamanho do conjunto? ");
		scanf("%d%*c",&tamanho);
		printf("\n");
		
		printf("Digite os valores: \n");
		for(int i=0; i<tamanho; i++){
			scanf("%d%*c",&valores[i]);
		}
		printf("\n");
	}
};

struct Math{
	Conjunto conjuntos[10];
	int contador=0;
    int quantidade=0;
	
	void ler(){
		if(contador<10){
			printf("Quantos conjuntos voce deseja cadastrar? ");
			scanf("%d%*c",&quantidade);
			printf("\n");
    	
    		while(quantidade-- && contador<10){
    			printf("Indice = %d\n", contador+1);
				conjuntos[contador].novoConjunto();
				contador++;
				printf("\n");

    			if(contador==10){
    				printf("Voce ja cadastrou muitos conjuntos!\n");
    				printf("\n");
    				break;
				}
			}
		}else{
			printf("Voce ja cadastrou muitos conjuntos!\n");
			printf("\n");
		}
	}
};

int main(){
	int escolha=0;
	Math m;
	
	//zerando os valores (não é necessário)
	//m.zerar();
	
	while(escolha!=6){
		//MENU
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Criar um conjunto vazio\n");
        printf("2 - Ler os dados de um conjunto\n");
        printf("3 - Fazer a uniao de dois conjuntos\n");
        printf("4 - Fazer a intersecao de dois conjuntos\n");
        printf("5 - Imprimir um conjunto\n");
        printf("6 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //vazio
        }else if(escolha==2){
            //ler
            m.ler();
        }else if(escolha==3){
            //uniao
        }else if(escolha==4){
            //intersecao
        }else if(escolha==5){
            //imprimir
        }else if(escolha==6){
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

