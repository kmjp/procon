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

int M,K;
int num[404040];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

ll pat[404040];
vector<int> V[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>K;
	ll A=0;
	FOR(i,M*K) {
		cin>>x;
		y=num[x]++;
		V[y].push_back(x);
		A+=bt(1<<19)-bt(y*M+x);
		bt.add(y*M+x,1);
	}
	ZERO(bt.bit);
	
	FOR(i,K) {
		vector<pair<int,int>> P;
		FOR(j,V[i].size()) P.push_back({V[i][j],j});
		sort(ALL(P));
		FORR2(x,j,P) {
			int Lle=bt(j);
			int Lmo=j-bt(j);
			int Rle=bt(M-1)-bt(j);
			int Rmo=(M-1-j)-Rle;
			pat[x+1]+=-Lmo+Rmo-Lle+Rle;
			bt.add(j,1);
		}
		FOR(j,M) bt.add(j,-1);
	}
	
	ll mi=1LL<<60;
	FOR(i,M) {
		if(i) pat[i]+=pat[i-1];
		mi=min(mi,pat[i]);
	}
	
	cout<<(A+mi)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
