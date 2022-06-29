class Queue {
public:
    int first;
     int rear;
     int *arr;
   
    Queue() {
        // Implement the Constructor
     first=0;
     rear=0;
     arr=new int[50001];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(first==rear) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        // Enqueue from Rear
        arr[rear++]=data;
    }

    int dequeue() {
        // Implement the dequeue() function
        // dequeue from front
        if(rear==first) return -1;
        return arr[first++];
    }

    int front() {
        // Implement the front() function
         if(rear==first) return -1;
        return arr[first];
    }
};



// Usding Ll


// Take two Node pointers tail and head and an integer size to store the size of the queue.

// In the Constructor function:
// Initialize the head and tail pointer NULL.
// In the enQueue function:
// Increase the value of size by 1.
// Create a new Node having the value to be pushed in the queue as data.
// If the head is NULL
// Update head = newNode.
// Update tail = newNode.
// Else, Update tail -> next = newNode.
// Return data.
// In the isEmpty function:
// If size is zero return 1.
// In the deQueue function:
// Check whether the queue is empty then return -1.
// Take a variable ans = head -> data.
// Update the head pointer to its next.
// Check if, after the update, head is NULL then update tail to NULL.
// Decrease the value of size by 1.

/*
    Time complexity: O(q)
    Space complexity: O(q)

    Where q is the number of queries.
*/

class Node {
public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
public:

    Node *head;
    Node *tail;
    int size;

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~Queue() {
        Node *temp = head;
        while (temp)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {

        // Increase the count of elements present in the List.
        size++;

        // Create a new node.
        Node *newNode = new Node(data);

        // Check if the Queue is empty.
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Push the element to the last of the queue.
        tail->next = newNode;
        tail = newNode;
        return;
    }

    int dequeue() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        int ans = head->data;


        Node *tmp = head;
        head = head->next;

        // If the queue is empty make the tail pointer NULL.
        if (head == NULL) {
            tail = NULL;
        }
        delete tmp;

        size--;

        return ans;
    }

    int front() {

        // Check if the queue is empty.
        if (isEmpty())  {
            return -1;
        }

        // Return the element at the front.
        return head->data;
    }
};
