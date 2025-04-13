#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public:
    void setNome(string _nome);
    string getNome();
    void setIdade(int _idade);
    int getIdade();
    void apresentar();
};

void Pessoa::setNome(string _nome) {
    nome = _nome;
}

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setIdade(int _idade) {
    idade = _idade;
}

int Pessoa::getIdade() {
    return idade;
}

void Pessoa::apresentar() {
    cout << "Olá, meu nome é " << nome << " e tenho " << idade << " anos de idade :) ." << endl;
}

int main() {
    Pessoa TipoPessoa;

    TipoPessoa.setNome("Milena");
    TipoPessoa.setIdade(21);

    TipoPessoa.apresentar();

    getch();

    return 0;
}

