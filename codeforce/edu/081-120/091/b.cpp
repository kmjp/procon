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

int T;
string S;
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		int C[3]={};
		N=S.size();
		FORR(c,S) {
			if(c=='R') C[0]++;
			if(c=='P') C[1]++;
			if(c=='S') C[2]++;
		}
		
		if(C[0]>=C[1]&&C[0]>=C[2]) {
			FOR(i,N) cout<<"P";
		}
		else if(C[1]>=C[0]&&C[1]>=C[2]) {
			FOR(i,N) cout<<"S";
		}
		else {
			FOR(i,N) cout<<"R";
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
