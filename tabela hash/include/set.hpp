#ifndef SET_HPP
#define SET_HPP

#include <bits/stdc++.h>
using namespace std;

struct ElementoTabela {
    string dado;
    bool vazio;
    bool retirada;

    ElementoTabela() : vazio(true), retirada(false) {}
};


class StringSet{

    public:
        StringSet(int tamanho);
        ~StringSet();

        void Inserir(string s);
        void Remover(string s);
        bool Pertence(string s);
        
        StringSet* Intersecao(StringSet* S);
        StringSet* Uniao(StringSet* S);
        StringSet* DiferencaSimetrica(StringSet* S);

        void Imprimir();

    private:
        int tamanhoOriginal;
        int tamanhoTabela;
        int tamanhoConjunto;
        ElementoTabela* tabela;

        int Hash(string s, int tam);
        void Rehash(int pos);
        void Resize(size_t tamanho);
};


#endif