#include<bits/stdc++.h>
using namespace std;

struct tri
{
    int x, y;
    string d;
};

int occur(string s, string a)
{
    int cnt = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == a[0])
        {
            int j;
            for(j=0;j<a.length();)
            {
                if(s[i+j] == a[j])
                    j++;
                else
                    break;
            }
            if(j==a.length())
            cnt++;
        }
    }
    return cnt;
}

void helper(int n, vector<string> &g, vector<long long int> &h, int s, vector<tri> &des)
{
    vector<int> cost;
    for(int z=0;z<s;z++)
    {
        int cnt=0;
        for(int i=des[z].x;i<=des[z].y;i++)
        {
            int temp = occur(des[z].d, g[i]);
            cnt +=  h[i]*temp;
        }
        cost.push_back(cnt);
    }
    cout<<*min_element(cost.begin(), cost.end())<<" "<<*max_element(cost.begin(), cost.end());
}

int main()
{
    int n, s;
    vector<string> g;
    vector<long long int> h;
    vector<tri> des;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        string input;
        cin>>input;
        g.push_back(input);
    }
    for(int i=0;i<n;i++)
    {
        long long int input;
        cin>>input;
        h.push_back(input);
    }
    cin>>s;
    for(int i=0;i<s;i++)
    {
        int a, b;
        string p;
        cin>>a>>b>>p;
        des.push_back({a, b, p});
    }
    helper(n, g, h, s, des);
    return 0;
}