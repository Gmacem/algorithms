#pragma once
#include <istream>
#include <vector>

class BaseGraph;
class BaseTree;


class BaseGraph {
public:
    using list_type = std::vector<int>;
    using adj_list_type = std::vector<list_type>;

public:

    BaseGraph() = default;
    BaseGraph(int num);
    BaseGraph(const adj_list_type& adj);

    const list_type& GetAdj(int vert) const;
    size_t Size() const;

    void AddNode();
    void AddDirectedEdge(int from, int to);
    void AddUndirectedEdge(int from, int to);

    friend void check_base_graph(const BaseGraph& graph);

private:
    size_t num_;
    adj_list_type adj_list_;
};


class RootedTree : public BaseGraph {
public:
    RootedTree(const std::vector<int>& parents, size_t root);

    int GetRoot() const {
        return root_;
    }

private:
    int root_;
};

BaseGraph ReadBaseGraph(std::istream& in);
size_t CalcNumOfComponents(const BaseGraph& graph);
