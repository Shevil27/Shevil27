#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

void combine( vector<int> &candidates, vector<int> &temp, int target, int i)
{
    if(i==candidates.size())
    {
        if(target == 0)
        {
            res.push_back(temp);
        }
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

vector<vector<int>> sol(vector<int> &candidates, int target)
{
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    combine(candidates, temp, target, 0);
    return res;
}

int main()
{
    vector<int> candidates;
    vector<vector<int>> res;
    int target=8, n=3;
    cout<<"Enter array:- ";
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        candidates.push_back(input);
    }
    res = sol(candidates, target);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}