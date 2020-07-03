#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int L[10101];

pair<int,int> hoge(int a,int b) {
	vector<int> V;
	int i;
	for(i=a;i<=b;i++) V.push_back(L[i]);
	sort(ALL(V));
	
	int ma=V.back();
	V.pop_back();
	int sum=0;
	FORR(v,V) sum+=v;
	
	int mi=max(ma-sum,0);
	
	return {mi,sum+ma};
	
	
}

double hoge2(double a,double b,double c) {
	double pi=atan(1)*4;
	if(b>c) swap(b,c);
	if(b+c<=a) return 0;
	if(b==0 || c==0) return 0;
	if(c>=a+b) return pi*b*b;
	
	double bt = acos((a*a+b*b-c*c)/(2*a*b));
	double ct = acos((a*a+c*c-b*b)/(2*a*c));
	
	double A=b*bt*b+c*ct*c-b*sin(bt)*b*cos(bt)-c*sin(ct)*c*cos(ct);
	
	return A;
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int sum=0;
	FOR(i,N+2) cin>>L[i];
	
	for(i=1;i<=N;i++) {
		auto a=hoge(1,i);
		auto b=hoge(i+1,N+1);
		
		double S=hoge2(L[0],a.second,b.second)+hoge2(L[0],a.first,b.first)-hoge2(L[0],a.second,b.first)-hoge2(L[0],a.first,b.second);
		_P("%.12lf\n",S);
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
