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

//‚³‚ç‚É’Zk
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt,bt2;

vector<int> V;
int Q;
ll T[101010],X[101010],F[101010],rev[101010];
int O[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	ll tadd=0;
	FOR(i,Q) {
		cin>>T[i]>>X[i];
		if(T[i]==1) {
			rev[i]=V.size();
			V.push_back(i);
		}
		else if(T[i]==3) {
			tadd+=X[i];
			bt.add(0,X[i]);
			bt.add(V.size(),-X[i]);
		}
	}
	
	vector<pair<ll,int>> P;
	FOR(i,Q) if(T[i]==1) {
		F[i]=X[i]+bt(rev[i]);
		P.push_back({F[i],i});
	}
	sort(ALL(P));
	FOR(i,P.size()) O[P[i].second]=i;
	
	ll add=0;
	FOR(i,Q) {
		if(T[i]==1) {
			bt2.add(O[i],1);
		}
		else if(T[i]==2) {
			bt2.add(O[V[X[i]-1]],-1);
		}
		else {
			add+=X[i];
		}
		
		ll dif=add-tadd;
		int L=0;
		for(j=20;j>=0;j--) {
			if(L+(1<<j)>V.size()) continue;
			
			ll t=L+(1<<j)-dif;
			x=lower_bound(ALL(P),make_pair(t,0))-P.begin();
			int num=bt2(Q)-(x?bt2(x-1):0);
			if(num>=L+(1<<j)) L+=1<<j;
		}
		cout<<L<<endl;
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
