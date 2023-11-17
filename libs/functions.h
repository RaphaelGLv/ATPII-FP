#ifndef FUNCTIONS_
#define FUNCTIONS_

typedef struct equipe
{
    char nomEqu[30];
    char nicEqu[30];
    int numSegEqu;
} EQUIPE;

typedef struct markt
{
    char patrocinador[30];
    char nickname[12];
    int numSeg;
} MARKT;

typedef struct hardware
{
    char model[15];
    char proces[10];
    char placa_video[10];
    int memRam;
} HARDWARE;

typedef struct dadoscamp
{
    int pontcamp;
    int numvit;
    int numdef;
    int numemp;
    int qntTitle;
    int posRanking;
} DADOSCAMP;

typedef struct dadojog
{
    char nome[50];
    char data[11];
    char cpf[15];
    char genero[20];
    char est_civ[30];
} DADOJOG;

typedef struct jogador
{
    DADOJOG dadojog;
    EQUIPE equipe;
    MARKT markt;
    HARDWARE hardware;
    DADOSCAMP dadoscamp;
} JOGADOR;

void inserirJogadoresVetor(JOGADOR jogadores[], int n);
void escreverJogadoresArquivo(JOGADOR jogadores[], int n);
void lerJogadoresArquivo(JOGADOR jogadores[], int n);
void printJogadoresVetor(JOGADOR jogadores[], int n);
void editarJogador();
void editarPontuacaoJogador();
void listarAlfabetico();
void listarPosicao();
void listarVitoria();
void printClassificacao();
void printJogadorPontuacaoMaior();
void printJogadorPontuacaoMenor();
void buscaNome();
void buscaPosicao();
void printSeguidores();

#include "functions.c"
#endif // FUNCTIONS_