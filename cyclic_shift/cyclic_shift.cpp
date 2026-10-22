#include <iostream>

void reverse(int* a, int left, int right) {
    --right;
    while (left < right) {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        ++left;
        --right;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = 0;
    for (const char* p = argv[1]; *p >= '0' && *p <= '9'; ++p) {
        n = n * 10 + (*p - '0');
    }

    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    long long k;
    std::cin >> k;

    
    long long m = k % n;
    if (m < 0) {
        m += n;
    }
    int r = m;

    if (r != 0) {
        reverse(a, 0, n);
        reverse(a, 0, r);
        reverse(a, r, n);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << '\n';
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << a[i];
    }
    std::cout << '\n';

    delete[] a;
    return 0;
}
