/*
    Write a function that insert linked list node at any position. The function takes the data of the node and the
    node position as inputs.

        For example if we have a linked list contains the followingdata nodes: 11 3 10 50 23 5 60
        If you asked the function to insert a new node has data equals to 15 at position 3 the linked list should be:
        11 3 10 <15> 50 23 5 60
*/

// DISCLOSURE : Implementation inspired from geekforgeek.com (https://www.geeksforgeeks.org/insert-a-node-at-a-specific-position-in-a-linked-list/)
// DISCLOSURE : I got somewhat stuck and was impressed with this solution. I have studied the code and now understand the steps.

#include <iostream>
using namespace std;
 
// A linked list Node
struct Node {
    int data;
    struct Node* next;
};
 
// Size of linked list
int size = 0;

Node* getNode(int data);
void insertPos(Node** current, int pos, int data);
void printList(struct Node* head);

// Driver Code
int main()
{   
    // Creating the list 11->3->10->50->23->5->60
    Node* head = NULL;
    head = getNode(11);
    head->next = getNode(3);
    head->next->next = getNode(10);
    head->next->next->next = getNode(50);
    head->next->next->next->next = getNode(23);
    head->next->next->next->next->next = getNode(5);
    head->next->next->next->next->next->next = getNode(60);
 
    size = 7;
 
    cout << "Linked list before insertion" << endl;
    printList(head);
 
    // insertion 15 at position 3
    int data = 15, pos = 3;
    insertPos(&head, pos, data);
    cout << "Linked list after insertion of 15 at position 3" << endl;
    printList(head);
 
    return 0;
}

// function to create and return a Node
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();
 
    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// function to insert a Node at required position
void insertPos(Node** current, int pos, int data)
{
    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
 
        // Keep looping until the pos is zero
        while (pos--) {
 
            if (pos == 0) {
 
                // adding Node at required position
                Node* temp = getNode(data);
 
                // Making the new Node to point to
                // the old Node at the same position
                temp->next = *current;
 
                // Changing the pointer of the Node previous
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the
              // pointer pointing to the address of next Node
              current = &(*current)->next;
        }
        size++;
    }
}
 
// This function prints contents
// of the linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        cout<< head->data << " ";
        head = head->next;
    }
    cout << endl;
}