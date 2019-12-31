#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class SCC_BI {
public:
	static const int MV = 120000;
	vector<int> E[MV];
	stack<int> roots,S;
	int NV,ord[MV],llink[MV],inin[MV],time;
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	//SCC_BI(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
	void init(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
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

SCC_BI bi;
int N,M,V;
vector<int> E[151010];
int A[151010],B[151010];
int mp[101010];
int tl;
int ok=2010100;

pair<int,int> dfs(int cur,int pre) {
	int num=1;
	int l=(E[cur].size()==1);
	FORR(r,E[cur]) if(r!=pre) {
		auto a=dfs(r,cur);
		l += a.first;
		num += a.second;
	}
	
	if(pre!=-1 && num!=2 && N-num!=2) {
		int l1=l+(E[cur].size()==2);
		int l2=tl-l+(E[pre].size()==2);
		ok=min(ok,((l1==1)?0:(l1+1)/2)+((l2==1)?0:(l2+1)/2));
	}
	return {l,num};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	bi.init(N);
	FOR(i,M) {
		cin>>A[i]>>B[i];
		bi.add_edge(A[i],B[i]);
	}
	
	bi.scc();
	V=bi.SC.size();
	if(V==1) return _P("IMPOSSIBLE\n");
	
	FOR(i,V) FORR(r,bi.SC[i]) mp[r]=i;
	FOR(i,M) if(mp[A[i]]!=mp[B[i]]) {
		E[mp[A[i]]].push_back(mp[B[i]]);
		E[mp[B[i]]].push_back(mp[A[i]]);
	}
	FOR(i,V) if(E[i].size()==1) tl++;
	dfs(0,-1);
	
	if(ok<=2*N) _P("%d\n",ok);
	else _P("IMPOSSIBLE\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
