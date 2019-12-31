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
int ma[26][26];
string A,B;
int lef[26];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(i,26) ma[i][i]=lef[i]=1;
	FOR(i,N) {
		cin>>A>>B;
		FOR(j,min(A.size(),B.size())) {
			if(A[j]!=B[j]) {
				ma[A[j]-'a'][B[j]-'a']=1;
				break;
			}
		}
		if(j==min(A.size(),B.size()) && A.size()>=B.size()) return _P("-1\n");
	}
	
	FOR(z,26) FOR(x,26) FOR(y,26) ma[x][y] |= ma[x][z] && ma[z][y];
	FOR(x,26) FOR(y,26) if(x!=y && ma[x][y] && ma[y][x]) return _P("-1\n");
	
	string R;
	while(R.size()<26) {
		FOR(x,26) if(lef[x]) {
			int ng=0;
			FOR(y,26) if(x!=y && lef[y] && ma[y][x]) ng=1;
			if(ng==0) {
				lef[x]=0;
				R += 'a'+x;
				break;
			}
		}
	}
	
	cout<<R<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
