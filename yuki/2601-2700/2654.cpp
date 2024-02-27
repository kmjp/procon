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
int A[202020],P[202020];
vector<int> As;
ll ret[202020];
vector<int> E[202020];
vector<pair<int,int>> V;

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
BIT<ll,20> num,sum;

ll hoge(int rem) {
	num.add(rem,-1);
	sum.add(rem,-V[rem].first);
	
	
	int tnum=num(N+2);
	int L,R;
	if(tnum%2==1) {
		L=R=num.lower_bound(tnum/2+1);
	}
	else {
		L=num.lower_bound(tnum/2);
		R=num.lower_bound(tnum/2+1);
	}
	ll ret=(sum(N+2)-sum(R-1))-(num(N+2)-num(R-1))*V[R].first;
	ret+=num(L)*V[R].first-sum(L);
	
	if(V[rem].first==V[L].first&&V[rem].first==V[R].first) ret++;
	
	num.add(rem,1);
	sum.add(rem,V[rem].first);
	return ret;
}

void dfs(int cur,int pre) {
	num.add(P[cur],1);
	sum.add(P[cur],A[cur]);
	
	int tnum=num(N+2);
	if(tnum<=2) {
		ret[cur]=-1;
	}
	else {
		int L=num.lower_bound(1);
		int R=num.lower_bound(tnum);
		
		if(L==R) {
			ret[cur]=1;
		}
		else {
			ret[cur]=min(hoge(L),hoge(R));
			
		}
	}
	
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
	num.add(P[cur],-1);
	sum.add(P[cur],-A[cur]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N+1) {
		cin>>A[i];
		V.push_back({A[i],i});
	}
	sort(ALL(V));
	FOR(i,N+1) P[V[i].second]=i;
	
	FOR(i,N) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(0,0);
	FOR(i,N) cout<<ret[i+1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
