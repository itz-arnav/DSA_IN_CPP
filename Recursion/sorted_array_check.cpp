// check if an array is sorted or not using recursion

#include <iostream>
#include <vector>
using namespace std;

bool rec(vector<int> &arr, int n){
    if(n == 1){
        return 1;
    }
    else{
        return (arr[n-1] < arr[n-2])?0:rec(arr,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<boolalpha<<rec(arr,n)<<endl;
}
