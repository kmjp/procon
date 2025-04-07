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

ll V[101010];

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
		set<int> A;
		int i,N=nums.size();
		set<pair<ll,int>> S;
		int ng=0,ret=0;
		
		FOR(i,N) {
			V[i]=nums[i];
			A.insert(i);
		}
		A.insert(-1);
		A.insert(N);
		
		FOR(i,N-1) {
			S.insert({V[i]+V[i+1],i});
			if(V[i]>V[i+1]) ng++;
		}
		while(ng) {
			ret++;
			auto p=S.begin();
			int b=p->second;
			S.erase(p);
			auto it=A.find(b);
			int a=*prev(it);
			int c=*next(it);
			int d=*next(next(it));
			if(a>=0) {
				if(V[a]>V[b]) ng--;
				S.erase({V[a]+V[b],a});
			}
			if(d<N) {
				if(V[c]>V[d]) ng--;
				S.erase({V[c]+V[d],c});
			}
			if(V[b]>V[c]) ng--;
			V[b]+=V[c];
			A.erase(c);
			if(a>=0) {
				if(V[a]>V[b]) ng++;
				S.insert({V[a]+V[b],a});
			}
			if(d<N) {
				if(V[b]>V[d]) ng++;
				S.insert({V[b]+V[d],b});
			}
		}
		return ret;
        
    }
};
