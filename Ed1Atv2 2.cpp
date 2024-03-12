#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct Funcionario{
	char nome[100];
	char cargo[100];
	double salarioBase;
	double salarioLiquido;
	double beneficios;
	double descontos;
	
	void novoFuncionario(){
		printf("Nome: ");
		scanf("%[^\n]%*c", nome);
		printf("Cargo: ");
		scanf("%[^\n]%*c", cargo);
		printf("Salario base: ");
		scanf("%lf%*c", &salarioBase);
		printf("Beneficios: ");
		scanf("%lf%*c", &beneficios);
		printf("Descontos: ");
		scanf("%lf%*c", &descontos);
		salarioLiquido=salarioBase+beneficios-descontos;
	}
};

struct Loja{
	Funcionario funcionarios[10];
	int contador=0;
    int quantidade=0;
    
    void zerar(){
		for(int i=0; i<10; i++){
			strcpy(funcionarios[i].nome, "");
			strcpy(funcionarios[i].cargo, "");
			funcionarios[i].salarioBase=0;
			funcionarios[i].salarioLiquido=0;
			funcionarios[i].beneficios=0;
			funcionarios[i].descontos=0;
		}
	}
    
	void cadastrar(){
		if(contador<10){
			printf("Quantos funcionarios voce deseja cadastrar? ");
			scanf("%d%*c",&quantidade);
			printf("\n");
    	
    		while(quantidade-- && contador<10){
    			printf("Indice = %d\n", contador+1);
				funcionarios[contador].novoFuncionario();
				contador++;
				printf("\n");

    			if(contador==10){
    				printf("Voce ja cadastrou muitos funcionarios!\n");
    				printf("\n");
    				break;
				}
			}
		}else{
			printf("Voce ja cadastrou muitos funcionarios!\n");
			printf("\n");
		}
	}
	
	void listar(){
		if(contador==0){
			printf("Voce nao tem funcionarios cadastrados!\n");
			printf("\n");
			return;
		}
		
		for(int i=0; i<contador; i++){
			printf("Indice = %d\n", i+1);
			printf("Nome = %s\n", funcionarios[i].nome);
			printf("Cargo = %s\n", funcionarios[i].cargo);
			printf("Salario Base = %.2lf\n", funcionarios[i].salarioBase);
			printf("Beneficios = %.2lf\n", funcionarios[i].beneficios);
			printf("Descontos = %.2lf\n", funcionarios[i].descontos);
			printf("Salario Liquido = %.2lf\n", funcionarios[i].salarioLiquido);
			printf("\n");
		}
	}
	
	void mediaSalarial(){
		double somaSalarios=0;
		double mediaSalarial=0;
		
		if(contador==0){
			printf("Voce nao tem funcionarios cadastrados!\n");
			printf("\n");
			return;
		}
		
		for(int i=0; i<contador; i++){
			somaSalarios+=funcionarios[i].salarioLiquido;
			mediaSalarial=somaSalarios/contador;
		}
		
		printf("Media Salarial: %.2lf!\n",mediaSalarial);
		printf("\n");
	}
	
	void maiorSalario(){
		double maiorSalario=0;
		int posicaoMaior=0;
		
		if(contador==0){
			printf("Voce nao tem funcionarios cadastrados!\n");
			printf("\n");
			return;
		}
		
		for(int i=0; i<contador; i++){
			if(funcionarios[i].salarioLiquido>maiorSalario){
				maiorSalario=funcionarios[i].salarioLiquido;
				posicaoMaior=i;
			}
		}
		
		printf("Funcionario com maior salario:\n",maiorSalario);
		printf("\n");
		
		printf("Indice = %d\n", posicaoMaior+1);
		printf("Nome = %s\n", funcionarios[posicaoMaior].nome);
		printf("Cargo = %s\n", funcionarios[posicaoMaior].cargo);
		printf("Salario Base = %.2lf\n", funcionarios[posicaoMaior].salarioBase);
		printf("Beneficios = %.2lf\n", funcionarios[posicaoMaior].beneficios);
		printf("Descontos = %.2lf\n", funcionarios[posicaoMaior].descontos);
		printf("Salario Liquido = %.2lf\n", funcionarios[posicaoMaior].salarioLiquido);
		printf("\n");
	}
};

int main(){
	int escolha=0;
	Loja l;
	
	//zerando os valores (não é necessário)
	l.zerar();
	
	while(escolha!=5){
		//MENU
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Cadastrar funcionario\n");
        printf("2 - Listar funcionarios\n");
        printf("3 - Qual a media salarial\n");
        printf("4 - Qual o maior salario\n");
        printf("5 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //cadastrar
            l.cadastrar();
        }else if(escolha==2){
            //listar
            l.listar();
        }else if(escolha==3){
            //media de salarios
            l.mediaSalarial();
        }else if(escolha==4){
            //maior salario
            l.maiorSalario();
        }else if(escolha==5){
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

