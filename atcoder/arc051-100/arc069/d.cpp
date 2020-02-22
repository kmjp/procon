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
string S;
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,4) {
		if(i==0) T="SS";
		if(i==1) T="SW";
		if(i==2) T="WS";
		if(i==3) T="WW";
		for(j=1;j<N-1;j++) {
			if((T[j]=='S') ^ (S[j]=='o')){
				T.push_back('S'+'W'-T[j-1]);
			}
			else {
				T.push_back(T[j-1]);
			}
		}
		
		if((T[N-1]=='S') ^ (S[N-1]=='o') ^ (T[N-2]!=T[0])) continue;
		if((T[0]=='S') ^ (S[0]=='o') ^ (T[N-1]!=T[1])) continue;
		cout<<T<<endl;
		return;
		
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
