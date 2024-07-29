#include<bits/stdc++.h>

using namespace std;

class LRUCache{
private:
    struct node{
        int key;
        int val;
        node* prev;
        node* next;
        node(int key, int val):key(key), val(val), prev(nullptr), next(nullptr) {};
    };
    
public:
    int cap;
    node* left = new node(0, 0);
    node* right = new node(0, 0);
    unordered_map<int, node*> cache;

    LRUCache(int capacity){
        cap = capacity;
        left->next = right;
        right->prev = left;
    }
    
    void remove(node* n){
        node* prev = n->prev;
        node* next = n->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(node* n){
        node* prev = right->prev;
        node* next = right;

        prev->next = n;
        next->prev = n;

        n->prev = prev;
        n->next = next;
    }

    int get(int key){
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value){
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        cache[key] = new node(key, value);
        insert(cache[key]);

        if(cache.size() > cap){
            node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);

            delete lru;
        }
    }
};


int main(){
    cout<<"initialize cache with capacity 2";LRUCache lru(2);cout<<endl;
    cout<<"put : 1";lru.put(1, 1);cout<<endl;
    cout<<"put : 2";lru.put(2, 2);cout<<endl;
    cout<<"get : 1 > ";cout<<lru.get(1)<<endl;
    cout<<"put : 3";lru.put(3, 3);cout<<endl;
    cout<<"get : 2 > ";cout<<lru.get(2)<<endl;
    cout<<"put : 4";lru.put(4, 4);cout<<endl;
    cout<<"get : 1 > ";cout<<lru.get(1)<<endl;
    cout<<"get : 3 > ";cout<<lru.get(3)<<endl;
    cout<<"get : 4 > ";cout<<lru.get(4)<<endl;
    return 0;
}