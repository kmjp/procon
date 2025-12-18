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

int Q;
int Y[3],M[3],D[3],DD[3];

int day(int Y,int M,int D) {
	M--,D--;
	int ret=0,i;
	for(i=1;i<Y;i++) {
		ret+=365;
		if(i%4==0&&(i%100||i%400==0)) ret++;
	}
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(Y%4==0&&(Y%100||Y%400==0)) days[1]++;
	FOR(i,M) ret+=days[i];
	ret+=D;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		cin>>Y[i]>>M[i]>>D[i];
		DD[i]=day(Y[i],M[i],D[i]);
	}
	cin>>Q;
	while(Q--) {
		cin>>Y[2]>>M[2]>>D[2];
		DD[2]=day(Y[2],M[2],D[2]);
		if(DD[1]-DD[0]+1<DD[2]-DD[1]) cout<<"More"<<endl;
		if(DD[1]-DD[0]+1==DD[2]-DD[1]) cout<<"Same"<<endl;
		if(DD[1]-DD[0]+1>DD[2]-DD[1]) cout<<"Less"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
