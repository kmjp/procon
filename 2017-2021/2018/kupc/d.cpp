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


int hoge;
int ask(int v) {
	string S;
	static int num=0;
	num++;
	assert(num<=30);
	
	if(hoge) return hoge%v%2;
	cout<<"? "<<v<<endl;
	cin>>S;
	return S=="odd";
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//cin>>hoge;
	int par=ask(2);
	int L=2-par,R=1000000000-par;
	while(R>L) {
		int M=(L+R)/2;
		if(M%2==0) M++;
		if(par!=ask(M)) {
			L=M;
			if(par==0) L++;
		}
		else {
			R=M-1;
			if(par) R--;
		}
	}
	
	cout<<"! "<<L<<endl;
	
}


int main(int argc,char** argv){
	solve(); return 0;
}
