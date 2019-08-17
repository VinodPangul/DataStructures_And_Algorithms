#include <iostream>
#include <string>

#include <stack>
#include <vector>
using namespace std;
#if 0
string getSubStr(string str ) {
    if (str.size() == 0) {
        cout << str;
    } else {
        for (int i = 0; i < str.size(); i++) {
            getSubStr(str+i);
        }

    }
}


int main2() {
    std::cout << "Hello, World!" << std::endl;
    getSubStr("MARTY");
    return 0;
}

 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL;
        ListNode *first;
        int carry=0;
        int sum=0;
        bool carryPending=false;
        ListNode *newNode;
        // If l1 is empty
        if(l1 == NULL){
            return l2;
        }else if(l2 == NULL){
            // If l2 is empty
            return l1;
        }else{

            // Else
            while(l1 != NULL && l2 != NULL){
                if(l3 == NULL){
                    newNode= new ListNode(carry);
                    newNode->next=NULL;
                    l3=newNode;
                    first=newNode;
                }
                cout<<"l1->val"<<l1->val;
                cout<<"l2->val"<<l2->val;
                int sum=carry+l1->val + l2->val;
                if(sum > 9){
                    carry=1;
                    sum=0;
                    carryPending=true;
                }
                l3->val=sum;
                cout<<"l3->val: "<<l3->val<<endl;
                l1=l1->next;
                l2=l2->next;
                if(l2 != NULL || l1 != NULL){
                    int tmp=0;
                    newNode=new ListNode(tmp);
                    newNode->next=NULL;
                    l3->next=newNode;

                }
            }  // End of while

            if(l1 == NULL && l2 == NULL){

                if(carryPending){
                    newNode=new ListNode(carry);
                    newNode->next=NULL;
                    l3->next=newNode;
                }
            }

            /*
            else if(l1 == NULL){
                sum=0;
                sum=carry+l2->val;
                if(sum > 9){
                    carry=sum-9;
                    sum=9;
                }
                l3->val=sum;
                if(carry>0){
                  newNode=new ListNode(carry);
                  newNode->val = carry;
                  newNode->next=NULL;
                  l3->next=newNode;
                }
            }else if(l2 == NULL){
                sum=0;
                sum=carry+l2->val;
                if(sum > 9){
                    carry=sum-9;
                    sum=9;
                }
                l3->val=sum;
                if(carry>0){
                  newNode=new ListNode(carry);
                  newNode->val = carry;
                  newNode->next=NULL;
                  l3->next=newNode;
                }
            }
           */

        }//End of else block
        return first;
    }
};
int main1() {
    std::cout << "Hello, World!" << std::endl;
    ListNode* l1(2, 4, 3);

    addTwoNumbers(l1, l2);
    return 0;
}

#endif

void printStars(int count){
    if(count==1){
        cout<<"* ";
    }else{
        cout<<"* ";
        printStars(count -1);
    }
}

int powInt(int base, int exp){
    if(exp<0)throw ("No negative exponent");
    if(exp==0){
        return 1;
    }else{
        return base* powInt(base, exp-1);
    }
}

bool isPalindrome(string str){
    if(str.size()<2){
        return true;
    }else{
        char first=str[0];
        char last=str[str.size()-1];
        if(first != last){
            return false;
        }else{
            string rest= str.substr(1, str.size()-2);
            return isPalindrome(rest);
        }
    }
}

void printBinary(int n){
    if(n<2){
        cout<<n;
    }else{
        //cout<<"n :"<<n<<endl;
        int d=n%2;

        printBinary(n/2);
        cout<<d;
    }
}


void getMaxStr(string str){

    int arr[47]={0};
    for(int i=0; i<str.size(); i++) {
        int index=str[i]-'a';
        arr[index]=str[i];
        cout << arr[i] << " ";
    }
    int count=0;
    for(int i=0; i<47; i++){
        if(arr[i] != 0){
            count++;
        }
    }

    cout<<"Count:"<<count;

}

/*

bool isAnagram(string s, string t) {
    stack<char> st;
    if(s.size() == t.size()){
        for(int i=0; i<s.size(); i++)
            st.push(s[i]);
        //cout<<"st.size()"<<st.size();

        for(int i=0; i<t.size(); i++){
            if(st.top() == t[i]){
                st.pop();
                t.erase(i, 1);
                //cout<<"* st.size()"<<st.size()<<endl;
                //cout<<"* t:"<<t<<endl;
                i=-1;
                //continue;
            }
        }
        if(st.size() == t.size() && st.empty()) return true;
        else   return false;
    }else
        return false;

}
*/

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int a[26]={0};
    for(int i=0; i<s.size(); i++){
        a[ s[i] - 'a' ]++;
        a[ t[i] - 'a']--;
    }
    for(int i=0; i<26; i++){
        if(a[i]) return false;
    }
    return true;

}

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int len=p.size();

    for(int i=0; i<s.size(); i++){
        char tmp[len+1]; //={'\0'};
        tmp[0]='\0';
        s.copy(tmp, p.size(), i);
        tmp[len]='\0';
        cout<<"TMP:"<<tmp<<endl;
        if(isAnagram(tmp, p)) res.push_back(i);
    }
    return res;

}

int main(){
    vector<int> res;
    res= findAnagrams("baa", "aa");

    cout<<"Res: "<<res.size()<<endl;

    cout<<"Printing the vector:"<<endl;
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" "<<endl;
    return 0;
    /*
    if(isAnagram("A", "B")){
        cout<<"Anagrammed"<<endl;
    }else{
        cout<<"Not an Anagram"<<endl;
    }
     //getMaxStr("abcdabc");
    */

//    printStars(5);
//    int power=powInt(5, 4);
//    cout<<"Power:"<<power<<endl;
/*
    power=powInt(5, -4);
    cout<<"Power:"<<power<<endl;
*/

//    cout<<isPalindrome("MADAM")<<endl;

//    printBinary(25);
// #endif
    return 0;
}
