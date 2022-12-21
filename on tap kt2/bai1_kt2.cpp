#include <bits/stdc++.h>
using namespace std;

struct PHONE{
    string brand;
    float size;
    float price;
};

void show(PHONE phones[], int n){

    cout << endl << "Danh sach dien thoai : " << endl;

    for(int i = 0; i < n; i++){
        cout << phones[i].brand << " " << phones[i].size << " " << phones[i].price << endl;
    }
    cout << endl;
}

int main(){
    int n;
    do{
        cout << "n = ";
        cin >> n;
    }while ( 5 > n || n > 10);
    
    PHONE phones[n];

    for(int i = 0; i < n; i++){
        fflush(stdin);
        cout << "nhap dt " << i + 1 << endl;
        cout << "hang : "; cin >> phones[i].brand;
        cout << "kich thuoc : "; cin >> phones[i].size;
        cout << "gia thanh : "; cin >> phones[i].price;
    }

    show(phones, n);

    return 0;
}