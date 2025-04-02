#include <stdlib.h>
#include <cstdio>

class MyList
{
    public:
    // constructor
    MyList() : head(nullptr), size(0), capacity(0){}
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
        }
        // incrementing
        this->capacity++;
        this->size++;
    }
    void extend(MyList &obj)
    {
        Node* lastNode;// I need to add findLast method in private
        if (head == obj.head)
        {  
                // logic
        }
        else
        {
            Node* currentNode = head;
            while(currentNode->next != nullptr)
            {   
                currentNode = currentNode->next;
            }
            lastNode = currentNode;
        }
        lastNode->next = obj.head;
        size += obj.size;
        capacity += obj.capacity;

    }
    void clear();
    void copy();
    int count();
    unsigned int Size(){
        return this->size;
    }
    unsigned int index(); // for 0 < size
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
    struct Node
    {
        int data;
        Node* next;
    //  Node* prev;

    // constructor of struct
        Node (int val) : data(val), next(nullptr){} 
    };

    Node* head;
};

int main()
{
    MyList test;
    MyList test2;
    for(int i = 0; i < 10; ++i)
    {
    test.append(i);
    test2.append(10);
    }
    
    test.print();
    test2.print();
    unsigned int mySize = test.Size();
    printf(" size of test - > %d \n", mySize);

    test.extend(test2);
    test.print();
    mySize = test.Size();
    printf(" size of test - > %d \n", mySize);
    
    

    return 0;
}