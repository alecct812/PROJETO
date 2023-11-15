#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

struct palavrascertas{
char palavracerta[50];

struct palavrascertas* link;

};


typedef struct Player
{
  char nome[50];
  int pontos;
  struct Player* next;
}Jogadores;

Jogadores* createJogador(char name[50], int pontuacao)
{
  Jogadores* novoJogador = (Jogadores*) malloc(sizeof(Jogadores));
  strcpy(novoJogador -> nome,name);
  novoJogador -> pontos = pontuacao;
  novoJogador -> next = NULL;

  return novoJogador;
}

Jogadores* addJogador(Jogadores* head, char name[50], int pontuacao) //add no final da lista;
{
  Jogadores* novoJogador = createJogador (name, pontuacao);

  if (head == NULL)
  {
    return novoJogador;
  }

  Jogadores *atual = head;

  while(atual -> next != NULL)
  {
    atual = atual -> next;
  }

  atual -> next = novoJogador;

  return head;
}

void freeLista(Jogadores* head)
{
  Jogadores *atual = head -> next;

  Jogadores *temp;

  while(atual != NULL)
    {
      temp = atual;

      atual = atual -> next;

      free(temp);
    }

}

void wArquivo_Lista(Jogadores* head, const char* nomeArquivo)
{
  FILE* arquivo = fopen(nomeArquivo, "a");

  if (arquivo == NULL)
  {
    printf("Não foi possível abrir o arquivo! \n");
    return;
  }

  Jogadores *atual = head;

  while(atual != NULL)
  {
    fprintf(arquivo, "Jogador: %s  --->  Pontuação: %d \n", atual -> nome, atual -> pontos);
    atual = atual -> next;
  }

  fclose(arquivo);
}


