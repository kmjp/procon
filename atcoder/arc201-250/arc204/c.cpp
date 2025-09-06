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

int N,Q;
int P[303030];

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
FunctionGraph<301010> fg;
bitset<156464> bs;
int C1[303030];
int C2[303030];
int Y[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		fg.E[i]=P[i];
	}
	fg.build(N);
	vector<int> M1;
	bs[0]=1;
	int sum[2]={};
	int ns[2]={};
	FOR(i,fg.NG) {
		if(fg.GS[i]%2==0) {
			bs|=bs<<(fg.GS[i]/2);
		}
		else {
			M1.push_back(fg.GS[i]);
		}
		ns[fg.GS[i]%2]++;
		sum[fg.GS[i]%2]+=fg.GS[i];
	}
	
	FOR(i,sum[0]/2+1) {
		C2[i]=i;
		if(bs[i]==0) {
			C2[i]--;
			C1[i]+=2;
		}
	}
	
	sort(ALL(M1));
	reverse(ALL(M1));
	
	int cur=sum[0]/2;
	
	// 0‚ğ1ŒÂ‚¨‚«‚É–„‚ß‚é
	FORR(v,M1) if(v>1) {
		C2[cur+1]=C2[cur];
		C1[cur+1]=C1[cur]+2;
		FOR(i,v/2-1) {
			cur++;
			C2[cur+1]=C2[cur]+1;
			C1[cur+1]=C1[cur];
		}
		cur++;
	}
	
	// 0‚ª2˜A‘±‚ÌêŠ‚ªo‚é‚æ‚¤‚É–„‚ß‚é
	FORR(v,M1) {
		C1[cur+1]=C1[cur];
		C2[cur+1]=C2[cur];
		Y[cur+1]=Y[cur]+1;
		if(v>1) {
			C1[cur+1]-=2;
			C2[cur+1]++;
		}
		cur++;
	}
	while(cur<N) {
		C1[cur+1]=C1[cur];
		C2[cur+1]=C2[cur]-1;
		Y[cur+1]=Y[cur]+2;
		cur++;
	}
	
	//FOR(i,N+1) cout<<i<<" "<<C2[i]<<" "<<C1[i]<<" "<<Y[i]<<endl;
	
	
	cin>>Q;
	while(Q--) {
		int N0,N1,N2;
		cin>>N0>>N1>>N2;
		
		int ret=2*N0-Y[N0];
		
		x=min(C2[N0],N1);
		ret+=2*x;
		N1-=x;
		x=min(C1[N0],N1);
		ret+=x;
		
		
		
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
