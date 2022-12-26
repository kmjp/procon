#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A[5],T;
int memo[14][14][14][14];

int win() {
	int i;
	int& ret=memo[A[0]][A[1]][A[2]][A[3]];
	
	if(A[0]+A[1]+A[2]+A[3]==0) return 0;
	if(ret==-1) {
		ret=0;
		int i,j;
		FOR(j,4) {
			for(i=1;i<=min(A[j],3);i++) {
				A[j]-=i;
				if(win()==0) ret=1;
				A[j]+=i;
			}
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>A[0]>>A[1]>>A[2]>>A[3];
	
	MINUS(memo);
	if(win()) cout<<"Taro"<<endl;
	else cout<<"Jiro"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
