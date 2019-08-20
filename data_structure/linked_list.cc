#if (__GNUC__ == 7 ||  __GNUC__ == 4)
#include "common.h"
#endif

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    void createLinkedList(int n);

    void travelLinkedList() const;

    int getLenth() const;

    bool isEmpty() const;

    ListNode *find(int data) const;

    void push_back(int data);
    void push_back(const initializer_list<int> &init);

    void insert(int data, int n);
    void insert(const initializer_list<int> &init, int n);

    void push_head(int data);
    void push_head(const initializer_list<int> &init);

    void pop_back();

    void erase(int n);

    void pop_head();

    void destroyList();

    void deleteDuplicates();

  private:
    ListNode *head;
};

LinkedList::LinkedList() {
    head = new ListNode(0);
    head->val = 0;
    head->next = nullptr;
}


LinkedList::~LinkedList(){

    destroyList();

    delete head;
}

void LinkedList::createLinkedList(int n){

    if(n <= 0)
        return;

    ListNode *p_new, *p_temp;

    p_temp = head;

    for(int i = 0; i < n; ++i){
        int data;
        cin >> data;
        p_new = new ListNode(data);

        p_temp->next = p_new;
        p_temp = p_new;
    }

}

void LinkedList::travelLinkedList() const {

    if(head == nullptr || head->next == nullptr){
        cout << "空链表" << endl;
    }

    ListNode *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
        cout << temp->val << " ";
    }

    cout << endl;
}

int LinkedList::getLenth() const {

    int len = 0;

    if(head == nullptr || head->next == nullptr){
        return len;
    }

    ListNode *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
        len++;
    }

    return len;
}

bool LinkedList::isEmpty() const {
    return head == nullptr || head->next == nullptr;
}

ListNode *LinkedList::find(int data) const{

    if(isEmpty())
        return nullptr;

    ListNode *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
        if(temp->val == data)
            return temp;
    }

    return nullptr;
}

void LinkedList::push_back(int data){
    ListNode *new_node = new ListNode(data);

    ListNode *temp = head;

    while(temp->next != nullptr)
        temp = temp->next;
    
    temp->next = new_node;
}

void LinkedList::push_back(const initializer_list<int> &init){

    ListNode *temp = head;

    while(temp->next != nullptr)
        temp = temp->next;

    for(int data : init){
        ListNode *new_node = new ListNode(data);
        temp->next = new_node;
        temp = new_node;
    }
}

void LinkedList::insert(int data, int n){

    if(n<0)
    {
        cerr << "Error location to insert the new element." << endl;
        return;
    }

    ListNode *new_node = new ListNode(data);
    
    ListNode *temp = head;

    while(--n>=0){
        temp = temp->next;
        if(n != 0 && temp->next == nullptr)
        {
            cerr << "Error location to insert the new element." << endl;
            return;
        }
    }

    new_node->next = temp->next;
    temp->next = new_node;

}

void LinkedList::insert(const initializer_list<int> &init, int n){
    
    if(n<0)
    {
        cerr << "Error location to insert the new element." << endl;
        return;
    }

    ListNode *temp = head;

    while(--n>=0){
        temp = temp->next;
        if(n != 0 && temp->next == nullptr)
        {
            cerr << "Error location to insert the new element." << endl;
            return;
        }
    }

    ListNode *after = temp->next;

    for(int data : init){
        ListNode *new_node = new ListNode(data);
        temp->next = new_node;
        temp = new_node;
    }

    temp->next = after;
}

void LinkedList::push_head(int data){

    ListNode *new_node = new ListNode(data);

    ListNode *temp = head->next;

    head->next = new_node;
    head->next->next = temp;
}

void LinkedList::push_head(const initializer_list<int> &init){

    ListNode *temp = head;
    ListNode *after = temp->next;

    for(int data : init){
        ListNode *new_node = new ListNode(data);
        temp->next = new_node;
        temp = new_node;
    }

    temp->next = after;
}


void LinkedList::pop_back(){
    
    if(head->next == nullptr)
        return;

    ListNode *temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::erase(int n){

    if(n<0)
    {
        cerr << "Error location to erase the element." << endl;
        return;
    }

    ListNode *temp = head;
    
    while(--n>=0){
        temp = temp->next;
        
        if(n!=0 && (temp == nullptr || temp->next == nullptr || temp->next->next == nullptr)){
            cerr << "Error location to erase the element." << endl;
            return;
        }
    }

    ListNode *after = temp->next->next;
    delete temp->next;
    temp->next = after;
}

void LinkedList::pop_head(){

    if(head->next == nullptr)
        return;

    ListNode *temp = head->next->next;
    delete head->next;

    head->next = temp;
}

void LinkedList::destroyList(){

    ListNode *temp = head->next;

    while(temp != nullptr){

        ListNode *next = temp->next;
        delete temp;
        temp = next;
    }

    head->next = nullptr;
}

void LinkedList::deleteDuplicates(){

    if(head->next == nullptr){
        return;
    }

    ListNode *temp = head->next;
    ListNode *next;

    while(temp != nullptr){

        next = temp->next;

        while(next != nullptr && temp->val == next->val){
            temp->next = next->next;
            delete next;
            next = temp->next;
        }

        temp = temp->next;
    }

}

int main(){

    LinkedList listNode;

    // listNode.createLinkedList(0);
    // listNode.push_back(10);
    // listNode.push_back(11);
    // listNode.push_back({1, 2, 3, 4});
    // listNode.destroyList();

    // listNode.push_head(4);
    // listNode.insert(2, 0);
    // listNode.insert({1, 2, 3}, 0);
    // listNode.push_head({1, 0, 0, 0, 0});

    // listNode.pop_back();
    // listNode.pop_head();

    // listNode.erase(2);

    listNode.push_back({1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4});
    listNode.deleteDuplicates();

    cout << "ListNode lenth: " << listNode.getLenth() << endl;

    cout << "Travel list: ";
    listNode.travelLinkedList();

    return 0;
}