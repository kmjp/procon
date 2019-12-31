#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int P[10];

int ma=0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,9) cin>>P[i];
	sort(P,P+9);
	do {
		ma=max(ma,min(P[0]+P[1]+P[2],min(P[3]+P[4]+P[5],P[6]+P[7]+P[8])));
		
	}while (next_permutation(P,P+9));
	cout<<ma/3<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
