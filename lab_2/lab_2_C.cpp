#include <iostream> 
using namespace std; 
 
struct node { 
    int value; 
    struct node* next; 
    struct node* prev; 
}; 
 
struct listNodes { 
    int size; 
    node* first; 
    node* last; 
}; 
 
void pushElem(listNodes* L, int max_size, int elem) { 
    if(L->size < max_size){ 
        node* temp = new node; 
        temp->value = elem; 
        temp->next = nullptr; 
        temp->prev = L->last; 
 
        if (L->first != nullptr){ 
            L->last->next = temp; 
            L->last = temp; 
        }else { 
            L->first = L->last = temp; 
        } 
        L->size = L->size + 1; 
         
    }else { 
 
        // забираем первый элемент из списка: 
        node* firstEl = L->first; 
        int elem2 = L->first->value; 
        L->first = L->first->next; 
        L->first->next->prev = nullptr; 
        delete firstEl; 
 
 
        //забираем последний элемент из списка: 
        int elem3 = L->last->value; 
        node* lastEl = L->last; 
        L->last = L->last->prev; 
        L->last->next = nullptr; 
        delete lastEl; 
 
        // располагаем элементы в порядке возрастания 
        if (elem > elem2) 
            swap(elem, elem2); 
        if (elem > elem3) 
            swap(elem, elem3); 
        if (elem2 > elem3) 
            swap(elem2, elem3); 
 
        // добавляем в список элементы - два максимальных в порядке возрастания 
 
        node* preMaxElement = new node; 
        node* maxElement = new node; 
        preMaxElement->value = elem2; 
        maxElement->value = elem3; 
        preMaxElement->next = maxElement; 
        maxElement->next = nullptr; 
        maxElement->prev = preMaxElement; 
 
        L->last->next = preMaxElement; 
        preMaxElement->prev = L->last; 
        L->last = maxElement; 
 
        L->size = L->size + 1; 
    } 
} 
 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    listNodes* linkedList = new listNodes; 
    linkedList->first = nullptr; 
    linkedList->last = nullptr; 
    linkedList->size = 0; 
 
    int capacity; 
    int findTreasure; 
 
    cin >> findTreasure >> capacity; 
 
    for(int i = 0; i < findTreasure; i++){ 
        int item; 
        cin >> item; 
        pushElem(linkedList, capacity, item); 
    } 
 
    node *currentEl = linkedList->first; 
 
    while(currentEl){ 
        cout << currentEl->value << " "; 
        currentEl = currentEl->next; 
    } 
 
    return 0; 
}