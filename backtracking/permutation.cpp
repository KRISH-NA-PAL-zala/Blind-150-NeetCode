#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
void dfs(vector<int>& nums, int index){
    if(index == nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i = index;i < nums.size();i++){
        swap(nums[i], nums[index]);
        dfs(nums, index + 1);
        swap(nums[i], nums[index]);
    }
    return;
}

int main(){
    vector<int> nums = {1,2,3};
    dfs(nums, 0);
    for(auto permutations: result){
        cout<<"[";
        for(auto permutation : permutations){
            cout<< permutation;
        }
        cout<<"]"<<endl;
    }
    cout<<"Total: "<<result.size();
    return 0;
}