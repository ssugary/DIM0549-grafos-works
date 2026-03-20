#ifndef GRAFOS_LISTA_ADJACENTE_HPP
#define GRAFOS_LISTA_ADJACENTE_HPP

#include <array>
#include <iostream>
#include "graph.hpp"
#include <vector>

using value = int;
using matriz = std::vector<std::vector<value>>;
using namespace grp;

class GraphAdj : Graph {
  public:
  value m_vertices{};
  matriz  m_adjacency;

   GraphAdj( value vertices ) : m_vertices( vertices ) {
    m_adjacency.resize( vertices, std::vector<value>( vertices, 0 ) );
}
  void add(value origin, value destiny);

  void remove( value origin, value destiny );

  void print() const;
};

#endif // GRAFOS_HPP
