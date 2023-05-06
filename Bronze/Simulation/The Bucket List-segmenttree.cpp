#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, br;
    int lazy;
    Node *ld, *rd;
    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->br = 0;
        this->lazy = 0;
    }
};

void Build(Node *k) {

    if(k->l == k->r) {
        k->ld = NULL;
        k->rd = NULL;
        return;
    }

    k->ld = new Node(k->l, (k->l+k->r)/2);
    k->rd = new Node((k->l+k->r)/2+1, k->r);

    Build(k->ld);
    Build(k->rd);
}

void push_lazy(Node *k) {
    k->br+= k->lazy;
    if(k->ld != NULL) k->ld->lazy+= k->lazy;
    if(k->rd != NULL) k->rd->lazy+= k->lazy;
    k->lazy = 0;
}

void Update(Node *k, int ll, int rr, int b) {

    push_lazy(k);

    if(k->r < ll || rr < k->l) return;

    if(ll <= k->l && k->r <= rr) {
        k->lazy+= b;
        push_lazy(k);
        return;
    }

    Update(k->ld, ll, rr, b);
    Update(k->rd, ll, rr, b);

    k->br = max(k->ld->br, k->rd->br);
}

int main()
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);


    Node *root = new Node(1, 1000);
    Build(root);

    int n, i;
    cin>>n;
    for(i=1;i<=n;i++) {
        int l, r, b;
        cin>>l>>r>>b;
        Update(root, l, r, b);
    }

    cout<<root->br<<endl;

    return 0;
}
