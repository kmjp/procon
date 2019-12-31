#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class SCC_BI {
public:
	static const int MV = 110000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
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
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

int N,M,P;
int U[300000],V[300000];
SCC_BI sb;

int mp[101010];
int ret[101010];
int C[101010];
vector<int> E[101010];
int num[101010][20];
int par[101010];

void dfs(int cur,int pre) {
	int i;
	par[cur]=pre;
	FOR(i,20) num[cur][i]=C[cur];
	FORR(tar,E[cur]) if(tar!=pre) {
		dfs(tar,cur);
		FOR(i,19) num[cur][i+1]+=num[tar][i];
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	sb.init(N);
	FOR(i,M) {
		cin>>U[i]>>V[i];
		sb.add_edge(--U[i],--V[i]);
	}
	
	sb.scc();
	
	FOR(i,sb.SC.size()) FORR(r,sb.SC[i]) mp[r]=i, C[i]++;
	FOR(i,M) if(mp[U[i]]!=mp[V[i]]) {
		E[mp[U[i]]].push_back(mp[V[i]]);
		E[mp[V[i]]].push_back(mp[U[i]]);
	}
	FOR(i,sb.SC.size()) {
		sort(ALL(E[i]));
		E[i].erase(unique(ALL(E[i])),E[i].end());
		par[i]=-1;
	}
	dfs(0,-1);
	
	FOR(i,sb.SC.size()) {
		int pre=-1,cur=i,x=P;
		FOR(j,P+1) {
			if(cur<0) break;
			ret[i]+=num[cur][x];
			if(pre>=0 && x) ret[i]-=num[pre][x-1];
			pre=cur;
			cur=par[cur];
			x--;
		}
	}
	
	
	FOR(i,N) cout<<(ret[mp[i]]-1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
