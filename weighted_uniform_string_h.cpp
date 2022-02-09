/*
A uniform string consists of a single character repeated zero or more times. For example, ccc and a are uniform strings, but bcb and cd are not.
Given a string, , let  be the set of weights for all possible uniform contiguous substrings of string . There will be  queries to answer where each query consists of a single integer. Create a return array where for each query, the value is Yes if . Otherwise, append No.
Note: The  symbol denotes that  is an element of set .
Example
Working from left to right, weights that exist are:
string  weight
a       1
b       2
bb      4
c       3
cc      6
ccc     9
d       4
dd      8
ddd     12
dddd    16
Now for each value in , see if it exists in the possible string weights. The return array is ['Yes', 'No', 'No', 'Yes', 'No'].
Function Description
Complete the weightedUniformStrings function in the editor below.
weightedUniformStrings has the following parameter(s):
- string s: a string
- int queries[n]: an array of integers
Returns
- string[n]: an array of strings that answer the queries
Input Format
The first line contains a string , the original string.
The second line contains an integer , the number of queries.
Each of the next  lines contains an integer , the weight of a uniform subtring of  that may or may not exist.
Constraints
 will only contain lowercase English letters, ascii[a-z].
Sample Input 0
abccddde
6
1
3
12
5
9
10
Sample Output 0
Yes
Yes
Yes
Yes
No
No
Explanation 0
The weights of every possible uniform substring in the string abccddde are shown below:
image
We print Yes on the first four lines because the first four queries match weights of uniform substrings of . We print No for the last two queries because there are no uniform substrings in  that have those weights.
Note that while de is a substring of  that would have a weight of , it is not a uniform substring.
Note that we are only dealing with contiguous substrings. So ccc is not a substring of the string ccxxc.
Sample Input 1
aaabbbbcccddd
5
9
7
8
12
5
Sample Output 1
Yes
No
Yes
Yes
No
*/

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
