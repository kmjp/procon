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

ll X[3],Y[3];
ll W,H;
ll mo=1000000007;
ll A[404040],B[404040];
ll CX[80404],BS[1200000];
vector<pair<ll,int>> D[80404];

const int prime_max = 1100000;
vector<int> prime;
int NP,divp[prime_max];

map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void gendivs_sub(vector<pair<ll,ll>>& ret,vector<pair<ll,int>>& D,int cur,ll mul,ll tot) {
	if(cur==D.size()) {
		ret.push_back({mul,tot});
		return;
	}
	int i;
	gendivs_sub(ret,D,cur+1,mul,tot);
	tot*=D[cur].first-1;
	for(int i=1;i<=D[cur].second;i++) {
		mul*=D[cur].first;
		gendivs_sub(ret,D,cur+1,mul,tot);
		tot*=D[cur].first;
	}
}

vector<pair<ll,ll>> gendivs(vector<pair<ll,int>> D) {
	vector<pair<ll,ll>> ret;
	gendivs_sub(ret,D,0,1,1);
	return ret;
}

ll hoge(ll X,ll Y) {
	X-=W-1;
	Y-=H-1;
	int x,y;
	
	FOR(x,2*W-1) CX[x]=X+x, D[x].clear();
	FORR(p,prime) {
		for(int cur=(X+p-1)/p*p-X;cur<2*W-1;cur+=p) {
			D[cur].push_back({p,0});
			while(CX[cur]%p==0) {
				CX[cur]/=p;
				D[cur].back().second++;
			}
		}
	}
	
	for(x=1;x<=prime_max;x++) {
		BS[x]=0;
		for(int cur=(Y+x-1)/x*x-Y;cur<2*H-1;cur+=x) BS[x]+=B[cur];
		BS[x]%=mo;
	}
	FOR(x,2*W-1) if(CX[x]>1) D[x].push_back({CX[x],1});
	
	ll ret=0;
	FOR(x,2*W-1) {
		auto divs=gendivs(D[x]);
		FORR(d,divs) {
			ll T=0;
			if(d.first<=prime_max) {
				T=BS[d.first];
			}
			else {
				for(ll cur=(Y+d.first-1)/d.first*d.first-Y;cur<2*H-1;cur+=d.first) T+=B[cur];
			}
			ret+=A[x]*T%mo*d.second%mo;
		}
	}
	return ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	FOR(i,3) cin>>X[i]>>Y[i];
	X[1]-=X[0];
	X[2]-=X[0];
	Y[1]-=Y[0];
	Y[2]-=Y[0];
	
	cin>>W>>H;
	FOR(i,2*W-1) A[i]=(i<=W-1?i+1:2*W-1-i);
	FOR(i,2*H-1) B[i]=(i<=H-1?i+1:2*H-1-i);
	
	ll S=((X[1]%mo)*(Y[2]%mo)%mo-(X[2]%mo)*(Y[1]%mo)%mo+mo)%mo*(mo+1)/2%mo;
	ll ret=(S+1)*W%mo*W%mo*W%mo*H%mo*H%mo*H%mo;
	ret += mo-W*H*hoge(X[1],Y[1])%mo*(mo+1)/2%mo;
	ret += mo-W*H*hoge(X[2],Y[2])%mo*(mo+1)/2%mo;
	ret += mo-W*H*hoge(X[1]-X[2],Y[2]-Y[1])%mo*(mo+1)/2%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
