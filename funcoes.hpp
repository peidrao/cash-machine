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
<<<<<<< HEAD
  double saldo_ = 0;
=======
  float saldo_ = 0.0;
>>>>>>> a1b425673b0f7f9e532482986c3ef9398a7fc79a
public:
  void criar_conta();
  void mostrar_conta() const;
  void mensagem() const;
  int get_conta() const;
  int get_senha() const;
<<<<<<< HEAD
  double get_saldo() const;
  double deposito(double);
  double retirar(double);
=======
  float get_saldo() const;
  float deposito(float);
  float retirar(float);
>>>>>>> a1b425673b0f7f9e532482986c3ef9398a7fc79a
};

void acessar_conta(int);
void salvar_conta();
void visualizar_contas();
void depositar(int, float);
void sacar(int, float);
void transferir(int, int); /*Recebe a conta que vai transferir e a conta destino*/
void saldo_atual(int);
void menu_cliente();
void menu_inicial();
char opcao_menu();
void listarClientes(); /* Função para visualizar todos os usuários -> Teste */



#endif // !HEADER_HPP
