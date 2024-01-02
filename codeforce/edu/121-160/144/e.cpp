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

int T;
int N;
vector<int> E[202020];
int ma;
int M[202020];
int C[202020];

void dfs(int cur,int pre) {
	E[cur].erase(remove(ALL(E[cur]), pre), E[cur].end());
	if(E[cur].empty()) {
		M[cur]=1<<20;
		C[cur]=1;
	}
	else {
		M[cur]=1<<20;
		vector<int> Cs;
		FORR(e,E[cur]) {
			dfs(e,cur);
			M[cur]=min(M[cur],M[e]);
			Cs.push_back(C[e]);
		}
		sort(ALL(Cs));
		int i;
		for(i=1;i<Cs.size();i++) M[cur]=min(M[cur],Cs[i]);
		C[cur]=Cs[0]+1;
	}
}

void dfs2(int cur,int pc,int pm) {
	if(E[cur].empty()) {
		ma=max(ma,min(pc+1,pm));
	}
	else {
		multiset<int> Cs,Ms;
		if(pc!=-1) Cs.insert(pc),Ms.insert(pm);
		FORR(e,E[cur]) {
			Cs.insert(C[e]);
			Ms.insert(M[e]);
		}
		ma=max(ma,min({*Ms.begin(),*Cs.begin()+1,*next(Cs.begin())}));
		
		FORR(e,E[cur]) {
			Cs.erase(Cs.find(C[e]));
			Ms.erase(Ms.find(M[e]));
			int nc=*Cs.begin()+1;
			int nm=min(*Ms.begin(),(Cs.size()>1?*next(Cs.begin()):1<<20));
			dfs2(e,nc,nm);
			
			Cs.insert(C[e]);
			Ms.insert(M[e]);
		}
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		FOR(i,N) if(E[i].size()>1) x=i;
		dfs(x,x);
		ma=min(M[x],C[x]);
		dfs2(x,-1,0);
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
