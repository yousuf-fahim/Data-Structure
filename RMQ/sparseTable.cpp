#include<bits/stdc++.h>
using namespace std;

// time complexity to build O(nlogn).
void build_sparse_table(vector<int > &arr, vector<vector<int> > &table){

    int row_len = arr.size();
    int col_len = log(row_len) + 1;

    table.resize(row_len,vector<int> (col_len));

    for(int i = 0; i < row_len; i++)    table[i][0] = arr[i];

    for(int j = 1; j < col_len; j++){
        for(int i = 0; i + (1 << j) - 1 < row_len; i++){
            int first_half = table[i][j-1];
            int second_half_index = i + (1 << j-1);
            int second_half = table[second_half_index][j-1];
            table[i][j] = min(first_half,second_half);
        }
    }
}

// time complexity is constant for query (best feature)
int query(int l, int r, vector<vector<int> > &table){

    int total_element = r - l + 1;
    int k = log(total_element);
    int first_half = table[l][k];
    int remain = total_element - (1 << k);
    int second_half = table[l+remain][k];
    return min(first_half,second_half);
}

int main(){

    vector<int> arr{1,23,11,-33,22,0,52,56,0,41,-32,-1,122};
    vector<vector<int> > table;

    build_sparse_table(arr,table);

    cout<<"Table created. Enter a range between 0 to "<<arr.size() - 1<<endl;
    int l,r;
    while(cin>>l>>r){
        if(l>r) swap(l,r);
        cout<<query(l,r,table)<<endl;
    }
    return 0;
}
