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

string S;
int Y,M,D;

int ok(int Y,int M,int D) {
	set<char> S;
	string a=to_string(Y);
	string b=to_string(M);
	string c=to_string(D);
	FORR(v,a) S.insert(v);
	FORR(v,b) S.insert(v);
	FORR(v,c) S.insert(v);
	if(M<10||D<10) S.insert('0');
	return S.size()==2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	Y=atoi(S.substr(0,4).c_str());
	M=atoi(S.substr(5,2).c_str());
	D=atoi(S.substr(8,2).c_str());
	
	while(ok(Y,M,D)==0) {
		D++;
		int MD[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(Y%4==0&&Y%100&&Y%400==0) MD[2]++;
		if(D>MD[M]) {
			D=1;
			M++;
			if(M==13) {
				Y++;
				M=1;
			}
		}
	}
	_P("%d/%02d/%02d\n",Y,M,D);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
