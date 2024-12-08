#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;
int is[202020];

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        sort(ALL(nums));
        int ret=nums.size();
        while(nums.size()&&nums.back()>threshold) {
			nums.pop_back();
		}
		uf.reinit(202020);
		int i;
		FOR(i,202020) is[i]=0;
		FORR(a,nums) is[a]++;
		int a,b;
		for(int i=1;i<=threshold;i++) {
			for(a=1;a*i<=threshold;a++) if(is[a*i]) {
				for(b=a+1;1LL*a*b*i<=threshold;b++) if(is[b*i]) {
					if(uf[a*i]!=uf[b*i]) {
						ret--;
						uf(a*i,b*i);
					}
				}
			}
		}
        return ret;
    }
};
