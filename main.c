#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#include "libs/functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int num, aux;
    char nome[30];

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
        printf("> ");

        scanf("%d", &num);

        switch (num)
        {
        case 0:
            break;

        case 1:
            printf("\nInsira quantos jogadores deseja cadastrar: ");
            scanf("%d", &aux);

            escreverJogadoresArquivo(inserirJogadoresVetor(aux), aux);

            system("pause");
            break;

        case 2:
            editarJogador();
            system("pause");
            break;

        case 3:
            atualiza_camp();
            system("pause");
            break;

        case 4:
            listarAlfabetico();
            system("pause");
            break;

        case 5:
            printClassificacaoMundial();
            system("pause");
            break;

        case 6:
            listarVitoria();
            system("pause");
            break;

        case 7:
            listarPosicao();
            system("pause");
            break;

        case 8:
            printf("Insira a pontuacao minima desejada: ");
            scanf("%d", &aux);

            printJogadorPontuacaoMaior(aux);
            system("pause");
            break;

        case 9:
            printf("Insira a pontuacao maxima desejada: ");
            scanf("%d", &aux);

            printJogadorPontuacaoMenor(aux);
            system("pause");
            break;

        case 10:
            buscaNome();
            system("pause");
            break;

        case 11:
            buscaPosicao();
            system("pause");
            break;

        case 12:
            printSeguidores();
            system("pause");
            break;

        default:
            printf("Insira um numero valido!\n");
            fflush(stdin);
            system("pause");
            break;
        }

    } while (num != 0);
}