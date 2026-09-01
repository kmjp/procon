#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

int from[5050],to[5050];


class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        
        int i;
        FOR(i,sum+1) from[i]=1<<30;
        from[0]=0;
        FORR(a,nums) {
			int i,j,k;
			FOR(i,sum+1) to[i]=from[i];
			FOR(i,13) FOR(j,13) {
				int v=(a>>i)<<j;
				for(int k=0;k+v<=sum;k++) chmin(to[k+v],from[k]+i+j);
			}
			swap(from,to);
		}
		
		if(from[sum]<1010000) return from[sum];
		return -1;
    }
};


