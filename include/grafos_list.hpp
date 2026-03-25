#include <list>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
class GraphList {
public:
  std::list<int> *adjacencyList;
  int vertices;
  GraphList(int vertices) {
    this->vertices = vertices;
    adjacencyList = new std::list<int>[vertices];
  }

  void add(int origin, int destiny);
  void remove(int origin, int destiny);
  void print() const;
  void dfsRec(int vertex);
  void dfsRecPred(int vertex);
  void dfsRecAux(int vertex, std::vector<bool> &visited);
  void dfsRecPredAux(int vertex, std::vector<bool> &visited, std::vector<int> &pred);
  void bfsOrdemRetirada(int vertex);
  void bfsClassificaArestas(int vertex);

};
