//
// Created by vpangul on 2019-04-17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> findAnagrams(string s, string p);
bool isAnagram(string s, string t);

bool isAnagram(string s, string t){
    if(s.size() != t.size()) return false;

    int arr[26]={0};
    for(int i=0; i<s.size(); i++){
        arr[s[i]-'0']++;
        arr[t[i]-'0']--;
    }

    for(int i=0; i<26; i++){
        if(arr[i]) return false;
    }
    return true;
}


vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int len=p.size();

    for(int i=0; i<s.size(); i++){
        char tmp[len+1];
        s.copy(tmp, p.size(), i);
        tmp[len]='\0';
        if(isAnagram(tmp, p)) res.push_back(i);
    }
    return res;

}

int main(){

    vector<int> res;
    res= findAnagrams("cbaebabacd", "abc");

    cout<<"Res: "<<res.size()<<endl;
    return 0;
}
