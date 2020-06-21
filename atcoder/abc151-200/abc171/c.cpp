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

string S;
ll N;
ll p[13],s[13];
void solve() {
	int i,j,k,l,r,x,y;
	
	p[0]=1;
	FOR(i,12) {
		p[i+1]=p[i]*26;
		s[i+1]=s[i]+p[i+1];
	}
	cin>>N;
	for(i=1;i<=12;i++) {
		if(N<=s[i]) {
			N--;
			N-=s[i-1];
			for(j=i;j>=1;j--) {
				S.push_back((char)('a'+(N/p[j-1])));
				N%=p[j-1];
			}
			break;
		}
	}
	
	
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
