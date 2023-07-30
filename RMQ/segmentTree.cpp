#include<bits/stdc++.h>
using namespace std;
#define mx 10000

int arr[mx];
int tree[4*mx]; // tree size will be atleast 3 times of original array



void buildTree(int Node, int st,int en){

    if(st == en){
        tree[Node] = arr[st];
        return;
    }

    int left = Node * 2,
        right = Node * 2 + 1,
        mid = (st + en) / 2;

        buildTree(left,st,mid);
        buildTree(right,mid+1,en);

        tree[Node] = min(tree[left],tree[right]);

}

int query(int Node,int st,int en,int l,int r){

    if(st>r or en<l)    return INT_MAX;   // [l,r] is completely out of [st,en] then we will return inf
    if(st>=l and en<=r) return tree[Node];  //

    int left = Node * 2,
        right = Node * 2 + 1,
        mid = (st + en) / 2;

    int x = query(left,st,mid,l,r);
    int y = query(right,mid+1,en,l,r);

    return min(x,y);

}

void update(int Node,int st,int en,int pos,int val){
    if(st==pos and en==pos){
        tree[Node] = val;
        return;
    }

    int left = Node * 2,
        right = Node * 2 + 1,
        mid = (st + en) / 2;

        if(pos<=mid) update(left,st,mid,pos,val);
        else update(right,mid+1,en,pos,val);

        tree[Node] = min(tree[left],tree[right]);
}

int main(){

    int N;
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildTree(1,1,N); //tree root index, value start index,value end index

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>> type;

        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,N,l,r)<<endl;
        }else if(type==2){
            int pos,val;
            cin>>pos>>val;
            update(1,1,N,pos,val);

        }
    }
}
/*
10
2 4 -3 4 5 10 12 6 -11 3
10
1 3 7
2 3 -45
1 1 10
2 3 -10
1 3 3
1 3 10
2 8 -22
2 1 -123
1 7 10
1 1 10

*/
