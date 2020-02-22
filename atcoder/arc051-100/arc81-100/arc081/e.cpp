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
int nex[202020][26];
int ne[26];
int len[202020],ta[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	FOR(i,26) ne[i]=nex[N+1][i]=N+1;
	for(i=N;i>=0;i--) {
		len[i]=202020;
		FOR(j,26) {
			nex[i][j]=ne[j];
			x = len[ne[j]];
			if(x<len[i]) {
				len[i]=x;
				ta[i]=j;
			}
		}
		len[i]++;
		if(i) ne[S[i-1]-'a']=i;
	}
	
	string R;
	int cur=0;
	while(cur!=N+1) {
		R+='a'+ta[cur];
		cur=nex[cur][ta[cur]];
	}
	
	cout<<R<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
