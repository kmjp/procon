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
string S[30303];

map<string,vector<int>> M;

string conv(string s) {
	string login,domain;
	int x=s.find('@');
	
	FORR(r,s) r=tolower(r);
	login = s.substr(0,x);
	domain = s.substr(x+1);
	
	if(domain!="bmail.com") return login+"@"+domain;
	string log2;
	FORR(r,login) {
		if(r=='.') continue;
		if(r=='+') break;
		log2+=r;
	}
	return log2+"@"+domain;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		M[conv(S[i])].push_back(i);
	}
	
	cout<<M.size()<<endl;
	FORR(r,M) {
		cout<<r.second.size();
		FORR(r2,r.second) cout<<" "<<S[r2];
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
