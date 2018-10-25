#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>

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

char arquivo[] = "pessoas100M_sort.dat";
vector <pessoa> tmp;
static unsigned long int tam = 100000000;

void cria_vetor(){
	pessoa pessoa;

	fstream arq("pessoas_100M.dat",ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	arq.seekg(0,ios_base::beg);
	while(arq.read((char *) &pessoa, sizeof(pessoa))){
   		tmp.push_back(pessoa);
	}
	arq.close();
}

/*
void print_BD(pessoa pessoa){
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

void acessa_arquivo(){
	arq.seekg(0,ios_base::beg);
   while(arq.read((char *) &pessoa, sizeof(pessoa))){
      //cout << "Sexo: " << pessoa.sexo << endl;
      cout << "Idade: " << pessoa.idade << endl;
      /*cout << "Renda: " << pessoa.renda << endl;
      cout << "Escolaridade: " << pessoa.escolaridade << endl;
      cout << "Idioma: " << pessoa.idioma << endl;
      cout << "Pais: " << pessoa.pais << endl;
      cout << "Localizador: " << pessoa.localizador << endl << endl;

		count++;
		cout << count << endl;
		//if (count == )
   }
}*/

int print_menu(){
	int comand;
	//system("clear");
	cout << "\t\t Bem vindo, escolha uma das opcoes abaixo digitando o numero da opcao ( 0 pra sair )\n" << endl;
	cout << "Opcao 1 - Contar o numero de pesosas que tem o mesmo genero e moram no mesmo pais." << endl;
	cout << "Opcao 2 - Contar o numero de pesosas que tem o mesmo genero, idade e moram no mesmo pais." << endl;
	cout << "Opcao 3 - Tirar a media de salario de pessoas que tem o mesmo genero e moram no mesmo pais." << endl;
	cout << "Opcao 4 - Tirar a media de idade de pessoas que tem o mesmo genero e moram no mesmo pais." << endl;
	cout << "Opcao 5 - Contar o numero de pesosas que tem o mesmo genero e moram em um pais especifico." << endl;
	cout << "Opcao 6 - Contar o numero de pesosas que sao de um determinado genero e moram em um pais especifico." << endl;
	cout << "Opcao 7 - Contar o numero de pesosas que tem o mesmo genero e moram em determinados paises." << endl;
	cout << "\n\t\tOpcoes Avancadas" << endl;
	cout << "Opcao 8 - Mostra o PIB de cada pais" << endl;
	cout << "Opcao 9 - Mostra a media do salario dos aposentados de cada pais" << endl;
	cout << "Opcao 10 - Conta a faixa etaria de toda a população" << endl;
	cout << ">>";
	cin >> comand;
	return comand;
}

void query1(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == pais) && (0 == tmp[i].sexo))
				_count_p[count_p]++;
			
			if((tmp[i].pais == pais) && (1 == tmp[i].sexo)){
				_count_s[count_s]++;
			}
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_p.push_back(0);
				_count_s.push_back(0);
				count_p++;
				count_s++;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " count " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i >=10){
				if(i >=100){
					cout << "  " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl;
					cout << "  " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;
				}else{
				cout << "   " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl;			
				cout << "   " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;
				}
			}else{
			cout << "    " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl; 
			cout << "    " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;	
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query2(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int idade = tmp[0].idade;
	vector <int> _count_is;
	unsigned long int count_is = 0;
	vector <int> _count_ip;
	unsigned long int count_ip = 0;
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	vector <int> ida;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	ida.push_back(idade);
	_count_p.push_back(0);
	_count_s.push_back(0);
	_count_ip.push_back(0);
	_count_is.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == pais) && (0 == tmp[i].sexo) && (tmp[i].idade == idade)){
				_count_p[count_p]++;
				_count_ip[count_ip]++;
			}
			
			if((tmp[i].pais == pais) && (1 == tmp[i].sexo) && (tmp[i].idade == idade)){
				_count_s[count_s]++;
				_count_is[count_is]++;
			}

			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				idade = tmp[i].idade;
				ida.push_back(idade);
				_count_p.push_back(0);
				_count_s.push_back(0);
				_count_ip.push_back(0);
				_count_is.push_back(0);
				count_p++;
				count_s++;
				count_ip++;
				count_is++;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " idade " << " | " << " count " << endl;
		for(int i = 0; i<255; i++){
			if (i >=10){
				if(i >=100){
					cout << "  " << i << "  |   " << 0 << "    |    " << ida[i] << "  |   " << _count_ip[i] << endl;
					cout << "  " << i << "  |   " << 1 << "    |    " << ida[i] << "  |   " << _count_is[i] << endl;
				}else{
				cout << "   " << i << "  |   " << 0 << "    |    " << ida[i] << "  |   " << _count_ip[i] << endl;			
				cout << "   " << i << "  |   " << 1 << "    |    " << ida[i] << "  |   " << _count_is[i] << endl;
				}
			}else{
			cout << "    " << i << "  |   " << 0 << "    |    " << ida[i] << "  |   " << _count_ip[i] << endl; 
			cout << "    " << i << "  |   " << 1 << "    |    " << ida[i] << "  |   " << _count_is[i] << endl;
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query3(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_rs = 0;
	vector <int> _count_rs;
	unsigned long int count_rp = 0;
	vector <int> _count_rp;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	vector <int> mp;
	vector <int> ms;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_rs.push_back(0);
	_count_rp.push_back(0);
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == pais) && (0 == tmp[i].sexo)){
				_count_p[count_p]++;
				_count_rp[count_p] += tmp[i].renda;
				count_rp++;
			}
			
			if((tmp[i].pais == pais) && (1 == tmp[i].sexo)){
				_count_s[count_s]++;
				_count_rs[count_s] += tmp[i].renda;
				count_rs++;
			}
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_s.push_back(0);
				_count_p.push_back(0);
				_count_rs.push_back(0);
				_count_rp.push_back(0);
				count_p++;
				count_s++;
				mp.push_back(count_rp);
				ms.push_back(count_rs);
				count_rp = 0;
				count_rs = 0;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " avg(idade) " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i >=10){
				if(i >=100){
					cout << "  " << i << "  |   " << 0 << "    |    " << _count_rp[i]*1000/float(mp[i]) << endl;
					cout << "  " << i << "  |   " << 1 << "    |    " << _count_rs[i]*1000/float(ms[i]) << endl;
				}else{
				cout << "   " << i << "  |   " << 0 << "    |    " << _count_rp[i]*1000/float(mp[i]) << endl;			
				cout << "   " << i << "  |   " << 1 << "    |    " << _count_rs[i]*1000/float(ms[i]) << endl;
				}
			}else{
			cout << "    " << i << "  |   " << 0 << "    |    " << _count_rp[i]*1000/float(mp[i]) << endl; 
			cout << "    " << i << "  |   " << 1 << "    |    " << _count_rs[i]*1000/float(ms[i]) << endl;	
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query4(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_rs = 0;
	vector <int> _count_rs;
	unsigned long int count_rp = 0;
	vector <int> _count_rp;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	vector <int> mp;
	vector <int> ms;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_rs.push_back(0);
	_count_rp.push_back(0);
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == pais) && (0 == tmp[i].sexo)){
				_count_p[count_p]++;
				_count_rp[count_p] += tmp[i].idade;
				count_rp++;
			}
			
			if((tmp[i].pais == pais) && (1 == tmp[i].sexo)){
				_count_s[count_s]++;
				_count_rs[count_s] += tmp[i].idade;
				count_rs++;
			}
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_s.push_back(0);
				_count_p.push_back(0);
				_count_rs.push_back(0);
				_count_rp.push_back(0);
				count_p++;
				count_s++;
				mp.push_back(count_rp);
				ms.push_back(count_rs);
				count_rp = 0;
				count_rs = 0;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " avg(idade) " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i >=10){
				if(i >=100){
					cout << "  " << i << "  |   " << 0 << "    |    " << _count_rp[i]/float(mp[i]) << endl;
					cout << "  " << i << "  |   " << 1 << "    |    " << _count_rs[i]/float(ms[i]) << endl;
				}else{
				cout << "   " << i << "  |   " << 0 << "    |    " << _count_rp[i]/float(mp[i]) << endl;			
				cout << "   " << i << "  |   " << 1 << "    |    " << _count_rs[i]/float(ms[i]) << endl;
				}
			}else{
			cout << "    " << i << "  |   " << 0 << "    |    " << _count_rp[i]/float(mp[i]) << endl; 
			cout << "    " << i << "  |   " << 1 << "    |    " << _count_rs[i]/float(ms[i]) << endl;	
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query5(int valor){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == valor) && (0 == tmp[i].sexo))
				_count_p[count_p]++;
			
			if((tmp[i].pais == valor) && (1 == tmp[i].sexo)){
				_count_s[count_s]++;
			}
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_p.push_back(0);
				_count_s.push_back(0);
				count_p++;
				count_s++;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " count " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i == valor){
				if (i >=10){
					if(i >=100){
						cout << "  " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl;
						cout << "  " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;
					}else{
					cout << "   " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl;			
					cout << "   " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;
					}
				}else{
				cout << "    " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl; 
				cout << "    " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;	
				}
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query6(int valor_p, int valor_s){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == valor_p) && (valor_s == tmp[i].sexo))
				_count_p[count_p]++;
			
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_p.push_back(0);
				_count_s.push_back(0);
				count_p++;
				count_s++;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " count " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i == valor_p){
				if (i >=10){
					if(i >=100){
						cout << "  " << i << "  |   " << valor_s << "    |    " << _count_p[i] << endl;
					}else{
					cout << "   " << i << "  |   " << valor_s << "    |    " << _count_p[i] << endl;	
					}
				}else{
				cout << "    " << i << "  |   " << valor_s << "    |    " << _count_p[i] << endl;	
				}
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query7(int valor_s, int valor_b){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
		//if((tmp[i].pais >= valor_s) && (tmp[i].pais <= valor_b)){
			if((tmp[i].pais == pais) && (0 == tmp[i].sexo))
				_count_p[count_p]++;
			
			if((tmp[i].pais == pais) && (1 == tmp[i].sexo)){
				_count_s[count_s]++;
			}
			
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_p.push_back(0);
				_count_s.push_back(0);
				count_p++;
				count_s++;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " sexo " << " | " << " count " << endl;
		for(unsigned long int i = valor_s; i<=valor_b; i++){
				if (i >=10){
					if(i >=100){
						cout << "  " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl;
						cout << "  " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;
					}else{
					cout << "   " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl;			
					cout << "   " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;	
					}
				}else{
				cout << "    " << i << "  |   " << 0 << "    |    " << _count_p[i] << endl; 
				cout << "    " << i << "  |   " << 1 << "    |    " << _count_s[i] << endl;	
				}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query8(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <unsigned long 	int> _count_p;
	unsigned long int count_rs = 0;
	vector <unsigned long int> _count_rs;
	unsigned long int count_rp = 0;
	vector <unsigned long int> _count_rp;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	vector <int> mp;
	vector <int> ms;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_rs.push_back(0);
	_count_rp.push_back(0);
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == pais)){
				_count_p[count_p]++;
				_count_rp[count_p] += tmp[i].renda;
				count_rp++;
			}
			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_s.push_back(0);
				_count_p.push_back(0);
				_count_rs.push_back(0);
				_count_rp.push_back(0);
				count_p++;
				count_s++;
				mp.push_back(count_rp);
				ms.push_back(count_rs);
				count_rp = 0;
				count_rs = 0;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		//for(int i = 0; i<count_p;i++){
		//	count += _count_rp[i];
		//}
		cout << " pais " << " | " << " PIB " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i >=10){
				if(i >=100){
					cout << "  " << i << "  |   " << _count_rp[i]*1000 << endl;
				}else{
				cout << "   " << i << "  |   " << _count_rp[i]*1000 << endl;
				}
			}else{
			cout << "    " << i << "  |   " << _count_rp[i]*1000 << endl;
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query9(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_p = 0;
	vector <int> _count_p;
	unsigned long int count_rs = 0;
	vector <int> _count_rs;
	unsigned long int count_rp = 0;
	vector <unsigned long int> _count_rp;
	unsigned long int count_s = 0;
	vector <int> _count_s;
	vector <unsigned long int> mp;
	vector <int> ms;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_rs.push_back(0);
	_count_rp.push_back(0);
	_count_p.push_back(0);
	_count_s.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].pais == pais) && (tmp[i].idade > 59)){
				_count_p[count_p]++;
				_count_rp[count_p] += tmp[i].renda;
				count_rp++;
			}

			if(tmp[i].pais != pais){
				pais = tmp[i].pais;
				_count_s.push_back(0);
				_count_p.push_back(0);
				_count_rs.push_back(0);
				_count_rp.push_back(0);
				count_p++;
				count_s++;
				mp.push_back(count_rp);
				ms.push_back(count_rs);
				count_rp = 0;
				count_rs = 0;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		cout << " pais " << " | " << " media_aposentadoria " << endl;
		for(unsigned long int i = 0; i<count_p; i++){
			if (i >=10){
				if(i >=100){
					cout << "  " << i << "  |   " << _count_rp[i]*1000/float(mp[i]) << endl;
				}else{
				cout << "   " << i << "  |   " << _count_rp[i]*1000/float(mp[i]) << endl;
				}
			}else{
			cout << "    " << i << "  |   " << _count_rp[i]*1000/float(mp[i]) << endl; 	
			}
		}
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void query10(){
	//fstream arq(arquivo,ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
	//pessoa tmp;
	//arq.seekg(0,ios_base::beg);
	unsigned long int count = 0;
	int pais = tmp[0].pais;
	unsigned long int count_i = 0;
	vector <int> _count_i;
	unsigned long int count_a = 0;
	vector <int> _count_a;
	unsigned long int count_te = 0;
	vector <int> _count_te;
	unsigned long int count_c = 0;
	vector <int> _count_c;
	//while(arq.read((char *) &tmp, sizeof(pessoa))){
	_count_i.push_back(0);
	_count_a.push_back(0);
	_count_te.push_back(0);
	_count_c.push_back(0);
	clock_t Ticks[2];
    Ticks[0] = clock();
	for(unsigned long int i=0;i<tam;i++){
		//for (int k = 0; k < 255; k+i){
			if((tmp[i].idade < 15)){
				count_c++;
			}
			if((tmp[i].idade > 14) && (tmp[i].idade <= 22)){
				count_te++;
			}
			if((tmp[i].idade > 22) && (tmp[i].idade <= 59)){
				count_a++;
			}
			if((tmp[i].idade > 59)){
				count_i++;
			}
		//}
	}
	//char c;
	//cout << "\nDeseja visualizar o banco?\n" << "Digite 1 caso a resposta seja afirmativa, qualquer entrada diferente sera considerado como nao." << endl;
	//cin >> c;
	//if(count == '1'){
		string tipo[4] = {"idoso","adulto","adlolescente","crianca"};
		cout << " faixa_etaria " << " | " << " pessoas " << endl;
		cout << "      crianca " << " | " << count_c << endl;
		cout << "       adulto " << " | " << count_a << endl;
		cout << "  adolescente " << " | " << count_te << endl;
		cout << "        idoso " << " | " << count_i << endl;
	//}else return;	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
}

void menu(int comand){
	int pais, sexo;
	switch(comand){
		case 0: cout << "Adeus, espero que nao volte nunca mais" << endl;
				break;
		case 1: query1();
				break;
		case 2: query2();
				break;
		case 3: query3();
				break;
		case 4: query4();
				break;
		case 5: cout << "Digite qual o pais especifico" << endl;
				cin >> pais;
				query5(pais);
				break;
		case 6: cout << "Digite qual o pais especifico" << endl;
				cin >> pais;
				cout << "Digite qual o sexo especifico" << endl;
				cin >> sexo;
				query6(pais,sexo);
				break;
		case 7: cout << "Digite o pais inicial da sequencia" << endl;
				cin >> pais;
				cout << "Digite o pais final da sequencia" << endl;
				cin >> sexo;
				query7(pais,sexo);
				break;
		case 8: query8();
				break;
		case 9: query9();
				break;
		case 10: query10();
				break;
		default: cout << "Opcao invalida, entre com um valor valido." << endl;
				break;
	}
}

void heapSort(unsigned long int n) {
   unsigned long int i = n / 2, pai, filho;
   pessoa t;
   for (;;) {
    	if (i > 0) {
        	i--;
        	t = tmp[i];
    	}else{
        	n--;
        	if (n == 0) break;
        	t = tmp[n];
        	tmp[n] = tmp[0];
    	}
    	pai = i;
    	filho = i * 2 + 1;
    	while (filho < n) {
        	if ((filho + 1 < n)  &&  (tmp[filho + 1].pais > tmp[filho].pais)){
        		filho++;
			}
        	if (tmp[filho].pais > t.pais) {
            	tmp[pai] = tmp[filho];
				pai = filho;
            	filho = pai * 2 + 1;
        	}else{
            	break;
        	}
    	}
    	tmp[pai] = t;
	}
	
	/*fstream arq2("pessoas1B_sort.dat",ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
   	for(unsigned long int i = 0; i < tam; i++){
      arq2.write((char *) &a[i], sizeof(pessoa));
   	}*/
}

int main(){
   int key = 1;
	//pessoa *vetor=(pessoa*) malloc(tam*sizeof(pessoa));

   cout << "Iniciando..." << endl;
   clock_t Ticks[2];
    Ticks[0] = clock();
   cria_vetor();

   heapSort(tam);
   Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

   system("clear");
   //system("cls");
   cout << "Sistema Inicializado" << endl;
   printf("\nTempo gasto para iniciar: %g ms.\n", Tempo);
   while(key){
   		
   		key = print_menu();
   		menu(key);
   		//system("pause");
   		system("read -r -p \"Press any key to continue...\" key");
   		system("clear");
   		//system("cls");
   }	
	
   return 0;
}
