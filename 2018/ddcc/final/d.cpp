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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V def;
	V comp(V l,V r){
		V ret(36,0);
		int x,y,z;
		FOR(x,6) for(y=x;y<6;y++) for(z=y;z<6;z++) {
			ret[x*6+z]+=l[x*6+y]*r[y*6+z];
		}
		return ret;
	};
	
	SegTree_1(){
		def.resize(36);
		int i;
		FOR(i,6) def[i*6+i]=1;
		val=vector<V>(NV*2,def);
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<vector<unsigned int>,1<<20> st;
int N,Q;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>Q;
	N=S.size();
	FOR(i,N) {
		st.val[i+(1<<20)]=st.def;
		if(S[i]=='D') st.val[i+(1<<20)][0*6+(0+1)]=1;
		if(S[i]=='I') st.val[i+(1<<20)][1*6+(1+1)]=1;
		if(S[i]=='S') st.val[i+(1<<20)][2*6+(2+1)]=1;
		if(S[i]=='C') st.val[i+(1<<20)][3*6+(3+1)]=1;
		if(S[i]=='O') st.val[i+(1<<20)][4*6+(4+1)]=1;
	}
	
	for(i=(1<<20)-1;i>=1;i--) {
		st.val[i]=st.comp(st.val[i*2],st.val[i*2+1]);
	}
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		auto a=st.getval(L,R);
		cout<<a[5]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
