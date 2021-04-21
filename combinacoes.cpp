#include "combinacoes.h"
#include <ostream>

using namespace std;

bool RoyalFlush(string cartas[5]){

    for (int i = 0;i<4;i++) {//laço para verivicar se os naipes são iguais
        if (cartas[i][1] != cartas[i+1][1]) {
            if (cartas[i][1] !='0' and cartas[i+1][1] !='0') {//condição para verificar se são do mesmo naipe
                return false;
            } else if (cartas[i][1] == '0' and cartas[i+1][1] != '0'){ // verifica a posibilidade
                if (cartas[i][2] != cartas[i+1][1]){                   // de um desles for 10
                    return false;
                }
            }else if (cartas[i+1][1] == '0' and cartas[i][1] != '0'){// verifica a posibilidade
                if (cartas[i+1][2] != cartas[i][1]){                 // de um desles for 10
                    return false;
                }
            }else {
                if (cartas[i][2] != cartas[i+1][2]){ // verifiva a posibilidade de ambos
                    return false;                    // forem 10
                }
            }
        }
    }

    int condicoes[5] = {0};//variavel para auxiliar na verificação das condição

    for (int i = 0;i<5;i++){//laço para verificar as condições de vitoria

        if(cartas[i][0] == '1' && cartas[i][1] == '0' && condicoes[0] != 1){
            condicoes[0]=1;
        }else if(cartas[i][0] == 'T' and condicoes[1] == 0){
            condicoes[1]=1;
        }else if(cartas[i][0] == 'Q' and condicoes[2] == 0){
            condicoes[2]=1;
        }else if(cartas[i][0] == 'K' and condicoes[3] == 0){
            condicoes[3]=1;
        }else if(cartas[i][0] == 'A' and condicoes[4] == 0){
            condicoes[4]=1;
        }
    }
    for (int i=0;i<5;i++){//esse laço verifica se uma condição não bateu
        if (condicoes[i]==0){ // se uma das consições for igual a 0 ele finaliza a função e retorna falso
            return false;
        }
    }
    return true;
}

bool StraightFlush(string cartas[5]){
    for (int i = 0;i<4;i++) {//laço para verivicar se os naipes são iguais
        if (cartas[i][1] != cartas[i+1][1]) {
            if (cartas[i][1] !='0' and cartas[i+1][1] !='0') {//condição para verificar se são do mesmo naipe
                return false;
            } else if (cartas[i][1] == '0' and cartas[i+1][1] != '0'){ // verifica a posibilidade
                if (cartas[i][2] != cartas[i+1][1]){                   // de um desles for 10
                    return false;
                }
            }else if (cartas[i+1][1] == '0' and cartas[i][1] != '0'){// verifica a posibilidade
                if (cartas[i+1][2] != cartas[i][1]){                 // de um desles for 10
                    return false;
                }
            }else {
                if (cartas[i][2] != cartas[i+1][2]){ // verifiva a posibilidade de ambos
                    return false;                    // forem 10
                }
            }
        }
    }

    char valores[5];//variavel para fazer a odernação dos valores
    char aux; // variavel para auxiliar na ordernação

    string  comparacao[9] = {"23456","34567","45678","56789","16789","1789T","189QT","19KQT","1AKQT"};
    const char *valorComparado;

    for (int i = 0;i<5;i++){ // inscere os valores no vetor
        valores[i]  = cartas[i][0];
    }

    for (int j = 0;j<4;j++) {//faz a ordenação
        for (int i = 0; i < 4; ++i) {//percorre a lista
            if (valores[i] > valores[i + 1]) {
                aux = valores[i + 1];
                valores[i + 1] = valores[i];
                valores[i] = aux;
            }
        }
    }

    valorComparado = valores; // aloca os valores no vetor de comparação

    for (int i = 0; i<9;i++){ //compara os valores com todas as possibilidades
        if (valorComparado == comparacao[i]){
            return true;
        }
    }
    return false;
}

bool Quadra(string carta[5]){
    char variaveldecontrole = 'n';  // variavel para guardar a primeira carta que não for
                                // igual ao valor do primeiro indice
    int quantidadedepar=0; // variavel para guardar o numero de pares

    for (int i=0;i<4;i++){ // laço para percorrer o vetor carta
        if (carta[i][0]==carta[i+1][0]){ //compara a posição 0 da string da posição i
           if (quantidadedepar>=2 and variaveldecontrole!='n'){
                return false;
            }                             // da variavel carta.
            quantidadedepar++;// se a condição bater ele adiciona +1
        } else {
            if (variaveldecontrole == 'n') { // testa para ver se a variavel já foi usada
                variaveldecontrole = carta[i][0];// caso não ele guarda o valor da carta i
            } else {

                for(int j = i;j<4;j++){ // caso já tenha esse loço inicia j = i para fazer a compração
                                        //  com a variavel de controle dos restantes dos elementos
                    if (variaveldecontrole==carta[j+1][0]){
                        quantidadedepar++;
                    } else{
                        return false;
                    }

                    if (quantidadedepar>=3){
                        return true;
                    }
                }
            }
        }
    }

    if (quantidadedepar>=3){ //se bateu a quantidade necessaria ele retorna verdadeiro
                            // caso não retorna falso
        return true;
    } else{
        return false;
    }
}

struct ValorRef{ // criei um tipo para usar como referencia para as comparações
    char valor = 'n';
    int quantidade = 0;
};

bool FullHouse(string carta[5],char &cartajogador){
    ValorRef valoreref[2];

    valoreref[0].valor = carta[0][0]; // indico a carta 1 para ser usada como referecia primaria
    for (int i = 1;i<5;i++){//começamos ja no indice 1 pós o indice 0 já esta sendo referenciado
        if (valoreref[0].valor == carta[i][0]){
            valoreref[0].quantidade++;
        } else if (valoreref[1].valor == 'n'){

            valoreref[1].valor = carta[i][0];
        } else if (valoreref[1].valor == carta[i][0]){
            valoreref[1].quantidade++;

        }else {
            return false;
        }
    }


    if (valoreref[0].quantidade == 2){
        cartajogador = valoreref[0].valor;
    } else if (valoreref[1].quantidade == 2){
        cartajogador = valoreref[1].valor;
    }

    if (valoreref[0].quantidade == 2 or valoreref[0].quantidade == 1){
        if (valoreref[1].quantidade == 2 or valoreref[1].quantidade ==1){
            return true;
        }
    }
    return false;
}

bool Flush(string cartas[5]){

    for (int i = 0;i<4;i++) {//laço para verivicar se os naipes são iguais
        if (cartas[i][1] != cartas[i+1][1]) {
            if (cartas[i][1] !='0' and cartas[i+1][1] !='0') {//condição para verificar se são do mesmo naipe
                return false;
            } else if (cartas[i][1] == '0' and cartas[i+1][1] != '0'){ // verifica a posibilidade
                if (cartas[i][2] != cartas[i+1][1]){                   // de um desles for 10
                    return false;
                }
            }else if (cartas[i+1][1] == '0' and cartas[i][1] != '0'){// verifica a posibilidade
                if (cartas[i+1][2] != cartas[i][1]){                 // de um desles for 10
                    return false;
                }
            }else {
                if (cartas[i][2] != cartas[i+1][2]){ // verifiva a posibilidade de ambos
                    return false;                    // forem 10
                }
            }
        }
    }

    return true; // caso nem umas da condição bater no laço de cima ele retorna verdeiro
}

bool Straight(string cartas[5]){
    char valores[5];//variavel para fazer a odernação dos valores
    char aux; // variavel para auxiliar na ordernação

    string  comparacao[9] = {"23456","34567","45678","56789","16789","1789T","189QT","19KQT","1AKQT"};
    const char *valorComparado;

    for (int i = 0;i<5;i++){ // inscere os valores no vetor
        valores[i]  = cartas[i][0];
    }

    for (int j = 0;j<4;j++) {//faz a ordenação
        for (int i = 0; i < 4; ++i) {//percorre a lista
            if (valores[i] > valores[i + 1]) {
                aux = valores[i + 1];
                valores[i + 1] = valores[i];
                valores[i] = aux;
            }
        }
    }

    valorComparado = valores; // aloca os valores no vetor de comparação

    for (int i = 0; i<9;i++){ //compara os valores com todas as possibilidades
        if (valorComparado == comparacao[i]){
            return true;
        }
    }
    return false;
}

