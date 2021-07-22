#include <iostream>
#include <vector>
using namespace std;

int nest(vector<int>a, int& depth){
    int d = 0;
    int index = 0;
    int i = 0;
    while(i<a.size()){
        if(a[i] == 1) d++;
        else d--;

        if(d > depth){
            index = i;
            depth = d;
        }
        i++;
    }
    return index;
}

int longest(vector<int>a, int& length){
    int index = 0, tempIndex = 0;
    bool started = false;
    int count = 0;
    int size = 0;
    int i=0;
    while(i<a.size()){
        if(!started){
            tempIndex = i;
            size = 0;
            started = true;
            count = 0;
        }
        if(a[i] == 1) count++;
        else count--;
        size++;
        i++;
        if(count == 0){
            started = false;
            if(size > length){
                length = size;
                index = tempIndex;
            }
        }
    }
    return index;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int depth = 0;
    int length = 0;
    int index1 = nest(a,depth) + 1;
    int index2 = longest(a,length) + 1;
    cout<<depth<<" "<<index1<<" "<<length<<" "<<index2<<endl;
}