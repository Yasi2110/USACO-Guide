#include <bits/stdc++.h>
using namespace std;

char c[4][4];
set<int> ind;
set<pair<int, int>> team;

void Ins(char c1, char c2) {
    if(c1 < c2) team.insert({c1-'a', c2-'a'});
    else  team.insert({c2-'a', c1-'a'});
}

void Check(char c1, char c2, char c3) {
    if(c1 == c2 && c2 == c3) ind.insert(c1-'a');
    else
    if(c1 == c2 || c2 == c3) Ins(c1, c3);
    else
    if(c1 == c3) Ins(c1, c2);
}


int main()
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    int i, j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            cin>>c[i][j];
    for(i=1;i<=3;i++) Check(c[1][i], c[2][i], c[3][i]);
    for(i=1;i<=3;i++) Check(c[i][1], c[i][2], c[i][3]);
    Check(c[1][1], c[2][2], c[3][3]);
    Check(c[1][3], c[2][2], c[3][1]);

    cout<<ind.size()<<endl;
    cout<<team.size()<<endl;

    return 0;
}
