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

int N,M;
int A[202020],B[202020],S[202020],T[202020],id[202020],sid[202020];
vector<pair<int,int>> Ss[202020];
ll X[202020];

vector<pair<int,int>> ev;
vector<pair<int,int>> Ts[202020]; 

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	// static V const def=1LL<<60; min
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
SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X[0];
	FOR(i,M) {
		cin>>A[i]>>B[i]>>S[i]>>T[i];
		A[i]--,B[i]--;
		ev.push_back({S[i],i});
		Ts[B[i]].push_back({T[i],i});
	}
	x=0;
	FOR(i,N) {
		sid[i]=x;
		sort(ALL(Ts[i]));
		FORR2(a,b,Ts[i]) id[b]=x++;
	}
	st.update(id[0],T[0]+X[0]);
		
	
	sort(ALL(ev));
	FORR2(a,i,ev) {
		x=lower_bound(ALL(Ts[A[i]]),make_pair(S[i]+1,0))-Ts[A[i]].begin();
		
		if(x) {
			ll y=st.getval(sid[A[i]],sid[A[i]]+x);
			X[i]=max(0LL,y-S[i]);
			st.update(id[i],T[i]+X[i]);
		}
		
	}
	
	
	
	
	FOR(i,M) if(i) cout<<X[i]<<" ";
	cout<<endl;
	
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
