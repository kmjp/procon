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

int C[101010];
int D[101010];
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
		UF<101010> uf;
		ZERO(C);
		ZERO(D);
		if(nums.size()==1) return 1;
        FORR(n,nums) C[n]++;
        int i;
        for(i=2;i<=100000;i++) if(D[i]==0) {
			int pre=0;
			for(int j=i;j<=100000;j+=i) {
				D[j]=1;
				if(C[j]) {
					if(pre) uf(pre,j);
					pre=j;
				}
			}
		}
		int sum=0;
		FOR(i,101000) sum+=C[i]>0;
		if(C[1]>1) return 0;
		return sum==uf.count(nums[0]);
        
    }
};
