#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int NV> class SegTree_Lazy {
public:
	typedef pair<int,int> V;
	vector<int> val;
	vector<V> to;
	SegTree_Lazy(){val.resize(NV*2); to.resize(NV*2);};
	V comp(V l,V r){ l.first+=r.first, l.second+=r.second; return l;};
	V makeval(int type,int num) {
		return {(type==1)?num:0,(type==2)?num:0};
	}

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return to[k];
		x=max(x,l);
		y=min(y,r);
		if(val[k]>=0) return makeval(val[k],y-x);
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=v;
			to[k]=makeval(v,r-l);
		}
		else if(l < y && x < r) {
			if(val[k]!=-1) {
				val[k*2]=val[k*2+1]=val[k];
				to[k*2]=to[k*2+1]=makeval(val[k],(r-l)/2);
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			to[k]=comp(to[k*2],to[k*2+1]);
		}
	}
};

int N,Q;
ll AA,BB;
SegTree_Lazy<1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>x>>l>>r;
		
		if(x==0) {
			auto rr=st.getval(l,r+1);
			if(rr.first>rr.second) AA+=rr.first;
			if(rr.first<rr.second) BB+=rr.second;
		}
		else {
			st.update(l,r+1,x);
		}
	}
	auto rr=st.getval(0,N);
	AA+=rr.first;
	BB+=rr.second;
	
	_P("%lld %lld\n",AA,BB);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
