#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
string S,T;
int NN[1002][1002];
ll dd[1010];
ll mo=1000000007;

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>S;
	FOR(i,N) {
		cin>>T;
		FOR(j,S.size()-T.size()+1) {
			if(S.substr(j,T.size())==T) NN[j][T.size()]++;
		}
	}
	dd[0]=1;
	FOR(i,S.size()) {
		for(j=1;j<=S.size();j++) dd[i+j]=(dd[i+j]+dd[i]*NN[i][j])%mo;
	}
	cout << dd[S.size()] << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


