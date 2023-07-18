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
ll K;
ll A[202020],B[202020];

int nex[202020];
int P[202020][20],D[202020],T[202020];
int inloop[202020];
int vis[202020];
vector<int> st;

vector<int> cand[202020];

vector<pair<ll,ll>> V[202020];
ll ret[202020];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int first) {
	vis[cur]=first;
	if(vis[nex[cur]]==first) {
		st.push_back(nex[cur]);
		inloop[cur]=nex[cur];
		if(inloop[cur]==cur) return -1;
		return inloop[cur];
	}
	else if(vis[nex[cur]]>=0) {
		return -1;
	}
	else {
		inloop[cur]=dfs(nex[cur],first);
		if(inloop[cur]==-1 || inloop[cur]==cur) return -1;
		return inloop[cur];
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		nex[i]=A[i];
		P[i][0]=A[i];
	}
	FOR(i,N) cin>>B[i];
	MINUS(vis);
	MINUS(inloop);
	FOR(i,N) if(vis[i]==-1) dfs(i,i);
	
	FOR(i,19) FOR(j,N) P[j][i+1]=P[P[j][i]][i];
	FOR(i,N) {
		if(inloop[i]>=0) {
			D[i]=0;
			V[P[i][0]].push_back({K,B[i]});
		}
		else {
			x=i;
			D[i]++;
			for(j=19;j>=0;j--) if(inloop[P[x][j]]==-1) {
				D[i]+=1<<j;
				x=P[x][j];
			}
			T[i]=P[x][0];
			cand[D[i]].push_back(i);
		}
	}
	
	for(i=N;i>=1;i--) FORR(c,cand[i]) {
		ret[c]%=mo;
		if(i==1) {
			V[P[c][0]].push_back({K,B[c]});
		}
		else {
			ret[P[c][0]]+=ret[c]+B[c];
			if(K+1>D[c]) {
				V[T[c]].push_back({K+1-D[c],B[c]});
			}
			else {
				x=c;
				FOR(j,20) if((K+1)&(1<<j)) x=P[x][j];
				ret[x]+=mo-B[c];
			}
		}
	}
	
	FOR(i,N) if(inloop[i]==i) {
		vector<int> Vs;
		Vs.push_back(i);
		while(1) {
			x=P[Vs.back()][0];
			if(x==i) break;
			Vs.push_back(x);
		}
		vector<ll> S(Vs.size()+1);
		ll L=Vs.size();
		FOR(j,Vs.size()) {
			x=Vs[j];
			FORR2(len,val,V[x]) {
				(S[0]+=val*(len/L%mo))%=mo;
				len%=L;
				(S[j]+=val)%=mo;
				if(j+len<=L) {
					(S[j+len]+=mo-val)%=mo;
				}
				else {
					(S[0]+=val)%=mo;
					(S[j+len-L]+=mo-val)%=mo;
				}
			}
		}
		FOR(j,L) {
			if(j) S[j]+=S[j-1];
			S[j]%=mo;
			ret[Vs[j]]=S[j];
		}
	}
	
	ll p=modpow(K);
	FOR(i,N) cout<<(ret[i]%mo*p)%mo<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
