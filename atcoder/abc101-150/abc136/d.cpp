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

int nex[101010][11];
int cur[101010];
int num[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	FOR(i,N) {
		x=i;
		FOR(j,10) {
			if(S[x]=='L') x--;
			else x++;
		}
		nex[i][0]=x;
		cur[i]=i;
	}
	
	FOR(i,10) {
		FOR(j,N) {
			x=j;
			FOR(y,10) x=nex[x][i];
			nex[j][i+1]=x;
			if(100&(1<<i)) cur[j]=nex[cur[j]][i];
		}
	}
	
	FOR(i,N) num[cur[i]]++;
	FOR(i,N) cout<<num[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
