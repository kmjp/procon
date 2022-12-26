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

int ptr;
string S;
int cnt[256];

pair<char,int> hoge() {
	if(S[ptr]=='[') {
		ptr++;
		auto a=hoge();
		assert(S[ptr]=='-');
		ptr++;
		auto b=hoge();
		assert(S[ptr]==']');
		ptr++;
		
		if(cnt[a.first]!=a.second && cnt[b.first]!=b.second) {
			_P("No\n");
			exit(0);
		}
		if(cnt[a.first]==a.second && cnt[b.first]==b.second) {
			_P("No\n");
			exit(0);
		}
		if(cnt[a.first]==a.second) {
			b.second++;
			if(cnt[b.first]<b.second) {
				_P("No\n");
				exit(0);
			}
			return b;
		}
		if(cnt[b.first]==b.second) {
			a.second++;
			if(cnt[a.first]<a.second) {
				_P("No\n");
				exit(0);
			}
			return a;
		}
		
	}
	else {
		return {S[ptr++],0};
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	FOR(i,26) {
		cin>>s;
		if(s.empty() || cnt[s[0]]) break;
		cin>>cnt[s[0]];
	}
	
	auto a=hoge();
	if(cnt[a.first]==a.second) {
		_P("Yes\n");
	}
	else {
		_P("No\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
