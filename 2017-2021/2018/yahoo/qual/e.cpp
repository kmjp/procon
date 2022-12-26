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
int D[101010];
ll S;

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
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>D[i+1];
		S+=D[i+1];
	}
	if(S%2) D[1]++;
	sort(D+1,D+N+1);
	for(i=1;i<=N;i++) {
		bt.add(i,D[i]-D[i-1]);
	}
	bt.add(N+1,1<<30);
	
	for(i=1;i<=N;i++) {
		x=bt(i);
		if(x==0) continue;
		bt.add(i,-x);
		bt.add(i+1,x);
		if(x>N-i || bt(N+1-x)==0) return _P("ABSOLUTELY NO\n");
		
		if(bt(N+1-x)!=bt(N-x)) {
			bt.add(N+1-x,-1);
			continue;
		}
		y=bt(N+1-x);
		j=bt.lower_bound(y);
		k=bt.lower_bound(y+1);
		int did=N+1-k;
		bt.add(j,-1);
		bt.add(j+(x-did),1);
		bt.add(k,-1);
	}
	
	
	if(S%2) _P("NO\n");
	else _P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
