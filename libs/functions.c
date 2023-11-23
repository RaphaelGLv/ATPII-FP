#include <stdio.h>
#include <string.h>
#include "functions.h"

void printVetor(JOGADOR vetor[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Jogador %d:\n", i = 1);
        printf("Nome: %s\n", vetor[i].dadojog.nome);
        printf("Data de nascimento: %s\n", vetor[i].dadojog.data);
        printf("CPF: %s\n", vetor[i].dadojog.cpf);
        printf("Gênero: %s\n", vetor[i].dadojog.genero);
        printf("Estado Civil: %s\n", vetor[i].dadojog.est_civ);
        printf("Equipe:\n");
        printf("   - Nome: %s\n", vetor[i].equipe.nomEqu);
        printf("   - Rede social: %s\n", vetor[i].equipe.nicEqu);
        printf("   - Seguidores: %d\n", vetor[i].equipe.numSegEqu);
        printf("Patrocinadora principal: %s\n", vetor[i].markt.patrocinador);
        printf("Rede social: %s\n", vetor[i].markt.nickname);
        printf("Seguidores: %d\n", vetor[i].markt.numSeg);
        printf("Equipamentos de Hardware:\n");
        printf("   - Modelo do computador: %s\n", vetor[i].hardware.model);
        printf("   - Modelo do processador: %s\n", vetor[i].hardware.proces);
        printf("   - Modelo da placa de vídeo: %s\n", vetor[i].hardware.placa_video);
        printf("   - Memória RAM: %d\n", vetor[i].hardware.memRam);
        printf("Dados do campeonato:\n");
        printf("   - Pontuação: %d\n", vetor[i].dadoscamp.pontcamp);
        printf("   - Vitórias: %d | Empates: %d | Derrotas: %d\n", vetor[i].dadoscamp.numvit, vetor[i].dadoscamp.numemp, vetor[i].dadoscamp.numdef);
        printf("   - Títulos ganhos: %d\n", vetor[i].dadoscamp.qntTitle);
        printf("   - Ranking mundial: %d\n", vetor[i].dadoscamp.posRanking);
        printf("===========================================================\n");
    }
}

// void inserirJogadoresVetor(JOGADOR jogadores[], int n)
// {

// }

// void escreverJogadoresArquivo(JOGADOR jogadores[], int n)
// {

// }

// void lerJogadoresArquivo(JOGADOR jogadores[], int n)
// {

// }

// void printJogadoresVetor(JOGADOR jogadores[], int n)
// {

// }

// void editarJogador()
// {

// }

// void editarPontuacaoJogador()
// {

// }

void listarAlfabetico()
{
    FILE *file = fopen("//..//arquivos//jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    int pos = fseek(file, 0, SEEK_END);

    int size = pos / sizeof(JOGADOR);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    JOGADOR aux;
    for (int i = 0; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = i + 1; j < size - i - 1; j++)
        {
            if (strcmp(jogadoresLidos[j].dadojog.nome, jogadoresLidos[j + 1].dadojog.nome) == 1)
            {
                aux = jogadoresLidos[j];
                jogadoresLidos[j] = jogadoresLidos[j + 1];
                jogadoresLidos[j + 1] = aux;

                hasChanged = 1;
            }
        }

        if (!hasChanged)
        {
            break;
        }
    }

    printVetor(jogadoresLidos, size);

    fclose(file);
}

void listarPosicao()
{
    FILE *file = fopen("//..//arquivos//jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    int pos = fseek(file, 0, SEEK_END);

    int size = pos / sizeof(JOGADOR);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    JOGADOR aux;
    for (int i = 0; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = i + 1; j < size - i - 1; j++)
        {
            if (jogadoresLidos[j].dadoscamp.posRanking < jogadoresLidos[j + 1].dadoscamp.posRanking)
            {
                aux = jogadoresLidos[j];
                jogadoresLidos[j] = jogadoresLidos[j + 1];
                jogadoresLidos[j + 1] = aux;

                hasChanged = 1;
            }
        }

        if (!hasChanged)
        {
            break;
        }
    }

    printVetor(jogadoresLidos, size);

    fclose(file);
}

