#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include "aluno.h"

struct comparator_aluno_f {
  bool operator()(const Aluno &a1, const Aluno &a2) const {
    return a1.get_matricula() < a2.get_matricula();
  }
};


int main() {
  std::string linha;
  std::istringstream stream_string;
  std::set<Aluno, comparator_aluno_f> alunos;
  // 1. Lê o stream cin (padrão/teclado) linha a linha
  while (std::getline(std::cin, linha)) {
    if (linha == "sair") // 2. Se o usuário digitar sair, quebra o laço
      break;
    // 3. Separa a linha em palavra. Para isto, se usa o istringstream
    //    Similar ao sscanf de C, usamos um texto como um arquivo.
    stream_string = std::istringstream(linha);
    std::string nome;
    int matricula;
    int codigo_disciplina;
    stream_string >> nome;
    stream_string >> matricula;
    stream_string >> codigo_disciplina;

    Aluno aluno(nome, matricula);
    alunos.insert(aluno);
  }

  for (Aluno aluno : alunos) {
    std::cout << aluno.get_nome() << std::endl;
  }
}
