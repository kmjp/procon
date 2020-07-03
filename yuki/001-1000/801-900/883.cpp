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

int N,K;
int T;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;

	cin>>N>>K;
	int NT=N;
	FOR(i,1010) if(i*min(i,K)>=N) {
		cout<<i<<endl;
		FOR(y,i) {
			string S(i,'.');
			FOR(x,min(i,K)) if(NT) {
				S[(x+y)%i]='#';
				NT--;
			}
			cout<<S<<endl;
		}
		break;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
