/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500

*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void combine( vector<int> &candidates, vector<int> &temp, int target, int i)
{
    if(i==candidates.size())
    {
        if(target == 0)
            res.push_back(temp);
        return;
    }
    if(candidates[i]<=target)
    {
        temp.push_back(candidates[i]);
        combine(candidates, temp, target-candidates[i], i);
        temp.pop_back();
    }
    combine(candidates, temp, target, i+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    combine(candidates, temp, target, 0);
    return res;
}

int main()
{
    vector<int> c={2,3,6,7};
    int amt=7;
    combinationSum(c, amt);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}