#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        printf("   - Modelo da placa de video: %s\n", vetor[i].hardware.placa_video);
        printf("   - Memoria RAM: %s\n", vetor[i].hardware.memRam);
        printf("Dados do campeonato:\n");
        printf("   - Pontuacao (%d jogos): %d\n", vetor[i].dadoscamp.total_jogos, vetor[i].dadoscamp.pontcamp);
        printf("   - Vitorias: %d | Derrotas: %d | Empates: %d\n", vetor[i].dadoscamp.numvit, vetor[i].dadoscamp.numdef, vetor[i].dadoscamp.numemp);
        printf("   - Titulos ganhos: %d\n", vetor[i].dadoscamp.qntTitle);
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

        int length = strlen(jogador[i].dadojog.nome);

        jogador[i].dadojog.nome[0] = toupper(jogador[i].dadojog.nome[0]);

        for (int i = 1; i < length; i++)
        {
            if (isspace(jogador[i].dadojog.nome[i - 1]))
            {
                jogador[i].dadojog.nome[i] = toupper(jogador[i].dadojog.nome[i]);
            }
        }

        printf("Data de nascimento: ");
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
        gets(jogador[i].hardware.memRam);

        fflush(stdin);

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
    file = fopen("./arquivos/jogadores.dat", "ab");

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

    JOGADOR jogadoresLidos[size];
    fread(jogadoresLidos, sizeof(JOGADOR), size, file);

    printVetor(jogadoresLidos, size);

    fclose(file);
}

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
            if (jogadoresLidos[j].dadoscamp.posRanking > jogadoresLidos[j + 1].dadoscamp.posRanking)
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

void printJogadorPontuacaoMaior(int pts)
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
    int count = 1;

    for (int i = 0; i < size; i++)
    {
        if (jogadoresLidos[i].dadoscamp.pontcamp >= pts)
        {
            printf("\n-----------------------------------------------------------\n");
            printf("Jogador %d:\n", count++);
            printf("Nome: %s\n", jogadoresLidos[i].dadojog.nome);
            printf("Data de nascimento: %s\n", jogadoresLidos[i].dadojog.data);
            printf("CPF: %s\n", jogadoresLidos[i].dadojog.cpf);
            printf("Genero: %s\n", jogadoresLidos[i].dadojog.genero);
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
            printf("   - Modelo da placa de video: %s\n", jogadoresLidos[i].hardware.placa_video);
            printf("   - Memoria RAM: %s\n", jogadoresLidos[i].hardware.memRam);
            printf("Dados do campeonato:\n");
            printf("   - Pontuacao: %d\n", jogadoresLidos[i].dadoscamp.pontcamp);
            printf("   - Vitorias: %d | Derrotas: %d | Empates: %d\n", jogadoresLidos[i].dadoscamp.numvit, jogadoresLidos[i].dadoscamp.numdef, jogadoresLidos[i].dadoscamp.numemp);
            printf("   - Titulos ganhos: %d\n", jogadoresLidos[i].dadoscamp.qntTitle);
            printf("   - Ranking mundial: %d", jogadoresLidos[i].dadoscamp.posRanking);
        }
    }
    printf("\n-----------------------------------------------------------\n");

    fclose(file);
}

void printJogadorPontuacaoMenor(int pts)
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
    int count = 1;

    for (int i = 0; i < size; i++)
    {
        if (jogadoresLidos[i].dadoscamp.pontcamp <= pts)
        {
            printf("\n-----------------------------------------------------------\n");
            printf("Jogador %d:\n", count++);
            printf("Nome: %s\n", jogadoresLidos[i].dadojog.nome);
            printf("Data de nascimento: %s\n", jogadoresLidos[i].dadojog.data);
            printf("CPF: %s\n", jogadoresLidos[i].dadojog.cpf);
            printf("Genero: %s\n", jogadoresLidos[i].dadojog.genero);
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
            printf("   - Modelo da placa de video: %s\n", jogadoresLidos[i].hardware.placa_video);
            printf("   - Memoria RAM: %s\n", jogadoresLidos[i].hardware.memRam);
            printf("Dados do campeonato:\n");
            printf("   - Pontuacao: %d\n", jogadoresLidos[i].dadoscamp.pontcamp);
            printf("   - Vitorias: %d | Derrotas: %d | Empates: %d\n", jogadoresLidos[i].dadoscamp.numvit, jogadoresLidos[i].dadoscamp.numdef, jogadoresLidos[i].dadoscamp.numemp);
            printf("   - Titulos ganhos: %d\n", jogadoresLidos[i].dadoscamp.qntTitle);
            printf("   - Ranking mundial: %d", jogadoresLidos[i].dadoscamp.posRanking);
        }
    }
    printf("\n-----------------------------------------------------------\n");

    fclose(file);
}

