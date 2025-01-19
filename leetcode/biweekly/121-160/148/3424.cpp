#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------



 class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int i,N=arr.size();
        ll sum=0;
        FOR(i,N) sum+=abs(arr[i]-brr[i]);
        sort(ALL(arr));
        sort(ALL(brr));
        ll sum2=k;
        FOR(i,N) sum2+=abs(arr[i]-brr[i]);
        return min(sum,sum2);
    }
};

