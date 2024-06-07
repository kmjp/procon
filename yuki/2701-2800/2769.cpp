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
ll X[1010],Y[1010];

map<pair<pair<ll,ll>,pair<ll,ll>>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		FOR(j,i) {
			ll sx=X[i]+X[j];
			ll sy=Y[i]+Y[j];
			ll dx=X[i]-X[j];
			ll dy=Y[i]-Y[j];
			if(dx<0) {
				dx=-dx;
				dy=-dy;
			}
			if(dx==0) dy=abs(dy);
			ll g=__gcd(abs(dx),abs(dy));
			dx/=g;
			dy/=g;
			M[{{sx,sy},{dx,dy}}]++;
			
			if(dx==0) {
				ret+=M[{{sx,sy},{1,0}}];
			}
			else if(dy==0) {
				ret+=M[{{sx,sy},{0,1}}];
			}
			else {
				swap(dx,dy);
				dx=-dx;
				if(dx<0) {
					dx=-dx;
					dy=-dy;
				}
				if(dx==0) dy=abs(dy);
				
				ret+=M[{{sx,sy},{dx,dy}}];
			}
			
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
