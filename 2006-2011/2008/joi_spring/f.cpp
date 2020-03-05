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
double D;
double X[1010],Y[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double PI=atan(1)*4;
	cin>>N>>D;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Y[i]+=i/1000000.0;
	}
	
	int ma=min(2,N);
	FOR(i,N) {
		int now=1;
		vector<pair<double,int>> V;
		FOR(j,N) if(i!=j) {
			if(Y[j]>Y[i]&&Y[j]<Y[i]+2*D) now++;
			double a=atan2(Y[j]-Y[i],X[j]-X[i]);

			V.push_back({a-2*PI,-1});
			V.push_back({a-PI,1});
			V.push_back({a,-1});
			V.push_back({a+PI,1});
			V.push_back({a+2*PI,-1});
			V.push_back({a+3*PI,1});
			double r=hypot(X[i]-X[j],Y[i]-Y[j]);
			if(r>2*D+1e-9) {
				double b=a-(PI/2.0-acos(2*D/r));
				V.push_back({b-2*PI,1});
				V.push_back({b,1});
				V.push_back({b+2*PI,1});
				b=a+(PI/2.0-acos(2*D/r))+PI;
				V.push_back({b-2*PI,-1});
				V.push_back({b,-1});
				V.push_back({b+2*PI,-1});
			}
		}
		sort(ALL(V));
		reverse(ALL(V));
		while(V.size()&&V.back().first<0) V.pop_back();
		reverse(ALL(V));
		while(V.size()&&V.back().first>=2*PI) V.pop_back();
		FORR(v,V) {
			now+=v.second;
			//cout<<v.first*180/PI<<":"<<now<<" ";
			ma=max(ma,now);
		}
		//cout<<endl;
			
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
