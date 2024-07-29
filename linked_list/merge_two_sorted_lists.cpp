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
    }
    if(!list2){
        return list1;
    }

    if(list1->val < list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main(){
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    ListNode* root_pointer;
    vector<int> list;
    
    //List1
    list = {1,2,4};
    if(list.size()){
        list1 = new ListNode(list[0]);
        root_pointer = list1;
        for(int i = 1;i < list.size(); i++){
            root_pointer->next = new ListNode(list[i]);
            root_pointer = root_pointer->next;
        }
        root_pointer = list1;
        cout<<"list1 -> [";

        while (root_pointer)
        {
            cout<<root_pointer->val<<" ";
            root_pointer = root_pointer->next;
        }

        cout<<"]"<<endl;
    }

    //List2
    list = {1,3,4};
    if(list.size()){
        list2 = new ListNode(list[0]);
        root_pointer = list2;
        for(int i = 1;i < list.size(); i++){
            root_pointer->next = new ListNode(list[i]);
            root_pointer = root_pointer->next;
        }
        root_pointer = list2;
        cout<<"list2 -> [";
        while (root_pointer)
        {
            cout<<root_pointer->val<<" ";
            root_pointer = root_pointer->next;
        }
        cout<<"]"<<endl;
    }

    root_pointer = mergeTwoLists(list1, list2);

    cout<<"merge -> [";
    while(root_pointer){
        cout<<root_pointer->val<<" ";
        root_pointer = root_pointer->next;
    }
    cout<<"]"<<endl;
    return 0;
}