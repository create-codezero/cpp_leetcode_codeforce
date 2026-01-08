#include<iostream>

#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int i = 0;

        int notnewyear = 0;
        int newyear = 0;
        while(i < s.length()){
            if(s[i] == '2' && s[i+1] == '0' && s[i+2] == '2'){
                if(s[i+3] == '5'){
                    notnewyear++;
                }
                if(s[i+3] == '6'){
                    newyear++;
                }
            }
            i++;
        }

        if(newyear){
            cout << 0 << "\n";
        }else if(notnewyear>0 && !newyear){
            cout << 1 << "\n";
        }else {
            cout << 0 << "\n";
        }
    }
}