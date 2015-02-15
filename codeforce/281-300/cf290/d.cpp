#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int mat[101][101];
int NG[101],num;
ll mo=1000000009;
vecor<int> E[101];
int NN[101];
int vis[101];
int vis2[101][101];
ll dp[101][101][101];

static const int N_=1020;
static ll C_[N_][N_];

class SCC_BI {
public:
	static const int MV = 5000;
	vector<int> E[MV];
	stack<int> roots,S;
	int NV,ord[MV],llink[MV],inin[MV],time;
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	SCC_BI(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear();
		ZERO(ord);ZERO(llink);ZERO(inin);time=0;
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

int dfs(int cur,int pre) {
	int ret=1,i;
	FOR(i,E[cur].size()) if(pre!=E[cur][i]) ret+=dfs(E[cur][i],cur);
	return ret;
}

void dfs2(int cur,int pre) {
	int ret=1,i;
	if(vis[pre][cur]>=0) return;
	vis[pre][cur] = 1;
	ll dp2[2][102];
	int c=0,t=1,x,y;
	
	dp2[0][1]=1;
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre) continue;
		dfs(tar,cur);
		ZERO(dp2[t]);
		FOR(x,vis[pre][cur]+1) {
			FOR(y,vis[cur][tar]+1) {
				dp2[t][x+y]+=dp2[c][x]*dp[cur][tar][y]%mo*C_[x+y][y]%mo;
			}
		}
		vis[pre][cur]+=vis[cur][tar];
		FOR(x,vis[pre][cur]+1) dp2[t][x] %= mo;
		swap(c,t);
	}
	FOR(i,101) dp[pre][cur][i]=dp2[c][i];
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	
	cin>>N>>M;
	SCC_BI sb(N);
	FOR(i,M) {
		cin>>x>>y;
		mat[x-1][y-1]=mat[y-1][x-1]=1;
		sb.add_edge(x-1,y-1);
	}
	sb.scc();
	num=N;
	FOR(i,sb.SC.size()) {
		if(sb.SC[i].size()>1) FOR(j,sb.SC[i].size()) NG[sb.SC[i][j]]=1, num--;
	}
	FOR(x,N) FOR(y,N) if(NG[x]||NG[y]) mat[x][y]=0;
	FOR(x,N) FOR(y,N) if(mat[x][y]) E[x].push_back(y);
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]|=mat[x][i]&&mat[i][y];
	
	MINUS(vis2);
	FOR(i,N) if(NG[i]==0) {
		NN[i]=dfs(i,-1);
		FOR(x,N) if(mat[i][x]) NN[x]=NN[i];
		FOR(x,N) if(mat[i][x]) dfs2(x,100);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
