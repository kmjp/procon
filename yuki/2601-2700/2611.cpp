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

const ll mo=998244353;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V def;
	V comp(V l,V r){
		V v;
		v[0]=l[0]+r[0];
		v[1]=l[1]+r[1];
		v[2]=l[2]+r[2]+r[0]*(l[0]+l[1]);
		v[3]=l[3]+r[3]+r[1]*(l[0]+l[1]);
		v[4]=l[4]+r[4]+r[0]*r[1]*(l[0]+l[1])+l[2]*r[1]+l[3]*r[0];
		v[5]=l[5]+r[5]+l[0]*(r[0]+r[1]);
		v[6]=l[6]+r[6]+l[1]*(r[0]+r[1]);
		v[7]=l[7]+r[7]+l[0]*l[1]*(r[0]+r[1])+r[5]*l[1]+r[6]*l[0];
		v[8]=l[8]+r[8]+l[4]*(r[0]+r[1])+r[7]*(l[0]+l[1])+l[2]*r[6]+l[3]*r[5];
		int i;
		FOR(i,9) v[i]=v[i]%mo;
		return v;
	};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		if(v==0) val[entry]={1,0,1,0,0,1,0,0,0};
		if(v==1) val[entry]={0,1,0,1,0,0,1,0,0};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
//0,1,a,b,ab,c,d,cd,g(x)
SegTree_1<array<ll,9>,1<<20> st;
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	cin>>s;
	FOR(i,N) {
		s[i]-='0';
		st.update(i,s[i]);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			x--;
			s[x]^=1;
			st.update(x,s[x]);
		}
		else {
			cin>>x>>y;
			auto v=st.getval(x-1,y);
			cout<<v[8]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
