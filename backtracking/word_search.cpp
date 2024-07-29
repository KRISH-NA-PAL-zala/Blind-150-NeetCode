#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
bool dfs(vector<vector<char>>& board, string word , int row, int cell, int currentPosition, vector<bool>& isVisited){
    if(isVisited[row*board[0].size() + cell]){
        return false;
    }
    if(board[row][cell] != word[currentPosition]){
        return false;
    }
    if(currentPosition == word.length() - 1){
        return true;
    }
    isVisited[row*board[0].size() + cell] = true;
    for(auto direction: directions){
        int next_row = row + direction.first;
        int next_cell = cell + direction.second;
        if(next_row < 0 || next_row >= board.size() || next_cell < 0 || next_cell >= board.size()) {
            continue;
        }
        if(dfs(board, word, next_row, next_cell, currentPosition + 1, isVisited)){
            return true;
        }
    }
    isVisited[row*board[0].size() + cell] = false;
    return false;
}
int main(){
    int first = 0, last = 0;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    vector<bool> isVisited(board.size()*board[0].size());
    for(auto row = 0; row < board.size(); row++){
        for(auto cell = 0; cell < board[0].size(); cell++){
            if(board[row][cell] == word[0]){
                first++;
            } else if(board[row][cell] == word[word.length() - 1]){
                last++;
            }
        }
    }
    
    if(last > first){
        reverse(word.begin(), word.end());
    }

    for(auto row = 0; row < board.size(); row++){
        for(auto cell = 0; cell < board[0].size(); cell++){
            if(dfs(board, word, row, cell, 0, isVisited)){
                cout<<"Founded"<<endl;
            }
        }
    }
    return 0;
}