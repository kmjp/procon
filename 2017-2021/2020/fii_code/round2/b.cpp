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
int K;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size();
	string T=S.substr(0,N-1);
	reverse(ALL(T));
	K--;
	S+=T;
	
	ll cnt[26]={};
	FORR(c,S) cnt[c-'a']++;
	
	FOR(j,K) {
		FOR(i,26) {
			cnt[i]*=2;
			if(i==S[0]-'a') cnt[i]--;
		}
	}
	FOR(i,26) cout<<cnt[i]<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
