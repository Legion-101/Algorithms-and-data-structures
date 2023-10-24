#include <iostream>
using namespace std;

//Structure of the Node
struct node{
    int data;
    node* link;
};

node *top = NULL;

//Function to check if stack is empty or not
bool isEmpty(){
    if(top == NULL)
        return true; 
    else
        return false;
}

//Function to insert an element in stack
void push (int value)
{
  node *ptr = new node();
  ptr->data = value;
  ptr->link = top;
  top = ptr;
}

//Function to delete an element from the stack
void pop ( ){
    if ( isEmpty() )
    cout << "Stack is Empty";
    else{
        node *ptr = top;
        top = top -> link;
        delete(ptr);
    }
}

// Function to show the element at the top of the stack
void showTop(){
    if ( isEmpty() )
        cout << "Stack is Empty";
    else
    cout<< top->data << "\n";
}

// Function to Display the stack
void displayStack(){
    if (isEmpty())
    cout << "Stack is Empty";
    else{
        node *temp=top;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << "\n";
    }
 }

// Main function
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int countCommand;
    cin >> countCommand;

    char sign;
    int number;

    for(int i = 0; i < countCommand; i++){
        cin >> sign;
        if(sign == '+'){
            cin >> number;
            push(number);
        }
        else{
            showTop();
            pop();
        }
   }
    return 0;
}