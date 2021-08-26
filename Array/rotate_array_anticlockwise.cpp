Problem Name: Rotate Image (N X N Array)
Problem Difficulty: None
Problem Constraints: N < 1000
Problem Description:
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise. 

<img src="https://image.flaticon.com/icons/png/512/1522/1522104.png" width="200px">
Input Format: First line contains a single integer N. Next N lines contain N space separated integers.
Sample Input: 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Output Format: Print N lines with N space separated integers of the rotated array.
Sample Output: 4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 



=====Solution=====
#include <iostream>
#include<algorithm>
using namespace std;
void rotate(int a[][1000], int n){
    for(int i=0;i<n;i++){
        reverse(a[i],a[i]+n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }
}
int main() {
    int n;
    cin>>n;
    int a[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    rotate(a,n);
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
//reverse then transpose
