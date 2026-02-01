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

ll A[1010][1010];
ll S[1010];

ll from[1010],to[1010];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return ((__int128)(A.second-C.second)*(B.first-A.first)<=(__int128)(A.second-B.second)*(C.first-A.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(((calc(Q[M],x)>=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int N=nums.size();
        int x,y;
        FOR(x,N) S[x+1]=S[x]+nums[x];
        
        FOR(x,N+1) from[x]=1LL<<60;
        from[0]=0;
        while(k--) {
			FOR(x,N+1) to[x]=1LL<<60;
			
			ConvexHull<ll> ch;
			FOR(x,N) {
				ll p=S[x];
				if(from[x]<1LL<<59) {
					ch.add(-p, from[x]+p*(p-1)/2);
				}
				if(ch.Q.size()) {
					p=S[x+1];
					to[x+1]=ch.query(p)+p*(p+1)/2;
				}
			}
			swap(from,to);
		}
        
		return from[N];
		
    }
};
