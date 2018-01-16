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

int N;
string S;
ll mo=998244353;
map<string,ll> memo;

ll hoge(string S) {
	if(S.empty()) return 1;
	if(memo.count(S)) return memo[S];
	ll ret=0;
	
	ret = (1+S[0])*hoge(S.substr(1))%mo;
	for(int rep=1;rep<=S.size()/2;rep++) {
		string C(rep,1);
		for(int num=1;rep*num<=S.size();num++) {
			for(int x=(num-1)*rep;x<rep*num;x++) C[x%rep] &= S[x];
			if(num>1) (ret+=hoge(C)*hoge(S.substr(rep*num)))%=mo;
		}
		
	}
	
	return memo[S]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) c-='0';
	
	cout<<hoge(S)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
