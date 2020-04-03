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

int N;
vector<ll> E[100][100];
int in[101],out[101];


template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	multiset<ll> E[MV];
	void add_path(int x,ll s) {
		E[x].insert(s);
	}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			ll to=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			dfs(to%100);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		assert(NV);
		int te=0,i;
		vector<int> deg(NV);
		int EC[101][101]={};
		FOR(i,NV) {
			te += E[i].size();
			deg[i]+=E[i].size();
			FORR(to,E[i]) {
				EC[i][to%100]++;
				deg[to%100]--;
			}
		}
		int d0=0,s=-1,d1=0;
		FOR(i,NV) {
			if(deg[i]>1 || deg[i]<-1) return false;
			if(deg[i]==0) d0++;
			if(deg[i]==1) s=i;
		}
		if(s==-1) {
			FOR(i,NV) if(E[i].size()) {
				s=i;
				break;
			}
		}
		dfs(s);
		reverse(path.begin(),path.end());
		FOR(i,path.size()-1) {
			if(--EC[path[i]][path[i+1]]<0) return false;
		}
		return path.size()==te+1;
	}
};

DirectedEulerPath<202020> dep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	dep.init(100);
	FOR(i,N) {
		cin>>s;
		ll a=0;
		FORR(c,s) a=a*10+c-'0';
		dep.add_path(a/100000000,a);
		E[a/100000000][a%100].push_back(a);
	}
	
	FOR(x,100) FOR(y,100) {
		sort(ALL(E[x][y]));
		reverse(ALL(E[x][y]));
	}
	
	if(!dep.GetPath()) {
		cout<<"impossible"<<endl;
		return;
	}
	FOR(i,N) {
		ll a = E[dep.path[i]][dep.path[i+1]].back();
		E[dep.path[i]][dep.path[i+1]].pop_back();
		string s="00000000000"+to_string(a);
		s=s.substr(s.size()-10);
		cout<<s<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
