#include "algorithms/number_theory.h"
#include "algorithms/methods.h"
#include "algorithms/graph.h"
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
