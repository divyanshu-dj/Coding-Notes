//Iterative approach  O(n)

Node reversedLinkedList(Node* head){
  //empty or single node linked list
  if(head == NULL || head -> next == NULL)
    return head;

  //more than one node in linked list
  Node* prev = NULL;
  Node* curr = head;
  Node* forward = NULL;
  while( curr != NULL ){
    forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = forward;
  }
  return prev;
}



//Recursive approach - 1

void reverse1(Node* head, Node* curr, Node* prev){
  //Base Case
  if( curr == NULL ){
    head = prev;
    return;
  }

  Node* forward = curr -> next;
  reverse1(head, forward, curr);
  curr -> next = prev;
  
}

Node reversedLinkedList(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  reverse1(head, curr, prev);
  return;
}


//Recursive approach - 2

//it will return the head of the reversed list
Node* reverse2(Node* head){
  //base case
  if( head == NULL || head -> next == NULL ){
    return head;
  }

  Node* chottaHead = reverse2(head->next);

  head->next->next = head;
  head->next = NULL:
    
  return chottaHead;
}

Node reversedLinkedList(Node* head){
  return reverse2(head);
}
