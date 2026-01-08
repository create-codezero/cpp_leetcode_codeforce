#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<string> words;

    while (n--){
        string word;
        cin >> word;
        words.push_back(word);

        if(word.length() > 10){
            words.pop_back();
            words.push_back(word[0] + to_string(word.length() - 2) + word[word.length() - 1]);
        }

    }

    int j = 0;
    while(j < words.size()){
        cout << words[j] << " ";
        j++;
    }
}