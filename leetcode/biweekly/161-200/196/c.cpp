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


int F[2020][3];
int T[2020][3];

class Solution {
public:
    int minOperations(vector<int>& nums) {
		
		int i,j;
		for(i=1;i<=2000;i++) {
			F[i][0]=abs(i-nums[0]);
			F[i][1]=1<<30;
			F[i][2]=1<<30;
		}
		for(i=1;i<nums.size();i++) {
			int v=nums[i];
			for(j=1;j<=2000;j++) {
				T[j][0]=F[j][0];
				T[j][1]=F[j][1];
				T[j][2]=F[j][2];
			}
			// go up
			int mi=1<<30;
			for(j=1;j<=2000;j++) {
				F[j][0]=mi+abs(j-v);
				F[j][1]=mi+abs(j-v);
				mi=min(mi,T[j][0]);
			}
			mi=1<<30;
			for(j=2000;j>=1;j--) {
				F[j][2]=mi+abs(j-v);
				mi=min(mi,T[j][1]);
				mi=min(mi,T[j][2]);
			}
		}
		int ret=1<<30;
		for(j=2000;j>=1;j--) ret=min(ret,F[j][2]);
		if(ret>1<<29) ret=-1;
		return ret;
		
        
    }
};


