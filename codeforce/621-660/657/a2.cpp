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
int N;
string S;
string H="abacaba";
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		string R;
		
		FOR(i,N-6) {
			string T=S;
			FOR(j,N) if(T[j]=='?') {
				if(j>=i && j<i+7) T[j]=H[j-i];
				else T[j]='z';
			}
			int num=0;
			FOR(j,N-6) if(T.substr(j,7)==H) num++;
			if(num==1) R=T;
			
		}
		if(R.size()) {
			cout<<"Yes"<<endl;
			cout<<R<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
			
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
