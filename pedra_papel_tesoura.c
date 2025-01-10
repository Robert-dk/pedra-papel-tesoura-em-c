/*
 * Jogo Pedra, Papel e Tesoura
 * Autor: Robert Emanuel
 * Data de Criação: 26-04-2024
 * Versão: 2.0
 * Descrição: Neste projeto, o usuario e o computador escolhem entre 
 pedra, papel ou tesoura. Sabendo que pedra ganha de tesoura, 
 papel ganha de pedra e tesoura ganha de papel, 
 exiba na tela o ganhador: usuario ou computador.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Opções do jogo
    char *opcoes[] = {"Pedra", "Papel", "Tesoura"};

    // Entrada do jogador
    printf("----------------\n");
    printf("| BEM VINDO!!! |\n");
    printf("----------------\n\n");
    
    int escolhaJogador;
    do { // Loop para garantir entrada válida
        printf("Escolha uma opção (0 - Pedra, 1 - Papel, 2 - Tesoura): ");
        if (scanf("%d", &escolhaJogador) != 1 || escolhaJogador < 0 || escolhaJogador > 2) {
            printf("Entrada inválida. Digite 0, 1 ou 2.\n");
            // Limpar o buffer de entrada
            while(getchar() != '\n'); // Evitar loop infinito
        } else {
            break; // Sai do loop se a entrada for válida
        }
    } while (1); // Loop infinito ate que a entrada seja válida
   
    // Escolha do pc
    srand(time(NULL));
    int escolhaComputador = rand() % 3;

    // Exibir escolhas
    printf("\nVocê escolheu: %s\n", opcoes[escolhaJogador]);
    printf("O computador escolheu: %s\n", opcoes[escolhaComputador]);
    printf("----------------\n\n");

    // Verificar vencedor
    if (escolhaJogador == escolhaComputador) {
        printf("Empate!\n");
    } else if ((escolhaJogador == 0 && escolhaComputador == 2) || // Pedra vs Tesoura
               (escolhaJogador == 1 && escolhaComputador == 0) || // Papel vs Pedra
               (escolhaJogador == 2 && escolhaComputador == 1)) { // Tesoura vs Papel
        printf("Você venceu!\n");
    } else {
        printf("Você perdeu!\n");
    }
    printf("----------------\n\n");

    return 0;
}