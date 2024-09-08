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

int H,W;
string S[20],T[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) cin>>T[y];
	
	int a=1,b=1;
	FOR(y,H) FOR(x,W) {
		if(S[y][x]==T[y][x]) a=0;
		if(S[y][x]==T[H-1-y][W-1-x]) b=0;
	}
	
	if(a&&b) {
		double ret=0;
		double p=1;
		for(i=1;i<=1000;i++) {
			double fail=pow(0.5,i-1);
			ret+=i*p*(1-fail);
			p*=fail;
		}
		_P("%.12lf\n",ret);
	}
	else if(a&&b==0) {
		double ret=0;
		double p=1;
		for(i=1;i<=1000;i++) {
			if(i%2) {
				double fail=pow(0.5,i-1);
				ret+=i*p*(1-fail);
				p*=fail;
			}
		}
		_P("%.12lf\n",ret);
	}
	else if(a==0&&b) {
		double ret=0;
		double p=1;
		for(i=1;i<=1000;i++) {
			if(i%2==0) {
				double fail=pow(0.5,i-1);
				ret+=i*p*(1-fail);
				p*=fail;
			}
		}
		_P("%.12lf\n",ret);
	}
	else {
		cout<<-1<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
