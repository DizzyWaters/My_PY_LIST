#include <stdlib.h>
#include <cstdio>

class MyList
{
    public:
    // constructor
    MyList() : head(nullptr), tail(nullptr), size(0), capacity(0){}
    // functions
    void append(int inputData)
    {
        Node* newNode = new Node(inputData);
        if(head == nullptr)
        {
        head = newNode;
        }
        else
        {
            Node* currentNode = head;
            while(currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
            newNode->prev = currentNode;
            tail = newNode;
        }
        // incrementing
        this->capacity++;
        this->size++;
    }
    void extend(MyList &obj)
    {
        if(obj.head == nullptr)
        {

        }
        else
        {
        Node* lastNode;// I need to add findLast method in private
        if (head == obj.head) {
            Node* current = obj.head;
            unsigned int originalSize = obj.size;
        
            for (unsigned int i = 0; i < originalSize; ++i) {
                this->append(current->data);  
                current = current->next;
            }
            return;
        }
        else
        {
            unsigned int secondSize = obj.size;
            Node* current = obj.head;
            while(current != nullptr)
            {
                this->append(current->data);
                current = current->next;
            }
          return;
        }
     
        }
    }
    void clear();
    void copy();
    int count();
    // function that returns size
    unsigned int Size(){
        return this->size;
    }
    // functions that returns data by index
    int index(int index) {

        if (index > size){
            printf("Out of bound\n");
        }

        Node* tmp = head;
        for (size_t i = 0 ; i < index; ++i){
            tmp = tmp->next;
        }
        return tmp->data;
    }
    // function that change data by index
    int write(int index,const int& value){

        if (index >= size){
            printf("Out of bound\n");
        }

        Node* tmp = head;
        for (size_t i = 0 ; i < index; ++i){
            tmp = tmp->next;
        }
        tmp->data = value;
        return tmp->data;
    }
    void insert();
    void pop();
    void remove();
    void print()
    {
        if (head == nullptr)
        {
           printf("List is empty"); 
        }
        else
        {
            Node* tmpNode = head;
            printf("[ "); //
            while(tmpNode != nullptr)
            {
                printf("%d, ", tmpNode->data);
                tmpNode = tmpNode->next;
            }    
            printf("]\n");
        }
    }
    void reverse();
    void sort();
    // variables

    private:
    // functions
    




    // variables
    unsigned int size;
    unsigned int capacity;
   
   // Node structure
    struct Node
    {
        int data;
        Node* next;
        Node* prev;

    // constructor of struct
        Node (int val) : data(val), next(nullptr), prev(nullptr){} 
    };

    Node* head;
    Node* tail;
};

int main()
{
    MyList test;
    MyList test2;
    for(int i = 0; i < 10; ++i)
    {
    test.append(i);
    test2.append(10 + i * 5);
    }
    
    test.print();
    test2.print();
    unsigned int mySize = test.Size();
    printf(" size of test - > %d \n", mySize);

    test.extend(test2);
    test.print();
    mySize = test.Size();
    printf(" size of test - > %d \n", mySize);
    
    printf("Testing Index\n");
    
    for(int i = 0; i < 20; ++i){
    printf("Index[%d] = %d\n", i, test.index(i));
    }
    printf("Testing extend to it self\n");

    test.extend(test);

    test.print();
    

    return 0;
}