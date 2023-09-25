#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s1, s2;
    cin>>s1>>s2;
    int i, j;

    string ans = "";

    for(i=0;i<s1.size();i++) {
        ans+= s1[i];
        if(ans.size() < s2.size()) continue;

        bool seq = true;

        int pos = ans.size()-s2.size();
        for(j=0;j<s2.size();j++,pos++) {
            if(ans[pos] != s2[j]) {
                seq = false;
                break;
            }
        }

        if(seq) {
            for(j=0;j<s2.size();j++) ans.pop_back();
        }

    }

    cout<<ans<<endl;

    return 0;
}
