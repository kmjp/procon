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

int D,S1,T1,S2,T2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>S1>>S2>>T1>>T2;
	
	S1=S1*60+S2;
	T1=T1*60+T2;
	
	if(D<=5) {
		if(S1>=19*60 && T1<=22*60) cout<<"Yay!"<<endl;
		else cout<<":("<<endl;
	}
	else {
		if(S1>=7*60 && T1<=22*60) cout<<"Yay!"<<endl;
		else cout<<":("<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
