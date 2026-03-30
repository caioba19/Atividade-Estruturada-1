// questão 2 
#include <stdio.h>
#include <string.h>

#define MAX 50

struct Funcionario {
    int codigo;
    char nome[100];
    float salario;
};

void cadastrarFuncionarios(struct Funcionario vetor[], int n);
void imprimirAcimaMedia(struct Funcionario vetor[], int n);

int main(void) {
    struct Funcionario funcionarios[MAX];
    int n;

    do {
        printf("Quantos funcionarios deseja cadastrar (1 a %d)? ", MAX);
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    cadastrarFuncionarios(funcionarios, n);
    imprimirAcimaMedia(funcionarios, n);

    return 0;
}

void cadastrarFuncionarios(struct Funcionario vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Funcionario %d ---\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &vetor[i].codigo);

        printf("Nome: ");
        scanf(" %[^\n]", vetor[i].nome);

        printf("Salario: ");
        scanf("%f", &vetor[i].salario);
    }
}

void imprimirAcimaMedia(struct Funcionario vetor[], int n) {
    float soma = 0.0;

    for (int i = 0; i < n; i++) {
        soma += vetor[i].salario;
    }

    float media = soma / n;
    printf("\nMedia salarial: R$ %.2f\n", media);
    printf("Funcionarios com salario acima da media:\n");

    for (int i = 0; i < n; i++) {
        if (vetor[i].salario > media) {
            printf("  - %s: R$ %.2f\n", vetor[i].nome, vetor[i].salario);
        }
    }
}

//questão 3 
#include <stdio.h>

struct Funcionario {
    int codigo;
    char nome[100];
    float salario;
};

void aplicarAumento(struct Funcionario *f, float percentual);

int main(void) {
    struct Funcionario func;

    func.codigo  = 101;
    func.salario = 3000.00f;

    func.nome[0] = 'A'; func.nome[1] = 'n'; func.nome[2] = 'a';
    func.nome[3] = '\0';

    printf("Salario original de %s: R$ %.2f\n", func.nome, func.salario);

    aplicarAumento(&func, 10.0f);

    printf("Salario apos aumento de 10%%: R$ %.2f\n", func.salario);

    return 0;
}

void aplicarAumento(struct Funcionario *f, float percentual) {
    f->salario = f->salario * (1.0f + percentual / 100.0f);
}
