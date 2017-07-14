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

int H[2],M[2],S[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) {
		cin>>H[0]>>M[0]>>S[0]>>H[1]>>M[1]>>S[1];
		H[1]-=H[0];
		M[1]-=M[0];
		S[1]-=S[0];
		if(S[1]<0) S[1]+=60, M[1]--;
		if(M[1]<0) M[1]+=60, H[1]--;
		cout<<H[1]<<" "<<M[1]<<" "<<S[1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
