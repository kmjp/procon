#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int CN=1001;
ll C[CN][CN];
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j]);
	
	cin>>N;
	int n5;
	
	for(int d=2;d<=30;d++) {
		ll p=0;
		FOR(n5,d) if(((n5+1)*2)%3==0) p+=C[d-1][n5];
		
		if(p>=N) {
			for(int mask=1;;mask+=2) if(__builtin_popcount(mask)*2%3==0) {
				if(--N==0) {
					FOR(x,d) s+='3'+((mask&(1<<x))!=0)*2;
					reverse(ALL(s));
					cout<<s<<endl;
					return;
				}
			}
		}
		else N-=p;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
