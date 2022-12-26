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


int N,Q;
int X[50],Y[50],Z[50];
ll W[50];
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i]>>Z[i]>>W[i];
		X[i]--,Y[i]--,Z[i]--;
	}
	ll pat=1;
	FOR(i,60) {
		int mask;
		int num=0;
		FOR(mask,1<<N) {
			int ok=1;
			FOR(j,Q) {
				x=(mask>>X[j])|(mask>>Y[j])|(mask>>Z[j]);
				if((x&1)!=((W[j]>>i)&1)) ok=0;
			}
			num+=ok;
		}
		pat=pat*num%mo;
	}
	cout<<pat<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
