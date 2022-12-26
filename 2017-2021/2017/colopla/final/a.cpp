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
vector<pair<char,ll>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) {
		if(V.empty() || V.back().first!=c) V.push_back({c,0});
		V.back().second++;
	}
	
	ll ret=0;
	if(V.size()==1) {
		if(V[0].first=='A') ret=1LL*(N*S.size())*(N*S.size()+1)/2;
	}
	else if(N==1) {
		int cur=0;
		FORR(c,S) {
			if(c=='A') cur++;
			else cur=0;
			ret+=cur;
		}
	}
	else {
		vector<pair<char,ll>> A,B,C;
		A=B=C=V;
		if(A.back().first=='A') {
			if(B[0].first=='A') {
				B[0].second+=A.back().second;
				C[0].second+=A.back().second;
			}
			else {
				B.insert(B.begin(),A.back());
				C.insert(C.begin(),A.back());
			}
			A.pop_back();
		}
		if(B.back().first=='A') B.pop_back();
		
		FORR(v,A) if(v.first=='A') ret+=v.second*(v.second+1)/2;
		FORR(v,B) if(v.first=='A') ret+=(N-2)*v.second*(v.second+1)/2;
		FORR(v,C) if(v.first=='A') ret+=v.second*(v.second+1)/2;
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
