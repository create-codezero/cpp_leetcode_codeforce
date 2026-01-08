#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int i =0;
        int count1 = 0;
        while(i<n){
            cin >> arr[i];
            if(arr[i] == 1){
                count1++;
            }
            i++;
        }
        if(count1 == n){
            cout << "Alice" << endl;
        }else if(arr[0] == 0 && arr[arr.size()-1] == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }

    return 0;
}