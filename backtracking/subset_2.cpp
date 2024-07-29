#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result){
    result.push_back(subset);
    for(int i = index;i < nums.size();i++){
        if(i > index && nums[i] == nums[i - 1]){
            continue;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, result);
        subset.pop_back();
    }
}

int main(){
    vector<vector<int>> result;
    vector<int> subset = {};
    vector<int> nums = {1,2,2};
    sort(nums.begin(), nums.end());
    dfs(nums, 0, subset, result);
    for(auto subset: result){
        cout<<"[";
        for(auto element : subset){
            cout<< element;
        }
        cout<<"]"<<endl;
    }
    return 0;
}