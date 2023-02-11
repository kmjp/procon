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

int SX,SY;
int TX,TY;
ll A,B,C,D;

vector<ll> XL,XR,YL,YR;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>SX>>SY>>TX>>TY;
	cin>>A>>B>>C>>D;
	
	if((TX-SX)%2||(TY-SY)%2) {
		cout<<"No"<<endl;
		return;
	}
	XL={SX};
	XR={SX};
	YL={SY};
	YR={SY};
	FOR(i,1000001) {
		if(XL.back()<=TX&&TX<=XR.back()&&YL.back()<=TY&&TY<=YR.back()) {
			vector<ll> X,Y;
			while(XL.size()>1) {
				XL.pop_back();
				XR.pop_back();
				YL.pop_back();
				YR.pop_back();
				if(XL.back()<=2*A-TX&&2*A-TX<=XR.back()) {
					X.push_back(A);
					TX=2*A-TX;
				}
				else if(XL.back()<=2*B-TX&&2*B-TX<=XR.back()) {
					X.push_back(B);
					TX=2*B-TX;
				}
				else if(A<=(XL.back()+TX)/2&&(XL.back()+TX)/2<=B) {
					X.push_back((XL.back()+TX)/2);
					TX=XL.back();
				}
				else if(A<=(XR.back()+TX)/2&&(XR.back()+TX)/2<=B) {
					X.push_back((XR.back()+TX)/2);
					TX=XR.back();
				}
				else {
					assert(0);
				}
				if(YL.back()<=2*C-TY&&2*C-TY<=YR.back()) {
					Y.push_back(C);
					TY=2*C-TY;
				}
				else if(YL.back()<=2*D-TY&&2*D-TY<=YR.back()) {
					Y.push_back(D);
					TY=2*D-TY;
				}
				else if(C<=(YL.back()+TY)/2&&(YL.back()+TY)/2<=D) {
					Y.push_back((YL.back()+TY)/2);
					TY=YL.back();
				}
				else if(C<=(YR.back()+TY)/2&&(YR.back()+TY)/2<=D) {
					Y.push_back((YR.back()+TY)/2);
					TY=YR.back();
				}
				else {
					assert(0);
				}
			}
			cout<<"Yes"<<endl;
			FOR(i,X.size()) cout<<X[X.size()-1-i]<<" "<<Y[Y.size()-1-i]<<endl;
			return;
		}
		{
			ll mi=max(min({2*A-XL.back(),2*B-XL.back(),2*A-XR.back(),2*B-XR.back()}),(-1LL<<30)+SX%2);
			ll ma=min(max({2*A-XL.back(),2*B-XL.back(),2*A-XR.back(),2*B-XR.back()}),(1LL<<30)+SX%2);
			XL.push_back(mi);
			XR.push_back(ma);
		}
		{
			ll mi=max(min({2*C-YL.back(),2*D-YL.back(),2*C-YR.back(),2*D-YR.back()}),(-1LL<<30)+SY%2);
			ll ma=min(max({2*C-YL.back(),2*D-YL.back(),2*C-YR.back(),2*D-YR.back()}),(1LL<<30)+SY%2);
			YL.push_back(mi);
			YR.push_back(ma);
		}
		
		
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
