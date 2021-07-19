#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<string,string> umap1;
    unordered_map<string,int> umap2,umap3;
    for(int i=0;i<n;i++){
        string chef,country;
        cin>>chef>>country;
        umap1.insert(make_pair(chef,country));
        umap2.insert(make_pair(chef,0));
        umap3.insert(make_pair(country,0));
    }
    int max1=0,max2=0;
    string chef,country;
    for(int i=0;i<m;i++){
        string tempChef;
        cin>>tempChef;
        string tempCountry = umap1.find(tempChef)->second;
        umap2.find(tempChef)->second++;
        umap3.find(tempCountry)->second++;
        if(umap2.find(tempChef)->second > max1){
            max1 = umap2.find(tempChef)->second;
            chef = tempChef;
        }else if(umap2.find(tempChef)->second == max1) chef = (chef<tempChef)?chef:tempChef;

        if(umap3.find(tempCountry)->second > max2){
            max2 = umap3.find(tempCountry)->second;
            country = tempCountry;
        }else if(umap3.find(tempCountry)->second == max2) country = (country<tempCountry)?country:tempCountry;
    }
    cout<<country<<endl;
    cout<<chef<<endl;
}