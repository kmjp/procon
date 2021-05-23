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

int N,M,Q;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
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

SegTree_1<int,1<<20> st;

vector<pair<int,int>> E[202020];

int dp[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	FOR(i,Q) {
		cin>>x;
		st.update(i+1,x);
	}
	FOR(i,N) {
		dp[i]=202020;
	}
	dp[0]=0;
	priority_queue<pair<int,int>> PQ;
	PQ.push({0,0});
	while(PQ.size()) {
		int day=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		if(dp[cur]!=day) continue;
		ret[day]++;
		FORR2(e,c,E[cur]) {
			x=st.getval(day+1,Q+1);
			if(x<c) continue;
			int R=Q;
			for(i=18;i>=0;i--) if(R-(1<<i)>day&&st.getval(day+1,R-(1<<i)+1)>=c) R-=1<<i;
			if(dp[e]>R) {
				dp[e]=R;
				PQ.push({-R,e});
			}
		}
		
	}
	
	
	for(i=1;i<=Q;i++) {
		ret[i]+=ret[i-1];
		cout<<ret[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