// Função para imprimir uma palavra aleatória de um array
void imprimirPalavraAleatoria(char array[][50], int tamanho,char palavra[50]) {
    int indiceAleatorio = rand() % tamanho;
    printf("Palavra Aleatória: %s\n", array[indiceAleatorio]);
    strcpy(palavra,array[indiceAleatorio]);
}
int forca(char palavra[50]) {
    int tamanho = strlen(palavra);

    char palavracensurada[tamanho + 1];

    memset(palavracensurada, '_', tamanho);

    palavracensurada[tamanho] = '\0';

    int erros = 0, acertos = 0, vitorias = 0;
    char jausadas[26]; // para letras do alfabeto apenas
    memset(jausadas, 0, sizeof(jausadas));

    while (erros < 12 && acertos < tamanho) {
        printf("\e[H\e[2J");

        printf("Palavra: %s\n", palavracensurada);
        printf("Erros = %d\n", erros);
        printf("Letras usadas: ");

        for (int i = 0; i < 26; i++) {
            if (jausadas[i] != 0) {
                printf("%c ", jausadas[i]);
            }
        }
        printf("\n");

        printf("Digite uma letra: ");
        char ch;
        scanf(" %c", &ch); // %c lê um caractere, espaço antes de %c para consumir espaços em branco

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
              palavracensurada[i] = palavra[i];
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

int main() {
    // Inicializa a semente para a função rand() com base no tempo atual
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");


  Jogadores* ListaJogadores = NULL;

  char nomeJogador[50];
  int points = 0;
  int vitorias = 0;

    // Países
    char paisesFaceis[10][50] = {"Brasil", "EstadosUnidos", "Canada", "Franca", "Alemanha", "Espanha", "Japao", "China", "India", "Russia"};
    char paisesMedios[20][50] = {"Brasil", "EstadosUnidos", "Canada", "Franca", "Alemanha", "Espanha", "Japao", "China", "India", "Russia",
                                "Australia", "Mexico", "Italia", "Argentina", "CoreiaDoSul", "Turquia", "AfricaDoSul", "Egito", "Suecia", "Indonesia"};
    char paisesDificeis[30][50] = {"Brasil", "EstadosUnidos", "Canada", "Franca", "Alemanha", "Espanha", "Japão", "China", "India", "Russia",
                                  "Australia", "México", "Itália", "Argentina", "CoreiaDoSul", "Turquia", "ÁfricaDoSul", "Egito", "Suécia", "Indonésia",
                                  "Cazaquistão", "Quirguistão", "Suazilandia", "Tonga", "Tuvalu", "Butao", "Comores", "Lesoto", "Nauru", "Vanuatu"};

    // Futebol
    char futebolLibertadores[10][50] = {"BocaJuniors", "RiverPlate", "Flamengo", "Palmeiras", "Gremio", "Santos", "Independiente", "SaoPaulo", "Nacional", "Penarol"};
    char futebolChampionsLeague[10][50] = {"RealMadrid", "Barcelona", "BayernDeMunique", "Liverpool", "ManchesterUnited", "ACMilan", "Juventus", "Ajax", "Chelsea", "InterDeMilao"};

    // Frutas
    char frutasFaceis[10][50] = {"Banana", "Maça", "Uva", "Pera", "Morango", "Abacaxi", "Melancia", "Manga", "Kiwi", "Abacate"};
    char frutasMedias[20][50] = {"Banana", "Maça", "Uva", "Pera", "Morango", "Abacaxi", "Melancia", "Manga", "Kiwi", "Abacate", 
                                "Maracuja", "Cereja", "Roma", "Pessego", "Coco", "Mamão", "Framboesa", "Groselha", "Ameixa", "Pitaya"};
    char frutasDificeis[30][50] = {"Banana", "Maça", "Uva", "Pera", "Morango", "Abacaxi", "Melancia", "Manga", "Kiwi", "Abacate",
                                  "Maracuja", "Cereja", "Roma", "Pessego", "Coco", "Mamão", "Framboesa", "Groselha", "Ameixa", "Pitaya",
                                  "Jabuticaba", "Carambola", "Lichia", "Mangostão", "Rambuta", "Kiwano", "Nêspera", "Jatobá", "Graviola", "Sapoti"};

    // Marcas de Carro
    char marcasCarroFaceis[10][50] = {"Volkswagen", "Ford", "Toyota", "Honda", "Chevrolet", "Nissan", "Fiat", "Hyundai", "Renault", "Peugeot"};
    char marcasCarroMedias[20][50] = {"Volkswagen", "Ford", "Toyota", "Honda", "Chevrolet", "Nissan", "Fiat", "Hyundai", "Renault", "Peugeot",
                                    "Mercedes-Benz", "BMW", "Audi", "Subaru", "Mazda", "Kia", "Volvo", "Tesla", "Jaguar", "LandRover"};
    char marcasCarroDificeis[30][50] = {"Volkswagen", "Ford", "Toyota", "Honda", "Chevrolet", "Nissan", "Fiat", "Hyundai", "Renault", "Peugeot",
                                      "Mercedes-Benz", "BMW", "Audi", "Subaru", "Mazda", "Kia", "Volvo", "Tesla", "Jaguar", "LandRover",
                                      "Maserati", "Bugatti", "Pagani", "McLaren", "Koenigsegg", "Alfa Romeo", "Genesis", "Rivian", "Lucid", "Rimac"};

    // Marcas de Tecnologia
    char marcasTecnologiaFaceis[10][50] = {"Microsoft", "Dell", "HP", "Lenovo", "Acer", "Asus", "Sony", "LG", "Toshiba", "Panasonic"};
    char marcasTecnologiaMedias[20][50] = {"Microsoft", "Dell", "HP", "Lenovo", "Acer", "Asus", "Sony", "LG", "Toshiba", "Panasonic",
                                          "Apple", "Samsung", "Google", "Intel", "AMD", "NVIDIA", "Logitech", "Canon", "Epson", "Brother"};
    char marcasTecnologiaDificeis[30][50] = {"Microsoft", "Dell", "HP", "Lenovo", "Acer", "Asus", "Sony", "LG", "Toshiba", "Panasonic",
                                            "Apple", "Samsung", "Google", "Intel", "AMD", "NVIDIA", "Logitech", "Canon", "Epson", "Brother",
                                            "Corsair", "Razer", "Seagate", "Western Digital", "Bose", "Sennheiser", "Kingston", "AMDRyzen", "Qualcomm", "EVGA"};
int escolha1, escolha2;
char palavramisteriosa[50];

  printf("Digite o nome do jogador: ");

  fgets(nomeJogador, sizeof(nomeJogador), stdin);

  nomeJogador[strcspn(nomeJogador, "\n")] = '\0';


  while(1){
printf("Qual você deseja?\n 1 - Países\n 2 - Futebol\n 3 - Frutas\n 4 - Marcas de Carro\n 5 - Marcas de Tecnologia\n");
    scanf("%d",&escolha1);
    getchar();

    switch(escolha1){
    case(1):
    printf("Qual você deseja?\n 1 - Fácil\n 2 - Médio\n 3 - Difícil\n");
    scanf("%d",&escolha2);
    getchar();
    switch(escolha2){
        case(1):
        imprimirPalavraAleatoria(paisesFaceis, 10,palavramisteriosa);
        break;
        case(2):
        imprimirPalavraAleatoria(paisesMedios, 20,palavramisteriosa);
        break;
        case(3):
        imprimirPalavraAleatoria(paisesDificeis, 30,palavramisteriosa);
        break;
    }

    break;
    case(2):
    printf("Qual você deseja?\n 1 - Libertadores\n 2 - Champios League\n");
    scanf("%d",&escolha2);
    getchar();
    switch(escolha2){
        case(1):
        imprimirPalavraAleatoria(futebolLibertadores, 10,palavramisteriosa);
        break;
        case(2):
        imprimirPalavraAleatoria(futebolChampionsLeague,10,palavramisteriosa);
        break;

    }
    break;
    case(3):
    printf("Qual você deseja?\n 1 - Fácil\n 2 - Médio\n 3 - Difícil\n");
    scanf("%d",&escolha2);
    getchar();
    switch(escolha2){
        case(1):
        imprimirPalavraAleatoria(frutasFaceis, 10,palavramisteriosa);
        break;
        case(2):
        imprimirPalavraAleatoria(frutasMedias, 20,palavramisteriosa);
        break;
        case(3):
        imprimirPalavraAleatoria(frutasDificeis, 30,palavramisteriosa);
        break;
    }
    break;
    case(4):
    printf("Qual você deseja?\n 1 - Fácil\n 2 - Médio\n 3 - Difícil\n");
    scanf("%d",&escolha2);
    getchar();
    switch(escolha2){
        case(1):
        imprimirPalavraAleatoria(marcasCarroFaceis, 10,palavramisteriosa);
        break;
        case(2):
        imprimirPalavraAleatoria(marcasCarroMedias, 20,palavramisteriosa);
        break;
        case(3):
        imprimirPalavraAleatoria(marcasCarroDificeis, 30,palavramisteriosa);
        break;
    }
    break;
    case(5):
    printf("Qual você deseja?\n 1 - Fácil\n 2 - Médio\n 3 - Difícil\n");
    scanf("%d",&escolha2);
    getchar();
    switch(escolha2){
        case(1):
        imprimirPalavraAleatoria(marcasTecnologiaFaceis, 10,palavramisteriosa);
        break;
        case(2):
        imprimirPalavraAleatoria(marcasTecnologiaMedias, 20,palavramisteriosa);
        break;
        case(3):
        imprimirPalavraAleatoria(marcasTecnologiaDificeis, 30,palavramisteriosa);
        break;
    }
    break;
    }
    int escolha;


    points += forca(palavramisteriosa);
    getchar();

    
    printf("\nDeseja continuar?\n 1 - Sim\n 2 - Não\n");
    scanf("%d",&escolha);
    getchar();

   

    if(escolha==2){
      printf("\e[H\e[2J");
      printf(" Você acertou %d palavras",points);
      ListaJogadores = addJogador(ListaJogadores,nomeJogador,points);
      break;
    }
   

  }

  wArquivo_Lista(ListaJogadores, "lista_jogadores.txt");

  freeLista(ListaJogadores);


    return 0;
}