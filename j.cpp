#include<bits/stdc++.h>
using namespace std;

bool found = true;

unsigned long long binsearch(unsigned long long n, unsigned long long x);
unsigned long long result(unsigned long long x);
int main(){
    unsigned long long s, result;
    while(true){
        found = true;
        cin>>s;
        result = binsearch(0, s);
        if(found){
            cout<<result<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}

unsigned long long binsearch(unsigned long long n, unsigned long long x){
    unsigned long long left, right, mid;
    left = 0;
    right = x;
    while(left<=right){
        mid = (left+right)/2;
        if(result(mid) == x){
            return mid;
        }
        if(x>result(mid)){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    found = false;
    return 0;
}
unsigned long long result(unsigned long long x){
    unsigned long long res=x;
    while(x>0){
        x = x/10;
        res = res+x;
    }
    return res;
}
