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

int T,N,M;
int A[1010101],B[1010101];
int isroot[1010101];
vector<int> C[1010101];
int D[1010101];
int id;
int L[1010101],R[1010101];

template<int NV> struct FunctionGraph {
	int E[NV];
	int N;
	int NG;
	int nex[61][NV];  // 2^iæ‚Ì“_
	vector<int> RE[NV]; // ‹tŒü‚«•Ó
	vector<int> G[NV]; // •Â˜H
	int GS[NV]; // •Â˜H’·
	int Gid[NV],Gindex[NV]; // •Â˜HID‚Æ‚»‚Ì’†‚ÌindexB•Â˜HŠO‚Ìê‡A•Â˜HID‚ÍÅŠñ‚è‚Ì•Â˜H‚¾‚ªindex‚Í-1
	int GV[NV], D[NV]; //ÅŠñ‚è‚Ì•Â˜H‚Ì“_‚Æ‚»‚±‚Ü‚Å‚Ì‹——£
	void dfs(int cur,int id,int d) {
		GV[cur]=id;
		Gid[cur]=Gid[id];
		D[cur]=d;
		FORR(e,RE[cur]) if(Gindex[e]==-1) dfs(e,id,d+1);
	}
	int move(int cur,ll step) { // stepæ‚Éi‚Ş
		int i;
		FOR(i,60) if(step&(1LL<<i)) cur=nex[i][cur];
		return cur;
	}
	void build(int N_) {
		N=N_;
		int i,j;
		vector<int> in(N);
		FOR(i,N) {
			RE[i].clear();
			G[i].clear();
			Gindex[i]=-2;
			nex[0][i]=E[i];
		}
		NG=0;
		FOR(i,N) {
			RE[E[i]].push_back(i);
			in[E[i]]++;
		}
		queue<int> Q;
		FOR(i,N) if(in[i]==0) Q.push(i);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			Gindex[cur]=-1;
			if(--in[E[cur]]==0) Q.push(E[cur]);
		}
		FOR(i,N) if(Gindex[i]==-2) {
			G[NG].push_back(i);
			while(1) {
				int x=G[NG].back();
				Gid[x]=NG;
				Gindex[x]=G[NG].size()-1;
				x=E[x];
				if(x==G[NG][0]) break;
				G[NG].push_back(x);
			}
			GS[NG]=G[NG].size();
			NG++;
		}
		FOR(i,N) if(Gindex[i]>=0) dfs(i,i,0);
		FOR(j,60) FOR(i,N) nex[j+1][i]=nex[j][nex[j][i]];
	}
};
FunctionGraph<1010101> fg;
void dfs(int cur,int d) {
	D[cur]=d;
	L[cur]=id++;
	FORR(e,C[cur]) dfs(e,d+1);
	R[cur]=id;
	
}

int can(int s,int t,int k) {
	if(s==t) return 1;
	if(fg.Gid[s]!=fg.Gid[t]) return 0;
	int root=fg.G[fg.Gid[s]][0];
	int nex=B[root];
	
	
	if(L[t]<L[s]&&L[s]<R[t]) {
		return (D[s]-D[t]<=k);
	}
	else if(L[nex]<L[t]||R[t]<=L[nex]) {
		return 0;
	}
	else {
		return (D[s]+1+D[nex]-D[t]<=k);
	}

}

int ok(int v) {
	if(v<0) return 0;
	int cur=0;
	int i;
	FOR(i,N) {
		while(cur<M&&can(A[i],cur,v)==0) cur++;
		if(cur==M) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(j,T) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
		}
		FOR(i,M) {
			cin>>B[i];
			B[i]--;
			fg.E[i]=B[i];
			C[i].clear();
		}
		fg.build(M);
		FOR(i,M) if(fg.Gindex[i]!=0) C[B[i]].push_back(i);
		id=0;
		FOR(i,M) if(fg.Gindex[i]==0) dfs(i,0);
		
		if(ok(M)==0) {
			cout<<-1<<endl;
			continue;
		}
		int ret=M;
		for(i=20;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
