#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> a(101);

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int i, j, t;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++) {
        string line = "";
        for(j=0;j<m;j++)
            for(t=1;t<=k;t++) line+= a[i][j];

        for(t=1;t<=k;t++) cout<<line<<endl;
    }


    return 0;
}
