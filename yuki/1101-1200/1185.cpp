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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<int> S;
	for(i=12;i<=99;i+=3) S.insert(i);
	
	vector<int> C;
	C.push_back(0);
	FOR(i,9) {
		vector<int> D;
		FORR(c,C) {
			for(j=0;j<=9;j+=3) {
				x=c*10+j;
				S.insert(x);
				D.push_back(x);
			}
		}
		swap(C,D);
	}
	
	int N;
	cin>>N;
	int ret=0;
	FORR(s,S) {
		if(s>=10 && s<=N) {
			ret++;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
