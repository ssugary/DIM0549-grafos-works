#include "../include/grafos_list.hpp"

void GraphList::add(int origin, int destiny) {
  if(origin < 1 || origin > vertices || destiny < 1 || destiny > vertices) {
    std::cerr << "Error: Vertex index out of bounds." << std::endl;
    return;
  }
  adjacencyList[origin - 1].push_back(destiny);
  adjacencyList[destiny - 1].push_back(origin); // Para grafos não direcionados
}

void GraphList::remove(int origin, int destiny) {
  if(origin < 1 || origin > vertices || destiny < 1 || destiny > vertices) {
    std::cerr << "Error: Vertex index out of bounds." << std::endl;
    return;
  }
  adjacencyList[origin - 1].remove(destiny);
  adjacencyList[destiny - 1].remove(origin); // Para grafos não direcionados
}

void GraphList::print() const {
  for(int i = 0; i < vertices; i++) {
    std::cout << "[ " << i + 1 << " ]: ";
    for(const auto& neighbor : adjacencyList[i]) {
      std::cout << neighbor << " -> ";
    }
    std::cout << std::endl;
  }
}

  int get_menor_ixd_g(const GraphList &g, int vertex, const std::vector<int> &visited) {
    if (vertex < 1 || vertex > g.vertices) {
      return -1;
    }

    
    if ((g.adjacencyList[vertex]).front() && visited[vertex] == 0) {
      return (g.adjacencyList[vertex]).front() + 1; 
    }

    return -1;
  }

  void GraphList::dfsRecAux(int u, std::vector<bool> &visited){
      visited[u - 1] = 1;
      std::cout << "Visitando: " << u << "\n";
      for(int v : adjacencyList[u - 1]){
        if(!visited[v - 1]){
          std::cout << "  Descendo do " << u << " para o vizinho " << v << "...\n";
          dfsRecAux(v, visited);
        }
      }
    }

    void GraphList::dfsRec(int vertex){

      if(vertex < 1 || vertex > vertices){
        std::cerr << "Error: Vertex index out of bounds\n";
      }

      std::vector<bool> visited(vertices, 0);
      std::cout << "Começando DFS com vértice: " << vertex << "\n";
      dfsRecAux(vertex, visited);
      std::cout << "\n";
    }

    void GraphList::dfsRecPred(int vertex){
      if(vertex < 1 || vertex > vertices){
        std::cerr << "Error: Vertex index out of bounds\n";
      }

      std::vector<bool> visited(vertices, 0);
      std::vector<int> pred(vertices, -1);
      std::cout << "Começando DFS com vértice: " << vertex << "\n";
      dfsRecPredAux(vertex, visited, pred);
      std::cout << "\n";
    }

    void GraphList::dfsRecPredAux(int u, std::vector<bool> &visited, std::vector<int> &pred){

      visited[u - 1] = 1;

      std::cout << "Visitando: " << u << "\n";

      for(int v : adjacencyList[u - 1]){
        if(!visited[v - 1]){
          pred[v - 1] = u;
          std::cout << "  Predecessor de " << v << " agora é " << u << "\n";
          dfsRecPredAux(v, visited, pred);
        }
      }

    }

