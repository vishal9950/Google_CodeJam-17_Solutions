/*
Problem C. Bathroom Stalls

A certain bathroom has N + 2 stalls in a single row; the stalls on the left and right ends are permanently occupied by the bathroom guards. The other N stalls are for users.

Whenever someone enters the bathroom, they try to choose a stall that is as far from other people as possible. To avoid confusion, they follow deterministic rules: For each empty stall S, they compute two values LS and RS, each of which is the number of empty stalls between S and the closest occupied stall to the left or right, respectively. Then they consider the set of stalls with the farthest closest neighbor, that is, those S for which min(LS, RS) is maximal. If there is only one such stall, they choose it; otherwise, they choose the one among those where max(LS, RS) is maximal. If there are still multiple tied stalls, they choose the leftmost stall among those.

K people are about to enter the bathroom; each one will choose their stall before the next arrives. Nobody will ever leave.

When the last person chooses their stall S, what will the values of max(LS, RS) and min(LS, RS) be?

Solving this problem

This problem has 2 Small datasets and 1 Large dataset. You must solve the first Small dataset before you can attempt the second Small dataset. You will be able to retry either of the Small datasets (with a time penalty). You will be able to make a single attempt at the Large, as usual, only after solving both Small datasets.

Input

The first line of the input gives the number of test cases, T. T lines follow. Each line describes a test case with two integers N and K, as described above.

Output

For each test case, output one line containing Case #x: y z, where x is the test case number (starting from 1), y is max(LS, RS), and z is min(LS, RS) as calculated by the last person to enter the bathroom for their chosen stall S.

Limits

1 ≤ T ≤ 100.
1 ≤ K ≤ N.
Small dataset 1

1 ≤ N ≤ 1000.
Small dataset 2

1 ≤ N ≤ 106.
Large dataset

1 ≤ N ≤ 1018.
Sample


Input
5
4 2
5 2
6 2
1000 1000
1000 1

Output

Case #1: 1 0
Case #2: 1 0
Case #3: 1 1
Case #4: 0 0
Case #5: 500 499

In Case #1, the first person occupies the leftmost of the middle two stalls, leaving the following configuration (O stands for an occupied stall and . for an empty one): O.O..O. Then, the second and last person occupies the stall immediately to the right, leaving 1 empty stall on one side and none on the other.

In Case #2, the first person occupies the middle stall, getting to O..O..O. Then, the second and last person occupies the leftmost stall.

In Case #3, the first person occupies the leftmost of the two middle stalls, leaving O..O...O. The second person then occupies the middle of the three consecutive empty stalls.

In Case #4, every stall is occupied at the end, no matter what the stall choices are.

In Case #5, the first and only person chooses the leftmost middle stall.

*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    //freopen("C-small-1-attempt1.in","r",stdin);
    //freopen("C-small-1-attempt1.out","w",stdout);
    long t;
    cin >> t;
    for(long c=1;c<=t;c++){
        long n,k;
        cin >> n >> k;
        long s[n];
        vector<long> index;
        vector<long> dist;
        long mid = (n-1)/2;
        s[mid]=1;
       // cout << "mid: " << mid << " s[mid]: " << s[mid] << endl;
        index.push_back(n);
        index.push_back(-1);
        index.push_back(mid);
        sort(index.begin(),index.end());
        /*for(int i=0;i<index.size();i++)
            cout << index[i] << " ";
        cout << endl;*/
        dist.push_back(mid);
        dist.push_back(n-mid-1);
        long maxi;
        long z;
        long in = dist[0]>=dist[1]?0:1;
        //cout << "in: " << in << endl;
        k--;
        if(k==0){
                in =1;
                long ls = index[in]-index[in-1]-1;
        long rs = index[in+1]-index[in]-1;
        if(ls>=rs){
            cout << "Case #" << c << ": " << ls << " " << rs << endl;
        }
        else{
            cout << "Case #" << c << ": " << rs << " " << ls << endl;
        }
        continue;
        }
        /*else if(k>n/2){
                cout << "Case #" << c << ": " << 0 << " " << 0 << endl;
                continue;
        }*/
        else{
        for(long i=0;i<k;i++){
            //if(i==0){
                //cout << "in: " << in << " index[in]: " << index[in] << endl;
                mid = index[in] + (index[in+1]-index[in])/2;
                s[mid]=1;
                //cout << "mid: " << mid << " s[mid]: " << s[mid] << endl;
                index.push_back(mid);
                sort(index.begin(),index.end());
                for(z=0;z<index.size();z++){
                    if(index[z]==mid)
                        break;
                }
                /*for(int k=0;k<index.size();k++)
                    cout << index[k] << " ";
                cout << endl;*/
                dist.clear();
                for(long j=1;j<index.size();j++){
                        //cout << "j: " << j << " index[j]: " << index[j] << endl;
                        long temp = index[j]-index[j-1]-1;
                        //cout << "temp: " << temp << endl;
                        dist.push_back(temp);
                }
                /*for(int k=0;k<dist.size();k++)
                    cout << dist[k] << " ";
                cout << endl;*/
                maxi = dist[0];
                in = 0;
                for(long j=1;j<dist.size();j++){
                    if(dist[j]>maxi){
                        maxi = dist[j];
                        in = j;
                    }
                }
                //cout << "in: " << in << " maxi: " << maxi << endl;
            /*}
            else{
                h
            }*/
        }
        }
        long ls = index[z]-index[z-1]-1;
        long rs = index[z+1]-index[z]-1;
        if(ls>=rs){
            cout << "Case #" << c << ": " << ls << " " << rs << endl;
        }
        else{
            cout << "Case #" << c << ": " << rs << " " << ls << endl;
        }
    }
}
