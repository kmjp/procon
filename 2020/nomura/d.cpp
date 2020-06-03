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
int P[5050];
const ll mo=1000000007;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<5050> uf;

int fix[5050],dyn[5050];
ll p[5050][5050];
ll num[5050];
ll fact[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	FOR(i,5010) {
		fact[i+1]=fact[i]*(i+1)%mo;
		p[i][0]=1;
		FOR(j,5010) p[i][j+1]=p[i][j]*i%mo;
	}
	
	
	cin>>N;
	ll pat=N-1;
	FOR(i,N) {
		cin>>P[i];
		if(P[i]>0) {
			P[i]--;
			uf(i,P[i]);
		}
	}
	int nd=0;
	FOR(i,N) {
		if(P[i]==-1) dyn[uf[i]]++, nd++;
		else fix[uf[i]]++;
	}
	
	int e=0;
	FOR(i,N) if(dyn[i]+fix[i]) {
		if(dyn[i]) e+=dyn[i]+fix[i];
		else e+=fix[i]-1;
	}
	pat=p[N-1][nd]*e%mo;
	
	num[0]=1;
	FOR(i,N) if(dyn[i]) {
		pat-=fix[i]*p[N-1][nd-1]%mo;
		for(j=N;j>=0;j--) {
			(num[j+1]+=num[j]*(dyn[i]+fix[i]))%=mo;
		}
	}
	
	for(i=2;i<=N;i++) if(num[i]) {
		pat-=num[i]*fact[i-1]%mo*p[N-1][nd-i]%mo;
	}
	
	pat=(pat%mo+mo)%mo;
	
	cout<<pat<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
