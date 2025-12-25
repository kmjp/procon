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


template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,-(1LL<<60));};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return -(1LL<<60);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,(1LL<<60));};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return (1LL<<60);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<ll,1<<20> spma,smma;
SegTree_mi<ll,1<<20> spmi,smmi;

int N,Q;
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		spma.update(i,X[i]+Y[i]);
		spmi.update(i,X[i]+Y[i]);
		smma.update(i,X[i]-Y[i]);
		smmi.update(i,X[i]-Y[i]);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>x>>y;
			i--;
			X[i]=x;
			Y[i]=y;
			spma.update(i,X[i]+Y[i]);
			spmi.update(i,X[i]+Y[i]);
			smma.update(i,X[i]-Y[i]);
			smmi.update(i,X[i]-Y[i]);
		}
		else {
			int L,R;
			cin>>L>>R>>x>>y;
			L--;
			ll ret=0;
			ret=max(ret,spma.getval(L,R)-(x+y));
			ret=max(ret,(x+y)-spmi.getval(L,R));
			ret=max(ret,smma.getval(L,R)-(x-y));
			ret=max(ret,(x-y)-smmi.getval(L,R));
			cout<<ret<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
