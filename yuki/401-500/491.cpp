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

ll N;
string A;
ll ret=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<string> V;
	for(i=1;i<=99999;i++) {
		char buf[1010];
		string S,T;
		sprintf(buf,"%d",i);
		S=buf;
		T=S;
		reverse(ALL(T));
		
		V.push_back(S+T);
		V.push_back(S+T.substr(1));
	}
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	cin>>A;
	string Z="000000000000000";
	FORR(a,V) {
		if(a.size()>9) continue;
		string b = a+Z.substr(0,9-a.size())+a;
		if(b.size()<A.size() || (b.size()==A.size() && b<=A)) ret++;
		
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
