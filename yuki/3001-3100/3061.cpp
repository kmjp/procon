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

int N;
int P[603030];
string S;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=-1;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<21> st;

int dfs(int L,int R) {
	if(R<=L) return 0;
	auto p=st.getval(L,R);
	int cur=p.second;
	if(S[p.first]=='B') return max({1,dfs(L,cur),dfs(cur+1,R)});
	return dfs(L,cur)+dfs(cur+1,R);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		P[N+i]=P[i];
	}
	cin>>S;
	if(count(ALL(S),'B')==0) {
		cout<<0<<endl;
		return;
	}
	if(S[N-1]=='W') {
		cout<<-1<<endl;
		return;
	}
	x=y=-1;
	FOR(i,2*N) {
		st.update(i,P[i]);
		if(P[i]==N-1) {
			if(x==-1) x=i;
		}
		if(P[i]==N-2) {
			if(x>=0&&y==-1) y=i;
		}
	}
	int r1=dfs(x+1,y);
	int r2=dfs(y+1,x+N);
	int ret;
	if(S[N-2]=='B') {
		ret=max({1,r1,r2});
	}
	else {
		ret=max({1,r1+r2});
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
