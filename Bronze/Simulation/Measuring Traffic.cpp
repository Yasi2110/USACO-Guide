#include <bits/stdc++.h>
using namespace std;

struct Input{
    string s;
    int l, r;
};
Input a[101];

int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n, i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i].s>>a[i].l>>a[i].r;
    int first_none = -1;
    int last_none = -1;

    for(i=n;i>=1;i--) {
        if(a[i].s == "none") {
            last_none = i;
            break;
        }
    }

    int l = a[last_none].l;
    int r = a[last_none].r;

    for(i=last_none-1;i>=1;i--) {
        if(a[i].s == "none") {
            l = max(l, a[i].l);
            r = min(r, a[i].r);
        }
        else
        if(a[i].s == "on") {
            l-= a[i].r;
            r-= a[i].l;
        }
        else
        if(a[i].s == "off") {
            l+= a[i].l;
            r+= a[i].r;
        }
    }

    l = max(0, l);
    r = max(0, r);
    cout<<l<<" "<<r<<endl;

    for(i=1;i<=n;i++) {
        if(a[i].s == "none") {
            first_none = i;
            break;
        }
    }

    l = a[first_none].l;
    r = a[first_none].r;

    for(i=first_none+1;i<=n;i++) {
        if(a[i].s == "none") {
            l = max(l, a[i].l);
            r = min(r, a[i].r);
        }
        else
        if(a[i].s == "off") {
            l-= a[i].r;
            r-= a[i].l;
        }
        else
        if(a[i].s == "on") {
            l+= a[i].l;
            r+= a[i].r;
        }
    }
    l = max(0, l);
    r = max(0, r);
    cout<<l<<" "<<r<<endl;

    return 0;
}
