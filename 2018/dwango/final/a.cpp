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

ll H,M,S,R;
int C1,C2;
int M1,M2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>M>>S;
	cin>>C1>>C2;
	R=12*3600;
	S=(H%12)*3600+M*60+S;
	H=S;
	M=S*12%R;
	S=S*12*60%R;
	
	int a=1<<30,b=0;
	int step=0;
	while(M1<=C1 && M2<=C2) {
		step++;
		if((M-S)*((M+12)-(S+720))<0) M1++;
		if((H-M)*((H+1)-(M+12))<0) M2++;
		H=(H+1)%R;
		M=(M+12)%R;
		S=(S+720)%R;
		int m=0;
		if(M==S) M1++,m=1;
		if(H==M) M2++,m=1;
		if(M1==C1 && M2==C2 && m==0) {
			a=min(a,step);
			b=max(b,step);
		}
	}
	
	if(a>b) _P("-1\n");
	else _P("%d %d\n",a,b);
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
