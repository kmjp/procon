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

int N,M,A[10101][101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> V;
	FOR(y,N) FOR(x,M) {
		cin>>A[y][x];
		V.push_back(A[y][x]);
	}
	sort(ALL(V));
	ll ret=0;
	for(y=N-1;y>=0;y--) {
		FOR(x,M) A[y][x]=lower_bound(ALL(V),A[y][x])-V.begin();
		sort(A[y],A[y]+M);
		FOR(x,M) {
			//self
			ret+=1LL*y*(1+x);
			ret+=bt(A[y][x]);
		}
		FOR(x,M) bt.add(A[y][x],1);
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
