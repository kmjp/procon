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

ll ret;
void hoge(ll A,ll B,vector<ll>& V) {
	if(A>B) {
		ret++;
		return;
	}
	
	hoge(A+1,B,V);
	
	int ng=0;
	FORR(v,V) if(__gcd(v,A)!=1) ng=1;
	if(ng==0) {
		V.push_back(A);
		hoge(A+1,B,V);
		V.pop_back();
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	ll A,B;
	cin>>A>>B;
	
	vector<ll> V;
	hoge(A,B,V);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
