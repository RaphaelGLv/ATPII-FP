#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "libs/functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int num, tam;

    do
    {
        printf("\nFavor indicar o que deseja fazer com um numero.\n");
        printf("================================== MENU =================================\n");
        printf("| 1 - Inserir um jogador novo                                           |\n");
        printf("| 2 - Alterar os dados de um jogador                                    |\n");
        printf("| 3 - Inserir vitoria, derrota ou empate a um jogador                   |\n");
        printf("| 4 - Listar os jogadores cadastrados em ordem alfabetica               |\n");
        printf("| 5 - Listar os jogadores cadastrados por posicao no Ranking Mundial    |\n");
        printf("| 6 - Listar os jogadores cadastrados por maior quantidade de vitorias  |\n");
        printf("| 7 - Listar a classificacao dos jogadores no campeonato                |\n");
        printf("| 8 - Listar os jogadores com pontuacao acima do que fornecer           |\n");
        printf("| 9 - Listar os jogadores com pontuacao abaixo do que fornecer          |\n");
        printf("| 10 - Buscar um jogador por nome                                       |\n");
        printf("| 11 - Buscar um jogador por posicao no Ranking Mundial                 |\n");
        printf("| 12 - Exibir a quantidade de seguidores media por jogador cadastrado   |\n");
        printf("| 0 - Sair                                                              |\n");
        printf("=========================================================================\n");

        scanf("%d", &num);

        switch (num)
        {
        case 0:
            break;

        case 1:
            printf("\nInsira quantos jogadores deseja cadastrar: ");
            scanf("%d", &tam);

            escreverJogadoresArquivo(inserirJogadoresVetor(tam), tam);

            break;

        case 2:
            // editarJogador();
            break;

        case 3:
            // editarPontuacaoJogador();
            break;

        case 4:
            listarAlfabetico();
            break;

        case 5:
            printClassificacaoMundial();
            break;

        case 6:
            listarVitoria();
            break;

        case 7:
            listarPosicao();
            break;

        case 8:
            // printJogadorPontuacaoMaior();
            break;

        case 9:
            // printJogadorPontuacaoMenor();
            break;

        case 10:
            // buscaNome();
            break;

        case 11:
            buscaPosicao();
            break;

        case 12:
            printSeguidores();
            break;

        default:
            printf("Insira um numero valido!\n");
            break;
        }
    } while (num != 0);
}