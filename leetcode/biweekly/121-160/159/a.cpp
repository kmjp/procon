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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
		int C[2]={};
		vector<int> A[2];
		int N=nums.size();
		FORR(a,nums) {
			a%=2;
			A[0].push_back(C[a]*2+a);
			A[1].push_back(C[a]*2+(a^1));
			C[a]++;
		}
		ll mi=1LL<<60;
		int i,j;
		FOR(i,2) {
			vector<int> B=A[i];
			sort(ALL(B));
			FOR(j,N) {
				if(B[j]!=j) break;
			}
			if(j<N) continue;
			B=A[i];
			ll sum=0;
			FOR(j,N) {
				sum+=bt(N)-bt(B[j]);
				bt.add(B[j],1);
			}
			mi=min(mi,sum);
			FOR(j,N) bt.add(j,-bt(j));
			
		}
        if(mi==1LL<<60) mi=-1;
        return mi;
    }
};

