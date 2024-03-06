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
int H,W;
string S[505050];
int L[505050],R[505050];
int dp[505050];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
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
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
	}
	
	for(y=H-2;y>=0;y--) {
		FOR(x,W) {
			if(S[y][x]=='#') L[x]=-1;
			else {
				L[x]=0;
				if(x&&S[y][x-1]>=0) L[x]=1+L[x-1];
			}
		}
		for(x=W-1;x>=0;x--) {
			if(S[y][x]=='#') R[x]=-1;
			else {
				R[x]=0;
				if(x+1<W&&S[y][x+1]>=0) R[x]=1+R[x+1];
			}
		}
		FOR(x,W) st.update(x,dp[x]);
		FOR(x,W) {
			if(S[y][x]=='#') {
				dp[x]=1<<30;
			}
			else {
				int cur=1<<30;
				if(st.getval(x-L[x],x+R[x]+1)<1<<30) {
					cur=max({L[x],R[x],st.getval(x-L[x],x+R[x]+1)});
					for(i=20;i>=0;i--) {
						int tmp=cur-(1<<i);
						if(tmp<0) continue;
						int v=st.getval(x-min(L[x],tmp),x+min(R[x],tmp)+1);
						if(v<=tmp) cur=tmp;
					}
				}
				dp[x]=cur;
			}
		}
		
	}
	FOR(x,W) cout<<dp[x]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
