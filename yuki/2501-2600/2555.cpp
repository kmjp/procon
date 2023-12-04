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

int A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	
	for(x=1;x<=100;x++) for(y=1;y<=100;y++) if(x+y+A<B+C && B<x+y+A+C && C<x+y+A+B) {
		double cb=(B*B+(x+y+A)*(x+y+A)-C*C)/(2.0*B*(x+y+A));
		double AD=sqrt(x*x+B*B-2*x*B*cb);
		double cad=(AD*AD+B*B-x*x)/(2.0*AD*B);

		double cc=(C*C+(x+y+A)*(x+y+A)-B*B)/(2.0*C*(x+y+A));
		double AE=sqrt(y*y+C*C-2*y*C*cc);
		double cae=(AE*AE+C*C-y*y)/(2.0*AE*C);
		
		if(abs(cad-cae)<=1e-7) {
			cout<<"Yes"<<endl;
			return;
		}
		
		
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
