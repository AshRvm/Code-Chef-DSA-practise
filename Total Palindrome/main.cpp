#include <iostream>
#include <string>

int* IntToArray(int x){
    int i=0;
    while(x != 0){
        result[i] = x%10;
        x /= 10;
        i++;
    }
    return (result);
}

int CheckOddPalindrome(int* num){
    int size = sizeof(num)/sizeof(num[0]);
    
}

int CheckTotalPalindrome(int num){
    int size = 0;
    int temp = num;
    while(temp != 0){
        temp /= 10;
        size ++;
    }
    int* revNum = new int[size];
    revNum = IntToArray(num);

}

int main(){
    int t;
    int a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        int answer = 0;
        cin>>a>>b;
        for(int j=a+1;j<=b;j++){
            answer += CheckTotalPalindrome(j);
        }
        cout<<answer<<endl;
    }
}