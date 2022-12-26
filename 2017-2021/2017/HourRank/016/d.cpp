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

int N,R;
vector<int> E[5050];

bitset<5000> now;
unordered_set<bitset<5000>> SS;
set<vector<ll>> S;

int ctim;
int tim[3030][3030];
ll memo[3030][3030];


void dfs(int cur,int pre,int l) {
	now[cur]=1;
	if(l) FORR(r,E[cur]) if(r!=pre) dfs(r,cur,l-1);
}

ll tree_normalize(vector<ll> T) {
	ll momo[2]={1000000007,1000000009};
	vector<ll> prim = {100291,100297,100313,100333,100343,100357,100361,100363,100379,100391};
	
	sort(ALL(T));
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a+=h*prim[(id++)%prim.size()])%=momo[0];
		(b+=l*prim[(id2++)%prim.size()])%=momo[1];
	}
	return (a<<32)+b;
}

ll dfs2(int cur,int pre) {
	
	if(tim[cur][pre]==ctim) return memo[cur][pre];
	
	vector<ll> V;
	V.push_back((1LL)+(1LL<<32));
	
	FORR(r,E[cur]) if(r!=pre && now[r]) V.push_back(dfs2(r,cur));
	
	memo[cur][pre]=tree_normalize(V);
	tim[cur][pre]=ctim;
	return memo[cur][pre];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>R;
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	MINUS(tim);
	
	FOR(i,N) {
		FOR(j,N) now[j]=0;
		ctim=i;
		dfs(i,-1,R);
		
		if(SS.count(now)) continue;
		SS.insert(now);
		
		vector<ll> V;
		FOR(j,N) if(now[j]) V.push_back(dfs2(j,3002));
		sort(ALL(V));
		S.insert(V);
		
	}
	
	cout<<S.size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
