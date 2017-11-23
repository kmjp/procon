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
vector<int> EV[101010];
ll ret;
ll mo=1000000007;
int vis[101010];
int NV[101010];

int cnt[101010];
vector<int> C,D;

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,int d) {
	if(d<=K) {
		(ret+=cnt[K-d])%=mo;
	}
	FORR(e,EV[cur]) if(vis[e]==0 && e!=pre) dfs3(e,cur,d+1);
	C.push_back(d);
}

void split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	cnt[0]++;
	FORR(e,EV[center]) if(vis[e]==0) {
		C.clear();
		dfs3(e,center,1);
		FORR(v,C) cnt[v]++, D.push_back(v);
	}
	cnt[0]--;
	FORR(v,D) cnt[v]--;
	D.clear();
	vis[center]=1;
	FORR(e,EV[center]) if(vis[e]==0) split(e,id+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		EV[x-1].push_back(y-1);
		EV[y-1].push_back(x-1);
	}
	split(0,0);
	cout<<(ret*(((1LL*K*(K+1))/2)%mo))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
