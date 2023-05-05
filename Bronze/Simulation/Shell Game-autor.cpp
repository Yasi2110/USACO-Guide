#include <bits/stdc++.h>
using namespace std;

int pos[4];
int br[4];

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, i;
    cin>>n;
    for(i=1;i<=3;i++) pos[i] = i;

    for(i=1;i<=n;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        swap(pos[a], pos[b]);
        br[pos[c]]++;
    }

    cout<<max(max(br[1], br[2]), br[3])<<endl;

    return 0;
}
