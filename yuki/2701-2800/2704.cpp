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

int N,L,R;
FunctionGraph<101010> fg;
map<int,int> maxd;
map<int,int> did;
int Q,S[101010],T[101010],B[101010];
int ret[101010];
vector<int> cand[101010];

int dp[101010];
int tar[101010];
int cur[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	FOR(i,N) {
		cin>>fg.E[i];
		fg.E[i]--;
	}
	fg.build(N);
	
	cin>>Q;
	FOR(i,Q) {
		cin>>S[i]>>T[i];
		S[i]--,T[i]--;
		ret[i]=-1;
		if(fg.Gid[S[i]]!=fg.Gid[T[i]] || fg.D[S[i]]<fg.D[T[i]]) {
			ret[i]=-1;
			continue;
		}
		else {
			x=fg.D[S[i]];
			y=fg.D[T[i]];
			if(y) {
				if(fg.move(S[i],x-y)!=T[i]) continue;
				int step=(x-y+R-1)/R;
				if(step*L<=x-y&&x-y<=step*R) {
					ret[i]=step;
				}
			}
			else {
				B[i]=x+fg.Gindex[T[i]]-fg.Gindex[fg.GV[S[i]]];
				if(fg.Gindex[fg.GV[S[i]]]>fg.Gindex[T[i]]) B[i]+=fg.GS[fg.Gid[S[i]]];
				cand[fg.GS[fg.Gid[S[i]]]].push_back(i);
			}
		}
	}
	FOR(i,N+1) if(cand[i].size()) {
		set<int> alive,alivep;
		FOR(j,N+1) {
			dp[j]=-1;
			tar[j%i]=j;
			cur[j]=-1;
			if(j) {
				alive.insert(j);
				alivep.insert(j%i);
				alivep.insert(j%i+i);
			}
		}
		dp[0]=0;
		deque<int> Q;
		Q.push_front(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop_front();
			if(cur>=i&&(dp[cur-i]>dp[cur]||dp[cur-i]==-1)) {
				dp[cur-i]=dp[cur];
				alive.erase(cur-i);
				Q.push_front(cur-i);
			}
			
			auto it=alive.lower_bound(cur+L);
			while(it!=alive.end()&&*it<=cur+R) {
				dp[*it]=dp[cur]+1;
				Q.push_back(*it);
				it=alive.erase(it);
			}
			int CL=cur+L;
			int CR=cur+R+1;
			if(CL<=N) CL=N+1;
			if(CR-CL>=i) {
				FORR(j,alivep) if(j<i) {
					for(x=j;x<=N;x+=i) if(alive.count(x)) {
						dp[x]=dp[cur]+1;
						Q.push_back(x);
						alive.erase(x);
					}
				}
				alivep.clear();
			}
			else if(CL<CR) {
				CL%=i;
				CR%=i;
				if(CR<CL) CR+=i;
				while(1) {
					auto it=alivep.lower_bound(CL);
					if(it==alivep.end()||*it>=CR) break;
					y=*it%i;
					for(x=y;x<=N;x+=i) if(alive.count(x)) {
						dp[x]=dp[cur]+1;
						Q.push_back(x);
						alive.erase(x);
					}
					alivep.erase(y);
					alivep.erase(y+i);
				}
			}
		}
		FORR(q,cand[i]) {
			ret[q]=dp[B[q]];
		}
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
