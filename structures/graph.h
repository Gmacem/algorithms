#pragma once
#include <vector>

class BaseGraph;
class BaseTree;


class BaseGraph {
public:
    BaseGraph() = default;
    BaseGraph(int num);
    BaseGraph(const std::vector<std::vector<int> >& adj);

    const std::vector<int>& GetAdj(int vert);
    size_t Size();
    
    friend void check_base_graph(const BaseGraph& graph);

private:
    size_t num_;
    std::vector<std::vector<int> > adj_list_;
};


class BaseTree: public BaseGraph {
};
