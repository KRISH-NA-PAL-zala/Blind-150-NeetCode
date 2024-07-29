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

int maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout<<"pre-orderd : ";pretraverse(root);cout<<endl;
    cout<<"in-orderd  : ";intraverse(root);cout<<endl;

    cout<<endl;

    cout<<"max-depth : "<<maxDepth(root);

    return 0;
}