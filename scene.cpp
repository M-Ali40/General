//For a DSA lab quiz on linked lists, scenario questions usually give you a real-world situation and ask you to code insert, delete, and traverse. Here are 3 common patterns that show up.

*1. Insertion scenarios*

- *At beginning*: "Add a new student to the front of the attendance list"
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}



- *At end*: "Append a new song to your playlist"
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


- *At position*: "Insert a new page after page 3 in a document"
void insertAtPosition(Node*& head, int pos, int data) {
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


*2. Deletion scenarios*

- *By value*: "Remove student with roll no. 25 from the list"
void deleteByValue(Node*& head, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) return; // not found
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}


*3. Traversing scenarios*

- *Display/Print*: "Print all items in shopping cart"
void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


- *Search*: "Check if product ID 102 exists in inventory list"
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}


*Lab quiz tip*: They often combine these. Example scenario: "You manage a call queue. New calls go to the end, urgent calls go to the front, hang-ups delete a call by ID, and you must display the whole queue." That's just insertAtTail + insertAtHead + deleteByValue + traverse.

*Common edge cases they test:*
1. Empty list: `head == NULL`
2. Single node deletion
3. Invalid position
4. Deleting head vs middle vs tail

Want me to make a full sample scenario question + solution like your teacher might give?