#include <bits/stdc++.h>
using namespace std;

int ans[27];

int main()
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n, i;
    cin>>n;
    while(n-- ) {
        string s1, s2;
        cin>>s1>>s2;
        int br1[27]{}, br2[27]{};
        for(i=0;i<s1.size();i++) br1[s1[i]-'a']++;
        for(i=0;i<s2.size();i++) br2[s2[i]-'a']++;
        for(i=0;i<26;i++) ans[i]+= max(br1[i], br2[i]);
    }

    for(i=0;i<26;i++) cout<<ans[i]<<endl;

    return 0;
}
