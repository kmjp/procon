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

int N,K;
int C[1010];
int A[1010][6];
ll X[1010],Y[1010];
const ll mo=998244353;
int ins[1010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

bool cmp(pair<pair<ll,ll>,pair<int,int>>& L,pair<pair<ll,ll>,pair<int,int>>& R) {
	ll ay=L.first.first;
	ll ax=L.first.second;
	ll by=R.first.first;
	ll bx=R.first.second;
	return ay*bx<by*ax;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>C[i];
	FOR(i,N) {
		FOR(j,6) {
			cin>>A[i][j];
			X[i]+=A[i][j];
			Y[i]+=1LL*A[i][j]*A[i][j];
		}
		Y[i]=Y[i]*6-C[i]*36-X[i]*X[i];
	}
	
	FOR(i,N) {
		FOR(j,N-1) {
			if(X[j]>X[j+1]||(X[j]==X[j+1]&&Y[j]>Y[j+1])) {
				swap(X[j],X[j+1]);
				swap(Y[j],Y[j+1]);
			}
		}
	}
	ll SX=0,SY=0;
	FOR(i,K) SX+=X[N-1-i],SY+=Y[N-1-i], ins[N-1-i]=1;
	ll ret=SX*SX+SY;
	vector<pair<pair<ll,ll>,pair<int,int>>> V;
	FOR(j,N) FOR(i,j) if(Y[i]>Y[j]) {
		V.push_back({{Y[j]-Y[i],X[j]-X[i]},{i,j}});
	}
	sort(ALL(V),cmp);
	FORR2(a,b,V) {
		x=b.first;
		y=b.second;
		if(ins[x]==0&&ins[y]==1) {
			SX+=X[x]-X[y];
			SY+=Y[x]-Y[y];
			ret=max(ret,SX*SX+SY);
			
			ins[x]=1;
			ins[y]=0;
		}
		
	}
	
	cout<<(ret%mo*modpow(36)%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
