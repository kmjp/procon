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

int A,B;
ll C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	vector<ll> V,W;
	FOR(i,60) {
		if(C&(1LL<<i)) V.push_back(1LL<<i);
		else W.push_back(1LL<<i);
	}
	x=V.size();
	
	FOR(i,x+1) {
		j=x-i;
		int add=A-i;
		if(B-j!=add) continue;
		if(j<0||add<0||add>W.size()||j>B) continue;
		ll X=0,Y=0;
		FOR(y,i) X|=V[y];
		FOR(y,j) Y|=V[i+y];
		FOR(y,add) {
			X|=W[y];
			Y|=W[y];
		}
		if((X^Y)!=C) continue;
		cout<<X<<" "<<Y<<endl;
		return;
		
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
