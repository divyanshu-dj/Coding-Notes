#include <iostream>
using namespace std

// Structure of the node of a singly linked list
class node{
    int data;
    node* next;
};

// Function prototypes
node *Create(int value);
node *InsertAtBeg(node *head, int value);
node *InsertAtPos(node *head, int value, int position);
node *InsertAtEnd(node *head, int value);
node *DeleteAtBeg(node *head);
node *DeleteAtPos(node *head, int position);
node *DeleteAtEnd(node *head);
node *Concatenate(node *head1, node *head2);
int Search(node *head, int element);
void Traverse(node *head);

int main()
{
    node *head1 = new node;
    // Creating a head node of value 81
    head1 = Create(81);

    //If we want to change " head1 = InsertAtEnd(head1, 2); " to " InsertAtEnd(head1, 2); " we will accept " node* &head1 " in agumented variable (i.e. the variable resieved by the function) like:-
    // node *InsertAtBeg(node* &head, int value)
    // {
    //     node *ptr = new node;
    //     ptr->data = value;
    //     ptr->next = head;
    //     head = ptr;
    // }
  
    // Inserting a node of value 2 at the end
    head1 = InsertAtEnd(head1, 2); 
    // Inserting a node of value 53 at the beginning
    head1 = InsertAtBeg(head1, 53);
    // Inserting a node of value 44 at the 2nd position
    head1 = InsertAtPos(head1, 44, 2);
    // Printing the first linked list
    cout<<"FIRST: ";
    Traverse(head1);

    cout<<"\n";

    node *head2 = new node;
    // Creating a head node of value 91
    head2 = Create(91);
    // Inserting a node of value 23 at the end
    head2 = InsertAtEnd(head2, 23);
    // Inserting a node of value -4 at the end
    head2 = InsertAtEnd(head2, -4);
    // Printing the second linked list
    cout << "SECOND: ";
    Traverse(head1);

    cout<<"\n";

    // Concatenating first and second linked list
    head1 = Concatenate(head1, head2);
    // Printing the concatenated linked list
    cout << "CONCATENATED: ";
    Traverse(head1);

    return 0;
}

// Function to create the head node (first node) of a singly linked list
node *Create(int value)
{
    node *ptr = new node;
    ptr->data = value;
    ptr->next = NULL;
    return ptr;
}

// Function to insert a new node at the beginning of a singly linked list
node *InsertAtBeg(node *head, int value)
{
    node *ptr = new node;
    ptr->data = value;
    ptr->next = head;
    head = ptr;
    return head;
}

// Function to insert a new node at the specified position of a singly linked list
node *InsertAtPos(node *head, int value, int position)
{
    if(position < 1)
    {
        cout<<"Invalid Position";
        return head;
    }
  
    if(position == 1)
        return InsertAtBeg(head, value);

    node *temp = new node;
    temp = head;

    //ptr2 is the node to be inserted
    node *ptr2 = new node;   
    ptr2->data = value;
    ptr2->next = NULL;

    while(--position > 1)
        temp = temp->next;

    ptr2->next = temp->next;
    //changing the pointer of temp to NULL
    temp->next = ptr2;

    return head;
}

// Function to insert a new node at the end of a singly linked list
node *InsertAtEnd(node *head, int value)
{
    node *temp = new node;
    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node *ptr2 = new node;
    ptr2->data = value;
    ptr2->next = NULL;

    temp->next = ptr2;

    return head;
}

// Function to delete a node from the beginning of a singly linked list
node *DeleteAtBeg(node *head)
{
    if(head == NULL)
    {
        cout<<"Underflow! Can't delete from empty list";
        return head;
    }
    node* ptr = new node;
    ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

// Function to delete a node from the specified position of a singly linked list
node *DeleteAtPos(node *head, int position)
{
    if(head == NULL)
    {
        cout << "Underflow! Can't delete from empty list";
        return head;
    }

    if(position < 1)
    {
        cout << "Invalid Position";
        return head;
    }

    if(position == 1)
        return DeleteAtBeg(head); 

    node *ptr1 = new node;
    ptr1 = head;

    position--;
    while(position > 1)
    {
        ptr1 = ptr1->next;
        position--;
    }

    node *ptr2 = new node;
    ptr2 = ptr1->next;
    ptr1->next = ptr2->next;
    delete ptr2;
    return head;
}

// Function to delete a node from the end of a singly linked list
node *DeleteAtEnd(node *head)
{
    if(head == NULL)
    {
        cout << "Underflow! Can't delete from empty list";
        return head;
    }
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    node *ptr1 = new node;
    ptr1 = head;

    while(ptr1->next->next != NULL)
        ptr1 = ptr1->next;

    node *ptr2 = new node;
    ptr2 = ptr1->next;
    delete ptr2;
    ptr1->next = NULL;
    return head;
}

// Function to concatenate two singly linked lists
node *Concatenate(node *head1, node *head2)
{
    node *ptr = new node;
    ptr = head1;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;
    return head1;
}

// Function to search for an element in a singly linked list
int Search(node *head, int element)
{
    node *ptr = new node;
    ptr = head;
    int position = 0;
    while (ptr != NULL)
    {
        position++;
        if (ptr->data == element)
            return position;
        ptr = ptr->next;
    }
    return 0;
}

// Function to print a singly linked list from head node to tail node
void Traverse(node *head)
{
    node *ptr = head;
    cout << "The linked list: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
