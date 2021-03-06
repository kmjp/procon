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
int A[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int num=0;
	FOR(y,N) FOR(x,N) if((2*x+y)%5==0) {
		A[y][x]|=3;
		num++;
		if(y) A[y-1][x]|=1;
		if(x) A[y][x-1]|=1;
		A[y+1][x]|=1;
		A[y][x+1]|=1;
	}
	
	FOR(y,N) {
		FOR(x,N) {
			if(A[y][x]==0) A[y][x]=3, num++;
			if(A[y][x]==3) cout<<"X";
			else cout<<".";
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
