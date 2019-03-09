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

int A,B,Q;
vector<ll> S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>Q;
	S.resize(A);
	T.resize(B);
	FOR(i,A) cin>>S[i];
	FOR(i,B) cin>>T[i];
	
	while(Q--) {
		ll v;
		cin>>v;
		ll mi=1LL<<60;
		
		
		x=lower_bound(ALL(S),v)-S.begin();
		if(x!=S.size()) {
			y=lower_bound(ALL(T),S[x])-T.begin();
			if(y!=T.size()) mi=min(mi,abs(v-S[x])+abs(S[x]-T[y]));
			if(y!=0) mi=min(mi,abs(v-S[x])+abs(S[x]-T[y-1]));
		}
		x--;
		if(x>=0) {
			y=lower_bound(ALL(T),S[x])-T.begin();
			if(y!=T.size()) mi=min(mi,abs(v-S[x])+abs(S[x]-T[y]));
			if(y!=0) mi=min(mi,abs(v-S[x])+abs(S[x]-T[y-1]));
		}
		
		x=lower_bound(ALL(T),v)-T.begin();
		if(x!=T.size()) {
			y=lower_bound(ALL(S),T[x])-S.begin();
			if(y!=S.size()) mi=min(mi,abs(v-T[x])+abs(T[x]-S[y]));
			if(y!=0) mi=min(mi,abs(v-T[x])+abs(T[x]-S[y-1]));
		}
		x--;
		if(x>=0) {
			y=lower_bound(ALL(S),T[x])-S.begin();
			if(y!=S.size()) mi=min(mi,abs(v-T[x])+abs(T[x]-S[y]));
			if(y!=0) mi=min(mi,abs(v-T[x])+abs(T[x]-S[y-1]));
		}
		cout<<mi<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
