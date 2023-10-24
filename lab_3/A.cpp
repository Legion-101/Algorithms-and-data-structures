#include <iostream>

using namespace std;

bool checkArray(int* arr, int size){
    int leftChildren = 0;
    int rightChildren = 0;
    
    for (int i = 0; i < size; i++) 
    { 
        leftChildren = 2 * i + 1;
        rightChildren = 2 * i + 2;
        
        // If left child is greater, return false 
        if(leftChildren < size-1 && arr[leftChildren] < arr[i])
            return false; 
    
        // If right child is greater, return false 
        if(rightChildren < size-1 && arr[rightChildren] < arr[i]) 
                return false; 
    } 
    return true; 
}

int main(){
    int size, numbers;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    if (checkArray(arr, size))
        cout << "YES";
    else cout << "NO";

}
