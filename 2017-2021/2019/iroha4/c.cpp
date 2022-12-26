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


bitset<100008> BS[65538];
bitset<100008> C;
string S;
int N,M;
ll X;

int more(bitset<100008>& a,bitset<100008>& b,int len) {
	int i;
	FOR(i,min(N,len)) {
		if(a[i]&&b[i]==0) return 1;
		if(a[i]==0&&b[i]==1) return 0;
	}
	if(N>len) return 1;
	
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>M;
	N=S.size();
	FOR(i,S.size()) {
		BS[0][i]=S[i]=='1';
	}
	FOR(i,(1<<16)+1) {
		BS[i+1]=BS[i]^(BS[i]<<2);
		BS[i+1][S.size()]=BS[i+1][S.size()+1]=0;
	}
	
	ll cur=0;
	FOR(i,M) {
		cin>>X>>S;
		FOR(j,S.size()) C[j]=S[j]=='1';
		
		FOR(j,min(1LL<<16,X-cur)+1) {
			if(more(BS[(cur+j)%(1<<16)],C,S.size())) break;
		}
		if(j>=min(1LL<<16,X-cur)+1) return _P("No\n");
		cur+=j;
	}
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
