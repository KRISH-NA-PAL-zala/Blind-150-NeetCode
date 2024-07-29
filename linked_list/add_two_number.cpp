#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* add_two_numbers(ListNode* root1, ListNode* root2){
    ListNode* sum_root = new ListNode();
    ListNode* root = sum_root;
    int carry = 0;
    int v1, v2, sum;

    while(root1 || root2 || carry){
        v1 = !root1 ? 0 : root1->val;
        v2 = !root2 ? 0 : root2->val;

        sum = v1 + v2 + carry;
        carry = sum / 10;
        root->next = new ListNode(sum%10);

        root = root->next;
        root1 = !root1 ? nullptr : root1->next;
        root2 = !root2 ? nullptr : root2->next; 
    }
    return sum_root->next;
}

int main(){
    ListNode* root1;
    ListNode* root2;
    ListNode* sum_root;
    ListNode* root_pointer;
    vector<int> list;

    list = {5,6,7}; 
    root1 = new ListNode(list[0]);
    root_pointer = root1;
    for(int i = 1;i < list.size(); i++){
        root_pointer->next = new ListNode(list[i]);
        root_pointer = root_pointer->next;
    }
    
    list = {1,3,4}; 
    root2 = new ListNode(list[0]);
    root_pointer = root2;
    for(int i = 1;i < list.size(); i++){
        root_pointer->next = new ListNode(list[i]);
        root_pointer = root_pointer->next;
    }

    cout<<"list1 -> ";
    root_pointer = root1;
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;
    
    cout<<"list2 -> ";
    root_pointer = root2;
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;

    sum_root = add_two_numbers(root1, root2);

    cout<<"sum   -> ";
    root_pointer = sum_root;
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;

    return 0;
}