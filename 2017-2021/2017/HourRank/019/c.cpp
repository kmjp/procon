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
vector<int> E[505050];

int dia[505050],dep[505050];
vector<pair<int,int>> DI[505050];
vector<pair<int,int>> DEP[505050];

int ma=0;


pair<int,int> dfs(int cur,int pre) {
	FORR(r,E[cur]) if(r!=pre) {
		auto p=dfs(r,cur);
		p.second++;
		DI[cur].push_back({p.first,r});
		DEP[cur].push_back({p.second,r});
		dia[cur]=max(dia[cur],p.first);
		dia[cur]=max(dia[cur],dep[cur]+p.second);
		dep[cur]=max(dep[cur],p.second);
	}
	return {dia[cur],dep[cur]};
}

void dfs2(int cur,int pre,pair<int,int> par) {
	
	DI[cur].push_back({0,cur});
	DEP[cur].push_back({0,cur});
	DI[cur].push_back({par.first,pre});
	DEP[cur].push_back({par.second+1,pre});
	
	ma=max(ma, dia[cur]+1+par.first);
	
	sort(ALL(DI[cur]));
	sort(ALL(DEP[cur]));
	reverse(ALL(DI[cur]));
	reverse(ALL(DEP[cur]));
	
	FORR(r,E[cur]) if(r!=pre) {
		int di=0;
		vector<int> de;
		FORR(a,DEP[cur]) if(a.second!=r) {
			de.push_back(a.first);
			if(de.size()>=2) break;
		}
		FORR(a,DI[cur]) if(a.second!=r) {
			di=a.first;
			break;
		}
		if(de.size()==2) di=max(di,de[0]+de[1]);
		
		dfs2(r,cur,{di,de[0]});
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	dfs2(0,-1,{-1<<20,-1<<20});
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
