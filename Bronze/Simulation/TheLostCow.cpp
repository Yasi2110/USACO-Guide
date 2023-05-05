#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y, i;
    cin>>x>>y;

    int ans = 0, dis = 1;
    int pos;
    for(i=1;;i++) {
        if(i%2 == 1) pos = x+dis;
        else pos = x-dis;
        if((x < y && y <= pos) || (x > y && y >= pos)) {
            ans+= abs(x-y);
            break;
        }
        ans+= 2*abs(pos-x);
        dis*= 2;
    }

    cout<<ans<<endl;

    return 0;
}
