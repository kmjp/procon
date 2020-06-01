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
int N,Q;
string T;

int nex[26][101010];
int pre[26][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,26) nex[i][N]=N+1;
	for(i=N-1;i>=0;i--) {
		FOR(x,26) nex[x][i]=nex[x][i+1];
		nex[S[i]-'a'][i]=i+1;
	}
	FOR(i,26) pre[i][0]=-1;
	FOR(i,N) {
		FOR(x,26) pre[x][i+1]=pre[x][i];
		pre[S[i]-'a'][i+1]=i;
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>T;
		int cur=0;
		FORR(c,T) {
			cur=nex[c-'a'][cur];
			if(cur>N) break;
		}
		if(cur>N) {
			cout<<-1<<endl;
			continue;
		}
		x=cur;
		reverse(ALL(T));
		FORR(c,T) x=pre[c-'a'][x];
		
		cout<<x+1<<" "<<cur<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
