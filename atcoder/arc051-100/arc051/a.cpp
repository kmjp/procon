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

int X1,Y1,R;
int X2,Y2,X3,Y3;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X1>>Y1>>R;
	cin>>X2>>Y2>>X3>>Y3;
	int red=0,blue=0;
	for(y=Y2;y<=Y3;y++) {
		for(x=X2;x<=X3;x++) {
			if((x-X1)*(x-X1)+(y-Y1)*(y-Y1)>R*R) blue=1;
		}
	}
	
	red=1;
	if(X2<=X1-R && X3>=X1+R && Y2<=Y1-R && Y3>=Y1+R) red=0;
	
	_P("%s\n",red?"YES":"NO");
	_P("%s\n",blue?"YES":"NO");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
