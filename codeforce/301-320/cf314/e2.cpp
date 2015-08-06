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
	static const int MV = 210000;
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
int N,M,S[2];
int A[101010],B[101010];
ll L[101010];
vector<int> E[2][101010];
ll dist[2][101010];
SCC_BI scc;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S[0]>>S[1];
	S[0]--,S[1]--;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>L[i];
		A[i]--,B[i]--;
		E[0][A[i]].push_back(i);
		E[1][B[i]].push_back(i);
	}
	
	FOR(i,2) {
		FOR(x,N) dist[i][x]=1LL<<60;
		priority_queue<pair<ll,int> > Q;
		dist[i][S[i]]=0;
		Q.push({-dist[i][S[i]],S[i]});
		
		while(Q.size()) {
			auto r=Q.top();
			Q.pop();
			ll co=-r.first;
			int cur=r.second;
			if(dist[i][cur]!=co) continue;
			
			FORR(r,E[i][cur]) {
				int tar=(i==0)?B[r]:A[r];
				if(dist[i][tar]>co+L[r]) {
					dist[i][tar]=co+L[r];
					Q.push({-dist[i][tar],tar});
				}
			}
		}
	}
	
	scc.init(N);
	FOR(i,M) {
		ll best=dist[0][S[1]];
		ll my=dist[0][A[i]]+dist[1][B[i]]+L[i];
		if(best==my) scc.add_edge(A[i],B[i]);
	}
	scc.scc();
	set<pair<int,int> > br;
	FORR(r,scc.BR) br.insert(r);
	
	FOR(i,M) {
		ll best=dist[0][S[1]];
		ll my=dist[0][A[i]]+dist[1][B[i]]+L[i];
		
		if(best==my) {
			if(br.count({A[i],B[i]})) cout<<"YES"<<endl;
			else if(L[i]>1) cout<<"CAN 1"<<endl;
			else cout<<"NO"<<endl;
		}
		else if(dist[0][A[i]]+dist[1][B[i]]<best-1) cout<<"CAN "<<my-best+1<<endl;
		else cout<<"NO"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
