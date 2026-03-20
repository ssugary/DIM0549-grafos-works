#include "../include/grafos_list.hpp"
#include <iostream>

void GraphList::add(value origin, value destiny) {
  if(origin < 1 || origin > vertices || destiny < 1 || destiny > vertices) {
    std::cerr << "Error: Vertex index out of bounds." << std::endl;
    return;
  }
  adjacencyList[origin - 1].push_back(destiny);
  adjacencyList[destiny - 1].push_back(origin); // Para grafos não direcionados
}

void GraphList::remove(value origin, value destiny) {
  if(origin < 1 || origin > vertices || destiny < 1 || destiny > vertices) {
    std::cerr << "Error: Vertex index out of bounds." << std::endl;
    return;
  }
  adjacencyList[origin - 1].remove(destiny);
  adjacencyList[destiny - 1].remove(origin); // Para grafos não direcionados
}

void GraphList::print() const {
  for(value i = 0; i < vertices; i++) {
    std::cout << "[ " << i + 1 << " ]: ";
    for(const auto& neighbor : adjacencyList[i]) {
      std::cout << neighbor << " -> ";
    }
    std::cout << std::endl;
  }
}