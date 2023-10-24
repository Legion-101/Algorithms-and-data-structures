#include <iostream>
#include <string>

bool isPalindrome(std::string word, int left, int right) {
    while (left < right) {
        if (word[left] != word[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool canBecomePalindrome(std::string word, int length) {
    int left = 0;
    int right = length - 1;
    while (left < right) {
        if (word[left] != word[right]) {
            return isPalindrome(word, left + 1, right) || isPalindrome(word, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int length;
    std::cin >> length;

    std::string word;
    std::cin >> word;

    if (canBecomePalindrome(word, length)) {
        std::cout << "YES" << "\n";
    } else {
        std::cout << "NO" << "\n";
    }

    return 0;
}
