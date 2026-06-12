#include <iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next;
    }
}
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = prev -> next;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == nullptr || head -> next == nullptr) return nullptr;
    Node* prev = head;
    head = head -> next;
    head -> back = nullptr;
    prev -> next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head -> next == nullptr) return nullptr;
    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    prev -> next = nullptr;
    tail -> back = nullptr;
    delete tail;

    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head == nullptr) return nullptr;

    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* front = temp -> next;
    
    if(front == nullptr && prev == nullptr){
        return nullptr;
    }
    else if(prev == nullptr) return deleteHead(head);
    else if(front == nullptr) return deleteTail(head);
    
    prev -> next = front;
    front -> back = prev;
    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp;

    return head;
}

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head -> back = newHead;

    return newHead;
}

void deleteNode(Node* temp){
    // here we are not deleting the head;
    // for head deletion we write fun(Node* head, Node* temp);
    Node* prev = temp -> back;
    Node* front = temp -> next;

    if(front == NULL){
        prev -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
        return;
    }
    prev -> next = front;
    front -> back = prev;
    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp;
    return;
}

Node* insertBeforeTail(Node* head, int val){
    if(head -> next == nullptr){
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    Node* prev = nullptr;
    while(tail->next != nullptr){
        tail = tail -> next;
    }
    prev = tail -> back;
    Node* newTail = new Node(val, tail, prev);
    tail -> back = newTail;
    prev -> next = newTail;

    return head;
}

Node* insertBeforeK(Node* head, int k, int val){
    if(k == 1){
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if( cnt == k){
            break;
        }
        temp = temp -> next;
    }
    prev = temp -> back;
    Node* newNode = new Node(val, temp, prev);
    prev -> next = newNode;
    temp -> back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = nullptr;
    prev = node -> back;
    Node* newNode = new Node(val, node, prev);
    prev -> next = newNode;
    node -> back = newNode;

    return;
}

Node* reverseDLL(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp != nullptr){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }
    return head;
}

Node* reverseDLLUsingLinks(Node* head){
    Node* cur = head;
    Node* last = nullptr;
    while(cur != nullptr){
        last = cur -> back;
        cur -> back = cur -> next;
        cur -> next = last;
        cur = cur -> back;
    }
    return (last -> back);

}

Node* sortALL(Node* head){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp -> data == 0) cnt0++;
        else if(temp -> data == 1) cnt1++;
        else cnt2++;
        temp = temp -> next;
    } 
    temp = head;
    while(temp != nullptr){
        if(cnt0){
            temp -> data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp -> data = 1;
            cnt1--;
        }
        else{
            temp -> data = 2;
            cnt2--;
        }
        temp = temp -> next;
    }
    return head;
}
int main(){
    vector<int> arr = {1,0,2,1,0};
    Node* head = convertArr2DLL(arr);
    // print(head);
    // print(deleteHead(head));
    //print(deleteTail(head));
    //print(deleteKthElement(head, 5));
    // (deleteNode(head->next));
    // print(head);
    // print(insertBeforeHead(head, 5));
    // print(insertBeforeTail(head, 0));
    // insertBeforeK(head, 3, 100);
    // print(head);
    // insertBeforeNode(head->next->next, 100);
    // print(head);
    // reverseDLL(head);
    // print(head);
    // print(reverseDLLUsingLinks(head));
    print(sortALL(head));
    return 0;
}
