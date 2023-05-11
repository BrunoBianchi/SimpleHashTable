#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gerarHash(string nome) {
    int hash = 0;
    for(int i = 0; i< nome.size();i++) {
        hash += nome[i] * (54059) ;
    }
    return hash % 37;
}
vector<string> adicionarHash(string nome, vector<string> array) {
    int hash = gerarHash(nome);
    if(array.size() < hash && array.size() != 0 ) {
        int newArrayTAM  = array.size();
        array.resize(array.size() + hash);
        for(int i = newArrayTAM; i<hash;i++) {
            if(i!=hash) {
                array[i] = "NULL";
            }else {
                array[hash] = nome;
                cout<<array[hash]<<endl;
            }
        }
    }else if(array.size() > hash && array.size() !=0) {
        array.insert(array.begin() + hash,nome);
    }else if(array.size() == 0) {
        array.resize(array.size() + hash);
        for(int i =0;i<hash;i++) {
            if(i != hash) {
                array[i] = "NULL";
            }
        }
                array.insert(array.begin() + hash,nome);

    }
    return array;
}
void verificarNome(string nome, vector<string> array) {
    int hash = gerarHash(nome);
    if(array.size() != 0) {
    if(array[hash] !="NULL") {
        cout<<"\nUsuario encontrado!"<<endl;
        cout<<"Index: "<<hash<<endl;
        cout<<"Nome: "<<nome<<endl; 
        puts("\n");
    }else {
        cout<<"\nUsuario "<<nome<<" nao encontrado!!\n"<<endl;
    }
    }else {
        cout<<"\nLista nao criada! Adicione Alguem \n";
    }


}
int main() {
    int codigo = 0;
    string nome;
    vector<string>nomes;

    do{
        cout<<"MENU:"<<endl;
        cout<<"1. Adicionar Nome"<<endl;
        cout<<"2. Verificar Nome"<<endl;
        cout<<"0. Sair"<<endl;
        cin>>codigo;
        puts("\n");
        switch(codigo) {
            case 1:
            cout<<"Digite um nome para adicionar"<<endl;
            cin>>nome;
            nomes = adicionarHash(nome,nomes);
            break;
            case 2:
            cout<<"Digite um nome para verificar"<<endl;
            cin>>nome;
            verificarNome(nome,nomes);
            break;
        }
    }while(codigo != 0);
}