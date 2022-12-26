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


int T;
double R=0; //3.14159565351e59;

int ask(double D) {
	cout<<fixed<<setprecision(100)<<"? "<<D<<endl;
	string s;
	cin>>s;
	return s=="Yes";
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<double> V;
	FOR(i,100000) V.push_back(i*0.00001);
	for(i=0;V.size()<=(1<<24);i++) V.push_back(min(12.22e74,pow(1.000015,i)));
	cin>>T;
	while(T--) {
		int L=0;
		for(i=23;i>=0;i--) if(ask(V[L+(1<<i)])) L+=1<<i;
		cout<<fixed<<setprecision(100)<<"! "<<((V[L]+V[L+1])/2.0)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
