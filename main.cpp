#include <iostream>
#include <locale.h>
#include "combinacoes.h"


//https://dojopuzzles.com/problems/poker/


using namespace std;

int main() {
    char cartajogador1 = 'n';
    char cartajogador2 = 'n';

    setlocale(LC_ALL, "Portuguese");

    string cartas1[5] = {"000"}; // variavel para gardar as cartas do primeiro jogador.
    string cartas2[5] = {"000"}; // variavel para gardar as cartas do segundo jogador .
    // o {"000"} depois do = siginifica que todas as posições do vetor recebe
    // "000", isso é para evitar lixo de memoria.




    cout << "Digite as 5 cartas do jogador 1, seguindo a ordem de numero da carta e seu naipe.\n"
            "exemplo:5H\n";
    for (int i = 0; i < 5; i++) {// laço para pedir as 5 cartas so jogador 1;
        do {
            cout << "digite o " << i + 1 << "º valor: ";
            cin >> cartas1[i];
            PreparEntrada(cartas1[i]);//verifica a entrada de minusculas e faz o tratamento convertendo em maiúscula
        } while (!ValidarEntrada(cartas1[i]));//verifica se os valores são validos
    }

    cout << "Digite as 5 cartas do jogador 2, seguindo a ordem de numero da carta e seu naipe.\n"
            "exemplo:5H\n";

    for (int i = 0; i < 5; i++) {// laço para pedir as 5 cartas so jogador 2;
        do {
            cout << "digite o " << i + 1 << "º valor: ";
            cin >> cartas2[i];
            PreparEntrada(cartas2[i]);
        } while (!ValidarEntrada(cartas2[i]));//verifica se os valores são validos
    }

    if (RoyalFlush(cartas1) or RoyalFlush(cartas2)) {
        if (RoyalFlush(cartas1) and !RoyalFlush(cartas2)) {
            cout << "jogador 1 venceu, com Royal Flush!!\n";
        } else if (!RoyalFlush(cartas1) and RoyalFlush(cartas2)) {
            cout << "jogador 2 venceu, com Royal Flush!!\n";
        } else {
            if (CartaMaior(cartas1, cartas2) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2) << " venceu, com carta maior!!\n";
            }
        }
    } else if (StraightFlush(cartas1) or StraightFlush(cartas2)) {
        if (StraightFlush(cartas1) and !StraightFlush(cartas2)) {
            cout << "jogador 1 venceu, com Straight Flush!!\n";
        } else if (!StraightFlush(cartas1) and StraightFlush(cartas2)) {
            cout << "jogador 2 venceu, com Straight Flush!!\n";
        } else {
            if (CartaMaior(cartas1, cartas2) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2) << " venceu, com carta maior!!\n";
            }
        }
    } else if (Quadra(cartas1) or Quadra(cartas2)) {
        if (Quadra(cartas1) and !Quadra(cartas2)) {
            cout << "jogador 1 venceu, com Quadra!!\n";
        } else if (!Quadra(cartas1) and Quadra(cartas2)) {
            cout << "jogador 2 venceu, com Quadra!!\n";
        } else {
            if (CartaMaior(cartas1, cartas2) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2) << " venceu, com carta maior!!\n";
            }
        }
    } else if (FullHouse(cartas1, cartajogador1) or FullHouse(cartas2,cartajogador2)) {
        if (FullHouse(cartas1,cartajogador1) and !FullHouse(cartas2,cartajogador2)) {
            cout << "jogador 1 venceu, com Full House!!\n";
        } else if (!FullHouse(cartas1,cartajogador1) and FullHouse(cartas2,cartajogador2)) {
            cout << "jogador 2 venceu, com Full House!!\n";
        }else if(cartajogador1>cartajogador2 ){
            cout<<"jogador 1 venceu, com um Full House de maior valor\n";
        } else if (cartajogador1<cartajogador2){
            cout<<"jogador 2 venceu, com uma Full Hause de maior valor\n";
        } else {
            if (CartaMaior(cartas1, cartas2, cartajogador1) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2, cartajogador1) << " venceu, com carta maior!!\n";
            }
        }
    } else if (Flush(cartas1) or Flush(cartas2)) {
        if (Flush(cartas1) and !Flush(cartas2)) {
            cout << "jogador 1 venceu, com Flush!!\n";
        } else if (!Flush(cartas1) and Flush(cartas2)) {
            cout << "jogador 2 venceu, com Flush!!\n";
        } else {
            if (CartaMaior(cartas1, cartas2) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2) << " venceu, com carta maior!!\n";
            }
        }
    } else if (Straight(cartas1) or Straight(cartas2)) {
        if (Straight(cartas1) and !Straight(cartas2)) {
            cout << "jogador 1 venceu, com Straight!!\n";
        } else if (!Straight(cartas1) and Straight(cartas2)) {
            cout << "jogador 2 venceu, com Straight!!\n";
        } else {
            if (CartaMaior(cartas1, cartas2) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2) << " venceu, com carta maior!!\n";
            }
        }
    } else if (Trinca(cartas1,cartajogador1) or Trinca(cartas2,cartajogador2)) {
        if (Trinca(cartas1,cartajogador1) and !Trinca(cartas2,cartajogador2)) {
            cout << "jogador 1 venceu, com Trinca!!\n";
        } else if (!Trinca(cartas1,cartajogador1) and Trinca(cartas2,cartajogador2)) {
            cout << "jogador 2 venceu, com  Trinca!!\n";
        }else if(cartajogador1>cartajogador2 ){
            cout<<"jogador 1 venceu, com uma Trinca de maior valor\n";
        } else if (cartajogador1<cartajogador2){
            cout<<"jogador 2 venceu, com uma Trinca de maior valor\n";
        } else {
            if (CartaMaior(cartas1, cartas2, cartajogador1) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2, cartajogador1) << " venceu, com carta maior!!\n";
            }
        }
    } else if (DoisPares(cartas1,cartajogador1) or DoisPares(cartas2,cartajogador2)) {
        if (DoisPares(cartas1,cartajogador1) and !DoisPares(cartas2,cartajogador2)) {
            cout << "jogador 1 venceu, com Dois Pares!!\n";
        } else if (!DoisPares(cartas1,cartajogador1) and DoisPares(cartas2,cartajogador2)) {
            cout << "jogador 2 venceu, com Dois Pares!!\n";
        }else if(cartajogador1>cartajogador2){
            cout<<"jogador 1 venceu, com o par de maior valor\n";
        } else if (cartajogador1<cartajogador2){
            cout<<"jogador 2 venceu, com um Par  de maior valor\n";
        }else {
            if (CartaMaior(cartas1, cartas2, cartajogador1) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2, cartajogador1) << " venceu, com carta maior!!\n";
            }
        }
    } else if (UmPar(cartas1,cartajogador1) or UmPar(cartas2,cartajogador2)) {
        if (UmPar(cartas1,cartajogador1) and !UmPar(cartas2,cartajogador2)) {
            cout << "jogador 1 venceu, com um Par\n";
        } else if (!UmPar(cartas1, cartajogador1) and UmPar(cartas2,cartajogador2)) {
            cout << "jogador 2 venceu, com um Par\n";
        } else if(cartajogador1>cartajogador2){
            cout<<"jogador 1 venceu, com um Par de maior valor\n";
        } else if (cartajogador1<cartajogador2){
            cout<<"jogador 2 venceu, com um Par de maior valor\n";
        }  else {
            if (CartaMaior(cartas1, cartas2, cartajogador1) == 0) {
                cout << "Jogo empatado!!\n";
            } else {
                cout << "Jogador " << CartaMaior(cartas1, cartas2, cartajogador1) << " venceu, com carta maior!!\n";
            }
        }
    }else {
        if (CartaMaior(cartas1, cartas2) == 1) {
            cout << "jogador 1 ganhou, por carta maior!!\n";
        } else if (CartaMaior(cartas1, cartas2) == 2) {
            cout << "jogador 2 ganhou, por carta maior!!\n";
        } else {
            cout << "jogo empatado!!\n";
        }
    }

        return 0;
}