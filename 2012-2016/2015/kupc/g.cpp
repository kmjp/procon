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
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

BIT<int,20> bt;
int N;
int A[101010],B[101010];
vector<pair<int,int> > V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		V.push_back({A[i],i});
		bt.add(i,1);
	}
	FOR(i,N) cin>>B[i];
	sort(ALL(V));
	
	set<int> S;
	ll ret=0;
	x=N-1;
	for(i=N-1;i>=0;i--) {
		while(x>=0 && V[x].first>=B[i]) S.insert(V[x--].second);
		if(S.empty()) return _P("-1\n");
		y = *(--S.end());
		S.erase(y);
		ret += bt.total(N+1)-bt.total(y);
		bt.add(y,-1);
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
