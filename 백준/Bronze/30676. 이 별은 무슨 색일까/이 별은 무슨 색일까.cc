#include<bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    
    cin >> n;
    string cStr;
    if(n<425)
        cStr = "Violet";
    else if(n<450)
        cStr = "Indigo";
    else if(n<495)
        cStr = "Blue";
    else if(n<570)
        cStr = "Green";
    else if(n<590)
        cStr = "Yellow";
    else if(n<620)
        cStr = "Orange";
    else if(n<=780)
        cStr = "Red";
    
    cout << cStr;
}