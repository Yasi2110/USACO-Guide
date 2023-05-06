#include <bits/stdc++.h>
using namespace std;

int br[1001], maxx = 0;

int main()
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n, i;
    cin>>n;

    while(n-- ) {
        int l, r, b;
        cin>>l>>r>>b;
        for(i=l;i<=r;i++) {
            br[i]+= b;
            maxx = max(maxx, br[i]);
        }
    }

    cout<<maxx<<endl;

    return 0;
}
