#include <bits/stdc++.h>
using namespace std;

int top[4][4];
int br[4];

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, i;
    cin>>n;

    for(i=1;i<=3;i++) top[i][i] = 1;

    while(n-- ) {
        int a, b, c;
        cin>>a>>b>>c;
        for(i=1;i<=3;i++) {
            swap(top[a][i], top[b][i]);
            if(top[c][i] == 1) br[i]++;
        }
    }

    int maxx = 0;
    for(i=1;i<=3;i++) maxx = max(maxx, br[i]);

    cout<<maxx<<endl;

    return 0;
}