void buscaNome()
{
    char nome[30];

    fflush(stdin);
    printf("Digite o nome procurado: ");
    gets(nome);

    FILE *file = fopen("./arquivos/jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("NAO FOI POSSIVEL BUSCAR!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    long pos = ftell(file);
    int size = pos / (sizeof(JOGADOR));

    fseek(file, 0, SEEK_SET);

    JOGADOR jogadorLido[size];

    fread(jogadorLido, sizeof(JOGADOR), size, file);

    fclose(file);

    for (int i = 0; i < size; i++)
    {
        int resultado = strcmp(nome, jogadorLido[i].dadojog.nome);

        if (resultado == 0)
        {
            printf("\nNome encontrado no arquivo!\n Posicao: %d", i + 1);
            JOGADOR vetor[1];
            vetor[0] = jogadorLido[i];
            printVetor(vetor, 1);

            return;
        }
    }
    printf("\nNome nao se encontra no arquivo!\n");
    return;
}

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
            printf("\nJogador encontrado!\n");
            printf("===========================================================\n");
            printf("Nome: %s\n", jogadoresLidos[i].dadojog.nome);
            printf("Data de nascimento: %s\n", jogadoresLidos[i].dadojog.data);
            printf("CPF: %s\n", jogadoresLidos[i].dadojog.cpf);
            printf("Genero: %s\n", jogadoresLidos[i].dadojog.genero);
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
            printf("   - Modelo da placa de video: %s\n", jogadoresLidos[i].hardware.placa_video);
            printf("   - Memoria RAM: %d\n", jogadoresLidos[i].hardware.memRam);
            printf("Dados do campeonato:\n");
            printf("   - Pontuacao: %d\n", jogadoresLidos[i].dadoscamp.pontcamp);
            printf("   - Vitorias: %d | Empates: %d | Derrotas: %d\n", jogadoresLidos[i].dadoscamp.numvit, jogadoresLidos[i].dadoscamp.numemp, jogadoresLidos[i].dadoscamp.numdef);
            printf("   - Titulos ganhos: %d\n", jogadoresLidos[i].dadoscamp.qntTitle);
            printf("   - Ranking mundial: %d\n", jogadoresLidos[i].dadoscamp.posRanking);
            printf("===========================================================\n\n");

            return;
        }
    }

    printf("Jogador nao encontrado.\n");
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

    printf("\nQuantidade media de seguidores por jogador: %d\n\n", totalSeg / size);
}

void atualiza_camp()
{
    FILE *file;
    file = fopen("./arquivos/jogadores.dat", "rb+");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    long pos = ftell(file);
    int tam = pos / (sizeof(JOGADOR));

    fseek(file, 0, SEEK_SET);

    JOGADOR vetor[tam];

    int cod, campo;
    fread(vetor, sizeof(JOGADOR), tam, file);

    do
    {
        printf("\n-------------ESCOLHA O JOGADOR------------ \n");
        printf("Escolha o jogador \n\n");
        fflush(stdin);
        for (int i = 0; i < tam; i++)
        {
            printf("[%d] %s \n", i + 1, vetor[i].dadojog.nome);
        }
        printf("[0] SAIR \n");
        printf("Digite o codigo:  ");
        fflush(stdin);
        scanf("%d", &cod);
        fflush(stdin);
        if (cod == 0)
        {
            printf("\nATUALIZACOES FEITAS COM SUCESSO!!!\n");
            fclose(file);
            return;
        }
        if (cod < 1 || cod > tam)
        {
            printf("Nao existe jogador correspondente a esse codigo!\n Tente novamente!\n");
        }
        else
        {
            cod = cod - 1;

            do
            {
                pos = cod * sizeof(JOGADOR);
                fseek(file, pos, SEEK_SET);
                printf("\n=================================\n");
                printf("\njogador(a) %s\n", vetor[cod].dadojog.nome);

                printf("%s | %d Pts | %d PJ | %d VIT | %d E | %d DER\n", vetor[cod].dadojog.nome, vetor[cod].dadoscamp.pontcamp, vetor[cod].dadoscamp.total_jogos, vetor[cod].dadoscamp.numvit, vetor[cod].dadoscamp.numemp, vetor[cod].dadoscamp.numdef);
                printf("\n=================================\n");

                printf("[0] Sair\n[1] Adcionar vitoria (+3Pts)\n[2] Adcionar empate (+1Pts)\n[3] Adcionar derrota\n");
                fflush(stdin);
                scanf("%d", &campo);
                fflush(stdin);

                pos = cod * sizeof(JOGADOR);
                fseek(file, pos, SEEK_SET);

                switch (campo)
                {
                case 0:
                    printf("\n Jogos de %s atualizados!\n", vetor[cod].dadojog.nome);
                    break;
                case 1:
                    vetor[cod].dadoscamp.numvit++;
                    vetor[cod].dadoscamp.pontcamp += 3;
                    vetor[cod].dadoscamp.total_jogos++;
                    fflush(stdin);
                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);
                    break;
                case 2:
                    vetor[cod].dadoscamp.numemp++;
                    vetor[cod].dadoscamp.pontcamp += 2;
                    vetor[cod].dadoscamp.total_jogos++;
                    fflush(stdin);
                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);
                    break;
                case 3:
                    fflush(stdin);
                    vetor[cod].dadoscamp.numdef++;
                    vetor[cod].dadoscamp.total_jogos++;

                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);
                    break;
                default:
                    printf("Opcao invalida! Tente novamente!\n");
                }
            } while (campo != 0);
        }
    } while (cod != -1);

    fclose(file);
    return;
}

