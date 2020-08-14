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

string A[3][3]={
	{"ABC","DEF","GHCG"},
	{"AABC","DEFG","HIBCJ"},
	{"ABCDEF","GDFHI","BDJEDJ"},
};
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	FOR(i,10) V.push_back(i);
	do {
		string B[3];
		FOR(i,3) {
			FORR(c,A[N-1][i]) B[i]+='0'+V[c-'A'];
		}
		
		if(B[0][0]=='0') continue;
		if(B[1][0]=='0') continue;
		if(B[2][0]=='0') continue;
		int x=atoi(B[0].c_str());
		int y=atoi(B[1].c_str());
		int z=atoi(B[2].c_str());
		if(x+y==z) {
			//cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;
			cout<<z<<endl;
			return;
		}
		
		
		
	} while(next_permutation(ALL(V)));
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
