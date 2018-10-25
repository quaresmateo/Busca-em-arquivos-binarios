#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct pessoa{
   unsigned int sexo:1;
   unsigned int idade:7;//127
   unsigned int renda:10;//1023
   unsigned int escolaridade:2;//3
   unsigned int idioma:12;//4095
   unsigned int pais:8;//255
   unsigned int localizador:24;//16777215
};

void cria_BD(pessoa pessoa){
	fstream arq("pessoas123.dat",ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
   	for(unsigned long int i = 0; i < 100; i++){
      pessoa.sexo = rand()%(2);
      pessoa.idade = rand()%(127)+1;
      pessoa.renda = rand()%(1023);
      pessoa.escolaridade = rand()%(3)+1;
      pessoa.idioma = rand()%(4095);
      pessoa.pais = rand()%(255);
      pessoa.localizador = rand()%(16777215);
      arq.write((char *) &pessoa, sizeof(pessoa));
   	}
   	cout << "FINALIZADO" << endl << endl;
}

void print_BD(pessoa pessoa){
	cout << "Criando o banco de dados binario" << endl;
	fstream arq("pessoas.dat",ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	arq.seekg(0,ios_base::beg);
   	while(arq.read((char *) &pessoa, sizeof(pessoa))){
      cout << "Sexo: " << pessoa.sexo << endl;
      cout << "Idade: " << pessoa.idade << endl;
      cout << "Renda: " << pessoa.renda << endl;
      cout << "Escolaridade: " << pessoa.escolaridade << endl;
      cout << "Idioma: " << pessoa.idioma << endl;
      cout << "Pais: " << pessoa.pais << endl;
      cout << "Localizador: " << pessoa.localizador << endl << endl;

   	}
}

int main(){
   srand((unsigned)time(0));
   pessoa pessoa;
    
    cria_BD(pessoa);
   return 0;
}

