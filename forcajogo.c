#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

int forca(char palavra[50]) {
    int tamanho = strlen(palavra);

    char palavracensurada[tamanho * 2 + 1];


    for (int i = 0; i < tamanho * 2; i += 2) {
        palavracensurada[i] = '_';
        palavracensurada[i + 1] = ' ';
    }
    palavracensurada[tamanho * 2] = '\0';

    int erros = 0, acertos = 0, vitorias = 0;
    char jausadas[26];
    memset(jausadas, 0, sizeof(jausadas));

    while (erros < 6 && acertos < tamanho) {
        printf("\e[H\e[2J");

        printf("Palavra: %s\n", palavracensurada);
        switch (erros) {
        case (0):
            printf("______\n|    |\n|     \n|      \n|      \n");
            break;
        case (1):
            printf("______\n|    |\n|    O\n|      \n|      \n");
            break;
        case (2):
            printf("______\n|    |\n|    O\n|    | \n|      \n");
            break;
        case (3):
            printf("______\n|    |\n|    O\n|   /| \n|      \n");
            break;
        case (4):
            printf("______\n|    |\n|    O\n|   /|\\\n|      \n");
            break;
        case (5):
            printf("______\n|    |\n|    O\n|   /|\\\n|   /  \n");
            break;
        case (6):
            printf("______\n|    |\n|    O\n|   /|\\\n|   / \\\n");
            break;
        }
        printf("Letras usadas: ");

        for (int i = 0; i < 26; i++) {
            if (jausadas[i] != 0) {
                printf("%c ", jausadas[i]);
            }
        }
        printf("\n");

        printf("Digite uma letra: ");
        char ch;
        scanf(" %c", &ch);

        bool letraUsada = false;
        for (int i = 0; i < 26; i++) {
            if (jausadas[i] == ch) {
                printf("Essa letra já foi usada. Tente outra.\n");
                letraUsada = true;
                break;
            }
        }

        if (letraUsada) {
            continue;
        }

        jausadas[ch - 'a'] = ch;

        bool encontrou = false;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == ch || palavra[i] == ch - 32) {
                
                palavracensurada[i * 2] = palavra[i];
                palavracensurada[i * 2 + 1] = ' ';
                acertos++;
                encontrou = true;
            }
        }

        if (!encontrou) {
            erros++;
        }
    }

    printf("\e[H\e[2J");
    if (acertos == tamanho) {
        printf("PARABÉNS!!! A palavra era: %s\n", palavra);
        vitorias++;
    } else {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }
    return vitorias;
}
