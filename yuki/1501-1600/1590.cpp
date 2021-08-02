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
int A[505];
int R[505];
pair<int,int> P[1010];
int O[505];

double from[505];
double to[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>R[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	FOR(i,N) O[P[i].second]=i;
	
	double ret=0;
	FOR(x,N) {
		ZERO(from);
		from[0]=1;
		FOR(y,N) {
			ZERO(to);
			
			if(O[y]<=O[x]) {
				for(k=N;k>=0;k--) from[k+1]=from[k];
				from[0]=0;
			}
			
			FOR(k,y+2) {
				to[k]+=from[k]/2.0;
				if(y>=x&&k==1) {
					ret+=from[k]/2.0*A[x]*R[y];
				}
				else {
					to[max(0,k-1)]+=from[k]/2.0;
				}
			}
			swap(from,to);
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
