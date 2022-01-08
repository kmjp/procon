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

int dif[10000];
ll p10[10001];




void hoge(int v) {
	cout<<string(v,'7')<<endl;
	exit(0);
}
void hoge2(int a,int b) {
	cout<<string(a,'7')<<"1"<<string(b,'7')<<endl;
	exit(0);
}
void hoge3(int a,int b,int c) {
	cout<<string(a,'7')<<dif[b]/10<<string(b,'7')<<dif[b]%10<<string(c,'7')<<endl;
	exit(0);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,10000) p10[i+1]=p10[i]*10%7;
	for(x=1;x<=6;x++) {
		for(y=1;y<=6;y++) {
			for(i=1;i<=3000;i++) {
				if((x*p10[i]+y)%7) dif[i-1]=x*10+y;
			}
		}
	}
	
	
	
	map<int,int> M;
	for(i=1;i<=2000;i++) {
		M[i*(i+1)/2]=i;
		assert(dif[i]);
	}
	
	cin>>N;
	
	for(i=1;i<=2000;i++) {
		if(i*(i+1)/2==N) hoge(i);
		for(j=1;j<=2000;j++) {
			x=i*(i+1)/2+j*(j+1)/2;
			if(x==N) hoge2(i,j);
			if(x>N) break;
			if(M.count(N-x)) hoge3(i,j,M[N-x]);
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
