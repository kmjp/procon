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

ll N;
ll ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N>200) {
		cout<<"000000000000"<<endl;
	}
	else {
		ret = 1;
		ll ret2=1;
		for(i=1;i<=N;i++) {
			ret=ret*i%1000000000000;
			ret2=ret2*i;
		}
		if(ret==ret2) {
			cout<<ret<<endl;
		}
		else {
			string S;
			FOR(i,12) {
				S += '0'+(ret%10);
				ret /= 10;
			}
			reverse(ALL(S));
			cout<<S<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
