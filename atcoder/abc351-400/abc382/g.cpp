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

int T;
ll K,SX,SY,TX,TY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>K>>SX>>SY>>TX>>TY;
		
		//‰Eã‚És‚­‚æ‚¤‰ñ“]
		while(SX>TX||SY>TY) {
			SX=SX*2+1;
			SY=SY*2+1;
			TX=TX*2+1;
			TY=TY*2+1;
			swap(SX,SY);
			SY=-SY;
			swap(TX,TY);
			TY=-TY;
			SX=(SX-1)/2;
			SY=(SY-1)/2;
			TX=(TX-1)/2;
			TY=(TY-1)/2;
			
		}
		
		ll a=(1LL<<60)/(2*K);
		SX+=a*2*K;
		TX+=a*2*K;
		SY+=a*2*K;
		TY+=a*2*K;
		if((SX/K+SY/K)%2) {
			SX+=K;
			TX+=K;
			swap(SX,SY);
			swap(TX,TY);
		}
		a=SX/K;
		SX-=a*K;
		TX-=a*K;
		a=SY/K;
		SY-=a*K;
		TY-=a*K;
		
		ll ret=1LL<<60;
		if(TX/K==0&&TY/K==0) {
			ret=min(2LL,abs(TY-SY));
			cout<<ret<<endl;
			continue;
		}
		
		ll ma=(K>2)?2:1;
		vector<pair<pair<ll,ll>,int>> A;
		A.push_back({{0,0},min(ma,SY)});
		A.push_back({{1,0},1});
		A.push_back({{0,1},1});
		A.push_back({{1,1},min(ma,K-1-SY)});
		vector<pair<pair<ll,ll>,int>> B;
		ll x=TX/K+TY/K;
		ll y=TY/K-TX/K;
		if(x%2==0) {
			B.push_back({{x+0,y},min(ma,TY%K)});
			B.push_back({{x+1,y},1});
			B.push_back({{x+0,y+1},1});
			B.push_back({{x+1,y+1},min(ma,K-1-TY%K)});
		}
		else {
			B.push_back({{x+0,y},1});
			B.push_back({{x+1,y},min(ma,K-1-TX%K)});
			B.push_back({{x+0,y+1},min(ma,TX%K)});
			B.push_back({{x+1,y+1},1});
		}
		FORR2(a1,a2,A) FORR2(b1,b2,B) {
			if(K>2) {
				ret=min(ret,a2+b2+abs(a1.first-b1.first)+abs(a1.second-b1.second));
			}
			else {
				ll ax=a1.first;
				ll ay=a1.second;
				ll bx=b1.first;
				ll by=b1.second;
				assert(bx>=ax);
				ll can=a2+b2+abs(ax-bx)+abs(ay-by);
				
				ay+=1LL<<58;
				by+=1LL<<58;
				
				if(ay<=by) {
					ll d=min(by-ay,bx-ax);
					can-=d/2;
					ay+=d/2*2;
					ax+=d/2*2;
				}
				else {
					ll d=min(ay-by,bx-ax);
					can-=d/2;
					ay-=d/2*2;
					ax+=d/2*2;
				}
				while(ay<by&&ax<bx) {
					if(ax%2==0) {
						ax++;
					}
					else if(ay%2) {
						ay++;
					}
					else {
						ax++;
						ay++;
						can--;
					}
				}
				while(ax<bx&&ay>by) {
					if(ax%2) {
						ax++;
					}
					else if(ay%2) {
						ay--;
					}
					else {
						ax++;
						ay--;
						can--;
					}
				}
				ret=min(ret,can);
			}
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
