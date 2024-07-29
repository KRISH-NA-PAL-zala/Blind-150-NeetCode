#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> subset = {};
void dfs(vector<int>& nums, int index){
    if(index >= nums.size()){
        result.push_back(subset);
        return;
    }

    subset.push_back(nums[index]);
    dfs(nums, index + 1);

    subset.pop_back();
    dfs(nums, index + 1);
}
int main(){
    vector<int> nums = {1,2,3};
    dfs(nums, 0);
    for(auto subset: result){
        cout<<"[";
        for(auto element : subset){
            cout<< element;
        }
        cout<<"]"<<endl;
    }
    return 0;
}