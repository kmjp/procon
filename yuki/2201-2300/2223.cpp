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
int A[505050];
int L[505050],R[505050];
int ret[505050];
vector<int> cand[505050];

struct D {
	int Lma,Rma,ma,sum;
};

template<class V,int NV> class SegTree_1 {
public:

	vector<V> val;
	V comp(V a,V b){
		if(b.sum==-1<<20) return a;
		if(a.sum==-1<<20) return b;
		V c;
		c.Lma=max(a.Lma,a.sum+b.Lma);
		c.Rma=max(a.Rma+b.sum,b.Rma);
		c.ma=max({a.ma,b.ma,a.Rma+b.Lma});
		c.sum=a.sum+b.sum;
		return c;
	}
	SegTree_1(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0,-1<<20};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
};
SegTree_1<D,1<<16> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		ret[i]=N;
		cand[N].push_back(i);
	}
	
	for(int span=1<<15;span>=1;span/=2) {
		for(int cur=N;cur>span;cur-=span*2) if(cand[cur].size()) {
			vector<int> c=cand[cur];
			cand[cur].clear();
			FOR(i,N) {
				if(A[i]<=cur-span) {
					st.val[(1<<16)+i]={-1,-1,-1,-1};
				}
				else {
					st.val[(1<<16)+i]={1,1,1,1};
				}
			}
			for(i=(1<<16)-1;i>=1;i--) st.val[i]=st.comp(st.val[i*2],st.val[i*2+1]);
			FORR(i,c) {
				D d=st.getval(L[i],R[i]);
				if(d.sum<0||d.sum-d.ma+1<0) ret[i]-=span;
				cand[ret[i]].push_back(i);
			}
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
