#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

#define MAX 10

using namespace std;

struct Conjunto{
	int valores[20];
	int tamanho=-1;
	
	void novoConjunto(){
		while(tamanho>20 || tamanho<0){
			printf("Qual o tamanho do conjunto? (Vazio: 0 | MAX: 20)\n");
			scanf("%d%*c",&tamanho);
			printf("\n");
			
			if(tamanho>20 || tamanho<0){
				printf("Tamanho invalido!\n");
            	printf("\n");
            	continue;
			}
		}
		
		if(tamanho==0){
			//conjunto vazio
			valores[0]=0;
			return;
		}
		
		printf("Digite os valores: \n");
		for(int i=0; i<tamanho; i++){
			scanf("%d%*c",&valores[i]);
		}
		printf("\n");
	}
	
	void mostrarConjunto(){
		if(tamanho==0) printf("(vazio)");
		
		for(int i=0; i<tamanho; i++){
			printf("%d ",valores[i]);
		}
		printf("\n");
	}
};

struct Math{
	Conjunto conjuntos[MAX];
	int contador=0;
    int quantidade=0;
	
	void ler(){
		if(contador<MAX){
			printf("Quantos conjuntos voce deseja cadastrar? ");
			scanf("%d%*c",&quantidade);
			printf("\n");
    	
    		while(quantidade-- && contador<MAX){
    			printf("Indice = %d\n", contador);
				conjuntos[contador].novoConjunto();
				contador++;
				printf("\n");

    			if(contador==MAX){
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
	
	void imprimir(){
		int escolha=0;
		
		if(contador==0){
			printf("Voce nao tem conjuntos cadastrados!\n");
			printf("\n");
			return;
		}
		
		while(escolha!=1 && escolha!=2){
			printf("Voce deseja listar todos ou mostrar um conjunto especifico?\n");
			printf("1 - Listar todos\n");
	        printf("2 - Mostrar um conjunto especifico\n");
			scanf("%d%*c",&escolha);
	        printf("\n");
        
        	if(escolha==1){
	            //listar todos
	            for(int i=0; i<contador; i++){
					printf("Indice = %d\n", i);
					conjuntos[i].mostrarConjunto();
					printf("\n");
				}
	        }else if(escolha==2){
	        	//mostrar especifico
				int indice=0;
	            
	            printf("Digite o INDICE do conjunto: ");
				scanf("%d%*c",&indice);
		        printf("\n");
	            
	            if(indice>contador-1){
	            	printf("Indice nao encontrado!\n");
	            	printf("\n");
	            	return;
				}
	            
				for(int i=0; i<=indice; i++){
					if(i==indice){
						printf("Indice = %d\n", i);
						conjuntos[i].mostrarConjunto();
					printf("\n");
					}
				}
	        }else{
	            printf("Opcao invalida!\n");
	            printf("\n");
	            
	            system("pause");
        		system("cls");
			}
		}
	}
	
	void uniao(){
		int conjA=0;
		int conjB=0;
		int ultimaPosicao=0;
		int falso=0;
		
		if(contador==0){
			printf("Voce nao tem conjuntos cadastrados!\n");
			printf("\n");
			return;
		}else if(contador==MAX){
			printf("Voce ja cadastrou muitos conjuntos!\n");
			printf("\n");
			return;
		}
		
		printf("Digite o INDICE do conjunto A: ");
		scanf("%d%*c",&conjA);
        printf("\n");
        
        if(conjA>contador-1){
        	printf("Indice do Conjunto A nao encontrado!\n");
        	printf("\n");
        	return;
		}
        
        printf("Digite o INDICE do conjunto B: ");
		scanf("%d%*c",&conjB);
        printf("\n");
		
		if(conjB>contador-1){
        	printf("Indice do Conjunto B nao encontrado!\n");
        	printf("\n");
        	return;
		}else if(conjA==conjB){
			printf("Escolha conjuntos (indices) diferentes!\n");
        	printf("\n");
        	return;
		}
		
		printf("Indice = %d\n", contador);
		for(int i=0; i<conjuntos[conjA].tamanho; i++){
			//adicionar todos de conjA a conjX
			conjuntos[contador].valores[i]=conjuntos[conjA].valores[i];
		}
		//salvar aonde parou o conjunto
		ultimaPosicao=conjuntos[conjA].tamanho;
		
		//salvando o tamanho do conjX
		conjuntos[contador].tamanho=conjuntos[conjA].tamanho;
		
		//percorrer todos de conjB pesquisando ele em conjA que é conjX
		for(int i=0; i<conjuntos[conjB].tamanho; i++){
			falso=0;
			for(int j=0; j<conjuntos[conjA].tamanho; j++){
				//se tiver no conjunto, pula e fala que tem
				if(conjuntos[conjB].valores[i]==conjuntos[contador].valores[j]){
					falso=1;
					break;
				}
			}
			
			//conferir se o número já n apareceu mesmo dentro do conjunto
			if(falso==0){
				conjuntos[contador].valores[ultimaPosicao]=conjuntos[conjB].valores[i];
				ultimaPosicao++;
				conjuntos[contador].tamanho++;
			}
		}
		
		contador++;
		printf("\n");
	}
	
	void intersecao(){
		int conjA=0;
		int conjB=0;
		int conjC=0;
		
		if(contador==0){
			printf("Voce nao tem conjuntos cadastrados!\n");
			printf("\n");
			return;
		}else if(contador==MAX){
			printf("Voce ja cadastrou muitos conjuntos!\n");
			printf("\n");
			return;
		}
		
		printf("Digite o INDICE do conjunto A: ");
		scanf("%d%*c",&conjA);
        printf("\n");
        
        if(conjA>contador-1){
        	printf("Indice do Conjunto A nao encontrado!\n");
        	printf("\n");
        	return;
		}
        
        printf("Digite o INDICE do conjunto B: ");
		scanf("%d%*c",&conjB);
        printf("\n");
		
		if(conjB>contador-1){
        	printf("Indice do Conjunto B nao encontrado!\n");
        	printf("\n");
        	return;
		}else if(conjA==conjB){
			printf("Escolha conjuntos (indices) diferentes!\n");
        	printf("\n");
        	return;
		}
		
		//se for fazio
		if(conjuntos[conjA].tamanho==0 || conjuntos[conjB].tamanho==0){
			conjuntos[contador].tamanho=0;
		}
		
		printf("Indice = %d\n", contador);
		//percorrer todos de conjB pesquisando ele em conjA que é conjX
		for(int i=0; i<conjuntos[conjB].tamanho; i++){
			for(int j=0; j<conjuntos[conjA].tamanho; j++){
				//se tiver no conjunto, adiciona
				if(conjuntos[conjB].valores[i]==conjuntos[conjA].valores[j]){
					conjuntos[contador].valores[conjC]=conjuntos[conjB].valores[i];
					conjC++;
					conjuntos[contador].tamanho++;
					break;
				}
			}
		}
		
		contador++;
		printf("\n");
	}
};

int main(){
	int escolha=0;
	Math m;
	
	while(escolha!=5){
		//MENU
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Ler os dados de um conjunto\n");
        printf("2 - Fazer a uniao de dois conjuntos\n");
        printf("3 - Fazer a intersecao de dois conjuntos\n");
        printf("4 - Imprimir um conjunto\n");
        printf("5 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //ler
			m.ler();
        }else if(escolha==2){
            //uniao
            m.uniao();
        }else if(escolha==3){
            //intersecao
            m.intersecao();
        }else if(escolha==4){
            //imprimir
            m.imprimir();
        }else if(escolha==5){
            //sair
            printf("Aluno: Joao Augusto Marciano Silva\n");

            return 0;
        }else{
            printf("Opcao invalida!\n");
            printf("\n");
        }

        system("pause");
        system("cls");
    }
    
	return 0;
}
