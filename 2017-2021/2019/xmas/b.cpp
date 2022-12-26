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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(S=="=") {
		FOR(i,N) cout<<i<<" ";
		cout<<endl;
	}
	else if(S=="<") {
		if(N<=2) {
			cout<<"Merry Christmas!"<<endl;
		}
		else {
			cout<<0;
			FOR(i,N-1) cout<<" "<<(i+2);
			cout<<endl;
		}
	}
	else {
		if(N<=7) {
			cout<<"Merry Christmas!"<<endl;
		}
		else {
			vector<int> V;
			V.push_back(0);
			V.push_back(2);
			FOR(i,N-5) V.push_back(3+4*i);
			V.push_back(V.back()+1);
			V.push_back(V.back()+2);
			V.push_back(4);
			sort(ALL(V));
			FORR(v,V) cout<<v<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
