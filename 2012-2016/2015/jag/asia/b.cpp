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

string S,T,A,B;

ll score(string a,string b) {
	ll v=0;
	ll p10=1;
	for(int i=a.size()-1;i>=0;i--) {
		v+=p10*(a[i]-b[i]);
		p10*=10;
	}
	v=abs(v);
	return min(v,p10-v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	string T;
	FOR(i,10) T.push_back('0'+i);
	
	string R;
	ll ma=-1;
	do {
		string A=T.substr(0,S.size());
		ll sc=score(A,S);
		if(sc>ma || (sc==ma && A<R)) R=A, ma=sc;
	} while(next_permutation(ALL(T)));
	
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
