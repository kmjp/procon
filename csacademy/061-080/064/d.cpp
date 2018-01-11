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

int memo[505][505];

int win(int left,int step) {
	step=min(step,left);
	if(left==0) return 0;
	
	if(memo[left][step]>=0) return memo[left][step];
	int ret=0;
	for(int i=1;i<=step;i++) if(win(left-i,i)==0) {
		ret=i;
		break;
	}
	return memo[left][step]=ret;
	
}

int N,S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	S=N-1;
	int step=500;
	while(N>0 && step) {
		step--;
		x=1;
		while(N%(x*2)==0) x*=2;
		cout<<x<<endl;;
		N-=x;
		cin>>S;
		N-=S;
	}
	return;
	
	
	
	
	MINUS(memo);
	for(x=1;x<=50;x++) {
		cout<<x<<"\t";
		for(y=1;y<=x-1;y++) cout<<win(x,y)<<",";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
