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

int num[202];
int did[202];
int pat[202];
int N;

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	ZERO(num);
	ZERO(did);
	cin>>N;
	FOR(i,N) {
		int M;
		cin>>M;
		int id=-1,best=10101;
		FOR(j,M) {
			cin>>pat[j];
			num[pat[j]]++;
			if(did[pat[j]]==0 && num[pat[j]]<best) {
				id=pat[j];
				best=num[pat[j]];
			}
		}
		
		if(id==-1) {
			cout<<-1<<endl;
		}
		else {
			cout<<id<<endl;
			did[id]=1;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
