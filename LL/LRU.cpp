// head{-1, -1} <-> node 1 <-> node 2 .... node n <-> tail{-1, -1}

class Node{                            //Implemented using double linked list
public:
    int key;
    int val;
    Node* next=nullptr;
    Node* prev=nullptr;

    Node(int key, int value){
        this->key=key;
        val=value;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head=nullptr;
    Node* tail=nullptr;
    int size;

    void insert(Node* newNode){          //insert a node into dll
        Node* temp=head->next;           //insertion occurs at head
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void del(Node* x){                   //delete a node
        Node* p=x->prev;
        Node* n=x->next;
        p->next=n;
        n->prev=p;
    }

    LRUCache(int capacity) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        size=capacity;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        tail->prev=head;
        head->next=tail;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;

        Node* x=mp[key];
        del(x);
        insert(x);

        mp[key]=head->next;
        return mp[key]->val;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* x=mp[key];
            del(x);
            x->val=value;
            insert(x);
        }
        else{
            Node* newNode=new Node(key, value);
            if(mp.size()==size){
                Node* p=tail->prev;          //least recently used node means at tail
                del(p);
                mp.erase(p->key);
            }
            insert(newNode);
        }
        mp[key]=head->next;
    }
};


/*
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

int get(int key) Return the value of the key if the key exists, otherwise return -1.

void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
*/

/*
TestCases:
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
*/