bool Trinca(string cartas[5], char &cartajogador ){
    ValorRef valorref[3] ; //vetor para a realização das contagens dos valors da cartas

    valorref[0].valor = cartas[0][0]; // a promeira posição será alocada para a prmeira carta
    valorref[0].quantidade++;// adicionamos mais 1 na somagem da carta

    for (int i = 1; i<5;i++){//percoremos o vetor cartas
        if (cartas[i][0]==valorref[0].valor){ // verificamos se o valor da posição i das cartas coresponde a da posiçao
            valorref[0].quantidade++;         // 0 do vetor de contagens, caso verdadeiro adiciona + 1 na quantidade.
        } else if(valorref[1].valor =='n'){ // verifica se a posição 1 da variavel de contagem esta disponivel
            valorref[1].valor = cartas[i][0];// caso sim, caso sim ele aloca o valor da carta da posição i  na posição 1
            valorref[1].quantidade++;// adiciona 1 na contagem
        } else if (valorref[1].valor != 'n'){
            if (cartas[i][0]==valorref[1].valor){
                valorref[1].quantidade++;
            } else if(valorref[2].valor == 'n'){
                valorref[2].valor = cartas[i][0];
                valorref[2].quantidade++;
            }else if (valorref[2].valor == cartas[i][0]){
                valorref[2].quantidade++;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {//percore o vetor de quantidade para ver se algum elemento bateu com a nececidade
        if (valorref[i].quantidade>=3){

            if (valorref[i].valor == '1'){
                cartajogador=':';
            }else if (valorref[i].valor =='T'){
                cartajogador=';';
            }else if (valorref[i].valor == 'Q'){
                cartajogador='<';
            }else if (valorref[i].valor=='K'){
                cartajogador='=';
            } else if (valorref[i].valor=='A'){
                cartajogador='>';
            } else {
                cartajogador = valorref[i].valor;
            }
            return true;
        }
    }

    return false;
}

bool DoisPares(string cartas[5],char &cartajogador){

    int quantidedepares = 0; // variavel para somar a quantidade de pares presente

    ValorRef valorref[3] ; //vetor para a realização das contagens dos valors da cartas

    valorref[0].valor = cartas[0][0]; // a promeira posição será alocada para a prmeira carta
    valorref[0].quantidade++;// adicionamos mais 1 na somagem da carta

    for (int i = 1; i<5;i++){//percoremos o vetor cartas
        if (cartas[i][0]==valorref[0].valor){ // verificamos se o valor da posição i das cartas coresponde a da posiçao
            valorref[0].quantidade++;         // 0 do vetor de contagens, caso verdadeiro adiciona + 1 na quantidade.
        } else if(valorref[1].valor =='n'){ // verifica se a posição 1 da variavel de contagem esta disponivel
            valorref[1].valor = cartas[i][0];// caso sim, caso sim ele aloca o valor da carta da posição i  na posição 1
            valorref[1].quantidade++;// adiciona 1 na contagem
        } else if (valorref[1].valor != 'n'){
            if (cartas[i][0]==valorref[1].valor){
                valorref[1].quantidade++;
            } else if(valorref[2].valor == 'n'){
                valorref[2].valor = cartas[i][0];
                valorref[2].quantidade++;
            }else if (valorref[2].valor == cartas[i][0]){
                valorref[2].quantidade++;
            }
        }
    }



    for (int i = 0; i < 3; ++i) {//percore o vetor de quantidade para ver se algum elemento bateu com a nececidade
        if (valorref[i].quantidade==2){
            if (valorref[i].valor == '1'){
                cartajogador=':';
            }else if (valorref[i].valor =='T'){
                cartajogador=';';
            }else if (valorref[i].valor == 'Q'){
                cartajogador='<';
            }else if (valorref[i].valor=='K'){
                cartajogador='=';
            } else if (valorref[i].valor=='A'){
                cartajogador='>';
            } else {
                cartajogador = valorref[i].valor;
            }
            quantidedepares++;
        }
    }

    if (quantidedepares == 2){
        return true;
    }

    return false;
}

bool UmPar(string cartas[5],char &cartajogador ){

    int quantidedepares = 0; // variavel para somar a quantidade de pares presente
    ValorRef valorref[4] ; //vetor para a realização das contagens dos valors da cartas

    valorref[0].valor = cartas[0][0]; // a promeira posição será alocada para a prmeira carta
    valorref[0].quantidade++;// adicionamos mais 1 na somagem da carta

    for (int i = 1; i<5;i++) {//percoremos o vetor cartas
        if (cartas[i][0] == valorref[0].valor) { // verificamos se o valor da posição i das cartas coresponde a da posiçao
            valorref[0].quantidade++;         // 0 do vetor de contagens, caso verdadeiro adiciona + 1 na quantidade.
        } else if (valorref[1].valor == 'n') { // verifica se a posição 1 da variavel de contagem esta disponivel
            valorref[1].valor = cartas[i][0];// caso sim, caso sim ele aloca o valor da carta da posição i  na posição 1
            valorref[1].quantidade++;// adiciona 1 na contagem
        } else if (valorref[1].valor != 'n') {
            if (cartas[i][0] == valorref[1].valor) {
                valorref[1].quantidade++;
            } else if (valorref[2].valor == 'n') {
                valorref[2].valor = cartas[i][0];
                valorref[2].quantidade++;
            } else if (valorref[2].valor != 'n') {
                if (cartas[i][0] == valorref[2].valor) {
                    valorref[2].quantidade++;
                } else if (valorref[3].valor == 'n') {
                    valorref[3].valor = cartas[i][0];
                    valorref[3].quantidade++;
                } else if (valorref[3].valor == cartas[i][0]) {
                    valorref[3].quantidade++;
                }
            }
        }
    }



    for (int i = 0; i < 4; ++i) {//percore o vetor de quantidade para ver se algum elemento bateu com a nececidade
        if (valorref[i].quantidade == 2){
            if (valorref[i].valor == '1'){
                cartajogador=':';
            }else if (valorref[i].valor =='T'){
                cartajogador=';';
            }else if (valorref[i].valor == 'Q'){
                cartajogador='<';
            }else if (valorref[i].valor=='K'){
                cartajogador='=';
            } else if (valorref[i].valor=='A'){
                cartajogador='>';
            } else {
                cartajogador = valorref[i].valor;
            }
            quantidedepares++;
        }
    }



    if (quantidedepares == 1){
        return true;
    }

    return false;
}

int CartaMaior(string cartas1[5], string cartas2[5], char cartajogador) {

    //essa função retorna 1 se o jogador um tiver o maior valor  ou 2 se o jogador 2 tiver e 0 para empate

    char valores1[5];//variavel para fazer a odernação dos valores1
    char valores2[5];
    char aux; // variavel para auxiliar na ordernação



    int ganhador;


    for (int i = 0; i < 5; i++) { // inscere os valores1 no vetor

        if (cartas1[i][0] == 'T') {
            valores1[i] = ';';
        } else if (cartas1[i][0] == 'Q') {
            valores1[i]= '<';
        } else if (cartas1[i][0] == 'K') {
            valores1[i]='=';
        } else if (cartas1[i][0] == 'A') {
            valores1[i]='>';
        } else if (cartas1[i][0] == '1') {
            valores1[i]=':';
        } else {

            valores1[i] = cartas1[i][0];
        }
    }


    for (int i = 0; i<5;i++){
        if (valores1[i]==cartajogador){
            valores1[i]='0';
        }
    }

    for (int j = 0; j < 4; j++) {//faz a ordenação
        for (int i = 0; i < 4; ++i) {//percorre a lista

            if (valores1[i] > valores1[i + 1]) {
                aux = valores1[i + 1];
                valores1[i + 1] = valores1[i];
                valores1[i] = aux;
            }
        }
    }


    for (int i = 0; i < 5; i++) { // inscere os valores1 no vetor
        if (cartas2[i][0] == 'T') {
            valores2[i] = ';';
        } else if (cartas2[i][0] == 'Q') {
            valores2[i]= '<';
        } else if (cartas2[i][0] == 'K') {
            valores2[i]='=';
        } else if (cartas2[i][0] == 'A') {
            valores2[i]='>';
        } else if (cartas2[i][0] == '1') {
            valores2[i]=':';
        } else {
            valores2[i] = cartas2[i][0];
        }
    }

    for (int i = 0; i<5;i++){
        if (valores2[i]==cartajogador){
            valores2[i]='0';
        }
    }

    for (int j = 0; j < 4; j++) {//faz a ordenação
        for (int i = 0; i < 4; ++i) {//percorre a lista
            if (valores2[i] > valores2[i + 1]) {
                aux = valores2[i + 1];
                valores2[i + 1] = valores2[i];
                valores2[i] = aux;
            }
        }
    }



   if (valores1[4] > valores2[4]){
       return 1;
   } else if (valores1[4] < valores2[4]){
       return 2;
   }
    return 0;
}

void PreparEntrada(string &carta){



    int i; // indice para a posibilidade do 10

    if (carta[1]=='0'){
        i = 2;
    } else{
        i = 1;
    }

    switch (carta[i]) {
        case 'd':
            carta[1]='D';
            break;
        case 'h':
            carta[i]='H';
            break;
        case 's':
            carta[i]='S';
            break;
        case 'c':
            carta[i]='C';
            break;
    }

    switch (carta[0]) {
        case 't':
            carta[0]='T';
            break;
        case 'q':
            carta[0]='Q';
            break;
        case 'k':
            carta[0]='K';
            break;
        case 'a':
            carta[0]='A';
            break;
    }

}

bool ValidarEntrada(string carta){

    // essa finção retorna true se a entrada de dados estiverem correta e false se não estiver

    int j;//varivar usada  no indece do naipe da carta.

        if (carta[1] == '0') { // verifica a posivel presença do 10
            j = 2;
        } else {
            j = 1;
        }

       if (carta[j] != 'D' and carta[j] != 'H' and
            carta[j] != 'S' and carta[j] != 'C') {//verifica se os naipes são validos
            printf("Valor invalido tente novamente!!\n");
            return false;

        }


        if ((carta[0] < '1' or carta[0] > '9') and carta[0] != 'T' and
            carta[0] != 'Q' and carta[0] != 'K' and carta[0] != 'A') {//verifica se os valores são validos
            printf("Valor invalido tente novamente!!\n");
            return false;
        }

        if (j == 2) {
            if (carta[1] != '0') {
                printf("Valor invalido tente novamente!!\n");
                return false;
            }
        }

    return true;
}
