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


struct node {
	int mi;
	int S,T;
	vector<pair<int,int>> L,R;
	node() { mi=1<<20; S=-1; };
};

int N,K,Q;


template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		if(l.S==-1) return r;
		if(r.S==-1) return l;
		V a;
		a.mi=min(l.mi,r.mi);
		a.S=l.S;
		a.T=r.T;
		
		a.L=l.L;
		a.R=r.R;
		int cur=0;
		if(a.L.size()) cur=a.L.back().first;
		FORR2(v,w,r.L) if((cur|v)!=cur) {
			cur|=v;
			if(cur==(1<<K)-1) {
				a.mi=min(a.mi,w-a.S+1);
				break;
			}
			a.L.push_back({cur,w});
		}
		cur=0;
		if(a.R.size()) cur=a.R.back().first;
		FORR2(v,w,l.R) if((cur|v)!=cur) {
			cur|=v;
			if(cur==(1<<K)-1) {
				a.mi=min(a.mi,a.T-w);
				break;
			}
			a.R.push_back({cur,w});
		}
		FORR2(x,y,l.R) FORR2(z,w,r.L) if((x|z)==(1<<K)-1) {
			a.mi=min(a.mi,w-y+1);
			break;
		}
		
		return a;
	};
	
	SegTree_1(){
		val=vector<V>(NV*2);
		int i;
		FOR(i,NV) {
			val[NV+i].S=i;
			val[NV+i].T=i+1;
			val[NV+i].mi=1<<20;
		}
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return node();
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		
		if(v==0) {
			val[entry].mi=1<<20;
			val[entry].L.clear();
			val[entry].R.clear();
		}
		else if(v==(1<<K)-1) {
			val[entry].mi=1;
			val[entry].L.clear();
			val[entry].R.clear();
		}
		else {
			val[entry].mi=1<<20;
			val[entry].L={{v,entry-NV}};
			val[entry].R={{v,entry-NV}};
		}
		val[entry].S=entry-NV;
		val[entry].T=entry-NV+1;
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<node,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		st.update(i,x);
	}
	cin>>Q;
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			st.update(x-1,y);
		}
		else {
			auto p=st.getval(x-1,y);
			if(p.mi>=1<<20) {
				cout<<-1<<endl;
			}
			else {
				cout<<p.mi<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
