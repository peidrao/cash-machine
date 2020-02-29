#include "funcoes.hpp"
using namespace std;

void Cliente::mostrar_conta() const {
  cout << "Nome do Proprietário: " << setw(5) << nome_ << endl;
  cout << "Conta: " << setw(10) << conta_ << endl;
  cout << "Saldo: " << setw(10) << saldo_ << endl;
}

double Cliente::deposito(double x) {
  return saldo_ += x; 
}

double Cliente::retirar(double y) {
  return saldo_ -= y;
}

int Cliente::get_conta() const {
  return conta_;
}

int Cliente::get_senha() const {
  return senha_;
}

double Cliente::get_saldo() const {
  return saldo_;
}

void Cliente::mensagem() const {
  cout << conta_ << setw(6) << "|" << nome_ << setw(6) << "| R$" << saldo_ << endl;    
}

void Cliente::criar_conta(){
  char opcao;
  cin.ignore();
  cout << "Nome: " ;
  cin >> nome_;
  cout << "Senha (Apenas números): " ;
  cin >> senha_;
  conta_ = senha_ + (rand() % 1000);
  cout << "Conta: " << conta_ << endl;

  do
  {
    cout << "+=============================+" << endl
       << "| DESEJA FAZER ALGUM DEPÓSITO |" << endl
       << "| | ( S ) SIM ||| ( N ) NÃO | |" << endl
       << "+=============================+" << endl
       << "|DIGITE UMA OPCAO >>>>> " ;
  
  cin >> opcao;
  if (opcao == 's' || 'S')
  {
    cout << "QUANTO DESEJA DEPOSITAR: R$ ";
    cin >> saldo_;
  } else {
    cout << "Opção inválida! Digite novamente!" << endl;
  }
  
  } while (opcao != 'S' || 's');
  cout << "Conta criada com sucesso!" << endl;
  
}
