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
int fail[10100];

int ask(int a,int b) {
	int ret;
	cout<<"Q "<<(a+1)<<" "<<(b+1)<<endl;
	cin>>ret;
	return ret-1;
}


int hoge(int a,int b) {
	if(b-a<=1) return a;
	int m=(a+b)/2;
	int x = hoge(a,m);
	int y = hoge(m,b);
	int z = ask(x,y);
	
	if(z==x) {
		fail[y]=x;
		return x;
	}
	else {
		fail[x]=y;
		return y;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(fail);
	x = hoge(0,N);
	vector<int> cand;
	FOR(i,N) if(fail[i]==x) cand.push_back(i);
	
	x = cand[0];
	for(i=1;i<cand.size();i++) x = ask(x,cand[i]);
	cout<<"A "<<x+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
