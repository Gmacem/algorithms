#include "graph.h"
#include "iostream"

int main() {
    BaseGraph graph(10);
    for (int i = 0; i < graph.Size(); ++i) {
        std::cout << graph.GetAdj(i).size() << '\n';
    }
}
