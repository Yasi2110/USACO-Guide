#include <bits/stdc++.h>
using namespace std;

int c[4], m[4];

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    cin>>c[1]>>m[1];
    cin>>c[2]>>m[2];
    cin>>c[3]>>m[3];

    int tek = 1;
    for(int i=1;i<=100;i++) {
        int sled = tek+1;
        if(sled == 4) sled = 1;

        if(m[tek]+m[sled] <= c[sled])
            m[sled]+= m[tek], m[tek] = 0;
        else
            m[tek]-= c[sled]-m[sled], m[sled] = c[sled];

        tek = sled;
    }

    cout<<m[1]<<endl;
    cout<<m[2]<<endl;
    cout<<m[3]<<endl;

    return 0;
}
