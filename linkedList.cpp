#include <iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data<<" ";
        temp = temp -> next;
    }
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}

bool checkifPresent(Node* head, int val){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val) return true;
        temp = temp -> next;
    }
    return false;
}

Node* removeHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* tailremoval(Node* head){
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp != nullptr){
        if(temp->next->next == nullptr){
            delete temp -> next;
            temp -> next = nullptr;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* removek(Node* head, int k){
    if(head == nullptr) return head;
    if(k == 1) return removeHead(head);
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* removeEl(Node* head, int el){
    if(head == nullptr) return head;
    if(head -> data == el) return removeHead(head);
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp -> data == el){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* insertatHead(Node* head, int val){
    Node* temp = new Node(val);
    temp -> next = head;
    return temp;
}

Node* insertTail(Node* head, int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    temp -> next = newNode;
    return head;
}

Node* insertPosition(Node* head, int el, int k){
    if(head == nullptr){
        if(k == 1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k == 1) return insertatHead(head, el);

    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(el);
            x -> next = temp -> next;
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}
Node* insertBeforeValue(Node* head, int el, int val){
    if(head == nullptr){
        return nullptr;
    }
    if(head -> data == val) return insertatHead(head, el);

    Node* temp = head;
    while(temp -> next != nullptr){
        if(temp -> next -> data == val){
            Node* x = new Node(el);
            x -> next = temp -> next;
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* deleteNthFromEnd(Node* head, int n){ // brute approach t.c = O(len) + O(len - n);
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp -> next;
    }
    if(cnt == n) return head -> next;
    temp = head;
    int res = cnt - n;
    while(temp != nullptr){
        res--;
        if(res == 0) break;
        temp = temp -> next;
    }
    Node* delNode = temp -> next;
    temp -> next = temp -> next -> next;
    free(delNode);
    return head;
}

Node* deletNthFromEnd(Node* head, int n){
    Node* slow = head;
    Node* fast = head;
    for(int i=0;i<n;i++){
        if(fast == nullptr) return head;  // when n > len;
        fast = fast -> next;
    }
    if(fast == nullptr) return head -> next; // edge case. when(n == len)
    while(fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next;
    }
    Node* delNode = slow -> next;
    slow -> next = slow -> next -> next;
    free(delNode);
    return head;
}

bool palindromeLL(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;

    while(temp != nullptr){
        if(temp -> data != st.top()) return false;

        temp = temp -> next;
        st.pop();
    }
    return true;
}

int main(){
    vector<int> arr = {1,2,3,2,1};
    Node* head = convertArr2LL(arr);
    //cout<<lengthofLL(head)
    //print(removeHead(head));
   // print(tailremoval(head));
    // print(removeEl(head,15));
    // print(insertatHead(head,100));
   // print(insertTail(head,20));
   // print(insertPosition(head,3,6));
    // print(insertBeforeValue(head,78,12));
    // print(deleteNthFromEnd(head, 2));
    // print(deletNthFromEnd(head, 5));
    if(palindromeLL(head)){
        cout<<"Its a palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }
   
}