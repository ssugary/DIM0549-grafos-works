#ifndef GRAFOS_HPP
#define GRAFOS_HPP

#include <array>
#include <iostream>
#include <vector>

using value = int;

class Graph {
  public:
  value m_vertices{1};
  std::vector<std::vector<value>> m_matAdjacency;

   Graph( value vertices ) : m_vertices( vertices ) {
    m_matAdjacency.resize( vertices, std::vector<value>( vertices, 0 ) );
}
    void add( value origin, value destiny ) {
    if(origin < 1 || origin > m_vertices || destiny < 1 || destiny > m_vertices) {
      std::cerr << "Error: Vertex index out of bounds." << std::endl;
      return;
    }
    m_matAdjacency[origin-1][destiny-1] = 1;
    m_matAdjacency[destiny-1][origin-1] = 1; 
    // Para grafos não direcionados, adicionamos a aresta em ambas as direções
  }
  void remove( value origin, value destiny ) {
    if(origin < 1 || origin > m_vertices || destiny < 1 || destiny > m_vertices) {
      std::cerr << "Error: Vertex index out of bounds." << std::endl;
      return;
    }
    m_matAdjacency[origin-1][destiny-1] = 0;
    m_matAdjacency[destiny-1][origin-1] = 0; 
    // Para grafos não direcionados, removemos a aresta em ambas as direções
  }

  void print() const {
    std::cout << " | ";
    for ( value i = 0; i < m_vertices; ++i ) {
      std::cout << i + 1 << " ";
    }
    std::cout << "|\n";
    for ( value i = 0; i < m_vertices; ++i ) {
     std::cout << i + 1 << "| ";
      for ( value j = 0; j < m_vertices; ++j ) {
        std::cout << m_matAdjacency[i][j] << " ";
      }

      std::cout << "| \n";
    }
  }

};

#endif // GRAFOS_HPP
