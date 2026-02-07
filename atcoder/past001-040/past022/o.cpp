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
	int SA;
	int len;
	ll SB;
	ll pre[3];
	ll suf[3];
	ll ma[3];
};

template<int NV> class SegTree_ma {
public:
	vector<node> val;
	node comp(node l,node r){
		if(l.len==0) return r;
		if(r.len==0) return l;
		
		node m;
		m.len=l.len+r.len;
		m.SA=(l.SA+r.SA)%3;
		m.SB=l.SB+r.SB;
		int i,x,y;
		FOR(i,3) m.ma[i]=max(l.ma[i],r.ma[i]);
		chmax(m.ma[m.SA],m.SB);
		FOR(i,3) {
			m.pre[i]=l.pre[i];
			m.suf[i]=r.suf[i];
		}
		FOR(x,3) FOR(y,3) {
			chmax(m.ma[(x+y)%3],l.suf[x]+r.pre[y]);
			chmax(m.pre[(l.SA+x)%3],l.SB+r.pre[x]);
			chmax(m.suf[(r.SA+x)%3],r.SB+l.suf[x]);
		}
		
		return m;
	};
	
	SegTree_ma(){
		val.resize(NV*2);
		int i;
		FOR(i,NV*2) ZERO(&val[i]);
	};
	node getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) {
			node a;
			ZERO(&a);
			return a;
		}
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int a,int b) {
		entry += NV;
		node v;
		v.SA=a;
		v.SB=b;
		v.len=1;
		v.pre[0]=v.pre[1]=v.pre[2]=-1LL<<60;
		v.suf[0]=v.suf[1]=v.suf[2]=-1LL<<60;
		v.ma[0]=v.ma[1]=v.ma[2]=-1LL<<60;
		v.pre[a]=v.suf[a]=v.ma[a]=b;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<1<<20> st;

int N,Q;
int A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		st.update(i,A[i],B[i]);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			A[x-1]=y;
			st.update(x-1,A[x-1],B[x-1]);
		}
		else if(i==2) {
			cin>>x>>y;
			B[x-1]=y;
			st.update(x-1,A[x-1],B[x-1]);
		}
		else {
			int L,R,X;
			cin>>L>>R>>X;
			auto p=st.getval(L-1,R);
			
			if(p.ma[X]<-1LL<<50) {
				cout<<"No"<<endl;
			}
			else {
				cout<<p.ma[X]<<endl;
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
