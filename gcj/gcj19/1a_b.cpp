#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	vector<int> P={16,9,5,7,11,13,17};
	vector<int> R;
	FORR(p,P) {
		FOR(i,18) {
			cout<<p;
			if(i<17) cout<<" ";
		}
		cout<<endl;
		int t=0;
		FOR(i,18) {
			cin>>x;
			t+=x;
		}
		
		R.push_back(t%p);
	}
	
	for(i=1;i<=M;i++) {
		FOR(j,7) if(i%P[j]!=R[j]) break;
		
		if(j==7) {
			cout<<i<<endl;
			cin>>j;
			return;
		}
	}
	assert(0);
	
	
}

void init() {
	cin>>N>>M;
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		solve(loop);
	}
	
	
	
	return 0;
}


