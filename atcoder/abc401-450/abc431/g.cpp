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

int N,Q;
int A[202020];

deque<int> P[202020];

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
BIT<ll,20> bt;

pair<int,int> ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		P[A[i]].push_front(i);
		bt.add(A[i],1);
	}
	set<pair<ll,int>> Qs;
	FOR(i,Q) {
		ll a;
		cin>>a;
		Qs.insert({a,i});
	}
	ll num=0;
	FOR(i,N) {
		while(Qs.size()) {
			ll a=Qs.begin()->first;
			if(num+bt(A[i]-1)<a) break;
			x=bt.lower_bound(a-num);
			ll b=bt(x-1);
			ret[Qs.begin()->second]={i+1,P[x][a-(num+b)-1]+1};
			Qs.erase(Qs.begin());
		}
		num+=bt(A[i]-1);
		bt.add(A[i],-1);
		P[A[i]].pop_back();
	}
	FOR(i,N) {
		P[A[i]].push_back(i);
	}
	FOR(i,N) {
		P[A[i]].pop_front();
		while(Qs.size()) {
			ll a=Qs.begin()->first;
			if(num+P[A[i]].size()<a) break;
			ret[Qs.begin()->second]={i+1,P[A[i]][0]+1};
			Qs.erase(Qs.begin());
		}
		num+=P[A[i]].size();
	}
	for(i=N-1;i>=0;i--) {
		while(Qs.size()) {
			ll a=Qs.begin()->first;
			if(num+bt(N)-bt(A[i])<a) break;
			x=bt.lower_bound(a-num+bt(A[i]));
			ll b=bt(x-1)-bt(A[i]);
			ret[Qs.begin()->second]={i+1,P[x][a-(num+b)-1]+1};
			Qs.erase(Qs.begin());
		}
		num+=bt(N)-bt(A[i]);
		bt.add(A[i],1);
		P[A[i]].push_front(i);
	}
	
	FOR(i,Q) cout<<ret[i].first<<" "<<ret[i].second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
