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

int A,B,C;

int hoge(int a,int b) {
	if(a>b) return a-b;
	return (b-a+1)/2;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>A>>B>>C;
	int mi=1010;
	FOR(x,100) FOR(y,100) FOR(z,100) {
		int AA=A+x+y;
		int BB=B+y+z;
		int CC=C+z+x;
		if(abs(AA-BB)%2) continue;
		if(abs(BB-CC)%2) continue;
		if(abs(CC-AA)%2) continue;
		int DD=max({AA,BB,CC});
		mi=min(mi,x+y+z+(DD-AA)/2+(DD-BB)/2+(DD-CC)/2);
		
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
