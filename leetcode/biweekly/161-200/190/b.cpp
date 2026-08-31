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

int L[1010];
int R[1010];

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
		int N=nums.size();
		int ma=0;
		int i,j;
		FOR(i,N+1) {
			vector<int> A;
			FOR(j,N) if(j!=i) A.push_back(nums[j]);
			L[0]=A[0];
			for(j=1;j<A.size();j++) L[j]=__gcd(L[j-1],A[j]);
			R[A.size()-1]=A[A.size()-1];
			for(j=(int)A.size()-2;j>=0;j--) R[j]=__gcd(R[j+1],A[j]);
			int ok=0;
			FOR(j,A.size()-1) if(L[j]==R[j+1]) ok++;
			ma=max(ma,ok);
			
			
		}
		return ma;
		
        
    }
};


