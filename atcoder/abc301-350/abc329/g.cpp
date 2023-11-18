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

int N,M,K;
int P[21][101010];
int D[101010];
vector<int> E[101010];
int id,L[202020],R[202020];
const ll mo=998244353;

int up[202020],upLfin[202020],upRfin[202020];
int downL[202020],downR[202020],downfin[202020];
int lef[202020];
int ri[202020];
int S[202020],T[202020];
int start[202020],fin[202020];
int Sstart[202020],Sfin[202020];

vector<ll> dfs2(int cur) {
	vector<ll> ret(K+1);
	int i;
	if(E[cur].empty()) {
		FOR(i,K+1) {
			if(i>=downfin[cur]&&i-downfin[cur]+up[cur]<=K) {
				ret[i]=1;
			}
		}
	}
	else {
		if(E[cur].size()==1) {
			E[cur].push_back(N);
			lef[cur]=1;
		}
		
		int s=E[cur][0];
		int t=E[cur][1];
		vector<ll> SS=dfs2(s);
		vector<ll> TT=dfs2(t);
		
		if(ri[cur]==0) {
			//ç∂Ç©ÇÁ
			FOR(i,K+1) {
				if(i<downfin[cur]) continue;
				int tar=i-downfin[cur]+downL[cur];
				if(tar<0||tar>K) continue;
				ll a=SS[tar];
				tar+=Sstart[s]-Sfin[s];
				if(tar<0||tar>K) continue;
				tar+=-upLfin[cur]+downR[cur];
				if(tar<0||tar>K) continue;
				a=a*TT[tar]%mo;
				tar+=Sstart[t]-Sfin[t];
				if(tar<0||tar>K) continue;
				tar+=-upRfin[cur]+up[cur];
				if(tar>=0&&tar<=K) ret[i]+=a;
			}
		}
		if(lef[cur]==0) {
			//âEÇ©ÇÁ
			FOR(i,K+1) {
				if(i<downfin[cur]) continue;
				int tar=i-downfin[cur]+downR[cur];
				if(tar<0||tar>K) continue;
				ll a=TT[tar];
				tar+=Sstart[t]-Sfin[t];
				if(tar<0||tar>K) continue;
				tar+=-upRfin[cur]+downL[cur];
				if(tar<0||tar>K) continue;
				a=a*SS[tar]%mo;
				tar+=Sstart[s]-Sfin[s];
				if(tar<0||tar>K) continue;
				tar+=-upLfin[cur]+up[cur];
				if(tar>=0&&tar<=K) ret[i]+=a;
			}
		}
	}
	FORR(r,ret) r%=mo;
	return ret;
}

void dfs(int cur) {
	L[cur]=id++;
	Sstart[cur]=start[cur];
	Sfin[cur]=fin[cur];
	FORR(e,E[cur]) {
		dfs(e);
		Sstart[cur]+=Sstart[e];
		Sfin[cur]+=Sfin[e];
	};
	R[cur]=id++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N-1) {
		cin>>P[0][i+1];
		P[0][i+1]--;
		D[i+1]=D[P[0][i+1]]+1;
		E[P[0][i+1]].push_back(i+1);
	}
	FOR(i,20) {
		FOR(j,N) P[i+1][j]=P[i][P[i][j]];
	}
	
	FOR(i,M) {
		cin>>S[i]>>T[i];
		S[i]--,T[i]--;
		start[S[i]]++;
		fin[T[i]]++;
	}
	dfs(0);
	FOR(i,M) {
		if(L[S[i]]<L[T[i]]&&L[T[i]]<R[S[i]]) {
			if(R[E[S[i]][0]]<=L[T[i]]) {
				downR[S[i]]++;
			}
			else {
				downL[S[i]]++;
			}
			downfin[T[i]]++;
		}
		else if(L[T[i]]<L[S[i]]&&L[S[i]]<R[T[i]]) {
			up[S[i]]++;
			if(R[E[T[i]][0]]<=L[S[i]]) {
				upRfin[T[i]]++;
			}
			else {
				upLfin[T[i]]++;
			}
		}
		else {
			x=S[i],y=T[i];
			up[x]++;
			FOR(j,20) {
				if(D[x]>D[y]&&((D[x]-D[y])&(1<<j))) x=P[j][x];
				if(D[y]>D[x]&&((D[y]-D[x])&(1<<j))) y=P[j][y];
			}
			for(j=19;j>=0;j--) if(P[j][x]!=P[j][y]) {
				x=P[j][x];
				y=P[j][y];
			}
			k=P[0][x];
			if(E[k][0]==x) {
				lef[k]++;
			}
			else {
				ri[k]++;
			}
			downfin[T[i]]++;
		}
	}
	auto R=dfs2(0);
	cout<<R[0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
