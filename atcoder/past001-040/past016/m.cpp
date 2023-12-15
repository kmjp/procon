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

int X[2][2],Y[2][2];

int cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
	ll XX[3],YY[3];
	XX[0]=x2-x1; YY[0]=y2-y1;
	XX[1]=x3-x1; YY[1]=y3-y1;
	XX[2]=x4-x1; YY[2]=y4-y1;
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<0&&c2<0)||(c1>0&&c2>0)) return 0;
	
	if(c1==0&&c2==0) {
		//ˆê’¼üã
		ll a1=0;
		ll a2=1LL*(x2-x1)*(x2-x1)+1LL*(y2-y1)*(y2-y1);
		ll a3=1LL*(x3-x1)*(x2-x1)+1LL*(y3-y1)*(y2-y1);
		ll a4=1LL*(x4-x1)*(x2-x1)+1LL*(y4-y1)*(y2-y1);
		if(a1>a2) swap(a1,a2);
		if(a3>a4) swap(a3,a4);
		return max(a1,a3)<=min(a2,a4);
	}
	
	XX[0]=x4-x3; YY[0]=y4-y3;
	XX[1]=x1-x3; YY[1]=y1-y3;
	XX[2]=x2-x3; YY[2]=y2-y3;
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<0&&c2<0)||(c1>0&&c2>0)) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0][0]>>Y[0][0]>>X[0][1]>>Y[0][1];
	cin>>X[1][0]>>Y[1][0]>>X[1][1]>>Y[1][1];
	
	if(cross(X[0][0],Y[0][0],X[0][1],Y[0][1],X[1][0],Y[1][0],X[1][1],Y[1][1])) {
		cout<<"Yes"<<endl;
		return;
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
