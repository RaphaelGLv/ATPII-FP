#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

void printVetor(JOGADOR vetor[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n-----------------------------------------------------------\n");
        printf("Jogador %d:\n", i + 1);
        printf("Nome: %s\n", vetor[i].dadojog.nome);
        printf("Data de nascimento: %s\n", vetor[i].dadojog.data);
        printf("CPF: %s\n", vetor[i].dadojog.cpf);
        printf("Genero: %s\n", vetor[i].dadojog.genero);
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
        printf("   - Vitórias: %d | Derrotas: %d | Empates: %d\n", vetor[i].dadoscamp.numvit, vetor[i].dadoscamp.numdef, vetor[i].dadoscamp.numemp);
        printf("   - Títulos ganhos: %d\n", vetor[i].dadoscamp.qntTitle);
        printf("   - Ranking mundial: %d", vetor[i].dadoscamp.posRanking);
    }
    printf("\n-----------------------------------------------------------\n");
}

JOGADOR *inserirJogadoresVetor(int tam)
{
    JOGADOR *jogador = malloc(tam * sizeof(JOGADOR));

    for (int i = 0; i < tam; i++)
    {
        fflush(stdin);
        printf("\n\nDIGITE OS DADOS DO JOGADOR:\n");
        printf("Nome: ");
        gets(jogador[i].dadojog.nome);

        printf("Data de nascimento:");
        gets(jogador[i].dadojog.data);

        printf("CPF: ");
        gets(jogador[i].dadojog.cpf);

        printf("Genero: ");
        gets(jogador[i].dadojog.genero);

        printf("Estado Civil: ");
        gets(jogador[i].dadojog.est_civ);

        printf("\n\nINFORMACOES ADICIONAIS:\n");
        printf("Patrocinadora: ");
        gets(jogador[i].markt.patrocinador);

        printf("Nickname nas redes sociais: ");
        gets(jogador[i].markt.nickname);

        fflush(stdin);

        printf("Numero de seguidores: ");
        scanf("%d", &jogador[i].markt.numSeg);
        fflush(stdin);

        printf("\n\nDADOS DA EQUIPE: \n");
        printf("Nome da equipe: ");
        gets(jogador[i].equipe.nomEqu);

        printf("Nickname das redes sociais: ");
        gets(jogador[i].equipe.nicEqu);

        fflush(stdin);
        printf("Numero de seguidores da equipe: ");
        scanf("%d", &jogador[i].equipe.numSegEqu);
        fflush(stdin);

        printf("\n\nDADOS DO HARDWARE: \n");
        printf("Modelo do computador: ");
        gets(jogador[i].hardware.model);

        printf("Processador: ");
        gets(jogador[i].hardware.proces);

        printf("Placa de video: ");
        gets(jogador[i].hardware.placa_video);

        fflush(stdin);

        printf("Quantidade de memoria RAM: ");
        scanf("%d", &jogador[i].hardware.memRam);

        printf("\n\nDADOS NO CAMPEONATO: \n");
        printf("Quantidade de vitorias no campeonato: ");
        scanf("%d", &jogador[i].dadoscamp.numvit);

        printf("Quantidade de empates no campeonato: ");
        scanf("%d", &jogador[i].dadoscamp.numemp);

        printf("Quantidade de derrotas no campeonato: ");
        scanf("%d", &jogador[i].dadoscamp.numdef);

        jogador[i].dadoscamp.pontcamp =
            (3 * jogador[i].dadoscamp.numvit) + jogador[i].dadoscamp.numemp;

        jogador[i].dadoscamp.total_jogos =
            jogador[i].dadoscamp.numvit + jogador[i].dadoscamp.numemp + jogador[i].dadoscamp.numdef;

        printf("Quantidade de titulos no campeonato: ");
        scanf("%d", &jogador[i].dadoscamp.qntTitle);

        printf("Posicao no Ranking Mundial: ");
        scanf("%d", &jogador[i].dadoscamp.posRanking);
        fflush(stdin);
    }

    return jogador;
}

void escreverJogadoresArquivo(JOGADOR *jogadores, int tam)
{
    FILE *file;
    file = fopen("./arquivos/jogadores.dat", "wb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!");
        return;
    }

    int QtdRegEscritos = fwrite(jogadores, sizeof(JOGADOR), tam, file);
    printf("Foram escritos %d jogadores!\n\n", QtdRegEscritos);

    free(jogadores);
    fclose(file);

    return;
}

void lerJogadoresArquivo()
{
    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    rewind(file);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    printVetor(jogadoresLidos, size);

    fclose(file);
}

// void editarJogador()
// {

// }

// void editarPontuacaoJogador()
// {

// }

void listarAlfabetico()
{
    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    fclose(file);

    JOGADOR aux;
    for (int i = 1; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = 0; j < size - 1; j++)
        {
            if (strcmp(jogadoresLidos[j].dadojog.nome, jogadoresLidos[j + 1].dadojog.nome) > 0)
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
}

void listarPosicao()
{
    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    fclose(file);

    JOGADOR aux;
    for (int i = 1; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = 0; j < size - 1; j++)
        {
            if (jogadoresLidos[j].dadoscamp.pontcamp < jogadoresLidos[j + 1].dadoscamp.pontcamp)
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
}

void listarVitoria()
{
    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    fclose(file);

    JOGADOR aux;
    for (int i = 1; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = 0; j < size - 1; j++)
        {
            if (jogadoresLidos[j].dadoscamp.numvit < jogadoresLidos[j + 1].dadoscamp.numvit)
            {
                aux = jogadoresLidos[j];
                jogadoresLidos[j] = jogadoresLidos[j + 1];
                jogadoresLidos[j + 1] = aux;

                hasChanged = 1;
                printf("\n\n\nMudou\n\n\n");
            }
        }

        if (!hasChanged)
        {
            break;
        }
    }

    printVetor(jogadoresLidos, size);
}

void printClassificacaoMundial()
{
    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    fclose(file);

    JOGADOR aux;
    for (int i = 1; i < size; i++)
    {
        int hasChanged = 0;

        for (int j = 0; j < size - 1; j++)
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
}

// void printJogadorPontuacaoMaior()
// {

// }

// void printJogadorPontuacaoMenor()
// {

// }

// void buscaNome()
// {

// }

void buscaPosicao()
{
    int searchPos;

    printf("Insira a posicao buscada: ");
    scanf("%d", &searchPos);

    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    fclose(file);

    for (int i = 0; i < size; i++)
    {
        if (jogadoresLidos[i].dadoscamp.posRanking == searchPos)
        {
            printf("Jogador encontrado!\n");
            printf("===========================================================\n");
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

            return;
        }
    }

    printf("Jogador não encontrado.\n");
}

void printSeguidores()
{
    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0 * sizeof(JOGADOR), SEEK_END);

    int pos = ftell(file);
    int size = pos / sizeof(JOGADOR);

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    int totalSeg = 0;
    for (int i = 0; i < size; i++)
    {
        totalSeg += jogadoresLidos[i].markt.numSeg;
    }

    printf("Quantidade media de seguidores por jogador: %d\n", totalSeg / size);
}