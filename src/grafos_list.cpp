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

    void GraphList::dfsRecPredAux(int vertex, std::vector<bool> &visited, std::vector<int> &pred){

      visited[vertex - 1] = 1;

      std::cout << "Visitando: " << vertex << "\n";

      for(int v : adjacencyList[vertex - 1]){
        if(!visited[v - 1]){
          pred[v - 1] = vertex;
          std::cout << "  Predecessor de " << v << " agora é " << vertex << "\n";
          dfsRecPredAux(v, visited, pred);
        }
      }

    }

void GraphList::bfsOrdemRetirada(int vertex) {
    if(vertex < 1 || vertex > vertices) return;

    std::vector<bool> visited(vertices, false);
    std::vector<int> ordem_retirada(vertices, 0); 
    std::queue<int> fila;

    visited[vertex - 1] = true;
    fila.push(vertex);

    int contador_ordem = 1;

    std::cout << "Iniciando BFS a partir do vértice " << vertex << "\n";

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ordem_retirada[u - 1] = contador_ordem++;
        
        std::cout << "Retirando da fila o vértice: " << u << "\n";

        for(int v : adjacencyList[u - 1]) {
            if(!visited[v - 1]) {
                visited[v - 1] = true;
                fila.push(v);
            }
        }
    }

    std::cout << "\nOrdem final de retirada (Largura de V)\n";
    for(int i = 0; i < vertices; i++) {
        std::cout << "Vértice " << i + 1 << ": retirado na posição " << ordem_retirada[i] << "\n";
    }
}

void GraphList::bfsClassificaArestas(int vertex) {
    if (vertex < 1 || vertex > vertices) {
        std::cerr << "Error: Vertex index out of bound.\n";
        return;
    }

    std::vector<bool> visited(vertices, 0);
    std::vector<int> nivel(vertices, -1);
    std::vector<int> pai(vertices, -1);
    std::queue<int> fila;

    visited[vertex - 1] = true;
    nivel[vertex - 1] = 0;
    fila.push(vertex);

    std::cout << "Classificação de Arestas a partir de " << vertex << " \n";

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for(int v : adjacencyList[u - 1]) {
            if(!visited[v - 1]) {
                visited[v - 1] = true;
                pai[v - 1] = u;
                nivel[v - 1] = nivel[u - 1] + 1;
                fila.push(v);
                
                std::cout << "Aresta (" << u << ", " << v << "): PAI\n";
            } 
            else if (v != pai[u - 1]) {
                if (nivel[u - 1] >= nivel[v - 1]) {
                    
                    if (nivel[u - 1] == nivel[v - 1]) {
                        if (pai[u - 1] == pai[v - 1]) {
                            std::cout << "Aresta (" << u << ", " << v << "): IRMAO\n";
                        } else {
                            std::cout << "Aresta (" << u << ", " << v << "): PRIMO\n";
                        }
                    } 
                    else if (nivel[v - 1] == nivel[u - 1] - 1) {
                        std::cout << "Aresta (" << u << ", " << v << "): TIO\n";
                    }
                }
            }
        }
    }
}