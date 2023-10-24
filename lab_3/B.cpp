#include <iostream>
#include <string>

using namespace std;

struct node{
    int value;
    node* next;
    node* prev;
};

struct queue{
    int key;
    node* head;
    node* tail;
    queue* next;
};

struct list{
    int size;
    queue* head;
};


// Создание очереди
void create(list* listIndexes){
    queue* newQueue = new queue;
    newQueue->key = listIndexes->size;
    newQueue->head = newQueue->tail = NULL;
    listIndexes->size += 1;
    listIndexes->head = newQueue;
}

// Вставка значения value в очередь с ключом key
void insert(list* &listIndexes, int key, int value){

}

//Извлечь минимальное значение из очереди с ключом key
void extractMin(int key){

}

// Создать новую очередь путем слияния очередей key и key_2
void merge(int key, int key_2){
    
}

// Заменить в очереди key значение value на replaceValue
void decreaseKey (int key, int value, int replaceValue){

}

int main(){
    string choice;
    list* listIndexesKey = new list;
    listIndexesKey->size = 0;
    listIndexesKey->head = NULL;
    while(true){
        cin >> choice;
        if(choice == "create"){
            create(listIndexesKey);
        } else if(choice == "insert"){
            int key, value;
            cin >> key >> value;
            insert(listIndexesKey, key, value);
            
        } else if (choice == "extract-min"){
            int key;
            cin >> key;

        } else if (choice == "merge"){
            int key, key2;
            cin >> key >> key2;
        } else {
            int key, replaceValue, value;
            cin >> key >> replaceValue >> value;
        }
    }

}