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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) {
		if(c<'a' || c>'m') {
			cout<<"Impossible"<<endl;
			return;
		}
		cnt[c]++;
	}
	int ok=0;
	for(x='a';x<='m';x++) {
		cnt[x]++;
		
		int is[3]={};
		FOR(i,256) {
			if(cnt[i]==1) is[1]++;
			if(cnt[i]==2) is[2]++;
		}
		
		if(is[1]==12 && is[2]==1) {
			ok=1;
			cout<<(char)x<<endl;
		}
			
		
		
		cnt[x]--;
	}
	
	if(ok==0) cout<<"Impossible"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
