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

int A,B;
ll L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>L>>R;
	L--;
	set<string> Q;
	string S,T;
	FOR(i,A) S+='a'+i;
	T=S;
	
	while(1) {
		
		S+=string(B,S.back());
		int mask=0;
		
		FOR(i,A) mask |= 1<<(S[S.size()-1-i]-'a');
		int left=A;
		string R;
		FOR(i,26) if(left && (mask&(1<<i))==0) {
			R+='a'+i;
			left--;
		}
		if(T==R) break;
		
		S+=R;
	}
	
	
	if(R-L>=S.size()*2) {
		set<int> T;
		FORR(c,S) T.insert(c);
		cout<<T.size()<<endl;
	}
	else {
		S+=S;
		S+=S;
		R-=L/(A+B)*(A+B);
		L-=L/(A+B)*(A+B);
		set<int> T;
		for(i=L;i<R;i++) T.insert(S[i]);
		cout<<T.size()<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
