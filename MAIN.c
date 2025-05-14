//Nome: Guilherme Willians de Souza Inácio e Kauã da Silva Lazarim 
//RM: 565319, 564625

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>





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


int main() {
    setlocale(LC_ALL, "Portuguese");
   

    

    do {
       

        switch(opcao) {
            case 1:
               
                break;
            case 2:
                
                break;
            case 3:
                verificarPalindromo();
                break;
            case 4:
                verificarSubstring();
                break;
            case 0:
               
                break;
            default:
               
        }

    } while(opcao != 0);

    return 0;
}
