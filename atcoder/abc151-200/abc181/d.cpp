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

string S;
int C[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) C[c-'0']++;
	if(S.size()==1) {
		if(C[8]) return _P("Yes\n");
	}
	else if(S.size()==2) {
		for(x=1;x<=9;x++) for(y=1;y<=9;y++) {
			if(C[x]==0||C[y]==0||(x==y&&C[x]<=1)) continue;
			if((x*10+y)%8==0) return _P("Yes\n");
		}
	}
	else {
		FOR(i,10) if(C[i]) {
			C[i]--;
			FOR(j,10) if(C[j]) {
				C[j]--;
				FOR(k,10) if(C[k]) {
					if((i*100+j*10+k)%8==0) return _P("Yes\n");
				}
				C[j]++;
			}
			C[i]++;
		}
	}
	
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
