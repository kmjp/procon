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

int T,N,L,R;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>R;
		L--;
		vector<int> a,b,c;
		ll sum=0;
		FOR(i,N) {
			cin>>A[i];
			if(i<L) a.push_back(A[i]);
			else if(i>=R) b.push_back(A[i]);
			else {
				c.push_back(A[i]);
				sum+=A[i];
			}
		}
		sort(ALL(a));
		sort(ALL(b));
		sort(ALL(c));
		reverse(ALL(c));
		ll ret=sum;
		ll cur=0;
		FOR(i,min(a.size(),c.size())) {
			cur+=a[i]-c[i];
			ret=min(ret,sum+cur);
		}
		cur=0;
		FOR(i,min(b.size(),c.size())) {
			cur+=b[i]-c[i];
			ret=min(ret,sum+cur);
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
