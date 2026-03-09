//Abaixo estamos carregando a biblioteca Standart Input Output para usarmos os comandos de entrada e saída de dados
//scanf (scan file) e saída printf (print file) de dados do usuário

#include <stdio.h>
// Uma biblioteca é um conjunto de códigos pré-escritos que podem ser reutilizados em diferentes programas. Elas fornecem funcionalidades específicas, como manipulação de arquivos, operações matemáticas, ou entrada e saída de dados, sem a necessidade de escrever o código do zero. As bibliotecas ajudam a economizar tempo e esforço, permitindo que os programadores se concentrem na lógica do programa em vez de reinventar a roda para tarefas comuns.

/*
Escreva um programa que solicite ao usuário Nome, Sexo, Idade e as três notas dos N alunos em uma turma,
e ao final apresente:
1) Quantidade de alunos cadastrados na turma;
2) Quantidade de alunos e alunas (%) aprovados / reprovados na turma;
3) Media de idade dos alunos aprovados / reprovados
4) Gerar relatorio de alunos aprovados / reprovados 
5) Tornar configuravel:
 - A média de aprovação
 - A quantidade de provas a serem realizadas pelo aluno 
6) Fazer tratamento de dados na entrada do usuario (notas, idades, media, sexo)
 - 0 < Nota < 10
 - 16 < idade < 100
 - 4.5 < media < 8
 - sexo somente M/m/F/f
*/

// Estrutura de dados
struct Aluno {
    char Nome[30]; //vetor
    char Sexo;
    int Idade;
    float Notas[3];
    bool Aprovado;
};


// A seguir temos a função principal do programa
int main() {
    int QtdAlunos, QtdAprovM=0, QtdAprovF=0;
    int QtdAlunoM=0,QtdAlunoF=0, QtdReproM=0, QtdReproF=0;
    float Media;
    int QtdProvas;
    float MdAprovacao;
    //Criação de um vetor 
    struct Aluno Alunos[100];

    printf(" Informe a quantidade de alunos: ");
    scanf("%i", &QtdAlunos);

    printf("Informe a quantidade de provas: ");
    scanf("%i", &QtdProvas);

    for(int i=1; i<= QtdAlunos; i++ ) {
        Media = 0;
        printf("Informe o nome do %i aluno: ", i);
        scanf("%s", Alunos[i].Nome);
        printf("Informe a idade de %s: ", Alunos[i].Nome);
        scanf("%i", &Alunos[i].Idade);
        do { //tratamento de dados para sexo do aluno
            printf("Informe o Sexo de %s (M - masculino, F - feminino): ", Alunos[i].Nome);
            scanf("%s", &Alunos[i].Sexo);
        } while (Alunos[i].Sexo != 'M' and Alunos[i].Sexo != 'm' && Alunos[i].Sexo != 'F' & Alunos[i].Sexo != 'f');
        
        if (Alunos[i].Sexo == 'M' or Alunos[i].Sexo == 'm') {
            QtdAlunoM++;
        } else {
            QtdAlunoF++;
        }
        
        for (int f=0; f<QtdProvas; f++ ){ 
            printf("Informe as notas de %s: ", Alunos[i].Nome);
            scanf("%f", &Alunos[i].Notas[f]);

            Media = Media + Alunos[i].Notas[f];
        }
        Media = Media/ QtdProvas;
        do { //tratamento de dados para média de aprovação
            printf("Informe a média mínima para aprovação: ");
            scanf("%f", &MdAprovacao);
        } while (Media<4.5 or Media>8);
    
        Alunos[i].Aprovado = Media >= MdAprovacao;

        if (Alunos[i].Aprovado and (Alunos[i].Sexo == 'M' or Alunos[i].Sexo == 'm')) {
            QtdAprovM++;
        } else if (Alunos[i].Aprovado and (Alunos[i].Sexo == 'F' or Alunos[i].Sexo == 'f')) {
            QtdAprovF++;
        } else if (!Alunos[i].Aprovado and (Alunos[i].Sexo == 'M' or Alunos[i].Sexo == 'm')) {
            QtdReproM++;
        } else {
            QtdReproF++;
        }
        
        
        
    }

    

}