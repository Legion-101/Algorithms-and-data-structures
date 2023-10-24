#include <iostream> 
#include <string> 
using namespace std; 
 
struct node { 
    int value; 
    struct node *next; 
}; 
 
void push(node* &top, int value) 
{ 
    node *newEl = new node; 
    newEl->value = value; 
    newEl->next = top; 
    top = newEl; 
} 
 
int pop(node* &top) 
{ 
    int temp = top->value; 
    node *topEl = top; 
    top = top->next; 
    delete topEl; 
    return temp; 
} 
 
int top(node* &top){ 
    return top->value; 
} 
 
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    node *Stack = nullptr; 
 
    int n; 
    cin >> n; 
    int input_arr[n]; 
    int result[n]; 
    for(int i = 0; i < n; i++){ 
        result[i] = -1; 
    } 
 
    for(int i = 0; i < n; i++){ 
        cin >> input_arr[i]; 
    } 
 
 
    for (int i = 0; i < n; i++){ 
 
        // цикл до тех пор, пока у нас не будет большего элемента сверху или stack не станет пустым. 
        // извлекаем из stack элементы меньшего размера, чем текущий 
 
        while (Stack && input_arr[top(Stack)] < input_arr[i]) 
        { 
            // установливаем разницу индексов ближайшего большего и текущего элементов в массив с результатами 
            int index = top(Stack); 
            result[index] = i - index; 
            pop(Stack); 
        } 
        push(Stack, i); 
    } 
 
    for(int i=0; i< n; i++){ 
        cout << result[i] << " "; 
    } 
    return 0; 
}