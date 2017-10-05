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
ll K;
ll memo[50][50];
ll C[201][201];



ll hoge(int op,int cl) {
	if(op==0 && cl==0) return 0;
	if(cl<op) return 0;
	if(memo[op][cl]>=0) return memo[op][cl];
	ll ret=0;
	
	if(op==cl) {
		ret=C[op+cl][cl-1];
	}
	else {
		ret=hoge(op-1,cl)+hoge(op,cl-1);
		if(ret<0) ret=0x7FFFFFFFFFFFFFFFLL;
	}
	
	return memo[op][cl]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,190) {
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++) {
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]<0) C[i][j]=0x7FFFFFFFFFFFFFFFLL;
		}
	}
	
	MINUS(memo);
	cin>>N>>K;
	int op=N,cl=N;
	
	string R;
	int ng=0;
	while(op || cl) {
		if(op>cl) ng=1;
		if(op==0) {
			R+=")";
			cl--;
		}
		else if(cl==0) {
			R+="(";
			op--;
		}
		else if(ng) {
			if(C[op+cl-1][op-1]>=K) {
				R+="(";
				op--;
			}
			else {
				K-=C[op+cl-1][op-1];
				R+=")";
				cl--;
			}
		}
		else {
			if(hoge(op-1,cl)>=K) {
				R+="(";
				op--;
			}
			else {
				K-=hoge(op-1,cl);
				R+=")";
				cl--;
			}
		}
	}
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
