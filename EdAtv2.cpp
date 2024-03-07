#include<iostream>
#include<string.h>
#include<time.h>

#define anoAtual 2024
#define mesAtual 03
#define diaAtual 07

using namespace std;

struct Idade {
    int dataAno;
    int dataMes;
    int dataDia;

    int calcular(){
        scanf("Data de nascimento (dd/mm/aaaa): %d/%d/%d \n",&dataDia ,&dataMes ,&dataAno);
    }

};

struct Cliente {
    char nome[100] = "";
    Idade idade;
    char sexo;
};

struct Gerencia {
    Cliente clientes[50];
    int contador=0;

    void zerar(){
        /*for(int i=0; i<50; i++){
            strcpy(nome, "");
            strcpy(sexo, '');
        }*/
    }

    void cadastrar(){
        int qtd=0;

        if(contador<=49){
            cout<<"Quantos clientes voce quer cadastrar?"
            cin>>qtd;

            while(qtd-- && contador<=49){
                scanf("Nome: %s \n", nome);
                idade();
                scanf("Sexo: %s \n", sexo);
            }
            contador++;
        }else{
            printf("Jean voce ja cadastrou o maximo de livros!\n");
        }
    }

    void listar(){
        if(contador==0){
            cout<<"Voce nao tem clientes cadastrados"<<endl;
            return;
        }
        for(int i=0; i<=contador; i++){
            printf("Indice = %d \n", i+1);
            printf("Nome: %s \n", nome);
            printf("Idade: %d \n", idade);
            printf("Sexo: %s \n", sexo);
            printf("\n");
        }
    }
};

int main(){
    Gerencia g;
    int escolha=0;

    g.zerar();

    while(escolha!=3){
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar\n");
        printf("3 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //cadastrar
            g.cadastrar();
        }else if(escolha==2){
            //listar
            g.listar();
        }else if(escolha==3){
            //sair

            printf("Aluno:\n");
            printf("Joao Augusto Marciano Silva:\n");
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
