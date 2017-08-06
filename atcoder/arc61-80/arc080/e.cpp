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

int T;
pair<int,int> P[202020];
vector<int> E[202020];
map<pair<int,int>,int> to;

int dfs(int L,int R) {
	if(R<=L) return -1;
	
	int tar;
	if(L%2==0) tar=ev.getval(L,R);
	else tar=od.getval(L,R);
	int x=rev[tar];
	
	if((x+1)%2==0) tar=ev.getval(x+1,R);
	else tar=od.getval(x+1,R);
	int y=rev[tar];
	
	int cur=T++;
	P[cur]={A[x],A[y]};
	to[P[cur]]=cur;
	
	int ch;
	ch=dfs(L,x);
	if(ch>=0) E[cur].push_back(ch);
	ch=dfs(x+1,y);
	if(ch>=0) E[cur].push_back(ch);
	ch=dfs(y+1,R);
	if(ch>=0) E[cur].push_back(ch);
	return cur;
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
	
	dfs(0,N);
	
	set<pair<int,int>> cand;
	vector<int> Q;
	cand.insert(P[0]);
	while(cand.size()) {
		pair<int,int> p=*cand.begin();
		cand.erase(cand.begin());
		Q.push_back(p.first);
		Q.push_back(p.second);
		
		x = to[p];
		FORR(e,E[x]) cand.insert(P[e]);
	}
	
	assert(T==N/2);
	assert(Q.size()==N);
	
	FOR(i,N) _P("%d%c",Q[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
