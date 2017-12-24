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
char S[101010];

int ok(int L) {
	int i;
	deque<int> D;
	FOR(i,N) if(S[i]!=S[i+1]) D.push_back(i+1);
	if(L>N) return 0;
	
	
	while(D.size()) {
		if(D.back()-D.front()>=L) {
			D.pop_back();
			D.pop_front();
		}
		else {
			if(D.front()+L>N && D.front()-L<0) return 0;
			D.pop_front();
		}
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=strlen(S);
	S[N]='0';
	
	int mi=1;
	for(i=20;i>=0;i--) if(ok(mi+(1<<i))) mi+=1<<i;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
