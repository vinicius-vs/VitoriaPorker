#ifndef TRUCO_COMBINACOES_H
#define TRUCO_COMBINACOES_H

#include <ostream>

using namespace std;

bool RoyalFlush (string cartas[5]);

bool StraightFlush(string cartas[5]);

bool Quadra(string carta[5]);

bool FullHouse(string carta[5], char &cartajogador);

bool Flush(string cartas[5]);

bool Straight(string carta[5]);

bool Trinca(string cartas[5],char &cartajogador);

bool DoisPares(string cartas[5], char &cartajogador);

bool UmPar(string cartas[5], char &cartajogador);

int CartaMaior(string cartas1[5], string cartas2[5], char cartajogador= 'n');

void PreparEntrada(string &carta);

bool ValidarEntrada(string carta);

#endif //TRUCO_COMBINACOES_H
