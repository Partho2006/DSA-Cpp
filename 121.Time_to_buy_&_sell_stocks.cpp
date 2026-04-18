// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/4868897/most-optimized-kadanes-algorithm-java-c-2yt85/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < buy){
                buy=prices[i];
            } else if(prices[i]-buy > profit){
                profit=prices[i]-buy;
            }
        }
        return profit;
    }
};

// Time complexity: O(n), where n is the length of the prices array. The algorithm iterates through the array once.
// Space complexity: O(1), as only a constant amount of extra space is used.


// Here's how the approach relates to Kadane's Algorithm:

// Initialization:

// In Kadane's Algorithm, max_current and max_global are initialized to the first element of the array.
// In the stock profit approach, buy is initialized with the first element of the prices array, and profit is initialized to 0.
// Iteration:

// Kadane's Algorithm iterates through the array, updating max_current based on the current element's value and deciding whether to start a new subarray.
// The stock profit approach iterates through the prices array, updating buy when a lower price is encountered and treating the difference between the current price and buy as a potential profit.