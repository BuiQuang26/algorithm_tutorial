#include <bits/stdc++.h>
using namespace std;

//n : vi tri so fibonacy
long fibonacy(int n){
    if(n < 2) return 1;
    return fibonacy(n - 1) + fibonacy(n - 2);
}

long _fibonacy(int n){
    if(n < 2) return 1;

    long a = 1, b = 1, c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    cout << _fibonacy(6) << " " << fibonacy(6);
    return 0;
}