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

string S;
int num[10]={3,2,2,2,3,2,3,2,4,3};
int num2[10]={3,1,1,1,3,1,3,1,5,3};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int mi=101010;
	int ret=1;
	FORR(c,S) ret+=num[c-'0'];
	mi=min(mi,ret);
	
	ret=2;
	FORR(c,S) ret+=num2[c-'0'];
	mi=min(mi,ret);
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
