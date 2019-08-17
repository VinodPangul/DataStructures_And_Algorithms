#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <stack>
#include <vector>

using namespace std;

int fact(int num){
    if(num == 0)
        return 1;
    else
        return num * fact(num-1);
}

int getLargest(const int arr[], int lidx, int hidx){
    int max=0;
    if(lidx == hidx){
        return arr[lidx];
    }else{
        max=getLargest(arr, lidx+1, hidx);

        if(max <= arr[lidx]) {
            max=arr[lidx];
            return max;
        }else
            return max;

    }
}

int getFib(int n, int a, int b){
    if(n==1) return a;
    else if(n==2) return b;
    else
        return getFib(n-1, a, b) + getFib(n-2, a, b);

}

void printToOtherBase(int num, int base){
    if(num>0){
        printToOtherBase(num/base, base);
        cout<<num%base<<" ";
    }
}

void printStars(int n){
    if(n==0){
        //cout<<"*"<<endl;
    }else{
        for(int i=n; i>0; i--)
            cout<<"*";
        cout<<endl;
        printStars(n-1);
        for(int i=0; i<n; i++)
            cout<<"*";
        cout<<endl;
    }
}

void reverseStars(int start, int n){

    if(start <= n){
        cout << setw(n-start + 1) << " ";
//        for(int i=1; i<=n-start; i++) {
//            cout << " ";
//        }
        for(int i=1; i<=start; i++) {
            cout << " * ";
        }
        cout<<endl;
        reverseStars(start+1, n);


        if (start != n)
        {
            cout << setw(n - start + 1) << "  ";

            for (int j = 1; j <= start; j++)
                cout << " * ";
            cout << endl;
        }

//        cout << setw(n-start + 1) <<" ";
////        for(int i=0; i<=n-start; i++) {
////            cout<<" ";
////        }
//        for(int i=1; i<start; i++) {
//            cout<<" * ";
//        }
//        cout<<endl;
    }
}


int countVowel(string s){

    int count=0;
    int sum=0;
    int i=0;
    if(s.size() == 0){
        return 0;
    }else{
        string sub=s.substr(1,s.size());
        count += countVowel(sub);
        if(s[0]== 'a' ||  s[0]== 'e' || s[0]== 'o' || s[0]== 'u' || s[0]== 'i' )
            count++;

        return count;
    }
}

int sumOfArray(int a[], int size){

    int sum=0;
   if(size == 1){
        return a[size-1];
   }else{
       sum += sumOfArray(a+1, size-1);

       sum += a[0];
       return sum;
   }
}

bool isPalindrome(string s){
    if(s.size() < 2){
        return true;
    }else{
        char ch1=s[0];
        char ch2=s[s.size()-1];
        if(ch1 != ch2 ) return false;
        else{
            string sub=s.substr(1, s.size()-2);
            return isPalindrome(sub);
        }
    }
}

void printReverse(string s){
    if(s.size()==1){
        cout<<s[0];
    }else{
        string sub=s.substr(1, s.size()-1);
        printReverse(sub);
        cout<<s[0];
    }
}

double calcPower(double x, double y){
    if(y==1){
        return x;
    }else{
        if(y>0) return x*calcPower(x,y-1);
    }
}

double getGcd(int x, int y){
    if(y==0) return x;
    else{
        return getGcd(y, x%y);
    }
}


#if 0
bool find132pattern(vector<int>& nums) {
    /*
     get an element from vector
         push if stack is empty
         else check stack.top < element and element > vector[elemenet + 1 ]
      */

    stack<int> st;
    int j = 0;
    int N = nums.size();
    for (int x : nums) {
        //cout<<"x:"<<x<<endl;
        //cout<<"st size"<<st.size();
        if (st.empty()) st.push(x);
        else if (st.top() < x && j < N && x > nums[j + 1] && st.top() < nums[j + 1]) {
            return true;
        } else {
            if (st.top() > x) {
                //st.pop();
                st.push(x);
            }
        }
        j++;
    }
    return false;
}
#endif

bool find132pattern(vector<int>& nums) {
    stack<int> stk;
    int s2 = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] < s2)
            return true;

        while (!stk.empty() && stk.top() < nums[i]) {
            s2 = stk.top();
            stk.pop();
        }
        stk.push(nums[i]);
    }
    return false;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    ListNode *current=head, *slow=head, *fast=head, *prev=NULL;

    while(fast && fast->next){
        if(fast)
            prev=fast;
        else
            prev=fast->next;

        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode *tmp=prev;
    while(current != tmp){
        prev->next=current->next;
        current->next=current->next->next;
        prev=prev->next;
    }

    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

#if 0
    cout<<"Factorial is:"<<fact(5)<<endl;

    int arr[]={12, 2 , 300, 4};
    cout<<"arr"<<arr[3]<<endl;
    cout<<"Largest element:"<<getLargest(arr,0,3);

    cout<<"getFib"<<endl;
    cout<<getFib(15, 1, 1);

    cout<<"Binary No is:";
    printToOtherBase(12,2);

    cout<<"Octal No is:";
    printToOtherBase(12,8);
#endif

    //printStars(10);
    cout<<endl;
    //reverseStars(1,4);

    //cout<<countVowel("aeighoaaaaaaaaaa");
    //int arr[9]={1, 2, 3, 4, 5};
    //cout<<sumOfArray(arr, 5);

    //cout<<"IsPalindrome?:"<<isPalindrome("madam")<<endl;
    //cout<<"IsPalindrome?:"<<isPalindrome("ABCDCBA")<<endl;

    //cout<<"Print this string in reverse:"<<endl;
    //printReverse("ABCDEFGHI");

//    cout<<"Power:"<<calcPower(2,3);
//    cout<<"Power:"<<1/calcPower(2,3);
//
//    cout<<"GCD:"<<getGcd(36, 12);

//    vector<int> v;
//    v = {3, 5, 0, 3, 4};
//    cout<<"Value Bool: "<<find132pattern(v);


    ListNode n=
    return 0;
}