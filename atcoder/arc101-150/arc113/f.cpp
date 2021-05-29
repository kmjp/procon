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

int N;
int X[22];
ll A[55],B[55][2];
ll P[201][51];
const ll mo=998244353;
int id[2][21];
ll pre[30];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int cmp(pair<ll,ll> L,pair<ll,ll> R) {
	return L.first*R.second<L.second*R.first;
}

ll PP,QQ;
int cmp2(pair<ll,ll>& a,pair<ll,ll>& b) {
	ll ap=a.first*PP+a.second*QQ;
	ll bp=b.first*PP+b.second*QQ;
	if(ap!=bp) return ap<bp;
	return a.first>b.first;
}

vector<ll> hoge(ll p, ll q) {
	PP=p,QQ=q;
	vector<pair<ll,ll>> C;
	int i,j,x;
	FOR(i,N) {
		C.push_back({-i,X[i]});
		C.push_back({-i,X[i+1]});
	}
	sort(ALL(C),cmp2);
	FOR(i,N) {
		FOR(j,C.size()) {
			if(C[j].first==-i&&C[j].second==X[i]) id[i][0]=j;
			if(C[j].first==-i&&C[j].second==X[i+1]) id[i][1]=j;
		}
	}
	
	ll from[44][22][22]={};
	from[0][0][0]=1;
	FOR(i,N) {
		ll to[44][22][22]={};
		ll len=X[i+1]-X[i];
		for(int range=id[i][0];range<id[i][1];range++) {
			ll X=(C[range+1].first-C[range].first+mo)*modpow(len)%mo;
			ll Y=(C[range+1].second-C[range].second+mo)*modpow(len)%mo;
			//•Ê‚Ìrange‚©‚ç—ˆ‚éƒP[ƒX
			for(int order=0;order<=i+1;order++) {
				ll t=0;
				for(int num=0;num<=i+1;num++) {
					for(int sr=0;sr<range;sr++) {
						t+=from[sr][order][num];
					}
				}
				(to[range][order][1]+=t%mo*Y)%=mo;
				(to[range][order+1][1]+=t%mo*X)%=mo;
			}
			for(int order=0;order<=i+1;order++) {
				for(int num=0;num<=i+1;num++) if(from[range][order][num]) {
					(to[range][order][num+1]+=from[range][order][num]*Y%mo*pre[num+1])%=mo;
					(to[range][order+1][num+1]+=from[range][order][num]*X%mo*pre[num+1])%=mo;
				}
			}
		}
		
		swap(from,to);
	}
	
	vector<ll> R(22);
	FOR(i,21) {
		FOR(j,21) {
			FOR(x,44) {
				R[i]+=from[x][i][j];
			}
		}
		R[i]%=mo;
	}
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=21;i++) pre[i]=modpow(i);
	
	cin>>N;
	FOR(i,N+1) cin>>X[i];
	FOR(i,N) {
		A[i]=-i;
		B[i][0]=X[i];
		B[i][1]=X[i+1];
	}
	vector<pair<ll,ll>> cand;
	FOR(y,N) FOR(x,y) {
		cand.push_back({B[y][0]-B[x][0],A[x]-A[y]});
		cand.push_back({B[y][0]-B[x][1],A[x]-A[y]});
		cand.push_back({B[y][1]-B[x][0],A[x]-A[y]});
		cand.push_back({B[y][1]-B[x][1],A[x]-A[y]});
	}
	FORR2(a,b,cand) {
		ll g=__gcd(a,b);
		a/=g;
		b/=g;
	}
	
	sort(ALL(cand),cmp);
	cand.erase(unique(ALL(cand)),cand.end());
	ll ret=0;
	vector<ll> A;
	FOR(i,cand.size()) if(i) {
		ll a=cand[i-1].first*modpow(cand[i-1].second)%mo;
		ll b=cand[i].first*modpow(cand[i].second)%mo;
		ll x1=1,x2=1;
		int order=0;
		A=hoge(cand[i].first,cand[i].second);
		FORR(p,A) {
			x1=x1*a%mo;
			x2=x2*b%mo;
			order++;
			(ret+=p*(x2+mo-x1)%mo*modpow(order))%=mo;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
