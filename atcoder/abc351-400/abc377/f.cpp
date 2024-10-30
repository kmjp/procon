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

ll N,M;
set<int> R,C,RpC,RmC;
set<pair<int,int>> S;

void add(int y,int x) {
	if(y>=0&&y<N&&x>=0&&x<N) S.insert({y,x});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		R.insert(y);
		C.insert(x);
		RpC.insert(y+x);
		RmC.insert(y-x);
	}
	FORR(r,R) {
		FORR(c,C) S.insert({r,c});
		FORR(k,RpC) add(r,k-r);
		FORR(k,RmC) add(r,r-k);
	}
	FORR(c,C) {
		FORR(k,RpC) add(k-c,c);
		FORR(k,RmC) add(k+c,c);
	}
	FORR(a,RpC) FORR(b,RmC) if((a+b)%2==0) {
		add((a+b)/2,(a-b)/2);
	}
	
	ll ret=1LL*N*N;
	ret-=R.size()*N;
	ret-=C.size()*N;
	FORR(a,RpC) {
		if(a<N) ret-=a+1;
		else ret-=2*N-1-a;
	}
	FORR(a,RmC) {
		ret-=N-abs(a);
	}
	
	FORR2(y,x,S) {
		ret--;
		if(R.count(y)) ret++;
		if(C.count(x)) ret++;
		if(RpC.count(y+x)) ret++;
		if(RmC.count(y-x)) ret++;
		
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
