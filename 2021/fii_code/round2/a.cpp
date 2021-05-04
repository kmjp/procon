#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int A,B;

map<pair<int,int>,int> M;

int win(int A,int B) {
	if(M.count({A,B})) return M[{A,B}];
	
	int ok=0;
	int i;
	for(i=1;i<A;i++) if(win(i,A-i)==0) ok=1;
	for(i=1;i<B;i++) if(win(i,B-i)==0) ok=1;
	
	cout<<A<<" "<<B<<" "<<ok<<endl;
	return M[{A,B}]=ok;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	if(A%2==1&&B%2==1) {
		cout<<"P"<<endl;
	}
	else {
		cout<<"A"<<endl;
	}
	return;
	if(win(A,B)) cout<<"A"<<endl;
	else cout<<"B"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
