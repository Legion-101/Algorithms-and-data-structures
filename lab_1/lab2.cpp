#include <iostream>

void flipArray(int *arr, int start_flip, int end_flip){
    int temp;
    for (int i = start_flip, j = end_flip; i < j; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int size, k;
    std::cin >> size >> k;
    int arr[size];
    for(int i = 0; i < size; i++)
        std::cin >> arr[i];
    if(k > size)
        k = k % size;
    else  if(k < 0){
        if((k * -1) > size){
            k = k % size;
        }
        k = size + k;
    }
    flipArray(arr, 0, size - 1);
    flipArray(arr, 0, k - 1);
    flipArray(arr, k, size - 1);
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n\n\n";
    return 0;
}

