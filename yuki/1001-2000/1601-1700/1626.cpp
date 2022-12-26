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

int t;
ll S,T;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>t;
	while(t--) {
		cin>>S>>T;
		__int128 SS=(__int128)16*S*S;
		
		__int128 tt=T;
		__int128 t2=tt-tt/3+1;
		
		if(SS%tt) {
			cout<<0<<endl;
			continue;
		}
		SS/=tt;
		if(SS>t2*t2*t2) {
			cout<<0<<endl;
			continue;
		}
		
		ll S3=SS;
		ll a,b,c;
		vector<vector<ll>> ret;
		for(c=1;c*c*c<=S3;c++) if(S3%c==0 && (T-c)%2==0) {
			ll C=(T-c)/2;
			ll S=S3/c;
			
			ll X=-4;
			ll Y=4*T-4*C;
			ll Z=T*2*C-T*T-S;
			ll D=Y*Y-4*X*Z;
			if(D<0) continue;
			ll DR=round(sqrt(D));
			if(DR*DR!=D) continue;
			if((-Y+DR)%8) continue;
			if((-Y-DR)%8) continue;
			ll a=(-Y+DR)/(2*X);
			ll b=(-Y-DR)/(2*X);
			if(a<=0||b<=0) continue;
			if(a>b||b>C) continue;
			ret.push_back({a,b,C});
			
		}
		
		cout<<ret.size()<<endl;
		FORR(a,ret) cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
