

#*1. Search by value - iterative*
Scenario: "Check if student with ID 205 exists in the class list"
bool searchByValue(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return true;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
    return false;
}


*2. Search by value - recursive*
Some instructors love asking for recursive versions.
bool searchRecursive(Node* head, int key) {
    if (head == NULL) return false;
    if (head->data == key) return true;
    return searchRecursive(head->next, key);
}


*3. Search by position/index*
Scenario: "Return the 3rd song in the playlist"
int getAtPosition(Node* head, int pos) {
    Node* temp = head;
    int count = 1;
    while (temp != NULL) {
        if (count == pos) return temp->data;
        temp = temp->next;
        count++;
    }
    return -1; // Invalid position
}


*4. Count occurrences*
Scenario: "How many times did error code 404 appear in the log list?"
int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) count++;
        temp = temp->next;
    }
    return count;
}


*Key things your instructor will check:*
1. *NULL check*: What if `head == NULL`? Your function should return false or -1, not crash.
2. *Position tracking*: Start counting from 1 or 0, but be consistent. Most DSA labs use 1-based.
3. *Time complexity*: All these are $O(n)$ because linked lists have no random access. Mention that if asked why it’s slow.

*Full scenario example for quiz:*
"An undo feature stores actions in a linked list. Write code to search if 'DELETE_FILE' action exists. If found, return its position, else return -1."

Answer: Use `searchByValue` but return position instead of bool.

Want me to combine insert, delete, traverse, and search into one complete sample question with solution?
