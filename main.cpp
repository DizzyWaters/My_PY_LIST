#include <cstdio>

class MyList
{
    public:
    // constructor
    MyList() : size(0), capacity(0), head(nullptr), tail(nullptr){}
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
            return;
        }
        else
        {
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
    // function that returns size
    unsigned int Size(){
        return this->size;
    }
    // functions that returns data by index
    int index(int index) {

        if (index > (int)size){
            printf("Out of bound\n");
        }

        Node* tmp = head;
        for (int i = 0 ; i < index; ++i){
            tmp = tmp->next;
        }
        return tmp->data;
    }
    // function that change data by index
    int write(int index, const int& value){

        if (index >= (int)size){
            printf("Out of bound\n");
        }
        Node* tmp = head;
        for (int i = 0 ; i < index; ++i){
            tmp = tmp->next;
        }
        tmp->data = value;
        return tmp->data;
    }
    void insert(const int& index, const int& value)
    {
        if (index > (int)size)
        {
            printf("Out of bound\n");
            return;
        }
        if(index == 0)
        {
            Node* newNode = new Node(value);
            newNode->next = head;
            if(head != nullptr)
            {
            head->prev = newNode;
            }
            head = newNode;
            if(tail == nullptr)
            {
            tail = newNode;
            }
            size++;
            capacity++;
            return;
        }        
        if(index == (int)size)
        {
            Node* newNode = new Node(value);
            newNode->prev = tail;
            if(tail != nullptr)
            {
            tail->next = newNode;
            }
            tail = newNode;
            if(head == nullptr)
            {
                head = newNode;
            }
            size++;
            capacity++;
            return;
        }
        else{
        Node* newNode = new Node(value);
        Node* currentNode = head;
        Node* leftNode;

        for(int i = 0; i < index; ++i)
        {
            currentNode = currentNode->next;
        }
        leftNode = currentNode->prev;
        leftNode->next = newNode;
        newNode->prev = leftNode;
        newNode->next = currentNode;
        currentNode->prev = newNode; 
        size++;
        capacity++;
            }
    }
    int pop()
    {
        if(tail == nullptr)
        {
            printf("List is empty\n");
            return 0;
        }

        Node* tmp = tail;
        int rData = tail->data;
        tail = tail->prev;
        
        if(tail == nullptr)
        {
            head = nullptr;
        }
        else
        {
            tail->next = nullptr;
        }

        delete  tmp;
        size--;
        capacity--;
        return rData;
    }

    int pop(int index)
    {
        if (index >= size || index < 0){
            printf("Out of bound\n");
            return 0;
        }
        if (head == nullptr && tail == nullptr){
            printf("list is empty\n");
            return 0;   
        }
        if(index == (size -1))
        {
            return pop();
        }

        Node* tmp;
        int rData;

        if(index == 0)
        {
            tmp = head;
            if(head->next != nullptr)
            {
                tmp = head;
                head = tmp->next;   
                rData = tmp->data;
                delete tmp;
            }
            else // list contains only one node
            {
                rData = head->data;
                delete head;
                head = nullptr;
                tail = nullptr;
            }
        }
        else
        {
            tmp = head;
            for(int i = 0; i < index; ++i)
            {
                tmp = tmp->next;
            }
            rData = tmp->data;
            tmp->prev->next = tmp->next;
            if(tmp->next != nullptr)
            {
            tmp->next->prev = tmp->prev;
            }
            delete tmp;
        }

        size--;
        capacity--;
        return rData;
    }

    // Remove the first item from the list whose value is equal to x. It raises a ValueError if there is no such item.
    void remove(int x)
    {
        Node* tmp = head;
        int index = 0;

        while(tmp != nullptr)
        {   
            if(tmp->data == x)
            {
                pop(index);
                return;
            }
            tmp = tmp->next;
            index++;            
        }
        printf("ValueError\n");
        return;
    }
   
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
    // Reverse the elements of the list in place.
    void reverse()
    {
    Node* current = head;
    Node* tmp = nullptr;

    while (current != nullptr)
    {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    // swap
    tmp = head;
    head = tail;
    tail = tmp;
    }
    void sort(); //         Return the number of times x appears in the list.
    

    ~MyList()
{
    Node* current = head;
    while(current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = capacity = 0;
}

    //                  ######## PTIVATE #######
    private:
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

    // functions
};

    //                      **** MIAN ****
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
    test.insert(3, 999); 
    test.print();
    test.reverse();
    printf("reversing list\n");
    test.print();
    test.pop();
    printf("pop\n");
    test.print();
    test.reverse();
    printf("reversing list\n");
    test.print();
    test.pop(2);
    printf("pop\n");
    test.print();
    return 0;
}