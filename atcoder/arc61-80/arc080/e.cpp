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
int A[202020];
int rev[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=303030;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> ev,od;
set<vector<int>> cand;

void add(int L,int R) {
	vector<int> ret;
	if(R<=L) return;
	
	int tar;
	if(L%2==0) tar=ev.getval(L,R);
	else tar=od.getval(L,R);
	int x=rev[tar];
	ret.push_back(tar);
	
	if((x+1)%2==0) tar=ev.getval(x+1,R);
	else tar=od.getval(x+1,R);
	int y=rev[tar];
	ret.push_back(tar);
	
	ret.push_back(L);
	ret.push_back(x);
	ret.push_back(y);
	ret.push_back(R);
	cand.insert(ret);
}

void dodo(vector<int> V) {
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(i%2==0) {
			ev.update(i,A[i]);
			od.update(i,1<<20);
		}
		else {
			od.update(i,A[i]);
			ev.update(i,1<<20);
		}
		rev[A[i]]=i;
	}
	
	vector<int> Q;
	
	add(0,N);
	while(cand.size()) {
		vector<int> v=*cand.begin();
		cand.erase(cand.begin());
		Q.push_back(v[0]);
		Q.push_back(v[1]);
		add(v[2],v[3]);
		add(v[3]+1,v[4]);
		add(v[4]+1,v[5]);
	}
	
	
	FOR(i,N) _P("%d%c",Q[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
