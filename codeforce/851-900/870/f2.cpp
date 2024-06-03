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

int T,N;
double X[202],Y[202];
double RX[202],RY[202];
mt19937 engine(0);



void solve() {
	int i,j,k,l,r,x,y; string s;
	double PI=atan(1)*4;
	uniform_real_distribution<double> UD(0,PI);
	
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<"? 1 0 0"<<endl;
		FOR(i,N) cin>>Y[200]>>Y[i];
		cout<<"? 0 1 0"<<endl;
		FOR(i,N) cin>>X[i]>>X[200];
		double deg;
		vector<pair<double,double>> P;
		while(1) {
			deg=UD(engine);
			P.clear();
			double a=cos(deg),b=sin(deg);
			FOR(y,N) FOR(x,N) {
				double dot=X[x]*a+Y[y]*b;
				P.push_back({dot*a,dot*b});
			}
			int ok=1;
			FOR(x,P.size()) FOR(y,x) {
				if(abs(P[x].first-P[y].first)<0.001&&abs(P[x].second-P[y].second)<0.001) ok=0;
			}
			if(ok==1) break;
		}
		cout<<std::setprecision(12)<<"? "<<-sin(deg)<<" "<<cos(deg)<<" 0"<<endl;
		vector<pair<double,double>> ret;
		FOR(i,N) {
			double rx,ry;
			cin>>rx>>ry;
			FOR(y,N) FOR(x,N) {
				if(abs(rx-P[y*N+x].first)<0.0004&&abs(ry-P[y*N+x].second)<0.0004) ret.push_back({X[x],Y[y]});
			}
		}
		assert(ret.size()==N);
		
		cout<<"!";
		FOR(i,N) cout<<std::setprecision(12)<<" "<<ret[i].first<<" "<<ret[i].second;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
