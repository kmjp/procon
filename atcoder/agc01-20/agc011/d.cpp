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
string S;
string T;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	int pos=0,rev=0,revn=0;
	while(pos<N && K-->0){
		
		if((S[pos]=='A') ^ rev ^ revn) {
			revn^=1;
		}
		else {
			pos++;
			revn = 0;
			rev ^=1;
		}
	}
	
	string R;
	if(pos==N) {
		while(R.size()<N) {
			if((N-R.size())%2==1) R+='A';
			else R+='B';
		}
		if(R[0]=='A' && K%2) R[0]='B';
	}
	else {
		int first=1;
		while(pos<N) {
			if(rev ^ ((first==1)&&revn)) R+='A'+'B'-S[pos];
			else R+=S[pos];
			pos++;
			first=0;
		}
		while(R.size()<N) {
			if((N-R.size())%2==1) R+='A';
			else R+='B';
		}
	}
	cout<<R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
