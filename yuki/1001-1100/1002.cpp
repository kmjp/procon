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

int N,K;
vector<pair<int,int>> E[202020];

int vis[201010];
int NV[201010];

int singlea;
map<int,int> sing,s2,p,p2;
map<pair<int,int>,int> doub,d2;
ll ret=0;

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) NV[cur]+=dfs(e.first,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) {
		int c = dfs2(e.first,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e.first];
		if(NV[e.first]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,int c1,int c2) {
	if(c2==-1) {
		//cout<<cur<<" "<<pre<<" "<<c1<<" "<<c2<<" "<<(singlea-sing[c1])<<endl;
		ret+=singlea-sing[c1];
		ret+=p[c1];
		s2[c1]++;
	}
	else {
		//cout<<cur<<" "<<pre<<" "<<c1<<" "<<c2<<" "<<(doub[{c1,c2}]+doub[{c2,c1}])<<endl;
		ret+=doub[{c1,c2}]+doub[{c2,c1}];
		ret+=sing[c1]+sing[c2];
		p2[c1]++;
		p2[c2]++;
		ret++;
		d2[{c1,c2}]++;
	}
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) {
		if(c1==e.second || c2==e.second) dfs3(e.first,cur,c1,c2);
		else if(c2==-1) dfs3(e.first,cur,c1,e.second);
	}
}


void split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	
	singlea=0;
	sing.clear();
	doub.clear();
	p.clear();
	FORR(e,E[center]) if(vis[e.first]==0) {
		dfs3(e.first,center,e.second,-1);
		FORR(s,s2) singlea+=s.second, sing[s.first]+=s.second;
		FORR(a,p2) p[a.first]+=a.second;
		FORR(d,d2) doub[d.first]+=d.second;
		s2.clear();
		d2.clear();
		p2.clear();
	}
	vis[center]=1;
	FORR(e,E[center]) if(vis[e.first]==0) split(e.first,id+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	split(0,0);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
