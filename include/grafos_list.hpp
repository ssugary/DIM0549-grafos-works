#ifndef GRAPH_LIST_HPP
#define GRAPH_LIST_HPP

#include <list>

using value = int;

class GraphList {
private:
  std::list<value> *adjacencyList;
  value vertices;
public:
  GraphList(value vertices) {
    this->vertices = vertices;
    adjacencyList = new std::list<value>[vertices];
  }

  void add(value origin, value destiny);
  void remove(value origin, value destiny);
  void print() const;
};

#endif