#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<int>& candidates, int target, int index, int sum, vector<int>& subset, vector<vector<int>>& result){
    if(sum > target){
        return;
    }
    if(sum == target){
        result.push_back(subset);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if(i > index && candidates[i] == candidates[i - 1]){
            continue;
        }
        subset.push_back(candidates[i]);
        dfs(candidates, target, i + 1, sum + candidates[i], subset, result);
        subset.pop_back();
    } 
}
int main(){
    vector<vector<int>> result;
    vector<int> subset = {};
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, 0, subset, result);
    for(auto subset: result){
        cout<<"[";
        for(auto element : subset){
            cout<< element;
        }
        cout<<"]"<<endl;
    }
    return 0;
}