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

int A,B;
string S,T;

int po[202020];
int nexS[202020][26];
int nexT[202020][26];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size();
	B=T.size();
	
	MINUS(po);
	po[A]=B;
	x=A;
	for(i=B-1;i>=0;i--) {
		if(x&&S[x-1]==T[i]) {
			x--;
			po[x]=i;
		}
	}
	
	FOR(i,26) nexS[A][i]=A+1;
	FOR(i,26) nexT[B][i]=nexT[B+1][i]=B+1;
	for(i=A-1;i>=0;i--) {
		FOR(j,26) nexS[i][j]=nexS[i+1][j];
		nexS[i][S[i]-'a']=i+1;
	}
	for(i=B-1;i>=0;i--) {
		FOR(j,26) nexT[i][j]=nexT[i+1][j];
		nexT[i][T[i]-'a']=i+1;
	}
	
	if(po[0]>=0) {
		cout<<-1<<endl;
		return;
	}
	
	string R;
	x=y=0;
	while(x<A) {
		FOR(i,26) {
			int x2=nexS[x][i];
			int y2=nexT[y][i];
			if(x2<=A&&y2>po[x2]) {
				R+='a'+i;
				x=x2;
				y=y2;
				break;
			}
		}
		if(y>=B+1) break;
		if(i==26) break;
	}
	
	if(R.empty()) R="-1";
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
