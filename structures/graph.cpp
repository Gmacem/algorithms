#include <assert.h>
#include "graph.h"

BaseGraph::BaseGraph(int num): num_(num) {
    assert(num >= 0);
    adj_list_.resize(num);
}

BaseGraph::BaseGraph(const std::vector<std::vector<int> >& adj)
    : num_(adj.size()), adj_list_(adj) {
#ifdef CHECK
    check_base_graph(*this);
#endif
}

const std::vector<int>& BaseGraph::GetAdj(int vert) {
#ifdef CHECK
    assert(vert >= 0 && vert < num_);
#endif
    return adj_list_[vert];
}

size_t BaseGraph::Size() {
    return num_;
}

void check_base_graph(const BaseGraph& graph) {
    assert(graph.num_ == graph.adj_list_.size());
    for (int i = 0; i < graph.num_; ++i) {
        for (int j = 0; j < graph.adj_list_[i].size(); ++j) {
            int to = graph.adj_list_[i][j];
            assert(to >= 0 && to < graph.num_);
        }
    }
}
