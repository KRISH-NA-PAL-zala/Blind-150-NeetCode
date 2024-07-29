#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<int> cols;
unordered_set<int> negative_diagonal;
unordered_set<int> positive_diagonal;

void dfs(int& n, int row, vector<string>& board, vector<vector<string>>& result){
    if(row == n){
        result.push_back(board);
        return;
    }
    for(int cell = 0;cell < n;cell++){
        if( cols.find(cell) != cols.end()
        ||  negative_diagonal.find(row - cell) != negative_diagonal.end()
        ||  positive_diagonal.find(row + cell) != positive_diagonal.end()
        ) continue;

        cols.insert(cell);
        negative_diagonal.insert(row - cell);
        positive_diagonal.insert(row + cell);
        board[row][cell] = 'Q';
        
        dfs(n, row + 1, board, result);

        cols.erase(cell);
        negative_diagonal.erase(row - cell);
        positive_diagonal.erase(row + cell);
        board[row][cell] = '.';
    }
}

int main(){
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result; 
    dfs(n, 0, board, result);
    for(auto board: result){
        cout<<"[";
        for(auto cell : board){
            cout<< cell << " ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}