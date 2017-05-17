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
vector<int> E[101010];
int D[101010];
int MD[101010],nc[101010],tot[101010];
int ret[101010];

void dfs(int cur,int pre,int d) {
	D[cur]=MD[cur]=d;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		if(MD[e]>MD[cur]) {
			MD[cur]=MD[e];
			nc[cur]=tot[cur]=0;
		}
		if(MD[e]==MD[cur]) {
			nc[cur]++;
			tot[cur]++;
			if(nc[e]==1) tot[cur]+=tot[e];
		}
	}
}
void dfs2(int cur,int pre,int md,int t) {
	
	vector<pair<int,int>> V;
	if(md>=0) V.push_back({md,t});
	
	FORR(e,E[cur]) if(e!=pre) {
		if(nc[e]==1) V.push_back({MD[e],1+tot[e]});
		else V.push_back({MD[e],1});
	}
	
	int mmd=max_element(ALL(V)).first;
	int tnc=0,ttot=0;
	FORR(r,V) if(r.first==mmd) {
		tnc++;
		ttot+=r.second;
	}
	
	if(tnc==1) ret[cur]=ttot;
	
	FORR(e,E[cur]) if(e!=pre) {
		if(MD[e]!=mmd) {
			if(tnc==1) dfs2(e,cur,mmd+2,1+ttot);
			else dfs2(e,cur,mmd+2,1);
		}
		else {
			if(tnc>2) {
				dfs2(e,cur,mmd+2,1);
			}
			else if(tnc==2) {
				dfs2(e,cur,mmd+2,1+ttot-(nc[e]==1?1+tot[e]:1));
			}
			else {
				int m2md=-1<<30,nc=0;
				int t=0;
				FORR(r,V) if(r.first!=mmd && r.first>m2md) m2md=r.first;
				FORR(r,V) if(r.first==m2md) t+=r.second, nc++;
				if(nc==1) dfs2(e,cur,m2md+2,1+t);
				else dfs2(e,cur,m2md+2,1);
			}
		}
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
	
	dfs(0,-1,0);
	dfs2(0,-1,0,0);
	FOR(i,N) cout<<N-1-ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
