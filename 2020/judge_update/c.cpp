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

int A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	vector<int> V;
	if(A>=3) V.push_back(3);
	if(B>=3) V.push_back(3);
	if(C>=3) V.push_back(3);
	if(A>=2) V.push_back(2);
	if(B>=2) V.push_back(2);
	if(C>=2) V.push_back(2);
	if(A>=1) V.push_back(1);
	if(B>=1) V.push_back(1);
	if(C>=1) V.push_back(1);
	int ret=0;
	sort(ALL(V));
	do {
		int C[3]={};
		ret++;
		FORR(v,V) {
			if(v>1 && C[v-1]>=C[v-2]) {
				ret--;
				break;
			}
			C[v-1]++;
		}
		
	} while(next_permutation(ALL(V)));
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
