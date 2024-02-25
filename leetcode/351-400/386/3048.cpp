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
		int ma[2020];
		int i;
		FOR(i,N) ma[i]=-1;
		FOR(i,M) if(v-i>0) {
			chmax(ma[B[(v-1-i)%M]-1],v-i);
		}
		vector<pair<int,int>> V;
		FOR(i,N) {
			if(ma[i]==-1) return 0;
			V.push_back({ma[i],A[i]});
		}
		sort(ALL(V));
		int pre=0,sp=0;
		FORR(v,V) {
			sp+=v.first-pre-1;
			if(v.second>sp) return 0;
			sp-=v.second;
			pre=v.first;
		}
		return 1;
			
	}
	
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		A=nums;
		B=changeIndices;
		N=A.size();
		M=B.size();
		
		ll ret=M;
		if(ok(M)==0) return -1;
		int i;
		for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		return ret;
    }
};
