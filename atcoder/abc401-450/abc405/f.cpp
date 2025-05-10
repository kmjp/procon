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
vector<int> add[2020200];
vector<int> del[2020200];
vector<int> cand[2020200];

int C[2020200],D[2020200];
int ret[2020200];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,22> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		add[x].push_back(y);
		del[y].push_back(x);
		bt.add(x,1);
		bt.add(y,-1);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>C[i]>>D[i];
		cand[C[i]].push_back(i);
	}
	FOR(i,2*N+1) {
		FORR(a,add[i]) {
			bt.add(i,-1);
			bt.add(a,2);
		}
		FORR(a,del[i]) {
			bt.add(i,-1);
		}
		FORR(c,cand[i]) {
			ret[c]=bt(D[c]);
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
