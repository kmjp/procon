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


int N,Q;
int S[202020];
int lef[202020],ri[202020];
int T[202020],L[202020],R[202020];

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		//update(R+1,-val,val*R);
	}
};
BIT_r<ll,21> btv,bts;
vector<pair<int,int>> ev[1<<18];
vector<int> rev[202020];
ll ret[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	
	vector<pair<int,int>> V;
	V.push_back({1<<30,-1<<19});
	FOR(i,N) {
		cin>>S[i];
		while(V.back().first<=S[i]) V.pop_back();
		lef[i]=V.back().second;
		V.push_back({S[i],i});
	}
	V.clear();
	V.push_back({1<<30,1<<19});
	for(i=N-1;i>=0;i--) {
		while(V.back().first<S[i]) V.pop_back();
		ri[i]=V.back().second;
		V.push_back({S[i],i});
	}
	
	FOR(i,N) {
		//左大三角形
		//bts.add((1<<19)+lef[i]+1,1<<21,S[i]);
		btv.add((1<<19)+ri[i],1<<20,-S[i]);
		if(ri[i]-(lef[i]+1)<N) ev[ri[i]-(lef[i]+1)].push_back({ri[i],S[i]});
		//左小三角形
		//bts.add((1<<19)+lef[i]+1,1<<20,-S[i]);
		btv.add((1<<19)+i,1<<20,S[i]);
		if(i-(lef[i]+1)<N) ev[i-(lef[i]+1)].push_back({i,-S[i]});
		//右三角形
		bts.add((1<<19)+i+1,1<<20,-S[i]);
		btv.add((1<<19)+ri[i],1<<20,S[i]);
		if(ri[i]<N) ev[ri[i]-(i+1)].push_back({ri[i],-S[i]});
	}
	
	FOR(i,Q) {
		cin>>T[i]>>L[i]>>R[i];
		L[i]--;
		rev[T[i]].push_back(i);
	}
	FOR(i,202010) {
		FORR(e,ev[i]) {
			bts.add((1<<19)+e.first-i,1<<20,-e.second);
			btv.add((1<<19)+e.first,1<<20,e.second);
		}
		FORR(e,rev[i]) {
			ret[e]+=btv.total((1<<19)+R[e]-1)-btv.total((1<<19)+L[e]-1);
			ret[e]+=bts.total((1<<19)+R[e]-1-i)-bts.total((1<<19)+L[e]-1-i);
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
