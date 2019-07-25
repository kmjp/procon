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

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int num=0;
	FORR(c,S) num+=c-'0';
	string R;
	while(num) {
		x=min(num,9);
		num-=x;
		R.push_back('0'+x);
	}
	reverse(ALL(R));
	if(S==R) {
		if(R.size()==1) {
			R="1"+R;
			R.back()--;
		}
		else if(R[0]=='9') {
			R[0]--;
			R="1"+R;
		}
		else {
			R[0]++;
			R[1]--;
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