void editarJogador()
{
    int cod, campo;
    FILE *file;
    file = fopen("./arquivos/jogadores.dat", "rb+");

    if (file == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    long pos = ftell(file);
    int tam = pos / (sizeof(JOGADOR));

    fseek(file, 0, SEEK_SET);

    JOGADOR vetor[tam];

    fread(vetor, sizeof(JOGADOR), tam, file);

    do
    {
        fflush(stdin);
        printf("\n-------EDICAO DE JOGADOR------- \n");
        printf("Escolha o jogador que deseja editar: \n");

        for (int i = 0; i < tam; i++)
        {
            printf("[%d] %s \n", i + 1, vetor[i].dadojog.nome);
        }
        printf("[0] SAIR\n");
        printf("Digite o codigo:  ");
        fflush(stdin);
        scanf("%d", &cod);
        fflush(stdin);

        pos = cod * sizeof(JOGADOR);
        fseek(file, pos, SEEK_SET);

        if (cod == 0)
        {
            printf("\nATUALIZACOES FEITAS COM SUCESSO!!!\n");
            fclose(file);
            return;
        }

        if (cod < 1 || cod > tam)
        {
            printf("\nNao existe jogador correspondente a esse codigo\n");
        }
        else
        {

            cod = cod - 1;

            do
            {
                pos = cod * sizeof(JOGADOR);
                fseek(file, pos, SEEK_SET);

                printf("\nQual setor gostaria de editar do jogador %s?\n", vetor[cod].dadojog.nome);
                printf("[1] Dados Pessoais\n[2] Dados da Equipe\n[3] Dados do Marketing\n[4] Equipamentos do Hardware\n[5] Dados do Campeonato\n[0] SAIR\n");
                fflush(stdin);
                scanf("%d", &campo);
                fflush(stdin);

                switch (campo)
                {
                case 0:
                    printf("\n Edicao finalizada!\n");
                    break;

                case 1:
                    printf("\nDados pessoais atuais \n");
                    printf("   -Nome: %s\n", vetor[cod].dadojog.nome);
                    printf("   -Data de nascimento: %s\n", vetor[cod].dadojog.data);
                    printf("   -CPF: %s\n", vetor[cod].dadojog.cpf);
                    printf("   -Genero: %s\n", vetor[cod].dadojog.genero);
                    printf("   -Estado Civil: %s\n", vetor[cod].dadojog.est_civ);

                    pos = cod * sizeof(JOGADOR);
                    fseek(file, pos, SEEK_SET);

                    fflush(stdin);
                    printf("\nEDITANDO DADOS:\n");
                    printf("NOME: ");
                    gets(vetor[cod].dadojog.nome);

                    fflush(stdin);
                    printf("DATA DE NASCIMENTO:");
                    gets(vetor[cod].dadojog.data);

                    fflush(stdin);
                    printf("CPF: ");
                    gets(vetor[cod].dadojog.cpf);

                    fflush(stdin);
                    printf("Genero: ");
                    gets(vetor[cod].dadojog.genero);

                    fflush(stdin);
                    printf("Estado Civil: ");
                    gets(vetor[cod].dadojog.est_civ);

                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);

                    break;

                case 2:
                    printf("Equipe atual:\n");
                    printf("   - Nome: %s\n", vetor[cod].equipe.nomEqu);
                    printf("   - Rede social: %s\n", vetor[cod].equipe.nicEqu);
                    printf("   - Seguidores: %d\n", vetor[cod].equipe.numSegEqu);

                    printf("\n EDITANDO DADOS \n");

                    fflush(stdin);
                    printf("NOME DA EQUIPE: ");
                    gets(vetor[cod].equipe.nomEqu);

                    fflush(stdin);
                    printf("NICKNAME DA REDE SOCIAL: ");
                    gets(vetor[cod].equipe.nicEqu);

                    fflush(stdin);
                    printf("NUMERO DE SEGUIDORES DA EQUIPE: ");
                    scanf("%d", &vetor[cod].equipe.numSegEqu);

                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);

                    break;

                case 3:
                    printf("Dados do Marketing atual:\n");
                    printf("   -Patrocinadora principal: %s\n", vetor[cod].markt.patrocinador);
                    printf("   -Rede social: %s\n", vetor[cod].markt.nickname);
                    printf("   -Seguidores: %d\n", vetor[cod].markt.numSeg);

                    printf("\nEDITANDO DADOS:\n");
                    printf("PATROCINADORA: ");
                    gets(vetor[cod].markt.patrocinador);
                    fflush(stdin);

                    printf("NICKNAME NAS REDES SOCIAIS: ");
                    gets(vetor[cod].markt.nickname);

                    fflush(stdin);

                    printf("NUMERO DE SEGUIDORES: ");
                    scanf("%d", &vetor[cod].markt.numSeg);
                    fflush(stdin);

                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);

                    break;

                case 4:
                    printf("Equipamentos de Hardware atual:\n");
                    printf("   - Modelo do computador: %s\n", vetor[cod].hardware.model);
                    printf("   - Modelo do processador: %s\n", vetor[cod].hardware.proces);
                    printf("   - Modelo da placa de video: %s\n", vetor[cod].hardware.placa_video);
                    printf("   - Memoria RAM: %d\n", vetor[cod].hardware.memRam);

                    fflush(stdin);
                    printf("\nEDITANDO DADOS:\n");
                    printf("\n\nDADOS DO HARDWARE: \n");
                    printf("MODELO DO COMPUTADOR/NOTEBOOK: ");
                    gets(vetor[cod].hardware.model);
                    fflush(stdin);

                    printf("PROCESSADOR: ");
                    gets(vetor[cod].hardware.proces);
                    fflush(stdin);

                    printf("PLACA DE VIDEO: ");
                    gets(vetor[cod].hardware.placa_video);

                    fflush(stdin);

                    printf("QUANTIDADE DE MEMORIA RAM: ");
                    scanf("%d", &vetor[cod].hardware.memRam);
                    fflush(stdin);

                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);
                    break;

                case 5:
                    printf("Dados no campeonato atual:\n");
                    printf("   - Pontuacao: %d (Em %d jogos)\n", vetor[cod].dadoscamp.pontcamp, vetor[cod].dadoscamp.total_jogos);
                    printf("   - Vitorias: %d | Empates: %d | Derrotas: %d\n", vetor[cod].dadoscamp.numvit, vetor[cod].dadoscamp.numemp, vetor[cod].dadoscamp.numdef);
                    printf("   - Titulos ganhos: %d\n", vetor[cod].dadoscamp.qntTitle);
                    printf("   - Ranking mundial: %d\n", vetor[cod].dadoscamp.posRanking);

                    fflush(stdin);
                    printf("\nEDITANDO DADOS:\n");
                    printf("Quantidade de vitorias no campeonato: ");
                    scanf("%d", &vetor[cod].dadoscamp.numvit);
                    fflush(stdin);

                    printf("Quantidade de empates no campeonato: ");
                    scanf("%d", &vetor[cod].dadoscamp.numemp);
                    fflush(stdin);
                    printf("Quantidade de derrotas no campeonato: ");
                    scanf("%d", &vetor[cod].dadoscamp.numdef);
                    fflush(stdin);
                    vetor[cod].dadoscamp.pontcamp = (3 * vetor[cod].dadoscamp.numvit) + vetor[cod].dadoscamp.numemp;
                    vetor[cod].dadoscamp.total_jogos = vetor[cod].dadoscamp.numvit + vetor[cod].dadoscamp.numemp + vetor[cod].dadoscamp.numdef;

                    printf("Quantidade de titulos no campeonato: ");
                    scanf("%d", &vetor[cod].dadoscamp.qntTitle);
                    fflush(stdin);

                    printf("Posicao no Ranking Mundial: ");
                    scanf("%d", &vetor[cod].dadoscamp.posRanking);
                    fflush(stdin);

                    fwrite(&vetor[cod], sizeof(JOGADOR), 1, file);

                    break;

                default:
                    printf("Opcao invalida. Por favor, escolha novamente.\n");
                    fflush(stdin);
                    break;
                }
            } while (campo != 0);
        }
    } while (cod != -1);
    fclose(file);
    return;
}