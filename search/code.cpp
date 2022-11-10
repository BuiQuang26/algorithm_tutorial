#include <bits/stdc++.h>
using namespace std;

bool linear_search(int a[], int n, int target){
	for(int i =0; i < n; i++){
		cout << i << endl;
		if(a[i] == target) return true;
	}
	return false;
}

//require: array sorted
bool binary_search(int a[], int n, int target){
	int l = 0, i = 0;
	int r = n - 1;
	while(l <= r){
		cout << i << endl;
		++i;
		int m = (l + r) /2;
		if(a[m] == target) return true;
		else if(a[m] > target) r = m - 1;
		else l = m + 1;
	}
	return false;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,23,44,66,12,34};
	int target = 12;
	if(linear_search(a, 12, target)){
		cout << "found" ;
	}else {
		cout << "not found";
	}
	return 0;
}


