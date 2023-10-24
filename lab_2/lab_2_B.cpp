#include <iostream>
using namespace std;

// Structure of Node.
struct node{
   int data;
   node *link;
};

node *front = NULL;
node *rear = NULL;

//Function to check if queue is empty or not
bool isEmpty(){
   if(front == NULL && rear == NULL)
   return true;
   else
   return false;
}

//function to enter elements in queue
void enqueue ( int value ){
   node *ptr = new node();
   ptr->data= value;
   ptr->link = NULL;

   //If inserting the first element/node
   if( front == NULL ){
      front = ptr;
      rear = ptr;
   }
   else{
      rear ->link = ptr;
      rear = ptr;
   }
}

//function to delete/remove element from queue
void dequeue ( )
{
   if( isEmpty() )
   cout<<"Queue is empty\n";
   else
   //only one element/node in queue.
   if(front == rear){
      free(front);
      front = rear = NULL;
   }
   else{
      node *ptr = front;
      front = front->link;
      free(ptr);
   }
}

//function to show the element at front
void showfront( ){
   if( isEmpty())
      cout << "Queue is empty\n";
   else{
      cout << front->data << '\n';
      dequeue();
   }
}

//function to display queue
void displayQueue(){
   if (isEmpty())
      cout<<"Queue is empty\n";
   else{
      node *ptr = front;
      while( ptr !=NULL){
         cout<<ptr->data<<" ";
         ptr= ptr->link;
      }
   }
}

//Main Function
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
         enqueue(number);
      }
      else{
         showfront();
      }
   }

 return 0;
}