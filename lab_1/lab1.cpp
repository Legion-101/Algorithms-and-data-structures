#include <iostream>

int reverse_array(int *array, int start_reverse, int end_reverse){
    int temp;
    for(int i = start_reverse; i < end_reverse; ++i){
        temp = array[i];
        array[i] = array[end_reverse - i - 1];
        array[end_reverse - i - 1] = temp;
    }
    return *array;
}

void print_array(int *array, int size){
    for(int i = 0; i < size - 1; ++i){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main(){
    int n, k;
    std::cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    if(k > 0){
        reverse_array(arr, 0, n - 1);
        std::cout << "Переворот массива "<<std::endl;
        print_array(arr, n);
        reverse_array(arr, 0, k - 1);
        std::cout << "Переворот первой части массива"<<std::endl;
        print_array(arr, n);
        reverse_array(arr, k, n - 1);
        std::cout << "Переворот второй части массива"<<std::endl;
        print_array(arr, n);
    }
    std::cout << "Результат"<<std::endl;
    print_array(arr, n);
    return 0;
}