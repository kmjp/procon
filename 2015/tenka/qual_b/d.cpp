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

int D,N;
string S[10100];
string mp="DIZEhsqLBGO";
string s[240];

void solve() {
	int i,j,k,l,r,x,y;;
	
	cin>>D>>N;
	
	int allzero=1;
	FOR(i,N) {
		cin>>S[i];
		FORR(r,S[i]) FOR(x,11) if(r==mp[x]) r='0'+x%10;
		reverse(ALL(S[i]));
		if(S[i][0]!='0') allzero=0;
	}
	
	sort(S, S+N, [](string &a, string &b){return a + b < b + a;});
	
	FOR(i,N) {
		string t=S[N-1-i];
		int l=t.size();
		for(j=200;j>=0;j--) if(j==0 || s[j].size()) {
			if(j+l>D) continue;
			if(!allzero && j==0 && t[0]=='0') continue;
			s[j+l]=max(s[j+l],s[j]+t);
		}
	}
	if(allzero) {
		string ma;
		FOR(i,D+1) {
			while(s[i].size() && s[i].back()=='0') s[i].pop_back();
			ma=max(ma,s[i]);
		}
		if(ma.size()) cout<<"0."<<ma.substr(1)<<endl;
		else cout<<0<<endl;
	}
	else {
		for(i=D;i>=0;i--) if(s[i].size()) {
			cout<<s[i]<<endl;
			break;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
