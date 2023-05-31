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

ll N,A,B,C,D;
ll X[3030],S[3030];
ll dp[3030][3030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1LL<<60);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<13> st[3020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C>>D;
	FOR(i,N) {
		cin>>X[i];
		S[i+1]=S[i]+X[i];
	}
	
	for(int len=1;len<=N;len++) {
		for(i=0;i+len<=N;i++) {
			dp[i][i+len]=-1LL<<60;
			chmax(dp[i][i+len],X[i+len-1]-dp[i][i+len-1]);
			chmax(dp[i][i+len],X[i]-dp[i+1][i+len]);
			if(len<=B) {
				chmax(dp[i][i+len],S[i+len]-S[i]-A);
			}
			else {
				chmax(dp[i][i+len],S[i+len]-S[i]-A+st[len-B].getval(i,i+B+1));
			}
			if(len<=D) {
				chmax(dp[i][i+len],S[i+len]-S[i]-C);
			}
			else {
				chmax(dp[i][i+len],S[i+len]-S[i]-C+st[len-D].getval(i,i+D+1));
			}
			st[len].update(i,-(S[i+len]-S[i])-dp[i][i+len]);
		}
	}
	
	
	cout<<dp[0][N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
