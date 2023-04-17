#include <iostream>
#include <cmath>

bool canMove(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    return x1 == x2 || y1 == y2 || std::abs(x1 - x2) == std::abs(y1 - y2);
}

int main() {
    int x1, y1, x2, y2;
    std::cout << "Введите координаты двух клеток шахматной доски:\n";
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (canMove(x1, y1, x2, y2)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}