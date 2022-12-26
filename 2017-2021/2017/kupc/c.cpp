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

int A;
string S;
int K[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>S;
	FOR(i,S.size()) K[i]=S[i]-'a'+1;
	FOR(i,26010) {
		FOR(j,1001) {
			if(K[j+1]>=1 && K[j]+A<=26) {
				K[j]+=A;
				K[j+1]--;
			}
		}
	}
	FOR(i,1010) {
		if(K[i]==0) break;
		_P("%c",'a'+K[i]-1);
	}
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
