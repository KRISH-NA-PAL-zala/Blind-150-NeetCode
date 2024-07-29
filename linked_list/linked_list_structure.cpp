#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    
    return 0;
}