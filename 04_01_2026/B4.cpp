#include<iostream>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;

    int sumMin=0, sumMax=0;
    int min[n],max[n];
	int i=0;
    while(n--){
        cin >> min[i] >> max[i];
        sumMin += min[i];
        sumMax += max[i++];
    }
    i--;
    
    if(t >= sumMin && t <= sumMax){
        cout << "YES" << endl;
        
        while(sumMin != t){
        	int currDiff = max[i] - min[i];
        	if ( currDiff <= (t-sumMin)){
        		min[i] = max[i];
				sumMin += currDiff;
			}else{
				min[i] = min[i] + (t-sumMin);
				sumMin += t-sumMin;
			}
			i--;
		}
		int j =0;
		while(j<(sizeof(min)/sizeof(int))){
			cout << min[j] << " ";
			j++;
		}
        
    } else {
        cout << "NO" << endl;
    }
    
    

    return 0;
}