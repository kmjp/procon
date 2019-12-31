#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	return v;
}

int L,K;
string S,T;
int LL[1001000],SS[2001000];
vector<int> Z;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>K>>S;
	
	Z=Zalgo(S);
	
	for(x=1;x*K<=L;x++) {
		FOR(y,K) if(Z[y*x]<x) break;
		if(y==K) LL[x*K-1]=x;
	}
	ll t=0;
	FOR(i,L) if(LL[i]) {
		SS[i]++;
		SS[min(i+LL[i]+1,i+1+Z[i+1])]--;
	}
	
	x=0;
	FOR(i,L) x+=SS[i], T+=x?'1':'0';
	cout<<T<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
