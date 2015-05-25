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
	V set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

int N,Q,NB;
BIT<ll,20> coln,cols;
int X[202000],A[202000],C[202000];
int rev[202000];

map<int,int> M;
vector<int> MV;
set<pair<int,int> > S;
set<pair<int,int> > Left, Right;
set<int> pos[200200];


ll dodo(int col) {
	
	if(Left.size()<=1) return 0;
	
	int LM=(Left.begin()->second!=col)?Left.begin()->first:(++Left.begin())->first;
	int RM=(Right.begin()->second!=col)?-Right.begin()->first:-(++Right.begin())->first;
	
	ll tn=coln.total(col-1);
	ll tot=cols.total(200001)-cols.total(col-1) - (S.size()-tn)*col;
	tot += tn*col-cols.total(col-1);
	
	return tot + (MV[RM]-MV[LM]) + min(abs(MV[RM]),abs(MV[LM]));
}

void change(int id, bool add) {
	set<int>& p = pos[A[id]];
	int x = M[X[id]];
	
	if(p.size()) {
		Left.erase(make_pair(*p.begin(),A[id]));
		Right.erase(make_pair(-*p.rbegin(),A[id]));
	}
	
	if(add) {
		S.insert(make_pair(x,id));
		rev[x] = id;
		coln.add(A[id],1);
		cols.add(A[id],A[id]);
		p.insert(x);
	}
	else {
		S.erase(make_pair(x,rev[x]));
		rev[x] = -1;
		coln.add(A[id],-1);
		cols.add(A[id],-A[id]);
		p.erase(x);
	}
	
	if(p.size()) {
		Left.insert(make_pair(*p.begin(),A[id]));
		Right.insert(make_pair(-*p.rbegin(),A[id]));
	}
}


void solve() {
	int i,j,k,l,r,x,y,q; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>A[i];
		M[X[i]]=0;
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>C[i+100000]>>X[i+100000]>>A[i+100000];
		M[X[i+100000]]=0;
	}
	M[1000000007]=M[-1000000007]=0;
	ITR(it,M) it->second = MV.size(), MV.push_back(it->first);
	
	FOR(i,N) change(i,true);
	
	for(q=100000;q<100000+Q;q++) {
		change(q,C[q]==1);
		
		ll mi=min(dodo(A[S.begin()->second]), dodo(A[S.rbegin()->second]));
		mi=min(mi,dodo(coln.lower_bound((S.size()+1)/2)));
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
