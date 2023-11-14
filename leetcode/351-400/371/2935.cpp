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

vector<int> V;

class Solution {
public:
	int hoge(int L,int R,int v,int cv,int d) {
		if(d==-1) return V[L];
		
		int M=lower_bound(V.begin()+L,V.begin()+R,cv+(1<<d))-V.begin();
		if(L==M) return hoge(M,R,v,cv+(1<<d),d-1);
		if(M==R) return hoge(L,M,v,cv,d-1);
		
		if(v&(1<<d)) return hoge(L,M,v,cv,d-1);
		else return hoge(M,R,v,cv+(1<<d),d-1);
		
		
		
	}
    int maximumStrongPairXor(vector<int>& nums) {
		int N=nums.size();
		sort(ALL(nums));
		V=nums;
		int ma=0;
		for(int L=0,R=0;L<N;L++) {
			while(R<N&&V[R]<=2*V[L]) R++;
			ma=max(ma,V[L]^hoge(L,R,V[L],0,19));
		}
        return ma;
    }
};
