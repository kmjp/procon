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
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

BIT<ll,20> num,sum;

class Solution {
public:
	set<int> P;
	int N;
	void add(int p) {
		if(p<=0||p>=N-1) return;
		if(P.count(p)) return;
		P.insert(p);
		auto it=P.lower_bound(p);
		int x=*it;
		int y=*next(it);
		num.set(x,1);
		sum.set(x,1LL*(y-x+1)*(y-x+2)/2);
		if(it!=P.begin()) {
			x=*prev(it);
			y=*it;
			sum.set(x,1LL*(y-x+1)*(y-x+2)/2);
		}

	}
	void del(int p) {
		if(p<=0||p>=N-1) return;
		if(P.count(p)==0) return;
		num.set(p,0);
		sum.set(p,0);
		P.erase(p);
		auto it=P.lower_bound(p);
		if(it!=P.begin()) {
			int x=*prev(it);
			int y=*it;
			sum.set(x,1LL*(y-x+1)*(y-x+2)/2);
		}
		
	}
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
		N=nums.size();
		int i;
		FOR(i,N+1) {
			num.set(i,0);
			sum.set(i,0);
		}
		P={N};
		for(i=1;i<N-1;i++) if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) {
			P.insert(i);
			num.add(i,1);
		}
		auto it=P.begin();
		int x,y;
		while(*it!=N) {
			x=*next(it)-*it;
			sum.add(*it,1LL*(x+1)*(x+2)/2);
			it++;
		}
		
		vector<ll> ret;
		FORR(q,queries) {
			if(q[0]==1) {
				int L=q[1],R=q[2];
				ll s=0;
				auto it=P.lower_bound(L+1);
				if(*it<R) {
					s=1LL*(*it-L+1)*(*it-L+2)/2;
					auto it2=prev(P.lower_bound(R));
					s+=1LL*(R-*it2+1)*(R-*it2+2)/2;
					
					s+=sum(*it2-1)-sum(L);
					s-=num(*it2-1)-num(L)+1;
					s=(1LL*(R-L+1)*(R-L+2)/2)-s;
				}
				ret.push_back(s);
			}
			else {
				int X=q[1],V=q[2];
				del(X);
				del(X-1);
				del(X+1);
				nums[X]=V;
				if(X>0&&X+1<N&&nums[X]>nums[X-1]&&nums[X]>nums[X+1]) add(X);
				if(X-1>0&&nums[X-1]>nums[X-2]&&nums[X-1]>nums[X]) add(X-1);
				if(X+1<N-1&&nums[X+1]>nums[X]&&nums[X+1]>nums[X+2]) add(X+1);
				
			}
		}
		return ret;
		
		
        
    }
};
