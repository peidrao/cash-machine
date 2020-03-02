#ifndef HEADER_HPP
#define HEADER_HPP

#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>

class Cliente
{
private:
  char nome_[50];
  int senha_;
  int conta_;
  double saldo_ = 0;
public:
  void criar_conta();
  void mostrar_conta() const;
  void mensagem() const;
  int get_conta() const;
  int get_senha() const;
  double get_saldo() const;
  double deposito(double);
  double retirar(double);
};

void acessar_conta(int);
void salvar_conta();
void visualizar_contas();
void depositar(int);
void sacar(int, double);
void transferir(int, int); /*Recebe a conta que vai transferir e a conta destino*/
void consultar_saldo(int);
void menu_cliente();
void menu_inicial();
char opcao_menu();


#endif // !HEADER_HPP
