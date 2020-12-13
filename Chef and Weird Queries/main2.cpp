#include <iostream>
using namespace std;

int Exponent(int base, int power){
    if(power == 1){
        return base;
    }else{
        return Exponent(base, power/2) * Exponent(base, power/2);
    }
}

int BinarySearchHelper(int n, int left, int right){
    if(left == right-1){
        if(rigth*right <= n){
            return right;
        }else if(left*left == n){
            return left;
        }else{
            return left-1;
        }
    }else{
        int middle = (right-left)/2;
        if(middle*middle > n){
            return BinarySearchHelper(n, left, middle-1);
        }else{
            return BinarySearchHelper(n, middle, right);
        }   
    }
}

int BinarySearch(int n, int leftPower, int rightPower){
    int left = Exponent(2, leftPower);
    int right = Exponent(2, rightPower);
    int middle = (right-left)/2;
    if(middle*middle > n){
        return BinarySearchHelper(n, left, middle-1);
    }else{
        return BinarySearchHelper(n, middle, right);
    }
}

int CheckQueryHelper(int n){
    int power = 1;
    int temp = 2;
    while(temp < n){
        temp *= 2;
        power++;
    }
    if((power%2) == 0){
        return BinarySearch(n, power/2 - 1, power/2);
    }else{
        return BinarySearch(n, (power-1)/2, (power-1)/2 + 1);
    }
}

int CheckQuery(long y){
    int result = 0;
    for(int i=1;i<=700;i++){
        result += CheckQueryHelper(y-i);
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    long y;
    for(int i=0;i<t;i++){
        cin>>y;
        cout<<CheckQuery(y)<<endl;
    }
    return 0;
}