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
  float saldo_ = 0.0;
public:
  void criar_conta();
  void mostrar_conta() const;
  void mensagem() const;
  int get_conta() const;
  int get_senha() const;
  float get_saldo() const;
  float deposito(float);
  float retirar(float);
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
