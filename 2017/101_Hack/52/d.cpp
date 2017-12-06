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

template<class V,int NV> class SegTree_max {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_max(){val=vector<V>(NV*2,def);};
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
template<class V,int NV> class SegTree_min {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_min(){val=vector<V>(NV*2,def);};
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

template<class V,int NV> class SegTree_or {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return l | r;};
	
	SegTree_or(){val=vector<V>(NV*2,def);};
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

template<class V,int NV> class SegTree_and {
public:
	vector<V> val;
	static V const def=0x7FFFFFFF;
	V comp(V l,V r){ return l & r;};
	
	SegTree_and(){val=vector<V>(NV*2,def);};
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



int N,K;
int A[101010];
SegTree_max<int,1<<18> stma;
SegTree_min<int,1<<18> stmi;
SegTree_or<int,1<<18> stor;
SegTree_and<int,1<<18> stand;

int nex[31][2];

int ret[101010];
vector<int> add[101010],del[101010];
set<int> cand[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(ret);
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		stma.update(i,A[i]);
		stmi.update(i,A[i]);
		stor.update(i,A[i]);
		stand.update(i,A[i]);
	}
	
	FOR(i,30) nex[i][0]=nex[i][1]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,30) {
			if(A[i]&(1<<j)) nex[j][1]=i;
			else nex[j][0]=i;
			cand[i].insert(nex[j][0]);
			cand[i].insert(nex[j][1]);
		}
		cand[i].erase(N);
		y=-1;
		FORR(e,cand[i]) {
			x=e;
			int ma=stma.getval(i,x+1);
			int mi=stmi.getval(i,x+1);
			int mor=stor.getval(i,x+1);
			int mand=stand.getval(i,x+1);
			int val=mor-mand-(ma-mi);
			if(val>=K) {
				y=x;
			}
		}
		if(y==-1) continue;
		for(j=19;j>=0;j--) {
			if(y+(1<<j)>=N) continue;
			y+=(1<<j);
			int ma=stma.getval(i,y+1);
			int mi=stmi.getval(i,y+1);
			int mor=stor.getval(i,y+1);
			int mand=stand.getval(i,y+1);
			int val=mor-mand-(ma-mi);
			if(val<K) y-=1<<j;
		}
		add[i].push_back(y-i+1);
		del[y+1].push_back(y-i+1);
		
	}
	
	
	
	map<int,int> MP;
	MP[-1]=1;
	FOR(i,N) {
		FORR(e,add[i]) MP[e]++;
		FORR(e,del[i]) {
			MP[e]--;
			if(MP[e]==0) MP.erase(e);
		}
		cout<<MP.rbegin()->first<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
