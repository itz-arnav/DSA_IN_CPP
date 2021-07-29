// generate all 'n' length strings (0 ... k-1) using backtracking

#include <iostream>
#include <vector>
using namespace std;

vector<char> str;
int k;

void generate(int n){
    if(n <= 0){
        for(auto i : str){
            cout<<i;
        }
        cout<<endl;
    }
    else{
        for(int i = 0; i<k; i++){
            str[n-1] = i + '0';
            generate(n-1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    cin>>k;
    
    str.resize(n);
    
    generate(n);
    
    return 0;
    
}
