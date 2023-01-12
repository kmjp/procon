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

int M,D,K;

set<int> S;
void hoge(int x) {
	S.insert(x%10), x/=10;
	S.insert(x%10), x/=10;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>D>>K;
	M--;
	D--;
	FOR(i,7) {
		hoge(M+1);
		hoge(D+1);
		D++;
		int C[]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(D>=C[M]) {
			D=0;
			M++;
			if(M==12) M=0;
		}
	}
	if(S.size()>=K) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
