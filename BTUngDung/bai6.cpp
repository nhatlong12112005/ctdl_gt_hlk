#include <iostream>
#include <cmath>
using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void sort(int a[], int n){
   for(int i = 0; i<n-1;i++){
    if(a[i]==0)
        continue;
    if((a[i] % 2 == 0)&&(a[i]!=0)){
        for(int j = i+1; j<n; j++){
            if((a[j]%2==0) && (a[j]!=0) && (a[i]>a[j]))
                swap(a[i],a[j]);
        }
    }
    else {
        for(int j = i+1; j<n; j++){
            if((a[j]%2==1) && (a[i]<a[j]))
                swap(a[i],a[j]);
        }
    }
   }
}



int main (){
   int a[10] = {1,2,0,4,5,6,0,7,8,10};
    sort(a,10);
    for (int i =0;i<10;i++){
        cout<<a[i]<<" ";
    }
}