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

int T;
int N,K;
int A[505050];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;

ll hoge() {
	map<int,int> M;
	int i;
	ll ret=0;
	FOR(i,N) {
		ret+=bt(A[i]);
		bt.add(A[i]+1,1);
		bt.add(A[i]+K+1,-1);
		M[A[i]+K]++;
		while(1) {
			auto it=M.lower_bound(A[i]);
			if(it==M.end()||it->first>=A[i]+K) break;
			bt.add(it->first+1,it->second);
			bt.add(A[i]+K+1,-it->second);
			int v=it->second;
			M.erase(it);
			M[A[i]+K]+=v;
		}
	}
	FOR(i,N) bt.add(A[i]+1,-1);
	FORR2(a,b,M) bt.add(a+1,b);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		map<int,int> S;
		ll ret=0;
		FOR(i,N) {
			cin>>A[i];
			ret+=++S[A[i]];
		}
		ret+=hoge();
		reverse(A,A+N);
		ret+=hoge();
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
