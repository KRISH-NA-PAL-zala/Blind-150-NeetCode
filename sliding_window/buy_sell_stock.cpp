#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices){
    int maxprofit = 0, buy = 0, sell = 0;
    while(sell < prices.size()){
        if(prices[sell] > prices[buy]){
            maxprofit = max(maxprofit, prices[sell] - prices[buy]);
        } else {
            buy = sell;
        }
        sell++;
    }
    return maxprofit;
}

int main() {
    vector<int> prices = {7,6,4,3,1};

    cout<<maxProfit(prices)<<endl;
}