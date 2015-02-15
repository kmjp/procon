#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
string FF[12][5000];
int F[3][55];
int num[2][20001];

int okok(int level,int k,int offset) {
	if(level<10) return S.substr(offset,FF[level][k].size())==FF[level][k];
	int len=F[2][level];
	if(num[0][offset+len]-num[0][offset]!=F[0][level]) return 0;
	if(num[1][offset+len]-num[1][offset]!=F[1][level]) return 0;
	
	if(k%2) return okok(level-2,k/4,offset) && okok(level-1,k/2,offset+F[2][level-2]);
	else return okok(level-1,k/2,offset) && okok(level-2,k/4,offset+F[2][level-1]);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	if(S=="a") return _P("2 0\n");
	if(S=="b") return _P("1 0\n");
	FOR(i,S.size()) num[0][i+1]=num[0][i]+(S[i]=='b');
	FOR(i,S.size()) num[1][i+1]=num[1][i]+(S[i]=='a');
	
	FF[1][0]="b";
	FF[2][0]="a";
	for(i=3;i<=11;i++) FOR(k,1<<(i-2)) {
		if(k%2) FF[i][k]=FF[i-2][k/4]+FF[i-1][k/2];
		else FF[i][k]=FF[i-1][k/2]+FF[i-2][k/4];
	}
	
	F[0][1]=F[2][1]=1;
	F[1][2]=F[2][2]=1;
	for(i=3;i<=25;i++) F[0][i]=F[0][i-1]+F[0][i-2];
	for(i=3;i<=25;i++) F[1][i]=F[1][i-1]+F[1][i-2];
	for(i=3;i<=25;i++) F[2][i]=F[2][i-1]+F[2][i-2];
	
	for(x=3;x<=35;x++) if(F[2][x]==S.size()) break;
	FOR(y,1<<(x-2)) if(okok(x,y,0)) return _P("%d %d\n",x,y);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
