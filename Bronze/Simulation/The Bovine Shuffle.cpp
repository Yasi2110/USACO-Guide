#include <bits/stdc++.h>
using namespace std;

int a[101];
int cows[101];

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n, i, t;
    cin>>n;
    for(i=1;i<=n;i++) {
        int pos;
        cin>>pos;
        a[pos] = i;
    }

    for(i=1;i<=n;i++) cin>>cows[i];

    for(t=1;t<=3;t++) {
        int neww[101];
        for(i=1;i<=n;i++)
            neww[a[i]] = cows[i];

        for(i=1;i<=n;i++)
            cows[i] = neww[i];
    }

    for(i=1;i<=n;i++) cout<<cows[i]<<endl;


    return 0;
}
