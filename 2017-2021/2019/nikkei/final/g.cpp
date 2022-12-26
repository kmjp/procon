#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,int>> E[201010];
vector<int> cand[202020];
ll ret[101010];
int L[202020];

int vis[201010];
int NV[201010];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) {
		return ((__int128)(B.second-C.second)*(B.first-A.first)<=(__int128)(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		if(Q.size() && Q.back().first==a) {
			//a‚ª“¯‚¶ê‡
			if(b<=Q.back().second) return; //max‚Ìê‡
			Q.pop_back();
		}
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(0^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};


vector<int> V;
ll VD[101010],VS[101010];
vector<pair<ll,ll>> F;



int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR2(e,c,E[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR2(e,c,E[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,ll D,ll S,ll M) {
	FORR(c,cand[cur]) {
		V.push_back(c);
		VD[c]=D;
		VS[c]=S;
	}
	
	FORR2(e,c,E[cur]) if(e!=pre && vis[e]==0) {
		dfs3(e,cur,D+1,S+c,max(M,(ll)c));
		if(c>M) F.push_back({c,S-c*D});
	}
}

void split(int cur) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	
	ConvexHull<ll> ch;
	V.clear();
	F.clear();
	F.push_back({0,0});
	dfs3(center,center,0,0,0);
	ch.add(F);
	FORR(v,V) if(VD[v]<=L[v]) ret[v]=max(ret[v],ch.query(L[v]-VD[v])+VS[v]);
	
	vis[center]=1;
	FORR2(e,c,E[center]) if(vis[e]==0) split(e);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	cin>>M;
	FOR(i,M) {
		cin>>x>>L[i];
		cand[x-1].push_back(i);
	}
	split(0);
	FOR(i,M) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
