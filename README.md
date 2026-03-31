# 📘 Atividade — Ponteiros, Structs e Passagem por Referência em C

Repositório com as resoluções da atividade de **Estruturas de Dados / Programação em C**, cobrindo ponteiros, endereços de memória, vetores de structs e passagem por referência via ponteiros.

**Aluno:** Caio Vinicius · [@caioba19](https://github.com/caioba19)  
**Curso:** Tecnologia em Análise e Desenvolvimento de Sistemas  
**Instituição:** Centro Universitário Jorge Amado — Salvador, BA

---

## 📁 Estrutura do Repositório

```
.
├── questao1/
│   └── ponteiros.c        # Manipulação de ponteiros e teste de mesa
├── questao2/
│   └── funcionarios.c     # Vetor de structs + funções modulares
└── questao3/
    └── aumento.c          # Ponteiro para struct + passagem por referência
```

---

## ❓ Questão 1 — Compreensão de Ponteiros e Endereços de Memória

### Enunciado

O programa a seguir manipula variáveis e ponteiros em C. Pede-se:

- **a)** Mostrar, passo a passo (teste de mesa), as mudanças nos valores de `a` e `b`.
- **b)** Explicar o que acontece na memória quando a instrução `p = q` é executada.
- **c)** Informar os valores impressos na tela ao final da execução.

```c
int main(void) {
    int a = 5, b = 12;
    int *p, *q;
    p = &a;
    q = &b;
    *p = *q + 3;
    b = *p * 2;
    p = q;
    *p = 10;
    printf("A = %d\n", a);
    printf("B = %d\n", b);
    return 0;
}
```

### Teste de mesa

| Instrução | `a` | `b` | `p` aponta para | `q` aponta para |
|---|---|---|---|---|
| `int a = 5, b = 12` | 5 | 12 | — | — |
| `p = &a` | 5 | 12 | `a` | — |
| `q = &b` | 5 | 12 | `a` | `b` |
| `*p = *q + 3` | **15** | 12 | `a` | `b` |
| `b = *p * 2` | 15 | **30** | `a` | `b` |
| `p = q` | 15 | 30 | **`b`** | `b` |
| `*p = 10` | 15 | **10** | `b` | `b` |

### O que acontece em `p = q`?

O **endereço** armazenado em `q` (que é o endereço de `b`) é copiado para `p`. Nenhum valor de `a` ou `b` é alterado nessa linha — apenas a "direção" para onde `p` aponta muda. A partir desse momento, ambos os ponteiros apontam para `b` na memória. Qualquer alteração via `*p` passa a afetar diretamente `b`.

### Saída esperada

```
A = 15
B = 10
```

---

## ❓ Questão 2 — Vetores de Tipos Abstratos de Dados (Structs)

### Enunciado

Considere um sistema de controle de funcionários. Cada funcionário possui código (int), nome (char[]) e salário (float). Pede-se:

- **a)** Definir uma `struct` chamada `Funcionario` com os campos descritos.
- **b)** Na `main`, declarar um vetor de até 50 funcionários e ler a quantidade `N` com validação por laço (1 ≤ N ≤ 50).
- **c)** Implementar a função `cadastrarFuncionarios` que receba o vetor e `N` e leia os dados via teclado.
- **d)** Implementar a função `imprimirAcimaMedia` que calcule a média salarial e imprima apenas os funcionários que ganham estritamente acima dela.

### Struct utilizada

```c
struct Funcionario {
    int   codigo;
    char  nome[100];
    float salario;
};
```

### Funções implementadas

| Função | Responsabilidade |
|---|---|
| `cadastrarFuncionarios(vetor, n)` | Lê os dados de N funcionários via teclado |
| `imprimirAcimaMedia(vetor, n)` | Calcula a média e exibe quem ganha acima dela |

### Exemplo de execução

```
Quantos funcionarios deseja cadastrar (1 a 50)? 3

--- Funcionario 1 ---
Codigo  : 1
Nome    : Carlos Silva
Salario : R$ 2000.00

--- Funcionario 2 ---
Codigo  : 2
Nome    : Beatriz Souza
Salario : R$ 4500.00

--- Funcionario 3 ---
Codigo  : 3
Nome    : Pedro Alves
Salario : R$ 3200.00

================================================
Media salarial: R$ 3233.33
Funcionarios com salario ACIMA da media:
------------------------------------------------
  Beatriz Souza                   R$ 4500.00
================================================
```

---

## ❓ Questão 3 — Ponteiros para Structs e Passagem por Referência

### Enunciado

Em C, para alterar os dados originais de uma variável dentro de uma função é necessário passar seu endereço (ponteiro) e usar o operador `->` para acessar os campos da struct. Pede-se:

- **a)** Utilizar a mesma `struct Funcionario` da questão anterior.
- **b)** Criar a função `aplicarAumento(struct Funcionario *f, float percentual)` que receba um ponteiro para funcionário e calcule/atualize o salário com o percentual informado.
- **c)** Na `main`, declarar uma variável do tipo `Funcionario`, imprimir o salário original, chamar `aplicarAumento` passando `&func` e 10%, e imprimir o salário atualizado para comprovar que a alteração ocorreu no escopo da `main`.

### Função implementada

```c
void aplicarAumento(struct Funcionario *f, float percentual);
```

### Por que usar `&` e `->`?

| Conceito | Explicação |
|---|---|
| `&func` | Passa o **endereço** de `func`, não uma cópia |
| `struct Funcionario *f` | Parâmetro recebe o endereço (ponteiro) |
| `f->salario` | Equivale a `(*f).salario` — acessa o campo via ponteiro |
| Sem ponteiro | A função receberia uma cópia; o salário original **não** mudaria |

### Exemplo de execução

```
================================================
Funcionario : Ana Lima (cod. 101)
Salario original   : R$ 3000.00
Salario apos +10%  : R$ 3300.00
================================================
```
