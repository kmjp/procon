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

ll X,Y,V;

ll dp[12][13][2][16];

std::string to_hex_string(int64_t i) {
    std::stringstream s;
    s << std::uppercase << std::hex << i;
    return s.str();
}

std::string FizzBuzz16(int64_t i) {
    if (i % 15 == 0) {
        return "FizzBuzz";
    } else if (i % 3 == 0) {
        return "Fizz";
    } else if (i % 5 == 0) {
        return "Buzz";
    } else {
        return to_hex_string(i);
    }
}

ll getlen(ll v) {
	ll ret=0;
	for(int d=1;d<=18;d++) {
		ll L=1LL<<(4*(d-1));
		ll R=min(v,(1LL<<(4*(d)))-1);
		if(L>v) break;
		
		ll n3=R/3-(L-1)/3;
		ll n5=R/5-(L-1)/5;
		ll n15=R/15-(L-1)/15;
		
		ret+=((R-L+1)-n3-n5+n15)*d;
		ret+=n3*4;
		ret+=n5*4;
	}
	return ret;
}

ll hoge(ll v) {
	
	ll mv=0;
	int i;
	for(i=40;i>=0;i--) if(getlen(mv+(1LL<<i))<v) mv+=1LL<<i;
	
	ZERO(dp);
	dp[11][0][0][0]=1;
	int d,num,le,mo,nv;
	for(d=10;d>=0;d--) {
		ll cv=(mv>>(4*d))%16;
		FOR(num,13) FOR(le,2) FOR(mo,15) if(dp[d+1][num][le][mo]) {
			FOR(nv,16) {
				if(le==0&&nv>cv) continue;
				dp[d][num+(nv==11)+(nv==15)][le|(nv<cv)][(mo*16+nv)%15]+=dp[d+1][num][le][mo];
			}
		}
	}
	
	ll ret=-8;
	FOR(num,13) FOR(le,2) FOR(mo,15) {
		if(mo%3==0) ret+=dp[0][num][le][mo];
		if(mo%5==0) ret+=dp[0][num][le][mo];
		if(mo%3&&mo%5) ret+=dp[0][num][le][mo]*num;
	}
	string mvn=FizzBuzz16(mv+1);
	ll lef=v-getlen(mv);
	FOR(i,lef) if(mvn[i]=='B'||mvn[i]=='F') ret++;
	
	
	return ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	
	cout<<hoge(Y)-hoge(X-1)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
