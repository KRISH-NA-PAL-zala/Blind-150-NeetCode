#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse_list(ListNode* root){
    if(!root || !root->next){
        return root;
    }
    ListNode* previous_pointer = nullptr;
    ListNode* current_pointer = root;
    while(current_pointer){
        ListNode* next_pointer = current_pointer->next;
        current_pointer->next = previous_pointer;
        previous_pointer = current_pointer;
        current_pointer = next_pointer;
    }
    return previous_pointer;
}

ListNode* recursion_reverse(ListNode* root){
    if(!root || !root->next){
        return root;
    }
    ListNode* new_root = root;
    if(root->next){
        new_root = recursion_reverse(root->next);
        root->next->next = root;
    }
    root->next = nullptr;
    return new_root;
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
    cout<<"main -> ";
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;
    // root = reverse_list(root);
    root = recursion_reverse(root);
    root_pointer = root;
    
    cout<<"reversed -> ";
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    
    return 0;
}