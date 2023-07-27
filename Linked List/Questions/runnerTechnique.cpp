//Finding the mid node of the linked list

Node* getMiddle(Node* head){
  if( head == NULL || head->next == NULL )
    return head;
  
  Node* slow = head;
  Node* fast = head->next;

  while( fast != NULL ){
    fast = fast->next;
    if( fast->next != NULL )
      fast = fast->next;
    slow = slow->next;
  }
  return slow;
}

Node* findMiddle(Node* head){
  return getMiddle(head);
}
