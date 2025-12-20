class Node{
public:
    Node* next;
    Node* prev;
    int data;
    int keyval;

    Node (int val, int key){
        next = NULL;
        prev = NULL;
        data = val;
        keyval = key; 
    }    
};

class LRUCache {
public:
    unordered_map<int, Node*>mpp;
    int cap = 0;
    Node* head;
    Node* tail;

    LRUCache(int capacity) { 
        cap = capacity;
        mpp.clear();
        head = new Node(-1, -1);  
        tail = new Node(-1, -1);  
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* temp){
        Node* pretemp = temp -> prev;
        Node* aftertemp = temp -> next;
        pretemp -> next = aftertemp;
        aftertemp -> prev = pretemp;
    }

    void insertnode(Node* temp){
        Node* afterhead=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=afterhead;
        afterhead->prev=temp;
    }

    
    int get(int key) {
        int val=0;
        if (mpp.find(key)==mpp.end()) return -1;
        else {
            val=mpp[key]->data;
            deletenode(mpp[key]);
            insertnode(mpp[key]);
        }
        return val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key)!=mpp.end()) {
            mpp[key]->data=value;
            deletenode(mpp[key]);
            insertnode(mpp[key]);
        }
        else {
            Node* temp;
            if (mpp.size()==cap){
                temp=tail->prev;
                mpp.erase(temp->keyval);
                temp->data=value;
                temp->keyval=key;
                deletenode(temp);
                insertnode(temp);
            }
            else {
                temp=new Node(value,key);
                insertnode(temp);
            }
            mpp[key]=temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */