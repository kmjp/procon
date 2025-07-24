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

int N,Q;
string S;

struct node {
	ll v0; //‘S‘Ì‚ª0/1
	ll v1;
	ll v1f; //“r’†‚Å1‚ÅI‚í‚é
	ll o00; //0‚ğó‚¯‚Ä0‚É‚È‚é
	ll o01;
	ll o10;
	ll o11;
	ll o01f;  //01‚ğ‚¤‚¯“r’†‚Å1‚ÅI‚í‚é
	ll o11f;
};

node def={0,0,0,1,0,0,1,0,0};

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){
		V m;
		m.v0=r.v0+l.v0*r.o00+l.v1*r.o10;
		m.v1=r.v1+l.v0*r.o01+l.v1*r.o11;
		m.v1f=l.v1f+r.v1f+l.v0*r.o01f+l.v1*r.o11f;
		m.o00=l.o00*r.o00+l.o01*r.o10;
		m.o01=l.o00*r.o01+l.o01*r.o11;
		m.o10=l.o10*r.o00+l.o11*r.o10;
		m.o11=l.o10*r.o01+l.o11*r.o11;
		m.o01f=l.o01f+l.o00*r.o01f+l.o01*r.o11f;
		m.o11f=l.o11f+l.o10*r.o01f+l.o11*r.o11f;
		return m;
	};
	
	SegTree_ma(){
		val.resize(2*NV,def);
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry,node  v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<node,1<<18> st;

node create_node(string v) {
	if(v=="T") return  {0,1,1, 0,0,0,0, 0,0};
	if(v=="F") return  {1,0,0, 0,0,0,0, 0,0};
	if(v=="+T") return {0,1,1, 0,1,0,1, 1,1};
	if(v=="*F") return {1,0,0, 1,0,1,0, 0,0};
	if(v=="^T") return {0,1,1, 0,1,1,0, 1,0};
	if(v=="+F") return {1,0,0, 1,0,0,1, 0,1};
	if(v=="*T") return {0,1,1, 1,0,0,1, 0,1};
	if(v=="^F") return {1,0,0, 1,0,0,1, 0,1};
	return node{};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	N=N/2+1;
	for(i=1;i<N;i++) st.update(i,create_node(S.substr(i*2-1,2)));
	while(Q--) {
		cin>>x>>y;
		x=(x-1)/2;
		y=(y-1)/2;
		
		auto p=create_node(S.substr(x*2,1));
		auto q=st.getval(x+1,y+1);
		auto r=st.comp(p,q);
		cout<<r.v1f<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
