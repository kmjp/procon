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

int N;
set<pair<string,string> > S;

pair<string,string> dodo(string s) {
	int i,x,y;
	pair<string,string> ret;
	FOR(i,s.size()) if(s[i]=='.') {
		ret.first=s.substr(0,i);
		s=s.substr(i+1);
		break;
	}
	x=y=-1;
	FOR(i,s.size()) {
		if(s[i]=='(') x=i;
		if(s[i]==')') y=i;
	}
	if(x==-1) {
		while(s.size()<600) s+="0";
	}
	else {
		string t=s.substr(x+1,y-x-1);
		s=s.substr(0,x);
		while(s.size()<600) s+=t;
		s.resize(600);
		int is9=1;
		for(i=400;i<600;i++) if(s[i]!='9') is9=0;
		if(is9) {
			for(i=599;i>=0;i--) {
				if(s[i]!='9') {
					s[i]++;
					break;
				}
				s[i]='0';
			}
			if(i==-1) {
				for(i=ret.first.size()-1;i>=0;i--) {
					if(ret.first[i]!='9') {
						ret.first[i]++;
						break;
					}
				}
				if(i==-1) ret.first="1"+ret.first;
			}
		}
	}
	ret.second=s;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		cin>>s;
		S.insert(dodo(s));
	}
	cout<<S.size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
