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
    char memRam[10];
} HARDWARE;

typedef struct dadoscamp
{
    int pontcamp;
    int numvit;
    int numemp;
    int numdef;
    int qntTitle;
    int total_jogos;
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

JOGADOR *inserirJogadoresVetor(int tam);
void printVetor(JOGADOR vetor[], int size);
void escreverJogadoresArquivo(JOGADOR *jogadores, int tam);
void lerJogadoresArquivo();
void printJogadoresVetor(JOGADOR jogadores[], int n);
void editarJogador();
void atualiza_camp();
void listarAlfabetico();
void listarPosicao();
void listarVitoria();
void printClassificacaoMundial();
void printJogadorPontuacaoMaior(int pts);
void printJogadorPontuacaoMenor(int pts);
void printSeguidores();
void buscaNome();
void buscaPosicao();

#endif // FUNCTIONS_