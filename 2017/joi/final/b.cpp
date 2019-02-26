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

int N,M,K;
ll A,B,C;
ll S[3030];
ll T;
ll ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>A>>B>>C;
	cin>>T;
	N--;
	FOR(i,M) cin>>S[i],S[i]--;
	
	vector<ll> cand;
	
	FOR(i,M) {
		ll t=S[i]*B;
		if(t>T) continue;
		
		if(i==M-1) {
			ret++;
			continue;
		}
		
		ll tar=min(S[i+1],S[i]+(T-t)/A+1);
		ret+=tar-S[i];
		FOR(j,3010) {
			ll left=T-(S[i]*B+(tar-S[i])*C);
			if(left<0) continue;
			ll nex=min(S[i+1],tar+left/A+1);
			cand.push_back(nex-tar);
			tar=nex;
		}
	}
	
	sort(ALL(cand));
	reverse(ALL(cand));
	FOR(i,min(K-M,(int)cand.size())) ret+=cand[i];
	
	cout<<ret-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
