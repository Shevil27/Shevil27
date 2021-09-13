#include<bits/stdc++.h>

using namespace std;

vector<int> weight(string &s)
{
    vector<int> a(10000000, 0);
    int j=0;
    for(int i=0;i<s.length();i++)
    {
        if(i>0 && s[i]!=s[i-1])
            j=0;
        j+=s[i]-'a'+1;
        a[j]=1;
    }
    return a;
}

void querry_check(string &s, int n, vector<int> &q)
{
    vector<int> w;
    w=weight(s);
    for(int i=0;i<n;i++)
    {
        if(w[q[i]] == 1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}

int main()
{
    string s;
    int n;
    vector<int> q; 
    cin>>s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        q.push_back(input);
    }
    querry_check(s, n, q);
    return 0;
}