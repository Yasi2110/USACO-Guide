#include <bits/stdc++.h>
using namespace std;

struct El{
    int pos, br;
};
vector<El> a;

bool sortfunc(El a1, El a2) { return a1.pos < a2.pos; }

int main()
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n, i;
    cin>>n;
    for(i=1;i<=n;i++) {
        int l, r, b;
        cin>>l>>r>>b;
        a.push_back({l, b});
        a.push_back({r+1, -b});
    }

    sort(a.begin(), a.end(), sortfunc);

    int tek = 0, maxx = 0;
    for(i=0;i<2*n;i++) {
        while(a[i].pos == a[i+1].pos) tek+= a[i].br, i++;
        tek+= a[i].br;
        maxx = max(maxx, tek);
    }
    cout<<maxx<<endl;

    return 0;
}
