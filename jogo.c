#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "forcajogo.h"

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

Jogadores* addJogador(Jogadores* head, char name[50], int pontuacao) 
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


void imprimirPalavraAleatoria(char array[][50], int tamanho,char palavra[50]) {
    int indiceAleatorio = rand() % tamanho;
    printf("Palavra Aleatória: %s\n", array[indiceAleatorio]);
    strcpy(palavra,array[indiceAleatorio]);
}


int main() {
    
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");


  Jogadores* ListaJogadores = NULL;

  char nomeJogador[50];
  int points = 0;
  int vitorias = 0;

    
    char paisesFaceis[10][50] = {"Brasil", "EstadosUnidos", "Canada", "Franca", "Alemanha", "Espanha", "Japao", "China", "India", "Russia"};
    char paisesMedios[20][50] = {"Brasil", "EstadosUnidos", "Canada", "Franca", "Alemanha", "Espanha", "Japao", "China", "India", "Russia",
                                "Australia", "Mexico", "Italia", "Argentina", "CoreiaDoSul", "Turquia", "AfricaDoSul", "Egito", "Suecia", "Indonesia"};
    char paisesDificeis[30][50] = {"Brasil", "EstadosUnidos", "Canada", "Franca", "Alemanha", "Espanha", "Japao", "China", "India", "Russia",
                                  "Australia", "Mexico", "Italia", "Argentina", "CoreiaDoSul", "Turquia", "AfricaDoSul", "Egito", "Suecia", "Indonesia",
                                  "Cazaquistao", "Quirguistao", "Suazilandia", "Tonga", "Tuvalu", "Butao", "Comores", "Lesoto", "Nauru", "Vanuatu"};

    
    char futebolLibertadores[10][50] = {"BocaJuniors", "RiverPlate", "Flamengo", "Palmeiras", "Gremio", "Santos", "Independiente", "SaoPaulo", "Nacional", "Penarol"};
    char futebolChampionsLeague[10][50] = {"RealMadrid", "Barcelona", "BayernDeMunique", "Liverpool", "ManchesterUnited", "ACMilan", "Juventus", "Ajax", "Chelsea", "InterDeMilao"};

    
    char frutasFaceis[10][50] = {"Banana", "Maca", "Uva", "Pera", "Morango", "Abacaxi", "Melancia", "Manga", "Kiwi", "Abacate"};
    char frutasMedias[20][50] = {"Banana", "Maca", "Uva", "Pera", "Morango", "Abacaxi", "Melancia", "Manga", "Kiwi", "Abacate", 
                                "Maracuja", "Cereja", "Roma", "Pessego", "Coco", "Mamao", "Framboesa", "Groselha", "Ameixa", "Pitaya"};
    char frutasDificeis[30][50] = {"Banana", "Maca", "Uva", "Pera", "Morango", "Abacaxi", "Melancia", "Manga", "Kiwi", "Abacate",
                                  "Maracuja", "Cereja", "Roma", "Pessego", "Coco", "Mamao", "Framboesa", "Groselha", "Ameixa", "Pitaya",
                                  "Jabuticaba", "Carambola", "Lichia", "Mangostao", "Rambuta", "Kiwano", "Nespera", "Jatoba", "Graviola", "Sapoti"};

    
    char marcasCarroFaceis[10][50] = {"Volkswagen", "Ford", "Toyota", "Honda", "Chevrolet", "Nissan", "Fiat", "Hyundai", "Renault", "Peugeot"};
    char marcasCarroMedias[20][50] = {"Volkswagen", "Ford", "Toyota", "Honda", "Chevrolet", "Nissan", "Fiat", "Hyundai", "Renault", "Peugeot",
                                    "Mercedes-Benz", "BMW", "Audi", "Subaru", "Mazda", "Kia", "Volvo", "Tesla", "Jaguar", "LandRover"};
    char marcasCarroDificeis[30][50] = {"Volkswagen", "Ford", "Toyota", "Honda", "Chevrolet", "Nissan", "Fiat", "Hyundai", "Renault", "Peugeot",
                                      "Mercedes-Benz", "BMW", "Audi", "Subaru", "Mazda", "Kia", "Volvo", "Tesla", "Jaguar", "LandRover",
                                      "Maserati", "Bugatti", "Pagani", "McLaren", "Koenigsegg", "Alfa Romeo", "Genesis", "Rivian", "Lucid", "Rimac"};

    
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
      printf("O jogo foi finalizado!\nVocê acertou um total de %d palavra(s).",points);
      ListaJogadores = addJogador(ListaJogadores,nomeJogador,points);
      break;
    }


  }

  wArquivo_Lista(ListaJogadores, "lista_jogadores.txt");

  freeLista(ListaJogadores);


    return 0;
}