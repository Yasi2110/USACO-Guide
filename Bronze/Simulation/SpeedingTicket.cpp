#include <bits/stdc++.h>
using namespace std;

struct Segment{
    int len, speed;
};
Segment a[101], b[101];

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m, i;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i].len>>a[i].speed;
    for(i=1;i<=m;i++) cin>>b[i].len>>b[i].speed;

    int path = 0;
    int path2 = 0, uk = 1;
    int maxx = 0;

    for(i=1;i<=n;i++) {
        if(path2 != path) maxx = max(maxx, b[uk-1].speed - a[i].speed);
        path+= a[i].len;
        while(path2 < path) {
            maxx = max(maxx, b[uk].speed - a[i].speed);
            path2+= b[uk++].len;
        }
    }
    cout<<maxx<<endl;

    return 0;
}
