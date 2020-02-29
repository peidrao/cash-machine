#include "funcoes.hpp"
using namespace std;

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
