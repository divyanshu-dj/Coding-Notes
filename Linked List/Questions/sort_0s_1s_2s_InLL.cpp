// Sort 0s, 1s and 2s : https://bit.ly/3s3fAOu

//////////////////////////// APPROACH 1////////////////////////////

Node* sortList(Node* head){
  int zeroCount = 0;
  int oneCount = 0;
  int twoCount = 0;

  Node* temp = head;
  
  while ( temp != NULL ){
    if( temp == 0 )
      zeroCount++;
    else if( temp == 1 )
      oneCount++;
    else if( temp == 2 )
      twoCount++;
    temp = temp->next;
  }

  temp = head;
  while( temp != NULL ){
    if( zeroCount != 0 ){
      temp->data = 0;
      zeroCount--;
    }
    else if( oneCount != 1 ){
      temp->data = 1;
      oneCount--;
    }
    else if( twoCount != 2 ){
      temp->data = 2;
      twoCount--;
    }
    return head;
  }
}

//////////////////////////////////////////////////////////////////////////


//////////////////////////// APPROACH 2////////////////////////////

void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

//////////////////////////////////////////////////////////////////////////////
