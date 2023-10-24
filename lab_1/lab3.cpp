#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    std::cout << x;
    return 0;
}

