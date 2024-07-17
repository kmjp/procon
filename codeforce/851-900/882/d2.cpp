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
string S;
int order[202020];
int L[202020],R[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q>>S;
	set<int> alive;
	FOR(i,N) alive.insert(i);
	
	int nex=0;
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]--;
		while(1) {
			auto it=alive.lower_bound(L[i]);
			if(it==alive.end()||*it>=R[i]) break;
			order[*it]=nex++;
			alive.erase(it);
		}
	}
	
	int need=nex;
	FORR(a,alive) order[a]=nex++;
	
	FOR(i,N) if(S[i]=='1') {
		bt.add(order[i],1);
	}
	
	FOR(i,Q) {
		cin>>x;
		x--;
		if(S[x]=='0') {
			S[x]='1';
			bt.add(order[x],1);
		}
		else {
			S[x]='0';
			bt.add(order[x],-1);
		}
		int num=min(need,bt(N));
		cout<<num-bt(num-1)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
