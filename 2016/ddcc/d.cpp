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
ll X;
vector<pair<int,int>> E[101010];
int did[101010], NC[101010], mie[101010];
vector<int> add,addsum;
ll ret;
int center;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt_tot,bt_num;


void dfs(int cur,int pre,int num) {
	NC[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre && did[e.first]==0) {
		dfs(e.first,cur,num);
		NC[cur]+=NC[e.first];
	}
	if(center==-1 && num-NC[cur]<num/2) center=cur;
}

void dfs2(int cur,int pre, int dep) {
	NC[cur]=1;
	dep=min(dep,101010);
	ll left=max(0LL,X-dep);
	ret += bt_tot(left)+bt_num(left)*dep+X*(addsum.size()-bt_num(left));
	add.push_back(dep);
	
	FORR(e,E[cur]) if(e.first!=pre && did[e.first]==0) {
		dfs2(e.first,cur,dep+e.second);
		NC[cur]+=NC[e.first];
	}
	
}


void gogo(int cur,int num) {
	if(num<=1) return;
	
	center=-1;
	dfs(cur,-1,num);
	if(center==-1) center=cur;
	
	FORR(e,E[center]) if(did[e.first]==0) {
		dfs2(e.first,center,e.second);
		FORR(a,add) {
			bt_tot.add(a,a);
			bt_num.add(a,1);
			addsum.push_back(a);
		}
		add.clear();
	}
	
	ret += bt_tot(X) + X*(addsum.size()-bt_num(X));
	
	FORR(r,addsum) {
		bt_tot.add(r,-r);
		bt_num.add(r,-1);
	}
	addsum.clear();
	
	did[center]=1;
	FORR(e,E[center]) if(did[e.first]==0) gogo(e.first,NC[e.first]);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) mie[i]=404040;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		x--;
		y--;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
		mie[x]=min(mie[x],r);
		mie[y]=min(mie[y],r);
	}
	
	gogo(0,N);
	
	FOR(i,N) FORR(r,E[i]) {
		x=r.first;
		if(i>x) continue;
		if(r.second<=X) continue;
		ll mi=r.second;
		if(E[i].size()>1&&E[x].size()>1) mi=min(mi,3*X);
		if(E[i].size()+E[x].size()-1!=N-1) mi=min(mi,2*X);
		mi=min(mi,X+mie[i]);
		mi=min(mi,X+mie[x]);
		ret += mi-X;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
