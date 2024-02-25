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



class Solution {
public:
	vector<int> A,B;
	int N,M;
	
	int ok(int v) {
		if(v<N) return 0;
		
		ll from[5050],to[5050];
		int x,y;
		FOR(x,M+1) from[x]=1LL<<60;
		from[0]=0;
		FOR(x,N) from[0]+=A[x]+1;
		for(x=v-1;x>=0;x--) {
			FOR(y,v+1) to[y]=1LL<<60;
			FOR(y,v+1) if(from[y]<=1LL<<59) {
				if(B[x]>=0&&y) chmin(to[y-1],from[y]-(A[B[x]]+1));
				chmin(to[y+1],from[y]);
			}
			swap(from,to);
		}
		
		FOR(x,v+1) if(from[x]<=x) return 1;
		return 0;
			
	}
	
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		A=nums;
		B=changeIndices;
		N=A.size();
		M=B.size();
		set<int> did;
		FORR(b,B) {
			b--;
			if(did.count(b)==0) did.insert(b);
			else b=-1;
		}
		
		int ret=M;
		if(ok(ret)==0) return -1;
		int i;
		for(i=13;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		return ret;
    }
};
