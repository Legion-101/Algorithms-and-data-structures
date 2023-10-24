#include <iostream>

int findOptimalSleepDay(int N, int *numbers) {
    int totalSum = 0;
    int leftSum = 0;

    for (int i = 0; i < N; i++) {
        totalSum += numbers[i];
    }

    for (int i = 0; i < N; i++) {
        totalSum -= numbers[i];
        if (leftSum == totalSum) {
            return i;
        }
        leftSum += numbers[i];
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    int  numbers[N];
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    int result = findOptimalSleepDay(N, numbers);
    std::cout << result << std::endl;

    return 0;
}
