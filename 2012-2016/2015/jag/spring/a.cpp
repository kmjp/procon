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
string S;
vector<int> E[101010];

int us[101010],ds[101010];
map<int,int> up[101010],down[101010];
ll ret;

void dfs(int cur,int pre) {
	int a=(S[cur]=='(')?1:-1;
	if(S[cur]=='(') {
		up[cur][1]=1;
	}
	else {
		down[cur][1]=1;
	}
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		
		
		if(up[cur].size()<down[e].size()) {
			FORR(u,up[cur]) if(down[e].count(u.first+us[cur]-ds[e])) ret+=1LL*u.second*down[e][u.first+us[cur]-ds[e]];
		}
		else {
			FORR(d,down[e]) if(up[cur].count(d.first+ds[e]-us[cur])) ret+=1LL*d.second*up[cur][d.first+ds[e]-us[cur]];
		}
		if(down[cur].size()<up[e].size()) {
			FORR(d,down[cur]) if(up[e].count(d.first+ds[cur]-us[e])) ret+=1LL*d.second*up[e][d.first+ds[cur]-us[e]];
		}
		else {
			FORR(u,up[e]) if(down[cur].count(u.first+us[e]-ds[cur])) ret+=1LL*u.second*down[cur][u.first+us[e]-ds[cur]];
		}
		
		
		
		
		
		if(up[cur].size()<up[e].size()) {
			swap(up[e],up[cur]);
			swap(us[e],us[cur]);
			us[cur]+=a;
			FORR(u,up[e]) up[cur][u.first+us[e]-us[cur]]+=u.second;
		}
		else {
			FORR(u,up[e]) up[cur][u.first+us[e]-us[cur]+a]+=u.second;
		}
		
		if(down[cur].size()<down[e].size()) {
			swap(down[e],down[cur]);
			swap(ds[e],ds[cur]);
			ds[cur]-=a;
			FORR(d,down[e]) down[cur][d.first+ds[e]-ds[cur]]+=d.second;
		}
		else {
			FORR(d,down[e]) down[cur][d.first+ds[e]-ds[cur]-a]+=d.second;
		}
		while(up[cur].size() && up[cur].begin()->first+us[cur]<0) up[cur].erase(up[cur].begin());
		while(down[cur].size() && down[cur].begin()->first+ds[cur]<0) down[cur].erase(down[cur].begin());
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
