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
int A[202020];
vector<int> As;
vector<int> E[202020];

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

ll dfs(int cur,int pre,int turn) {
	int x=lower_bound(ALL(As),A[cur])-As.begin();
	bit.add(x,1);
	
	ll ret;
	if(cur&&E[cur].size()==1) {
		int N=bit(1<<19);
		
		int a=bit.lower_bound((N+1)/2);
		int b=bit.lower_bound((N+2)/2);
		ret=As[a]+As[b];
	}
	else {
		if(turn==0) {
			ret=-1LL<<60;
			FORR(e,E[cur]) if(e!=pre) ret=max(ret,dfs(e,cur,1));
		}
		else {
			ret=1LL<<60;
			FORR(e,E[cur]) if(e!=pre) ret=min(ret,dfs(e,cur,0));
		}
	}
	
	bit.add(x,-1);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]/=2;
		As.push_back(A[i]);
	}
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	cout<<dfs(0,0,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
