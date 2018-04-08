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

int T,testcase;
int A;
int H,W;
int did[25][25];

void dig(int y,int x) {
	int i,j;
	while(1) {
		int num=0;
		if(y<H-1 && x<W-1) {
			if(did[y-1][x-1]==0) return;
		}
		
		FOR(i,3) FOR(j,3) num+=did[y-1+i][x-1+j];
		if(num==0) break;
		cout<<x<<" "<<y<<endl;
		cin>>i>>j;
		if(i==0&&j==0) ZERO(did);
		did[j][i]=0;
	}
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	if(A==20) H=4,W=5;
	if(A==200) H=10,W=20;
	ZERO(did);
	for(x=1;x<=W;x++) for(y=1;y<=H;y++) did[y][x]=1;
	
	for(y=2;y<=H-1;y++) for(x=2;x<=W-1;x++) dig(y,x);
	
}


int main(int argc,char** argv){
	string s;int i;
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
