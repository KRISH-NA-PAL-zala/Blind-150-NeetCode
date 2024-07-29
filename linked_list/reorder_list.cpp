#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode* reverse(ListNode* root) {
//     ListNode* prev = nullptr;
//     ListNode* curr = root;
//     ListNode* next = curr->next;

//     while (curr != nullptr)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
    
//     return prev;
// }

// void merge(ListNode* l1, ListNode* l2){
//     while (l1 != nullptr)
//     {
//         ListNode* p1 = l1->next;
//         ListNode* p2 = l2->next;

//         l1->next = l2;
//         if(p1 == nullptr){
//             break;
//         }
//         l2->next = p1;

//         l1 = p1;
//         l2 = p2;
//     }
    
// }

void reorderList(ListNode* root){
    ListNode* s = root;
    ListNode* f = root;

    while(f && f->next){     
        s = s -> next;
        f = f -> next -> next;
    }
    ListNode* second = s -> next;
    s -> next = nullptr;
    ListNode* prev = nullptr;
    while (second){
        ListNode* nxt = second->next;
        second->next = prev;
        prev = second;
        second = nxt;
    }

    while(prev){
        ListNode* tmp = root->next;
        ListNode* ptmp = prev->next;
        root->next = prev;
        prev->next = tmp;
        root = tmp;
        prev = ptmp;
    }
}

int main(){
    ListNode* root;
    ListNode* root_pointer;
    vector<int> list;

    list = {1,2,3,4,5}; 
    root = new ListNode(list[0]);
    root_pointer = root;
    for(int i = 1;i < list.size(); i++){
        root_pointer->next = new ListNode(list[i]);
        root_pointer = root_pointer->next;
    }
    root_pointer = root;
    cout<<"list -> ";
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;
    
    reorderList(root);
    root_pointer = root;
    cout<<"list -> ";
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;
    
    return 0;
}