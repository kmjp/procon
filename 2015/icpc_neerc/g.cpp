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

int N,M;
ll T[303030];
ll D[303030],R[303030],ret[303030];

//’Zk”Å
template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
};

BIT<ll,21> num,tot;
vector<int> del[1010100];
vector<int> q[1010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>T[i];
		num.add(i+1,1);
		tot.add(i+1,T[i]);
		del[T[i]].push_back(i);
	}
	
	FOR(i,N) {
		cin>>D[i]>>R[i];
		q[D[i]].push_back(i);
	}
	for(int t=0;t<=1000001;t++) {
		FORR(r,q[t]) {
			int day=(1<<20)-1;
			for(j=19;j>=0;j--) if(tot.total(day-(1<<j))-num.total(day-(1<<j))*t>=R[r]) day -= 1<<j;
			if(day==(1<<20)-1) day=0;
			ret[r]=day;
		}
		FORR(r,del[t]) num.add(r+1,-1),tot.add(r+1,-T[r]);
	}
	FOR(i,N) _P("%d ",(int)ret[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
