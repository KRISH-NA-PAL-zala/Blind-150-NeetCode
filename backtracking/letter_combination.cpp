#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

unordered_map<char, string> map = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
void dfs(string& digits, int index, string& subset, vector<string>& result){
    if(index == digits.size()){
        result.push_back(subset);
        return;
    }
    string letters = map[digits[index]];
    for(int i = 0; i < letters.size();i++){
        subset.push_back(letters[i]);
        dfs(digits, index + 1, subset, result);
        subset.pop_back();
    }
}

int main(){
    string digits = "234";
    string subset = "";
    vector<string> result; 
    dfs(digits, 0, subset, result);
    cout<<"[";
    for(auto subset: result){
        cout<<"'"<<subset<<"' ";
    }
    cout<<"]";
    return 0;
}