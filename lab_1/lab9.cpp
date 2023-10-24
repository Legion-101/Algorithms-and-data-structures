#include <iostream>
#include <bitset>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long x, y;
    std::cin >> x >> y;

    int countUpDays = 0;

    for (long long day = x; day <= y; day++) {
        std::string binaryDay = std::bitset<64>(day).to_string(); // Преобразование числа в двоичную строку

        bool hasThreeConsecutiveOnes = false;
        bool hasThreeConsecutiveZeros = false;

        for (int i = 0; i < binaryDay.length(); i++) {
            char currentBit = binaryDay[i];

            if (currentBit == '1') {
                hasThreeConsecutiveZeros = false;
                if (++hasThreeConsecutiveOnes == 3) {
                    countUpDays++;
                    break; // Выходим из внутреннего цикла
                }
            } else {
                hasThreeConsecutiveOnes = false;
                if (++hasThreeConsecutiveZeros == 3) {
                    countUpDays++;
                    break; // Выходим из внутреннего цикла
                }
            }
        }
    }

    std::cout << countUpDays << "\n";

    return 0;
}
