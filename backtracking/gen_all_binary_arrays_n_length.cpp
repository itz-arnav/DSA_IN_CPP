// generate all 'n' length strings (consisting of 0's & 1's) using backtracking

#include <iostream>
#include <vector>
using namespace std;

vector<char> str;

void generate(int n){
    if(n <= 0){
        for(auto i : str){
            cout<<i;
        }
        cout<<endl;
    }
    else{
        str[n-1] = '0';
        generate(n-1);
        str[n-1] = '1';
        generate(n-1);
    }
}

int main(){
    int n;
    cin>>n;
    str.resize(n);
    
    generate(n);
    
    return 0;
    
}
