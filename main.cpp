#include "include/graph.hpp"
#include "include/grafos_adjacency.hpp"
#include "include/grafos_list.hpp"

using namespace grp;

int main(int argc, char const *argv[])
{
    //exemplo do slide
    GraphAdj g(6);
     g.add(1, 4);
     g.add(2, 4);
     g.add(2, 3);
     g.add(3, 4);
     g.add(4, 5);
     g.add(5, 6);
     g.add(6, 4);
     g.print();
    std::cout << "\n\n";
    GraphList gl(5);
    gl.add(1, 2);
    gl.add(1, 3);
    gl.add(2, 3);
    gl.add(3, 4);
    gl.add(3, 5);
    gl.print();
    std::cout << "\n\n";
    DiGraph dg(5);
    dg.add(1, 2);
    dg.add(1, 3);
    dg.add(2, 3);
    dg.add(3, 4);
    dg.add(3, 5);
    dg.print();
    std::cout << "\n\n";
    dg.printInc();
    std::cout << "\n\n";
    dg.printRStar();
    return 0;
}
