#ifndef CABECALHO_HPP
#define  CABECALHO_HPP
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
class Conta {
    private:
        char nome[50];
        int senha;
        double saldo = 0;
        int conta;
    public:
        void criarConta();
        void mostrarConta() const;
        double deposito(double);
        double retirar(double);
        void report() const;
        double getSaldo() const;
        int getConta();
        int getSenha() const;
};

void salvarConta();
void todasContas();
void fazerDeposito(int);
void fazerSaque(int, double);
void transferencia(int, int );
 int contAux(int, double);
 void consultaSaldo(int);

void menuCliente();
void menuInicial();
char opcaoMenu();
void acessarConta(int);

#endif
