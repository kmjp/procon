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

int R,S;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>R>>S;
	vector<int> V;
	FOR(i,S) for(j=1;j<=R;j++) V.push_back(j);
	
	vector<pair<int,int>> ret;
	int len=R*S;
	while(len) {
		int ma=0;
		FOR(i,len) if(V[i]>=V[ma]) ma=i;
		if(ma==len-1) {
			len--;
		}
		else {
			//FORR(v,V) cout<<v<<" ";
			//cout<<endl;
			
			int cnt=0;
			FOR(i,len-1) if(V[i]>V[i+1]) cnt++,x=i;
			if(cnt==1 && V[0]>=V[len-1]) {
				ret.push_back({x+1,len-(x+1)});
				
			}
			else {
				y=0;
				FOR(x,len) if(V[y]==V[x]) y=x;
				FOR(x,y+1) if(V[x]==V[y+1]) break;
				if(x==y+1) {
					ret.push_back({y+1,len-(y+1)});
					
				}
				else {
					ret.push_back({x+1,y-x});
				}
			}
			rotate(V.begin(),V.begin()+ret.back().first,V.begin()+ret.back().first+ret.back().second);
		}
	}
	
	//FORR(v,V) cout<<v<<" ";
	//cout<<endl;
	
	_P("Case #%d: %d\n",_loop,(int)ret.size());
	FORR(r,ret) _P("%d %d\n",r.first,r.second);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


