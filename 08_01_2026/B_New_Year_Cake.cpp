// #include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement:
    cake with atleast one layer

    chocolates : dark(0), white(1) (layer coloring must follow alternate coloring)
    
    if k is layer size it will take k kg of chocolate

    layers : 1,2,4,8,16,
    
    a : kg of white 
    b : kg of dark
    
    calculate maximum layers of cake that can be made
    )
*/

#include <bits/stdc++.h>
using namespace std;

int maxLayers(int a, int b, bool startDark) {
    int layers = 0;
    int prevLayer = 1;
    bool isDark = startDark;

    while(true){
        if(isDark){
            if(b < prevLayer) break;
            b -= prevLayer;
        }else{
            if(a < prevLayer) break;
            a -= prevLayer;
        }
        layers++;
        prevLayer *= 2;
        isDark = !isDark;
    }
    return layers;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int ans = max(maxLayers(a,b,true), maxLayers(a,b,false));
        cout << ans << "\n";
    }
}
