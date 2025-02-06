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
ll X[2010],Y[2010];

int cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
	ll XX[3],YY[3];
	XX[0]=x2-x1; YY[0]=y2-y1;
	XX[1]=x3-x1; YY[1]=y3-y1;
	XX[2]=x4-x1; YY[2]=y4-y1;
	
	//bounding box判定。同一直線上に並ぶケースを除外
	if(max(x1,x2)<min(x3,x4)) return 0;
	if(max(x3,x4)<min(x1,x2)) return 0;
	if(max(y1,y2)<min(y3,y4)) return 0;
	if(max(y3,y4)<min(y1,y2)) return 0;
	
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if((c1<0&&c2<0)||(c1>0&&c2>0)) return 0;
	
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
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[N+i]=X[i];
		Y[N+i]=Y[i];
	}
	
	// 隣以外で交差したらアウト
	FOR(x,N) for(y=x+2;y<N;y++) {
		if(x==0&&y==N-1) continue;
		if(cross(X[x],Y[x],X[x+1],Y[x+1],X[y],Y[y],X[y+1],Y[y+1])) {
			cout<<0<<endl;
			return;
		}
	}
	//一直線ならアウト
	for(x=1;x<=N;x++) {
		ll dx1=X[x-1]-X[x];
		ll dy1=Y[x-1]-Y[x];
		ll dx2=X[x+1]-X[x];
		ll dy2=Y[x+1]-Y[x];
		if(dx1*dy2-dy1*dx2==0) {
			cout<<"0"<<endl;
			return;
		}
	}
	
	FOR(k,2) {
		FOR(i,N) {
			int ok=1;
			FOR(j,N) {
				ll dx1=X[j+1]-X[j];
				ll dy1=Y[j+1]-Y[j];
				ll dx2=X[i]-X[j];
				ll dy2=Y[i]-Y[j];
				if(dx1*dy2-dx2*dy1<0) ok=0;
			}
			if(ok) {
				cout<<1<<endl;
				return;
			}
		}
		reverse(X,X+2*N);
		reverse(Y,Y+2*N);
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
