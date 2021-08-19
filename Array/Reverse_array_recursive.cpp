#include <iostream>
using namespace std;

void reverse(int a[], int start, int end){
    if(start == end)
    return;
    else{
        a[start] = a[start] ^ a[end];
        a[end] = a[start] ^ a[end];
        a[start] = a[start] ^ a[end];
        reverse(a,start+1,end-1);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)
    cin>>a[i];
    reverse(a,0,n-1);
    for(auto x: a)
    cout<<x<<" ";
    cout<<endl;
    
}
