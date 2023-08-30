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

int N,H;
int X[2020],Y[2020];
vector<pair<double,int>> Vs;
vector<int> Xs;

double hoge(ll xx,ll xy,ll yy) {
	if(xx==0) return 0;
	double a=1.0*xy/xx;
	return (yy-2*a*xy+a*a*xx);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		double a=(Y[i]-H/2.0)/X[i];
		Vs.push_back({a,i});
		Xs.push_back(X[i]);
	}
	Xs.push_back(505);
	double ret=1e9;
	sort(ALL(Vs));
	FORR(px,Xs) {
		ll YY[2]={},XY[2]={},XX[2]={};
		FOR(i,N) {
			if(X[i]<px) {
				XX[1]+=(X[i]*X[i]);
				XY[1]+=(X[i]*(-H+Y[i]));
				YY[1]+=((-H+Y[i])*(-H+Y[i]));
			}
			else {
				XX[0]+=(X[i]*X[i]);
				XY[0]+=(X[i]*Y[i]);
				YY[0]+=(Y[i]*Y[i]);
			}
		}
		ret=min(ret,hoge(XX[0],XY[0],YY[0])+hoge(XX[1],XY[1],YY[1]));
		FORR2(d,i,Vs) {
			if(X[i]<px) {
				XX[0]+=(X[i]*X[i]);
				XY[0]+=(X[i]*Y[i]);
				YY[0]+=(Y[i]*Y[i]);
				XX[1]-=(X[i]*X[i]);
				XY[1]-=(X[i]*(-H+Y[i]));
				YY[1]-=((-H+Y[i])*(-H+Y[i]));
			}
			else {
				XX[0]-=(X[i]*X[i]);
				XY[0]-=(X[i]*Y[i]);
				YY[0]-=(Y[i]*Y[i]);
				XX[1]+=(X[i]*X[i]);
				XY[1]+=(X[i]*(-H+Y[i]));
				YY[1]+=((-H+Y[i])*(-H+Y[i]));
			}
			ret=min(ret,hoge(XX[0],XY[0],YY[0])+hoge(XX[1],XY[1],YY[1]));
		}
	}
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
