#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N[10];

pair<int,int> ask(int a,int b,int c,int d) {
	int x,y;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	cin>>x>>y;
	return {x,y};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mi=4;
	for(i=3;i<=9;i++) {
		auto r=ask(0,1,2,i);
		N[i]=r.first+r.second;
		mi=min(mi,N[i]);
	}
	for(i=3;i<=9;i++) N[i]=N[i]-mi;
	for(i=0;i<=2;i++) {
		auto r=ask(i,7,8,9);
		N[i]=r.first+r.second-N[7]-N[8]-N[9];
	}
	vector<int> V;
	FOR(i,10) if(N[i]) V.push_back(i);
	do {
		auto r=ask(V[0],V[1],V[2],V[3]);
		if(r.first==4) return;
	} while(next_permutation(ALL(V)));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
