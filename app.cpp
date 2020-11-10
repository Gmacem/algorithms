
/*** Start of inlined file: number_theory.h ***/
#pragma once
#include <vector>

template<class T>
bool IsPrimeSimple(T num) {
    if (num == 1) {
        return false;
    }
    for (T i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

template<class T>
std::vector<T> Factorize(T num, T bound) {
    std::vector<T> ans;
    for (T i = 2; i < bound && i < num; ++i) {
        while (num % i == 0) {
            ans.emplace_back(i);
            num /= i;
        }
    }
    if (num != 1) {
        ans.emplace_back(num);
    }
    return ans;
}


/*** Start of inlined file: number_theory.cpp ***/
/*** End of inlined file: number_theory.cpp ***/

/*** End of inlined file: number_theory.h ***/


/*** Start of inlined file: methods.h ***/
#pragma once

/*
If func(mid, args...) == true, then move left bound else right
limit - max number of check. Need for BinSearch<double>
*/

template<typename T, typename... ArgTypes>
T BinSearch(T left, T right, int limit, bool func(int, ArgTypes...), ArgTypes... args) {
    while (right - left > 1 && limit != 0) {
        T mid = (left + right) / 2;
        if (func(mid, args...)) {
            left = mid;
        } else {
            right = mid;
        }
        --limit;
    }
    return left;
}


/*** Start of inlined file: methods.cpp ***/
#include <assert.h>

/*** End of inlined file: methods.cpp ***/

/*** End of inlined file: methods.h ***/


/*** Start of inlined file: graph.h ***/
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


/*** Start of inlined file: graph.cpp ***/
#include <assert.h>

#ifdef NDEBUG
#define CHECK_BASE_GRAPH(x) ((void)0)
#else
#define CHECK_BASE_GRAPH(x) check_base_graph(x)
#endif

BaseGraph::BaseGraph(int num): num_(num) {
    assert(num >= 0);
    adj_list_.resize(num);
}

BaseGraph::BaseGraph(const BaseGraph::adj_list_type& adj)
    : num_(adj.size()), adj_list_(adj) {
    CHECK_BASE_GRAPH(*this);
}

const BaseGraph::list_type& BaseGraph::GetAdj(int vert) const {
    assert(vert >= 0 && vert < num_);
    return adj_list_[vert];
}

size_t BaseGraph::Size() const {
    return num_;
}

void BaseGraph::AddNode() {
    num_++;
    adj_list_.emplace_back();
}

void BaseGraph::AddDirectedEdge(int from, int to) {
    assert(from >= 0 && from < num_);
    assert(to >= 0 && to < num_);
    adj_list_[from].emplace_back(to);
}

void BaseGraph::AddUndirectedEdge(int from, int to) {
    assert(from >= 0 && from < num_);
    assert(to >= 0 && to < num_);
    adj_list_[from].push_back(to);
    adj_list_[to].push_back(from);
}

void check_base_graph(const BaseGraph& graph) {
    assert(false);
    assert(graph.num_ == graph.adj_list_.size());
    for (int i = 0; i < graph.num_; ++i) {
        for (int j = 0; j < graph.adj_list_[i].size(); ++j) {
            int to = graph.adj_list_[i][j];
            assert(to >= 0 && to < graph.num_);
        }
    }
}

BaseGraph ReadBaseGraph(std::istream& in, int shifted=0) {
    int n, m;
    in >> n >> m;
    std::vector<std::vector<int> > adj_list(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        in >> a >> b;
        a += shifted;
        b += shifted;
        adj_list[a].emplace_back(b);
        adj_list[b].emplace_back(a);
    }
    return BaseGraph(adj_list);
}

size_t dfs_component_size(int vert, std::vector<bool>& used, const BaseGraph& graph) {
    used[vert] = true;
    size_t ans = 1;
    for (auto to : graph.GetAdj(vert)) {
        if (used[to]) {
            continue;
        }
        ans += dfs_component_size(to, used, graph);
    }
    return ans;
}

size_t CalcNumOfComponents(const BaseGraph& graph) {
    int num = graph.Size();
    std::vector<bool> used(num, false);
    size_t ans = 0;
    for (int i = 0; i < num; ++i) {
        if (!used[i]) {
            ++ans;
            dfs_component_size(i, used, graph);
        }
    }
    return ans;
}

RootedTree::RootedTree(const std::vector<int>& parents, size_t root): BaseGraph(parents.size()), root_(root) {
    assert(root >= 0 && root < Size());
    for (int i = 0; i < parents.size(); ++i) {
        if (i != root) {
            this->AddDirectedEdge(parents[i], i);
        }
    }
}

/*** End of inlined file: graph.cpp ***/

/*** End of inlined file: graph.h ***/

#include "iostream"

using namespace std;

bool check_function(int a, int b) {
    if (a * b > 100) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int ans = BinSearch(0, 100000000, -1, check_function, 10);
    cout << ans << '\n';
    auto factorize = Factorize(42, 1000);
    for (auto a : factorize) {
        cout << a << '\n';
    }
    return 0;
}

