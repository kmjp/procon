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
int SY[2],SM[2],SD[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		cin>>S;
		FORR(c,S) c-='0';
		SY[i]=S[0]*1000+S[1]*100+S[2]*10+S[3];
		SM[i]=S[5]*10+S[6]-1;
		SD[i]=S[8]*10+S[9]-1;
		
	}
	
	int pat=0;
	int cur=0;
	for(int y=2022;y<10000;y++) {
		int m=0,d=0;
		int D[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(y%4==0&&y%100) D[1]++;
		if(y%400==0) D[1]++;
		while(m<12) {
			int add=0;
			
			if(y>SY[0]||(y==SY[0]&&(m>SM[0]||(m==SM[0]&&d>=SD[0])))) add=1;
			if(y>SY[1]||(y==SY[1]&&(m>SM[1]||(m==SM[1]&&d>SD[1])))) add=0;
			
			if(cur==0||cur==1) pat+=add;
			d++;
			if(d>=D[m]) d=0,m++;
			cur=(cur+1)%7;
		}
	}
	cout<<pat<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
