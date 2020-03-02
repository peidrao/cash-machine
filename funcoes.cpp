#include "funcoes.hpp"

using namespace std;

  int Cliente::get_conta() const {
    return saldo_;
  }
  int Cliente::get_senha() const {
    return senha_;
  }
  double Cliente::get_saldo() const {
    return saldo_;
  }

double Cliente::deposito(double saldo) {
  return saldo_ += saldo;
}
double Cliente::retirar(double saldo) {
  return saldo_ -= saldo;
}  

void Cliente::criar_conta() {
  cin.ignore();

  cout << "Digite seu nome: ";
  cin >> nome_;
  cout << "Digite uma senha (numérica): ";
  cin >> senha_;
  conta_ = senha_ + (random() % 1000 + 9999 );
  cout << "Sua conta: " << conta_ << endl;
  char opcao;
  do
  {
  cout << "Deseja fazer algum depósito? (s/n)" ;
  cin >> opcao;
  if(opcao == 's') {
    cout << "Dinheiro depositado: R$ ";
    cin >> saldo_;
  } 
  } while (opcao == 'n');
  
  cout << "Conta criada com sucesso!" << endl;
} 

void Cliente::mostrar_conta() const {
  cout << "Número da conta: " << conta_ << endl;
  cout << "Nome do proprietário: " << nome_ << endl;
}

void Cliente::mensagem() const {
  cout << conta_ << setw(6) << " " << nome_ << setw(6) << " " << saldo_ << endl;
}
