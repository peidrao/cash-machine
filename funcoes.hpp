#ifndef HEADER_HPP
#define HEADER_HPP

#include <math.h>
#include <iostream>
#include <fstream>

class Cliente
{
private:
  char nome[50];
  int senha_;
  int conta_;
  float saldo_ = 0;
public:
  void criar_conta();
  void mostrar_conta() const;
  void mensagem() const;
  int get_conta() const;
  int get_senha() const;
  double get_saldo() const;
  double deposito();
  double retirar();
};




#endif // !HEADER_HPP
