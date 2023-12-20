#include "../include/set.hpp"

StringSet::StringSet(int tamanho) {
  tamanhoOriginal = tamanho;
  tamanhoTabela = 2 * tamanho;
  tamanhoConjunto = 0;
  tabela = new ElementoTabela[tamanhoTabela];
}

StringSet::~StringSet() { delete[] tabela; }

int StringSet::Hash(string s, int tam) {
  int hash = 0;
  for (char c : s) {
    hash = (hash * 31 + c) % tam;
  }
  return hash;
}

void StringSet::Inserir(string s) {
  if (Pertence(s)) {
    cout << "Elemento " << s
         << " já pertence ao conjunto. Não inserido novamente." << endl;
    return;
  }

  int pos = Hash(s, tamanhoTabela);
  while (!tabela[pos].vazio && !tabela[pos].retirada) {
    pos = (pos + 1) % tamanhoTabela;
  }

  tabela[pos].dado = s;
  tabela[pos].vazio = false;
  tabela[pos].retirada = false;
  tamanhoConjunto++;

  

  if (tamanhoConjunto > tamanhoTabela / 2) {
    Resize(2 * tamanhoTabela);
  }
}

void StringSet::Remover(string s) {
  int pos = Hash(s, tamanhoTabela);
  while (!tabela[pos].vazio) {
    if (!tabela[pos].retirada && tabela[pos].dado == s) {
      tabela[pos].retirada = true;
      tamanhoConjunto--;

      if (tamanhoConjunto < tamanhoTabela / 8) {
        Resize(tamanhoTabela / 2);
      }
      return;
    }
    pos = (pos + 1) % tamanhoTabela;
  }
}

bool StringSet::Pertence(string s) {
  int pos = Hash(s, tamanhoTabela);
  while (!tabela[pos].vazio) {
    if (!tabela[pos].retirada && tabela[pos].dado == s) {
      return true;
    }
    pos = (pos + 1) % tamanhoTabela;
  }
  return false;
}

StringSet *StringSet::Intersecao(StringSet *S) {
  StringSet *resultado = new StringSet(tamanhoOriginal);

  for (int i = 0; i < tamanhoTabela; i++) {
    if (!tabela[i].vazio && !tabela[i].retirada &&
        S->Pertence(tabela[i].dado)) {
      resultado->Inserir(tabela[i].dado);
    }
  }

  return resultado;
}

StringSet *StringSet::Uniao(StringSet *S) {
  StringSet *resultado = new StringSet(tamanhoOriginal);

  for (int i = 0; i < tamanhoTabela; i++) {
    if (!tabela[i].vazio && !tabela[i].retirada) {
      resultado->Inserir(tabela[i].dado);
    }
  }

  for (int i = 0; i < S->tamanhoTabela; i++) {
    if (!S->tabela[i].vazio && !S->tabela[i].retirada) {
      resultado->Inserir(S->tabela[i].dado);
    }
  }

  return resultado;
}

StringSet *StringSet::DiferencaSimetrica(StringSet *S) {
  StringSet *resultado = new StringSet(tamanhoOriginal);

  for (int i = 0; i < tamanhoTabela; i++) {
    if (!tabela[i].vazio && !tabela[i].retirada &&
        !S->Pertence(tabela[i].dado)) {
      resultado->Inserir(tabela[i].dado);
    }
  }

  for (int i = 0; i < S->tamanhoTabela; i++) {
    if (!S->tabela[i].vazio && !S->tabela[i].retirada &&
        !Pertence(S->tabela[i].dado)) {
      resultado->Inserir(S->tabela[i].dado);
    }
  }

  return resultado;
}

void StringSet::Imprimir() {
  for (int i = 0; i < tamanhoTabela; i++) {
    if (!tabela[i].vazio && !tabela[i].retirada) {
      cout << tabela[i].dado << " ";
    }
  }
  cout << endl;
}

void StringSet::Rehash(int pos) {
  ElementoTabela *novaTabela = new ElementoTabela[2 * tamanhoTabela];
  int novoTamanho = 2 * tamanhoTabela;

  for (int i = 0; i < tamanhoTabela; i++) {
    if (!tabela[i].vazio && !tabela[i].retirada) {
      int novaPos = Hash(tabela[i].dado, novoTamanho);
      while (!novaTabela[novaPos].vazio) {
        novaPos = (novaPos + 1) % novoTamanho;
      }
      novaTabela[novaPos].dado = tabela[i].dado;
      novaTabela[novaPos].vazio = false;
      novaTabela[novaPos].retirada = false;
    }
  }

  delete[] tabela;
  tabela = novaTabela;
  tamanhoTabela = novoTamanho;
}

void StringSet::Resize(size_t novoTamanho) {
  if (novoTamanho < tamanhoOriginal)
    return;

  ElementoTabela *antigaTabela = tabela;
  int antigoTamanho = tamanhoTabela;

  tamanhoTabela = novoTamanho;
  tabela = new ElementoTabela[tamanhoTabela];
  tamanhoConjunto = 0;

  for (int i = 0; i < antigoTamanho; i++) {
    if (!antigaTabela[i].vazio && !antigaTabela[i].retirada) {
      Inserir(antigaTabela[i].dado);
    }
  }

  delete[] antigaTabela;
}
