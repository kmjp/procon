#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[100000];
int p=1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(x,N) {
		for(j=1;j<10;j++) {
			FOR(i,p) {
				if(j%2==0) S[j*p+i]=S[i];
				else S[j*p+i]=S[p-1-i];
			}
		}
		FOR(j,10) FOR(i,p) S[j*p+i]+='0'+j;
		p*=10;
	}
	
	cout<<p-1<<endl;
	FOR(i,p) cout<<S[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
