#ifndef BASE_GRAPH_HPP
#define BASE_GRAPH_HPP

#include <iostream>
#include <fstream>
#include <vector>

using value = int;

namespace grp {

    class Graph {
        private:
            value vertices;

        public:
            virtual void add(value origin, value destiny){};
            virtual void remove(value origin, value destiny){};
            virtual void print() const{};
    };

    class DiGraph : Graph {
        public:
    value m_vertices{1};
    std::vector<std::vector<value>> m_matAdjacency;

    DiGraph(value vertices);
    void add(value origin, value destiny);
    void remove( value origin, value destiny );
    void print() const;
    void printInc() const;
    void printRStar() const;

    };

};
#endif