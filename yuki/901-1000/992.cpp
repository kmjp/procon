#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[202020],B[202020];
int ID[202020],IDnum[202020],IDs[202020];
int num[202020];
ll dp[202020];
int V[202020];
ll mo=1000000007;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]+=v)%=mo,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V[0]=-1<<30;
	FOR(i,N) V[i+1]=1<<30;
	int ma=0;
	FOR(i,N) {
		cin>>A[i];
		x=lower_bound(V,V+N+1,A[i])-V;
		ID[i]=x;
		ma=max(ma,x);
		IDnum[i]=++num[x];
		V[x]=A[i];
	}
	IDs[1]=1;
	for(i=2;i<=ma;i++) IDs[i]=IDs[i-1]+num[i-1];
	B[0]=-1<<30;
	FOR(i,N) B[IDs[ID[i]]+num[ID[i]]-IDnum[i]]=A[i];
	ll ret=0;
	bt.add(0,1);
	FOR(i,N) {
		x=lower_bound(B+IDs[ID[i]-1],B+IDs[ID[i]],A[i])-B;
		x--;
		dp[i]=(bt(x)-bt(IDs[ID[i]-1]-1)+mo)%mo;
		if(ID[i]==ma) ret+=dp[i];
		bt.add(IDs[ID[i]]+num[ID[i]]-IDnum[i],dp[i]);
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
