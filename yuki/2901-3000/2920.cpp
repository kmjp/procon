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

string A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	int P[4]={};
	FORR(a,A) FORR(b,B) {
		string C;
		C+=a;
		C+=b;
		sort(ALL(C));
		if(C=="AA"||C=="AO") P[0]++;
		if(C=="BB"||C=="BO") P[1]++;
		if(C=="AB") P[2]++;
		if(C=="OO") P[3]++;
	}
	FOR(i,4) P[i]*=25;
	cout<<P[0]<<" "<<P[1]<<" "<<P[2]<<" "<<P[3]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
