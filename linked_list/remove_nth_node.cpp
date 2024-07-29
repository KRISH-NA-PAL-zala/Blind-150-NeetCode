#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* remove_nth_node_from_end(ListNode* root, int n){
    ListNode* root_pointer = root;
    int root_length = 0;

    while(root_pointer){
        root_length++;
        root_pointer = root_pointer->next;
    }
    if(root_length == n){
        return root->next;
    }
    root_pointer = root;

    for(int i = 0; i < root_length - n - 1; i++){
        root_pointer = root_pointer->next;
    }
    root_pointer->next = root_pointer->next->next;

    return root;
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
    root = remove_nth_node_from_end(root, 5);
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