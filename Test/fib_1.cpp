
#include  <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int jump_rec(int n) {
    if (n <= 1) return n;
    return jump_rec(n - 1) + jump_rec(n - 2);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return 0;
    }

    int n = stoi(argv[1]);

    auto start = high_resolution_clock::now();
    cout << "fib_rec(" << n << ") = " << jump_rec(n) << endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;

    return 0;
}