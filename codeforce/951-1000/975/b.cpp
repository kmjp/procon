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

int T,N,A[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
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
SegTree_1<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			st.update(i,A[i]);
		}
		
		int miL=1<<20,maR=0;
		int L=0,R=N-1;
		while(1) {
			int len=R-L+1;
			if(st.getval(L,R+1)>=len) break;
			if(A[R]>=len) {
				R--;
				continue;
			}
			if(A[L]>=len) {
				L++;
				continue;
			}
			L=R+1;
			break;
		}
		if(L<=R) {
			miL=min(miL,L);
			maR=max(maR,R);
		}
		L=0,R=N-1;
		while(1) {
			int len=R-L+1;
			if(st.getval(L,R+1)>=len) break;
			if(A[L]>=len) {
				L++;
				continue;
			}
			if(A[R]>=len) {
				R--;
				continue;
			}
			L=R+1;
			break;
		}		
		if(L<=R) {
			miL=min(miL,L);
			maR=max(maR,R);
		}
		if(maR>=miL) cout<<maR-miL+1<<endl;
		else cout<<0<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
