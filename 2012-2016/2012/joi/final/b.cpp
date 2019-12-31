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

int A,B;
int S[5050],T[5050];
int cnt[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	FOR(i,A) cin>>S[i];
	FOR(i,B) cin>>T[i];
	
	int ma=0;
	FOR(x,B) {
		int cur=0;
		for(y=x;y<B;y++) {
			while(cur<A && S[cur]!=T[y]) cur++;
			if(cur==A) break;
			cur++;
		}
		ma=max(ma,y-x);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
