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
int A[202020];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return l|r;};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
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
SegTree_ma<int,1<<20> st;

map<int,int> M[202020];
int nex[30][202020];
vector<pair<int,int>> add[202020],del[202020];

map<int,multiset<int>> memo;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(j,30) nex[j][N]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,30) {
			nex[j][i]=nex[j][i+1];
			if(A[i]&(1<<j)) nex[j][i]=i+1;
		}
	}
	add[0].push_back({0,0});
	del[0].push_back({0,0});
	int ret=0;
	FOR(i,N) {
		FORR2(a,b,add[i]) {
			memo[a].insert(b);
			ret=max(ret,b);
		}
		vector<int> cand={N+1};
		FOR(j,30) cand.push_back(nex[j][i]);
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());
		
		FORR2(a,b,memo) {
			int v=0;
			int num=*b.rbegin();
			FOR(j,cand.size()-1) {
				v|=A[cand[j]-1];
				if(v>=a) {
					add[cand[j]].push_back({v,num+1});
					del[cand[j+1]-1].push_back({v,num+1});
				}
			}
		}
		
		FORR2(a,b,del[i]) {
			memo[a].erase(memo[a].find(b));
			if(memo[a].empty()) memo.erase(a);
		}
	}
	FORR2(a,b,add[N]) {
		ret=max(ret,b);
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
