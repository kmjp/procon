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

int N;
string S,T;
set<int> A,B;
int Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	
	FOR(i,N) {
		if(S[i]<T[i]) A.insert(i);
		if(S[i]>T[i]) B.insert(i);
	}
	A.insert(N);
	B.insert(N);
	cin>>Q;
	while(Q--) {
		string C;
		cin>>C>>j>>k;
		j--;
		A.erase(j);
		B.erase(j);
		if(C=="S") S[j]='0'+k;
		else T[j]='0'+k;
		
		if(S[j]<T[j]) A.insert(j);
		if(S[j]>T[j]) B.insert(j);
		if(*A.begin()>*B.begin()) cout<<">"<<endl;
		else if(*A.begin()<*B.begin()) cout<<"<"<<endl;
		else cout<<"="<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
