//Nome: Guilherme Willians de Souza Inácio e Kauã da Silva Lazarim 
//RM: 565319, 564625

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define MAX_FIBONACCI 50
#define MAX_FATORIAL 20


void calcularFibonacci();
void calcularFatorial();
void verificarPalindromo();
void verificarSubstring();

void verificarPalindromo() {
    char palavra[101];
    printf("Digite uma palavra: ");
    getchar();
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    int tamanho = strlen(palavra);
    int ehPalindromo = 1;

    for (int i = 0; i < tamanho / 2; i++) {
        if (palavra[i] != palavra[tamanho - 1 - i]) {
            ehPalindromo = 0;
            break;
        }
    }

    if (ehPalindromo) {
        printf("A palavra é um palindrome.\n");
    } else {
        printf("A palavra NÃO é um palindrome.\n");
    }
}


void verificarSubstring() {
    char string1[100], string2[100];
    printf("Digite a primeira string: ");
    getchar();
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Digite a segunda string: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';

    int tam1 = strlen(string1);
    int tam2 = strlen(string2);
    int encontrou = 0;

    if (tam2 <= tam1) {
        for (int i = 0; i <= tam1 - tam2; i++) {
            int coincide = 1;
            for (int j = 0; j < tam2; j++) {
                if (string1[i + j] != string2[j]) {
                    coincide = 0;
                    break;
                }
            }
            if (coincide) {
                encontrou = 1;
                break;
            }
        }
    }

    if (encontrou) {
        printf("A segunda string está contida na primeira.\n");
    } else {
        printf("A segunda string NÃO está contida na primeira.\n");
    }
}


void calcularFibonacci() {
    int n, i;
    long long fib[MAX_FIBONACCI];

    printf("Digite quantos números da sequência de Fibonacci quer ver (1-%d): ", MAX_FIBONACCI);
    scanf("%d", &n);


    if(n < 1 || n > MAX_FIBONACCI) {
        printf("Número inválido, deve ser entre 1 e %d.\n", MAX_FIBONACCI);
        return;
    }


    fib[0] = 0;
    if(n > 1) {
        fib[1] = 1;
    }

    for(i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }


    printf("Sequência de Fibonacci: ");
    for(i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");
}


void calcularFatorial() {
    int n, i;
    long long fat[MAX_FATORIAL];

    printf("Digite um número para calcular os fatoriais (1-%d): ", MAX_FATORIAL);
    scanf("%d", &n);


    if(n < 1 || n > MAX_FATORIAL) {
        printf("Número inválido, deve ser entre 1 e %d.\n", MAX_FATORIAL);
        return;
    }


    fat[0] = 1;

    for(i = 1; i < n; i++) {
        fat[i] = fat[i-1] * (i+1);
    }


    printf("Fatoriais calculados:\n");
    for(i = 0; i < n; i++) {
        printf("%d! = %lld\n", i+1, fat[i]);
    }
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    printf("Bem-vindo ao programa de cálculos!\n");

    do {
        printf("\nMenu Principal:\n");
        printf("1 - Sequência de Fibonacci\n");
        printf("2 - Cálculo de Fatoriais\n");
        printf("3 - Verificar Palíndromo\n");
        printf("4 - Verificar Substring\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                calcularFibonacci();
                break;
            case 2:
                calcularFatorial();
                break;
            case 3:
                verificarPalindromo();
                break;
            case 4:
                verificarSubstring();
                break;
            case 0:
                printf("Encerrado\n");
                break;
            default:
                printf("Opção inválida\n");
        }

    } while(opcao != 0);

    return 0;
}
