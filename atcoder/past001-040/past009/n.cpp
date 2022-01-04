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

int N,M;
vector<pair<double,double>> S;
vector<pair<double,double>> T;


pair<double,double> cross(pair<double,double> A1,pair<double,double> A2,pair<double,double> B1,pair<double,double> B2) {
	double sp=(B1.first-A1.first)*(B2.second-B1.second)-(B1.second-A1.second)*(B2.first-B1.first);
	double sq=(A2.first-A1.first)*(B2.second-B1.second)-(A2.second-A1.second)*(B2.first-B1.first);
	double tp=(A1.first-B1.first)*(A2.second-A1.second)-(A1.second-B1.second)*(A2.first-A1.first);
	double tq=(B2.first-B1.first)*(A2.second-A1.second)-(B2.second-B1.second)*(A2.first-A1.first);
	const double EPS=1e-9;
	if(abs(sq)<1e-9||abs(tq)<1e-9) return {1e9,1e9};
	sp/=sq;
	tp/=tq;
	//if(sp<-EPS||sp>1+EPS) return {1e9,1e9};
	//if(tp<-EPS||tp>1+EPS) return {1e9,1e9};
	double x=A1.first+(A2.first-A1.first)*sp;
	double y=A1.second+(A2.second-A1.second)*sp;
	return {x,y};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		S.push_back({x,y});
	}
	FOR(i,M) {
		cin>>x>>y;
		T.push_back({x,y});
	}
	
	FOR(i,M) {
		double tx=T[i].first;
		double ty=T[i].second;
		double tdx=T[(i+1)%M].first-T[i].first;
		double tdy=T[(i+1)%M].second-T[i].second;
		vector<pair<double,double>> NS;
		FOR(j,S.size()) {
			double sx1=S[j].first;
			double sy1=S[j].second;
			double sx2=S[(j+1)%S.size()].first;
			double sy2=S[(j+1)%S.size()].second;
			double c1=(sx1-tx)*tdy-(sy1-ty)*tdx;
			double c2=(sx2-tx)*tdy-(sy2-ty)*tdx;
			if(c1-1e-9<0) {
				NS.push_back(S[j]);
			}
			if((c1>1e-9&&c2<-1e-9)||(c2>1e-9&&c1<-1e-9)) {
				NS.push_back(cross(S[j],S[(j+1)%S.size()],T[i],T[(i+1)%M]));
			}
			
		}
		S=NS;
	}
	
	double A=0;
	FOR(i,S.size()) {
		A+=S[i].first*S[(i+1)%S.size()].second-S[i].second*S[(i+1)%S.size()].first;
	}
	_P("%.12lf\n",abs(A)/2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
