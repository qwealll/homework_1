#include <iostream>

struct n {
    int sign;
    const char* ipart;
    int ilen;
    const char* fpart; 
    int flen;
};

bool digit(char c) {
    return c >= '0' && c <= '9';
}

n parse(const char* p) {
    n res;
    int s = 1;
    if (*p == '+') {
        ++p;
    } else if (*p == '-') {
        s = -1;
        ++p;
    }
    res.ipart = p;
    while (digit(*p)) {
        ++p;
    }
    res.ilen = p - res.ipart;
    res.fpart = p;
    res.flen = 0;
    if (*p == '.') {
        ++p;
        res.fpart = p;
        while (digit(*p)) {
            ++p;
        }
        res.flen = p - res.fpart;
    }
    bool zero = (res.ilen == 1 && res.ipart[0] == '0' && res.flen == 0);
    res.sign = zero ? 0 : s;
    return res;
}

int compabs(const n& a, const n& b) {
    if (a.ilen != b.ilen) {
        return a.ilen < b.ilen ? -1 : 1;
    }
    for (int i = 0; i < a.ilen; ++i) {
        if (a.ipart[i] != b.ipart[i]) {
            return a.ipart[i] < b.ipart[i] ? -1 : 1;
        }
    }
    int shortest = a.flen < b.flen ? a.flen : b.flen;
    for (int i = 0; i < shortest; ++i) {
        if (a.fpart[i] != b.fpart[i]) {
            return a.fpart[i] < b.fpart[i] ? -1 : 1;
        }
    }
    if (a.flen != b.flen) {
        return a.flen < b.flen ? -1 : 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 1;
    }
    n a = parse(argv[1]);
    n b = parse(argv[2]);

    int result;
    if (a.sign != b.sign) {
        result = a.sign < b.sign ? -1 : 1;
    } else if (a.sign == 0) {
        result = 0;
    } else {
        result = compabs(a, b) * a.sign;
    }

    if (result < 0) {
        std::cout << "less\n";
    } else if (result == 0) {
        std::cout << "equal\n";
    } else {
        std::cout << "greater\n";
    }
    return 0;
}