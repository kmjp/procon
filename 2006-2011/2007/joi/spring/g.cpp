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
int N;
int cnt[26];
ll fact[30];

ll pat() {
	int tot=0;
	int i;
	ll ret=1;
	FOR(i,26) tot+=cnt[i];
	ret=fact[tot];
	FOR(i,26) ret/=fact[cnt[i]];
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=20;i++) fact[i]=fact[i-1]*i;
	
	cin>>S;
	N=S.size();
	FORR(c,S) {
		c-='A';
		cnt[c]++;
	}
	
	ll ret=1;
	FOR(i,N) {
		FOR(j,S[i]) if(cnt[j]) {
			cnt[j]--;
			ret+=pat();
			cnt[j]++;
		}
		cnt[S[i]]--;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
