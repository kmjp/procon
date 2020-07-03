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

int cnt[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	FORR(c,s) cnt[c]++;
	int p1=0,p2=0;
	char cc=0;
	FOR(i,256) {
		if(cnt[i]==1) p1++,cc=i;
		if(cnt[i]==2) p2++;
	}
	
	if(p1==1 && p2==6) {
		cout<<cc<<endl;
	}
	else {
		cout<<"Impossible"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
