#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string hoge(string s) {
	int dodo=1;
	int i;
	while(dodo) {
		dodo=0;
		FOR(i,s.size()-1) if(s[i]=='O' && s[i+1]=='O') {
			dodo=1;
			s=s.substr(0,i)+"o"+s.substr(i+2);
			goto out;
		}
		FOR(i,s.size()-1) if(s[i]=='o' && s[i+1]=='o') {
			dodo=1;
			s=s.substr(0,i)+"O"+s.substr(i+2);
			goto out;
		}
		
		out:
		;
	}
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	
	for(i=s.size()-8;i>=0;i--) {
		if(s.substr(i,8)=="ookayama"&& i && s[i-1]=='o') {
			int len=8;
			while(i&&s[i-1]=='o') i--,len++;
			s=s.substr(0,i)+hoge(s.substr(i,len))+s.substr(i+len);
		}
	}
	cout<<s<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
