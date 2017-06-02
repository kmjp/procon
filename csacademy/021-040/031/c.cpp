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

ll F[51];
int N,K;

string hoge(int a,int b) {
	if(b>F[a]) return "-1";
	if(a==0) return "a";
	if(a==1) return "b";
	if(a==2) return "c";
	
	if(b<=F[a-1]) return hoge(a-1,b);
	b-=F[a-1];
	if(b<=F[a-2]) return hoge(a-2,b);
	b-=F[a-2];
	if(b<=F[a-3]) return hoge(a-3,b);
	return "-1";
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=F[1]=F[2]=1;
	for(i=3;i<=50;i++) F[i]=F[i-1]+F[i-2]+F[i-3];
	
	cin>>N>>K;
	
	cout<<hoge(N,K)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
