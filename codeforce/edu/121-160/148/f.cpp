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

ll N,K,X,M;
ll L[2020],R[2020];
ll A[2020],B[2020];
vector<pair<ll,ll>> V;
ll len[4040][2020];
int opt[2020][2020];
ll le[4040][2020];

ll from[2020][2020];
ll val[2020][2020];

void dfs(int cur,int KL,int KR,int FL,int FR) {
	if(KL+1>=KR) return;
	int i;
	if(FL==FR) {
		for(i=KL+1;i<KR;i++) {
			from[i][cur]=FL;
			val[i][cur]=val[i-1][FL]+le[FL][cur];
		}
	}
	else {
		int KM=(KL+KR)/2;
		for(i=FL;i<=FR;i++) {
			if(chmin(val[KM][cur],val[KM-1][i]+le[i][cur])) from[KM][cur]=i;
		}
		dfs(cur,KL,KM,FL,from[KM][cur]);
		dfs(cur,KM,KR,from[KM][cur],FR);
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X>>M;
	vector<ll> cand={0,X-M};
	FOR(i,N) {
		cin>>A[i]>>B[i];
		V.push_back({A[i]+B[i],i});
		cand.push_back(min(A[i],X-M));
		cand.push_back(max(0LL,B[i]-M));
	}
	
	sort(ALL(V));
	FOR(i,N) L[i]=A[V[i].second], R[i]=B[V[i].second];
	
	sort(ALL(cand));
	
	le[0][N]=1LL<<60;
	FOR(i,cand.size()) {
		FOR(j,N) {
			ll x;
			if(cand[i]>=R[j]) {
				x=M+R[j]-L[j];
			}
			else if(cand[i]+M<=L[j]) {
				x=M+R[j]-L[j];
			}
			else {
				x=max(R[j],cand[i]+M)-min(L[j],cand[i]);
			}
			len[i][j+1]=len[i][j]+x;
		}
		if(chmin(le[0][N],len[i][N])) opt[0][N]=i;
	}
	for(l=N-1;l>=1;l--) {
		for(int s=0;s+l<=N;s++) {
			int t=s+l;
			le[s][t]=1LL<<60;
			for(i=((s)?opt[s-1][t]:0);i<=((t<N)?opt[s][t+1]:cand.size()-1);i++) {
				if(chmin(le[s][t],len[i][t]-len[i][s])) opt[s][t]=i;
			}
		}
	}
	
	FOR(i,N+1) FOR(j,N+1) val[j][i]=1LL<<60;
	val[0][0]=0;
	
	for(i=1;i<=N;i++) {
		k=min(i,(int)K);
		FOR(j,i) if(chmin(val[k][i],val[k-1][j]+le[j][i])) from[k][i]=j;
		from[1][i]=0;
		val[1][i]=le[0][i];
		dfs(i,1,k,0,from[k][i]);
	}
	
	
	cout<<1LL*N*X-val[K][N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
