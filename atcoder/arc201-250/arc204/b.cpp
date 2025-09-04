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
int P[5050],R[5050];

template<int NV> struct FunctionGraph {
	//input
	int E[NV];
	//output
	int N;
	int NG; //•Â˜H”
	int nex[61][NV];  // 2^iæ‚Ì“_
	vector<int> RE[NV]; // ‹tŒü‚«•Ó
	vector<int> G[NV]; // •Â˜H
	int GS[NV]; // •Â˜H’·
	int NC[NV]; // subtree‚Ì—v‘f”
	int Gid[NV],Gindex[NV]; // •Â˜HID‚Æ‚»‚Ì’†‚ÌindexB•Â˜HŠO‚Ìê‡A•Â˜HID‚ÍÅŠñ‚è‚Ì•Â˜H‚¾‚ªindex‚Í-1
	int GV[NV], D[NV]; //ÅŠñ‚è‚Ì•Â˜H‚Ì“_‚Æ‚»‚±‚Ü‚Å‚Ì‹——£
	int dfs(int cur,int id,int d) {
		GV[cur]=id;
		Gid[cur]=Gid[id];
		D[cur]=d;
		NC[cur]=1;
		FORR(e,RE[cur]) if(Gindex[e]==-1) NC[cur]+=dfs(e,id,d+1);
		return NC[cur];
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



FunctionGraph<10010> fg;
int dp[10100][10101];
vector<int> nex[505];
int N2;
vector<int> VV;
int get(int L,int R) {
	if(L>=N2/2) return get(L-N2/2,R-N2/2);
	return dp[L][R];
}

int hoge(vector<int> V) {
	FORR(v,V) v%=N;
	if(V.size()==1) return 0;
	int x,y=V.size();
	FOR(x,y) V.push_back(V[x]);
	VV=V;
	N2=V.size();
	FOR(x,N2) FOR(y,N2/2) dp[x][x+y]=0;
	
	FOR(x,N) nex[x].clear();
	FOR(x,N2) nex[V[x]].push_back(x);
	
	int ma=0;
	
	for(int len=1;len<N2/2;len++) {
		for(x=0;x<N2/2;x++) {
			int y=x+len;
			if(x>=N2/2) {
				dp[x][y]=dp[x-N2/2][y-N2/2];
			}
			else {
				int ret=dp[x+1][y];
				
				auto it=lower_bound(ALL(nex[VV[x]]),x+1);
				while(it!=nex[VV[x]].end()&&*it<=y) {
					
					ret=max(ret,1+get(x+1,*it)+get(*it,y));
					it++;
				}
				dp[x][y]=ret;
			}
		}
	}
	
	FOR(x,N2/2) {
		FORR(e,nex[V[x]]) if(e>x&&e<N2/2) ma=max(ma,dp[x][e]+dp[e][x+N2/2]-1);
	}
	
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N*K) {
		cin>>P[i];
		P[i]--;
		fg.E[i]=P[i];
	}
	fg.build(N*K);
	
	int ret=0;
	FOR(i,fg.NG) ret+=hoge(fg.G[i]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
