// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main() {
    srand(time(0));
    long long t = 1;
    long long n = rand(2, 20);
    long long d = rand(1, n);
    long long l = rand(2, n);
    cout << n << " " << d << " " << l << "\n";
}