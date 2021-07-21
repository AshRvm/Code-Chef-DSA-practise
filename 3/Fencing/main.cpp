#include <iostream>
#include <vector>
using namespace std;

void func(vector<vector<int> >& a, vector<vector<bool> >& b, int& count, int r, int c){
    if(b[r][c] == true) return;
    if(a[r][c] == 1){
        if((r==0) || (a[r-1][c] == 0)) count++;
        if((c==0) || (a[r][c-1] == 0)) count++;
    }else{
        if((r>0) && (a[r-1][c] == 1)) count++;
        if((c>0) && (a[r][c-1] == 1)) count++;
    }

    b[r][c] = true;
    if(r+1 < a.size()) func(a,b,count,r+1,c);
    if(c+1 < a[r].size()) func(a,b,count,r,c+1);
    return ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int> > a(n,vector<int> (m));
        vector<vector<bool> > b(n,vector<bool> (m,false));
        for(int i=0;i<k;i++){
            int r,c;
            cin>>r>>c;
            a[r-1][c-1] = 1;
        }
        int count = 0;
        func(a,b,count,0,0);
        for(int i=0;i<m;i++) if(a[n-1][i] == 1) count++;
        for(int i=0;i<n;i++) if(a[i][m-1] == 1) count++;
        cout<<count<<endl;
    }
}