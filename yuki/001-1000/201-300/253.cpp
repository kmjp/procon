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

int ask(int Y){
	cout << "? " << Y << endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	x=ask(80);
	
	if(x==0) {
		cout << "! " << 80 << endl;
		return;
	}
	if(x<0) {
		for(i=2;i<=100;i++) {
			x=ask(0);
			if(x==0) {
				cout << "! " << i-1 << endl;
				return;
			}
		}
	}
	
	int L=80,R=1000000009;
	int num=1;
	while(L<R) {
		int M=(L+R)/2;
		
		x=ask(M-num);
		if(x==0) {
			cout << "! " << M << endl;
			return;
		}
		num++;
		if(x>0) L=M+1;
		else R=M;
	}
	cout << "! " << L << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
