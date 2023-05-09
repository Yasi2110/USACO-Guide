#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n, i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    int minn = INT_MAX;
    for(i=1;i<=n;i++) {
        int sum = 0, br = 1;
        int pos = i+1;
        if(pos == n+1) pos = 1;
        while(pos != i) {
            sum+= br*a[pos];
            pos++; br++;
            if(pos == n+1) pos = 1;
        }
        minn = min(minn, sum);
    }
    cout<<minn<<endl;

    return 0;
}
