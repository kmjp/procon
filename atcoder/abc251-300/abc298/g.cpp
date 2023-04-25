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

int H,W,T;
ll A[10][10];
ll S[10][10];
ll memo[11][11][11][11];
ll TL,TR;

ll dfs(int U,int L,int D,int R) {
	if(memo[U][L][D][R]!=-1) return memo[U][L][D][R];
	ll ret=0;
	
	ll sum=S[D][R]-S[D][L]-S[U][R]+S[U][L];
	if(sum>=TL&&sum<=TR) ret|=2;
	for(int y=U+1;y<D;y++) {
		ll a=dfs(U,L,y,R);
		ll b=dfs(y,L,D,R);
		int i;
		FOR(i,37) if(a&(1LL<<i)) ret|=b<<i;
	}
	for(int x=L+1;x<R;x++) {
		ll a=dfs(U,L,D,x);
		ll b=dfs(U,x,D,R);
		int i;
		FOR(i,37) if(a&(1LL<<i)) ret|=b<<i;
	}
	return memo[U][L][D][R]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>T;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		
		S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x]+A[y][x];
	}
	vector<ll> cand;
	FOR(y,H) FOR(x,W) {
		for(int y1=1;y+y1<=H;y1++) {
			for(int x1=1;x+x1<=W;x1++) {
				ll sum=S[y+y1][x+x1]-S[y+y1][x]-S[y][x+x1]+S[y][x];
				cand.push_back(sum);
			}
		}
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	ll mi=1LL<<60;
	FORR(y,cand) FORR(x,cand) if(y>=x&&y-x<=mi) {
		TL=x;
		TR=y;
		MINUS(memo);
		ll a=dfs(0,0,H,W);

		if(a&(1LL<<(T+1))) {
			mi=min(mi,y-x);
		}
		else {
			break;
		}
	}
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
