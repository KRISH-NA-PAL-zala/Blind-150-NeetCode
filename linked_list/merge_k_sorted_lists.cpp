#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(!list1){
        return list2;
    }else if(!list2){
        return list1;
    }

    if(list1->val < list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

ListNode* mergeKLists(vector<ListNode*> lists){
    int n = lists.size();
    if(!n){
        return NULL;
    }

    while(n > 1){
        for(int i = 0;i < n/2; i++){
            lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
        }
        n = (n + 1) / 2;
    }
    return lists.front();
}

int main(){
    ListNode* root1;
    ListNode* root2;
    ListNode* root3;
    ListNode* root_pointer;
    vector<int> list;
    vector<ListNode*> lists;

    list = {1,4,5}; 
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
    
    list = {2,6}; 
    root3 = new ListNode(list[0]);
    root_pointer = root3;
    for(int i = 1;i < list.size(); i++){
        root_pointer->next = new ListNode(list[i]);
        root_pointer = root_pointer->next;
    }

    lists.push_back(root1);
    lists.push_back(root2);
    lists.push_back(root3);

    root_pointer = mergeKLists(lists);

    cout<<"list -> ";
    while (root_pointer)
    {
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<endl;

    
    return 0;
}