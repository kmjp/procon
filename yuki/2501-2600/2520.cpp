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
ll M;
ll X[3030],Y[3030],H[3030];
ll L[3030],R[3030],D[3030],U[3030];
ll ret[3030];
int dp[3030];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	map<ll,vector<int>> ev;
	vector<ll> Ys;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>H[i];
		L[i]=(X[i]-Y[i])-(M-H[i]);
		R[i]=(X[i]-Y[i])+(M-H[i]);
		D[i]=(X[i]+Y[i])-(M-H[i]);
		U[i]=(X[i]+Y[i])+(M-H[i]);
		Ys.push_back(D[i]);
		Ys.push_back(U[i]);
	}
	sort(ALL(Ys));
	Ys.erase(unique(ALL(Ys)),Ys.end());
	FOR(i,N) {
		D[i]=lower_bound(ALL(Ys),D[i])-Ys.begin();
		U[i]=lower_bound(ALL(Ys),U[i])-Ys.begin();
		ev[L[i]].push_back(i);
		ev[R[i]].push_back(i);
	}
	ll pre=0;
	FORR2(x,e,ev) {
		FOR(y,Ys.size()-1) {
			(ret[dp[y]]+=1LL*(Ys[y+1]-Ys[y])%mo*((x-pre)%mo))%=mo;
		}
		FORR(i,e) if(R[i]==x) {
			for(y=D[i];y<U[i];y++) dp[y]--;
		}
		FORR(i,e) if(L[i]==x) {
			for(y=D[i];y<U[i];y++) dp[y]++;
		}
		pre=x;
	}
	for(i=1;i<=N;i++) cout<<ret[i]%mo*(mo+1)/2%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
