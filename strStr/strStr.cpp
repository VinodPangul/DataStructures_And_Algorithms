//
// Created by vpangul on 2019-04-12.
//
#include <iostream>
#include "stack"
#include <vector>


using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        stack<char> s;
        int j=0;

        bool found = false;
        int firstMatch=-1;
        //cout<<needle.size()<<"needle.size()"<<endl;


        for(int i=0; i<haystack.size(); i++){
            if(haystack[i]==needle[j]){
                if(firstMatch == -1) firstMatch=i;
                found=true;
                s.push(needle[j]);
                j++;
                if(j==needle.size()) break;
            }else{
                if(found){
                    do{
                        cout<<"s.size()="<<s.size()<<endl;
                        s.pop();
                    }while(s.size()>0);
                    cout<<"s.size()="<<s.size()<<endl;
                }

                j=0;
                if(haystack[i]==needle[j]){
                    s.push(needle[j]);
                    found=true;
                    firstMatch=i;
                    j++;
                    if(j==needle.size()) break;
                }else if(haystack[i-1]==needle[j] && haystack[i-1+1]==needle[j+1]) {
                    s.push(needle[j]);
                    s.push(needle[j+1]);
                    found=true;
                    firstMatch=i-1;
                    j+=2;
                    if(j==needle.size()) break;
                }
                else{
                        found=false;
                        firstMatch=-1;
                }
            }
        }

        //cout<<s.size()<<"s.size()"<<endl;
        //cout<<needle.size()<<"needle.size()"<<endl;

        if(s.size()==needle.size())
            return firstMatch;
        else
            return -1;

    }
};

int countNoBits(int num){
    int sum=0;
    while(num){
        sum += num & 1;
        num = num >> 1;
    }
    cout<<"sum:"<<sum<<endl;
    return sum;
}

void isPowerOfTwo(int n){
    if( ! (n&(n-1)) ){
       cout<<"Power Of Two"<<endl;
    }else
        cout<<"Not a power of two"<<endl;
}

void swap(int i, int j, vector<int> &a){
    int tmp = a[i];
    a[i]= a[j];
    a[j] = tmp;
}
// 2 4 6 4 6 3 5


//5, 7, 2, 4, 1, 9, 8
void arrangeArray(vector<int> & arr){
  int head = 0;
  int tail = arr.size()-1;
  int i=0;

  while(head<tail){
      while((arr[head] % 2) == 0){ // odd
          head++;
      }
      while((arr[tail] %2) != 0 ){ //even
          tail--;
      }
      swap(head, tail, arr);
      head++;
      tail--;
  }
}

int main(){

#if 0
    string haystack="aabaaaababaababaa";
    string needle="bbbb";
    //string haystack="mississippi";
    //string haystack="ippi";
    //string needle="issip";
    Solution s;
    int ptr=s.strStr(haystack, needle);
    cout<<"Ptr : "<<ptr<<endl;
#endif

    //countNoBits(23);  //  1 0 1 1 1
    vector<int> arr = {5, 7, 2, 4, 1, 9, 8, 12, 14 , 13, 123, 1345, 120};
    arrangeArray(arr);
    for(auto i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    return 0;
}