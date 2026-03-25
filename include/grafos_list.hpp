#include <list>
#include <iostream>
#include <stack>
#include <vector>
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
  void dfsRecAux(int u, std::vector<bool> &visited);
  void dfsRecPredAux(int u, std::vector<bool> &visited, std::vector<int> &pred);

};
