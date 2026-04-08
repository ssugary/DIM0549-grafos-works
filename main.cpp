#include "include/grafos.hpp"
#include <cstdlib>

int main(int argc, char const *argv[])
{
    Graph<int> g(6);
     g.add(1, 4);
     g.add(2, 4);
     g.add(2, 3);
     g.add(3, 4);
     g.add(4, 5);
     g.add(5, 6);
     g.add(6, 4);
     g.print();
     std::cout << "-------------------\n";
     g.to_list();
     g.print();
    std::cout << "-------------------\n";
     Graph<char> g2(3);
        g2.add('A', 'B');
        g2.add('B', 'C');
        g2.add('C', 'A');
        g2.print();
        g2.to_list();
    std::cout << "-------------------\n";
        g2.print();
     
    return 0;
}
