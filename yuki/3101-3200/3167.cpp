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

int N;
vector<int> pre[603030];

int Q;
int T[303030],V[303030];
int order[606060];
int A[606060];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bit;

void dfs(int cur,int& pos) {
	FORR(e,pre[cur]) dfs(e,pos);
	A[pos]=cur;
	order[cur]=pos++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		pre[0].push_back(x);
	}
	cin>>Q;
	int cur=N+1;
	FOR(i,Q) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>V[i];
			pre[V[i]].push_back(cur++);
		}
		else if(T[i]==3) {
			cin>>V[i];
		}
	}
	x=0;
	dfs(0,x);
	FOR(i,N) bit.add(order[i+1],1);
	cur=N+1;
	FOR(i,Q) {
		if(T[i]==1) {
			bit.add(order[cur++],1);
		}
		else if(T[i]==2) {
			y=bit.lower_bound(1);
			bit.add(y,-1);
		}
		else {
			y=bit.lower_bound(V[i]);
			cout<<A[y]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
