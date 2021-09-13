#include<bits/stdc++.h>

using namespace std;

void helper(int q, vector<string> &s)
{
    for(int z=0;z<s.size();z++)
    {
        string a, t;
        for(int i=1;i<=s[z].size()/2 && s[z] != t;i++)
        {
            t=s[z].substr(0, i);
            a=s[z].substr(0, i);
            for(int j=1;t.size()<s[z].size();j++)
            {
                t += to_string(stoll(a)+j);
            }
        }
        if(s[z]==t)
            cout<<"YES "<<a<<endl;
        else
            cout<<"NO"<<endl;
    }
}

int main()
{
    int q;
    vector<string> s; 
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string input;
        cin>>input;
        s.push_back(input);
    }
    helper(q, s);
    return 0;
}