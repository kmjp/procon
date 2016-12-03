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

ll A,B,C;
vector<pair<int,int>> V;
int S[201010],L;

string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>T;
	L=T.size();
	FORR(c,T) {
		c-='0';
		if(V.empty() || V.back().first!=c) {
			V.push_back({c,1});
		}
		else {
			V.back().second++;
		}
	}
	
	ll mi=1LL<<60;
	if(V.size()==1) {
		if(T[0]==0) mi=min(A*L,B*L+C);
		else mi=min(A*L+C,B*L);
	}
	else {
		FOR(i,V.size()) S[i+1]=S[i]+V[i].second;
		
		// all left
		mi = min(mi, A*L+C*((int)V.size()-1+(V[0].first!=0)));
		// all right
		mi = min(mi, B*L+C*((int)V.size()-1+(V.back().first!=1)));
		for(i=1;i<=V.size()-1;i++) {
			ll left=A*S[i];
			ll right=B*(L-S[i]);
			ll sw=C*max(i-1+(V[0].first!=0), (int)V.size()-i-1+(V.back().first!=1));
			mi = min(mi, left+right+sw);
		}
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
