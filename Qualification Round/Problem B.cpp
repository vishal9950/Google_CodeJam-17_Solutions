/*
Problem B. Tidy Numbers
Tatiana likes to keep things tidy. Her toys are sorted from smallest to largest, her pencils are
sorted from shortest to longest and her computers from oldest to newest. One day, when practicing her
counting skills, she noticed that some integers, when written in base 10 with no leading zeroes, have 
theirtheir digits sorted in non-decreasing order. Some examples of this are 8, 123, 555, and 224488. She decided to call these numbers tidy. Numbers that do not have this property, like 20, 321, 495 and 999990, are not tidy.

She just finished counting all positive integers in ascending order from 1 to N. What was the last tidy number she counted?

Input

The first line of the input gives the number of test cases, T. T lines follow. Each line describes a test case with a single integer N, the last number counted by Tatiana.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the last tidy number counted by Tatiana.

Limits

1 ≤ T ≤ 100.

Small dataset

1 ≤ N ≤ 1000.

Large dataset

1 ≤ N ≤ 1018.

Sample


Input 
 4 
132 
1000 
7 
111111111111111110

Output 
  Case #1: 129
 Case #2: 999
 Case #3: 7
 Case #4: 99999999999999999 




*/


#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
  //  freopen("B-large.in","r",stdin);
  //  freopen("B-large.out","w",stdout);
    int t;
    cin >> t;
    for(int c=1;c<=t;c++){
        string s;
        cin >> s;
        int flag;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]<=s[i+1])
                continue;
            else{
                s[i]--;
                for(int j=i+1;j<s.length();j++){
                    s[j]='9';
                }
                for(int j=i-1;j>=0;j--){
                    if(s[j]<=s[j+1]){
                        flag=1;
                        break;
                    }
                    else{
                        s[j]--;
                        s[j+1]='9';
                    }
                }
            }
            if(flag==1)
                break;
        }
        int f=1;
        cout << "Case #" << c << ": ";
        for(int i=0;i<s.length();i++){
            if(s[i]=='0' && f==1){
                continue;
            }
            else{
                cout << s[i];
                f=0;
            }
        }
        cout << endl;
    }
}
