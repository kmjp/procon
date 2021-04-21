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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

int N,Q;
vector<pair<int,int>> E[202020];
ll C[101010];
int id;
int L[101010],R[101010];
int re[101010];

void dfs(int cur,int pre) {
	L[cur]=id++;
	re[L[cur]]=cur;
	bt.add(L[cur],C[cur]);
	bt.add(L[cur]+1,-C[cur]);
	int i;
	FOR(i,E[cur].size()) if(E[cur][i].second==pre) {
		E[cur].erase(E[cur].begin()+i);
		break;
	}
	
	FORR2(v,e,E[cur]) {
		dfs(e,cur);
		v=R[e]-1;
	}
	
	
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back({0,y-1});
		E[y-1].push_back({0,x-1});
	}
	id=1;
	dfs(0,0);
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y>>r;
			
			x--;
			y--;
			if(L[x]<L[y]&&L[y]<R[x]) {
				k=lower_bound(ALL(E[x]),make_pair(L[y],0))-E[x].begin();
				bt.add(L[E[x][k].second],r);
				bt.add(R[E[x][k].second],-r);
				
			}
			else {
				bt.add(0,r);
				bt.add(L[x],-r);
				bt.add(R[x],r);
			}
			
		}
		else {
			cin>>x;
			y=L[x-1];
			cout<<bt(y)<<endl;
		}
	}
		
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
