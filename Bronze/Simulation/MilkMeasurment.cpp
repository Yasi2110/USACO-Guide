#include <bits/stdc++.h>
using namespace std;

struct Zapis{
    int den;
    string name;
    string dif;
};
const int MAXN = 101;
Zapis a[MAXN];

bool sortfunc(Zapis a1, Zapis a2) {
    return a1.den < a2.den;
}

map<string, int> cnt;

int Digit(string s) {
    int res = 0;
    for(int i=1;i<s.size();i++) {
        res*= 10;
        res+= s[i]-'0';
    }
    return res;
}

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++) {
        cin>>a[i].den>>a[i].name>>a[i].dif;
    }

    sort(a+1, a+n+1, sortfunc);

    int ans = 0, maxx = 0;
    set<string> tablo, neww;
    tablo.insert("Bessie");
    tablo.insert("Elsie");
    tablo.insert("Mildred");
    for(i=1;i<=n;i++) {
        if(a[i].dif[0] == '+') {
            cnt[a[i].name]+= Digit(a[i].dif);
        }
        else
        if(a[i].dif[0] == '-') {
            cnt[a[i].name]-= Digit(a[i].dif);
        }
        maxx = max(cnt["Bessie"], max(cnt["Elsie"], cnt["Mildred"]));

        neww.clear();
        if(cnt["Bessie"] == maxx) neww.insert("Bessie");
        if(cnt["Elsie"] == maxx) neww.insert("Elsie");
        if(cnt["Mildred"] == maxx) neww.insert("Mildred");

        if(neww != tablo) ans++, tablo = neww;
    }

    cout<<ans<<endl;


    return 0;
}
