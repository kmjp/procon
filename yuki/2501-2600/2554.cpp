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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V a;
		int i,j;
		ll rs=0;
		FOR(i,53) a[i]=l[i]+r[i];
		FOR(i,26) rs+=r[i];
		FOR(i,26) {
			//M + MA
			a[52]+=l[i]*r[26+i];
			//M + A
			a[i+26]+=l[i]*(rs-r[i]);
			//MM + A
			a[52]+=l[i]*(l[i]-1)/2*(rs-r[i]);
		}
		return a;
	};
	
	SegTree_1(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return V();
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, char v) {
		entry += NV;
		int i;
		FOR(i,53) val[entry][i]=0;
		val[entry][v-'A']=1;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,53>,1<<17> st;

int N;
string S;
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) st.update(i,S[i]);
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>s;
			st.update(x-1,s[0]);
		}
		else {
			cin>>x>>y;
			auto a=st.getval(x-1,y);
			cout<<a[52]<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
