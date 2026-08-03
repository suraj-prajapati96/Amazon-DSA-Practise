#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

class LRUCache{
public:
    struct Node{
        Node *prev,*next;
        int key,val;
    
    Node(int _key,int _val){
        key = _key;
        val = _val;
        }
    };
    Node * head = new Node(0,0), * tail = new Node(0,0);
    unordered_map<int,Node*> map;
    int capacity;
    LRUCache(int _capacity){
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(map.find(key)!=map.end()){
            Node *node = map[key];
            remove(node);
            insert(node);
            return node->val;
        }else{
            return -1;
        }
    }

    void put(int key, int val){
        if(map.find(key)!=map.end()){
            map.erase(key);
        }
        if(map.size() == capacity){
            remove(tail->prev);
        }
        insert(new Node(key,val));
    }
    void remove(Node *node){
        map.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node *node){
        map[node->key]=node;
        Node *headNext = head->next;
        head->next = node;
        node->prev = head;
        headNext->prev = node;
        node->next = headNext; 
    }
};

int main(){
    LRUCache obj(3);
    obj.put(1,1);
    obj.put(2,2);
    cout<<obj.get(1)<<endl;
    obj.put(3,3);
    cout<<obj.get(2)<<endl;
    obj.put(4,4);
    cout<<obj.get(1)<<endl;
    cout<<obj.get(3)<<endl;
    cout<<obj.get(4)<<endl;
    return 0;
}