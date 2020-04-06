#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,B;
int A[101];
int ask(int pos) {
	int x;
	cout<<pos+1<<endl;
	cin>>x;
	//cerr<<pos<<" "<<x<<endl;
	return x;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	int flipped=-1;
	int rev=-1;
	int cur=0;
	FOR(i,15) {
		int num=10;
		//cerr<<"!"<<i<<cur<<endl;
		if(flipped>=0) {
			x=ask(flipped);
			num--;
			//cerr<<"flipp"<<endl;
			if(A[flipped]!=x) {
				FOR(j,B) A[j]^=1;
			}
		}
		if(rev>=0) {
			x=ask(rev);
			num--;
			//cerr<<"rev"<<endl;
			if(A[rev]!=x) {
				FOR(j,B/2) swap(A[j],A[B-1-j]);
			}
		}
		while(cur<B/2 && num>=2) {
			num-=2;
			A[cur]=x=ask(cur);
			A[B-1-cur]=y=ask(B-1-cur);
			if(x==y) flipped=cur;
			else rev=cur;
			cur++;
		}
		if(cur==B/2&&num) {
			FOR(i,B) cout<<A[i];
			cout<<endl;
			string s;
			cin>>s;
			//cerr<<s<<endl;
			assert(s=="Y");
			return;
		}
		if(num) ask(0);
	}
}

void init() {
	cin>>T>>B;
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	init();
	int i;
	FOR(i,T) solve(T);
	
	return 0;
}


