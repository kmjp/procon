#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S[13];

int ok(vector<int> V) {
	int x,y;
	FOR(x,V.size()) {
		int sum=0;
		for(y=x;y<V.size();y++) {
			sum+=V[y];
			if(sum%26==0) return 0;
		}
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<int> V;
	FOR(i,26) V.push_back(i);
	
	while(1) {
		vector<int> A,B;
		random_shuffle(ALL(V));
		FOR(i,12) A.push_back(V[i]);
		FOR(i,12) B.push_back(V[12+i]);
		
		if(ok(A)&&ok(B)) {
			i=0;
			cout<<13<<endl;
			FOR(y,13) {
				j=0;
				FOR(x,13) {
					S[y].push_back('a'+(i+j)%26);
					if(x<12) j+=B[x];
				}
				if(y<12) i+=A[y];
				cout<<S[y]<<endl;
			}
			return;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
