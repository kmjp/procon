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

int C[101010];

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
UF<101010> uf;

class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
		int i;
		FOR(i,n) C[i]=0;
		uf.reinit(n);
		FORR(e,edges) {
			C[e[0]]++;
			C[e[1]]++;
			uf(e[0],e[1]);
		}
		FOR(i,n) if(uf[i]!=i) C[uf[i]]+=C[i];
		vector<int> A[2];
		FOR(i,n) if(uf[i]==i) {
			if(uf.count(i)*2==C[i]) A[1].push_back(uf.count(i));
			else A[0].push_back(uf.count(i));
		}
		ll ret=0;
		int cur=n;
		sort(ALL(A[0]));
		sort(ALL(A[1]));
		reverse(ALL(A[0]));
		reverse(ALL(A[1]));
		FORR(a,A[1]) {
			int L=cur,R=cur;
			cur--;
			FOR(i,a-1) {
				ret+=1LL*R*cur;
				R=cur--;
				swap(L,R);
			}
			ret+=1LL*L*R;
		}
		FORR(a,A[0]) {
			int L=cur,R=cur;
			cur--;
			FOR(i,a-1) {
				ret+=1LL*R*cur;
				R=cur--;
				swap(L,R);
			}
		}
		return ret;
		
        
    }
};
