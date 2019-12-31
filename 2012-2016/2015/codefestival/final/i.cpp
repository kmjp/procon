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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N,Q;
vector<int> E[101010];
int L[101010],P[101010],D[101010],ma[101010],num[101010];

vector<int> PR;
map<int,int> ret,rev;

void dfs(int cur,int order) {
	int i,tar;
	num[cur] += bt(1000000)-bt(D[cur]);
	
	FOR(i,E[cur].size()) {
		if(order==0) tar=E[cur][i];
		else tar=E[cur][E[cur].size()-1-i];
		dfs(tar,order);
		bt.add(ma[tar],1);
	}
	
	FOR(i,E[cur].size()) bt.add(ma[E[cur][i]],-1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i], D[i]=L[i];
	
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
		D[i+1]=L[i+1]+D[P[i+1]];
	}
	
	PR.push_back(0);
	FOR(i,N) PR.push_back(D[i]);
	sort(ALL(PR));
	PR.erase(unique(ALL(PR)),PR.end());
	FOR(i,PR.size()) rev[PR[i]]=i;
	
	for(i=N-1;i>=0;i--) {
		D[i]=lower_bound(ALL(PR),D[i])-PR.begin();
		ma[i]=max(ma[i],D[i]);
		ma[P[i]]=max(ma[P[i]],ma[i]);
		num[i]+=E[i].size();
	}
	dfs(0,0);
	assert(bt(1000000)==0);
	dfs(0,1);
	
	FOR(i,N) {
		if(ret.count(D[i])==0) ret[D[i]]=1000000;
		ret[D[i]]=min(ret[D[i]],num[i]);
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x;
		if(rev.count(x)==0) cout<<-1<<endl;
		else cout<<ret[rev[x]]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
