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


int H,W;
int N;

int Y[101010],X[101010],V[101010];
int Q;
int L[101010],R[101010],U[101010],D[101010];
ll ret[101010][2];
vector<int> evC[101010],evE[101010];
const ll mo=1000000007;
int px,py;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>Y[i]>>X[i]>>V[i];
	}
	px=rand()%1000000+3;
	py=rand()%1000000+3;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>D[i]>>L[i]>>U[i]>>R[i];
		evE[D[i]].push_back(i);
		evE[U[i]].push_back(Q+i);
	}
	
	FOR(j,2) {
		FOR(y,H+2) {
			evC[y].clear();
			evE[y].clear();
		}
		FOR(i,N) {
			evC[Y[i]].push_back(i);
		}
		FOR(i,Q) {
			evE[D[i]].push_back(i);
			evE[U[i]+1].push_back(Q+i);
		}
		
		ZERO(bt.bit);
		FOR(y,H+2) {
			FORR(e,evE[y]) {
				if(e<Q) {
					ret[e][j]=bt(R[e])-bt(L[e]-1);
				}
				else {
					e-=Q;
					ll v=(bt(R[e])-bt(L[e]-1))-ret[e][j];
					ret[e][j]=v*modpow(modpow(py),D[e])%mo;
					ret[e][j]=ret[e][j]*modpow(modpow(px),L[e])%mo;
				}
			}
			FORR(e,evC[y]) {
				bt.add(X[e],V[e]*modpow(px,X[e])%mo*modpow(py,Y[e])%mo);
			}
			
		}
		FOR(i,N) {
			Y[i]=H+1-Y[i];
			X[i]=W+1-X[i];
			if(V[i]==6) V[i]=9;
			else if(V[i]==9) V[i]=6;
		}
		FOR(i,Q) {
			L[i]=W+1-L[i];
			R[i]=W+1-R[i];
			swap(L[i],R[i]);
			D[i]=H+1-D[i];
			U[i]=H+1-U[i];
			swap(D[i],U[i]);
			
		}
	}
	FOR(i,Q) {
		ret[i][0]=(ret[i][0]%mo+mo)%mo;
		ret[i][1]=(ret[i][1]%mo+mo)%mo;
		if(ret[i][0]==ret[i][1]) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
