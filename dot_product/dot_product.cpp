#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = 0;
    for (const char* p = argv[1]; *p >= '0' && *p <= '9'; ++p) {
        n = n * 10 + (*p - '0');
    }

    double* a = new double[n];
    double* b = new double[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }

    std::cout.precision(15);
    std::cout << sum << '\n';

    delete[] a;
    delete[] b;
    return 0;
}