void listarVitoria()
{
    FILE *file = fopen("//..//arquivos//jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    int pos = fseek(file, 0, SEEK_END);

    int size = pos / sizeof(JOGADOR);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    JOGADOR aux;
    for (int i = 0; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = i + 1; j < size - i - 1; j++)
        {
            if (jogadoresLidos[j].dadoscamp.numvit < jogadoresLidos[j + 1].dadoscamp.numvit)
            {
                aux = jogadoresLidos[j];
                jogadoresLidos[j] = jogadoresLidos[j + 1];
                jogadoresLidos[j + 1] = aux;

                hasChanged = 1;
            }
        }

        if (!hasChanged)
        {
            break;
        }
    }

    printVetor(jogadoresLidos, size);

    fclose(file);
}

// void printClassificacao()
// {

// }

// void printJogadorPontuacaoMaior()
// {

// }

// void printJogadorPontuacaoMenor()
// {

// }

// int buscaNome(char nome[30])
// {

// }

int buscaPosicao(int searchPos)
{
    FILE *file = fopen("//..//arquivos//jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    int pos = fseek(file, 0, SEEK_END);

    int size = pos / sizeof(JOGADOR);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    int hasFound = 0;
    for (int i = 0; i < size; i++)
    {
        if (jogadoresLidos[i].dadoscamp.posRanking == searchPos)
        {
            printf("Jogador ecnontrado!:\n", i = 1);
            printf("Nome: %s\n", jogadoresLidos[i].dadojog.nome);
            printf("Data de nascimento: %s\n", jogadoresLidos[i].dadojog.data);
            printf("CPF: %s\n", jogadoresLidos[i].dadojog.cpf);
            printf("Gênero: %s\n", jogadoresLidos[i].dadojog.genero);
            printf("Estado Civil: %s\n", jogadoresLidos[i].dadojog.est_civ);
            printf("Equipe:\n");
            printf("   - Nome: %s\n", jogadoresLidos[i].equipe.nomEqu);
            printf("   - Rede social: %s\n", jogadoresLidos[i].equipe.nicEqu);
            printf("   - Seguidores: %d\n", jogadoresLidos[i].equipe.numSegEqu);
            printf("Patrocinadora principal: %s\n", jogadoresLidos[i].markt.patrocinador);
            printf("Rede social: %s\n", jogadoresLidos[i].markt.nickname);
            printf("Seguidores: %d\n", jogadoresLidos[i].markt.numSeg);
            printf("Equipamentos de Hardware:\n");
            printf("   - Modelo do computador: %s\n", jogadoresLidos[i].hardware.model);
            printf("   - Modelo do processador: %s\n", jogadoresLidos[i].hardware.proces);
            printf("   - Modelo da placa de vídeo: %s\n", jogadoresLidos[i].hardware.placa_video);
            printf("   - Memória RAM: %d\n", jogadoresLidos[i].hardware.memRam);
            printf("Dados do campeonato:\n");
            printf("   - Pontuação: %d\n", jogadoresLidos[i].dadoscamp.pontcamp);
            printf("   - Vitórias: %d | Empates: %d | Derrotas: %d\n", jogadoresLidos[i].dadoscamp.numvit, jogadoresLidos[i].dadoscamp.numemp, jogadoresLidos[i].dadoscamp.numdef);
            printf("   - Títulos ganhos: %d\n", jogadoresLidos[i].dadoscamp.qntTitle);
            printf("   - Ranking mundial: %d\n", jogadoresLidos[i].dadoscamp.posRanking);
            printf("===========================================================\n");

            hasFound = 1;
            break;
        }
    }

    if (!hasFound)
    {
        printf("Jogador não foi encontrado.\n");
    }
    

    fclose(file);
}

void printSeguidores()
{
    FILE *file = fopen("//..//arquivos//jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }
    
    int pos = fseek(file, 0*sizeof(JOGADOR), SEEK_END);

    int size = pos/sizeof(JOGADOR);

    JOGADOR jogadoresLidos[size];

    int totalSeg = 0;
    for (int i = 0; i < size; i++)
    {
        totalSeg += jogadoresLidos[i].markt.numSeg;
    }

    printf("Quantidade media de seguidores por jogador: %d\n", totalSeg/size);

    fclose(file);    
}