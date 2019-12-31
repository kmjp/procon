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

int N,K;
int rm[200001];
int num[200001];
double np[200001];
double res[200001];
int mi,ma;
string S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>S;
	
	num[0]=K;
	FOR(i,N) {
		
		if(S[i]=='0') {
			rm[i]=mi;
			num[mi]--, num[mi+1]++;
			ma=max(ma,mi+1);
			if(num[mi]==0) mi++;
		}
		else {
			rm[i]=ma;
			num[ma]--, num[ma+1]++;
			while(num[mi]==0) mi++;
			ma++;
		}
	}
	
	for(i=N-1;i>=0;i--) {
		j=rm[i];
		res[i]=j+1+np[j+1];
		np[j] = (np[j]*(num[j]) + (np[j+1]+1))/(num[j]+1.0);
		num[j+1]--;
		num[j]++;
	}
	
	FOR(i,N) _P("%.12lf\n",res[i]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
