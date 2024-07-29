#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pretraverse(TreeNode* root){
    if(!root) return;

    cout<<root->val<<" ";
    pretraverse(root->left);
    pretraverse(root->right);
}

void intraverse(TreeNode* root){
    if(!root) return;

    intraverse(root->left);
    cout<<root->val<<" ";
    intraverse(root->right);
}

bool isSameTree(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2) return true;

    if(!root1 || !root2 || root1->val != root2->val) return false;

    return (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
}

bool isSubTree(TreeNode* root, TreeNode* sub_root){
    if(!sub_root) return true;
    if(!root) return false;

    if(isSameTree(root, sub_root)) return true;

    return isSubTree(root->left, sub_root) || isSubTree(root->right, sub_root);
}

int main(){
    TreeNode* root1 = new TreeNode(3);

    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    
    TreeNode* root2 = new TreeNode(4);

    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    cout<<"pre-orderd : ";pretraverse(root1);cout<<endl;
    cout<<"in-orderd  : ";intraverse(root1);cout<<endl;
    
    cout<<"pre-orderd : ";pretraverse(root2);cout<<endl;
    cout<<"in-orderd  : ";intraverse(root2);cout<<endl;

    cout<<isSubTree(root1, root2);

    return 0;
}