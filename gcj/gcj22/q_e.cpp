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

int N,K;
int num[101010];
void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>N>>K;
	MINUS(num);
	
	int small=0;
	ll smallS=0;
	int large=0;
	ll largeS=0;
	
	cin>>x>>y;
	small++;
	smallS+=y;
	num[x]=y;
	
	vector<int> cand;
	FOR(i,N) cand.push_back(i+1);
  	random_shuffle(ALL(cand));
  	
	FORR(c,cand) if(K&&num[c]==-1) {
		K--;
		cout<<"T "<<c<<endl;
		cin>>x>>y;
		num[x]=y;
		small++;
		smallS+=y;
		
		if(K) {
			K--;
			cout<<"W"<<endl;
			cin>>x>>y;
			if(num[x]==-1) {
				num[x]=y;
				large++;
				largeS+=y;
			}
		}
		
	}
	
	//cerr<<" "<<N<<" "<<small<<" "<<smallS<<" "<<large<<" "<<largeS<<endl;
	ll a=(smallS*(N-large)/small+largeS)/2;
	cout<<"E "<<a<<endl;
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		solve(loop);
	}
	
	return 0;
}


