#include <stdio.h>
#include <string.h>
#include "functions.h"

void printVetor(JOGADOR vetor[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Jogador %d:\n", i=1);
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

    int size = pos/sizeof(JOGADOR);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);
    
    JOGADOR aux;
    for (int i = 0; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = i+1; j < size - i - 1; j++)
        {
            if (strcmp(jogadoresLidos[j].dadojog.nome, jogadoresLidos[j+1].dadojog.nome) == 1)
            {
                aux = jogadoresLidos[j];
                jogadoresLidos[j] = jogadoresLidos[j+1];
                jogadoresLidos[j+1] = aux;

                hasChanged = 1;
            }
            
        }

        if (!hasChanged)
        {
            break;
        }
    }
    
    fclose(file);
}

// void listarPosicao()
// {

// }

// void listarVitoria()
// {

// }

// void printClassificacao()
// {

// }

// void printJogadorPontuacaoMaior()
// {

// }

// void printJogadorPontuacaoMenor()
// {

// }

// void buscaNome()
// {

// }

// void buscaPosicao()
// {

// }

// void printSeguidores()
// {

// }