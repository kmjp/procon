#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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


const int NUM_=20003;
const ll mo[2]={998244353,1000000007};
static ll fact[2][NUM_+1],factr[2][NUM_+1],inv[2][NUM_+1];


class Solution {
public:
	ll num(vector<int> C) {
		int i,j;
		int s=0;
		FORR(a,C) s+=a;
		ll a[2]={fact[0][s],fact[1][s]};
		FOR(i,2) FORR(v,C) (a[i]*=factr[i][v])%=mo[i];
		if(a[0]==a[1]) return a[0];
		return 1LL<<30;
	}

    string smallestPalindrome(string s, int k) {
		int i,j;
		
		FOR(j,2) {
			inv[j][1]=fact[j][0]=factr[j][0]=1;
			for (int i=2;i<=NUM_;++i) inv[j][i] = inv[j][mo[j] % i] * (mo[j] - mo[j] / i) % mo[j];
			for (int i=1;i<=NUM_;++i) fact[j][i]=fact[j][i-1]*i%mo[j], factr[j][i]=factr[j][i-1]*inv[j][i]%mo[j];
		}

		
		vector<int> C(256);
		FORR(c,s) C[c]++;
		string A,B,W;
		int len=0;
		FOR(i,256) {
			FOR(j,C[i]%2) B+=(char)i;
			C[i]/=2;
			len+=C[i];
		}
		ll sum=num(C);
		if(sum<k) return "";
		
		k--;
		FOR(i,len) {
			FOR(j,256) if(C[j]) {
				C[j]--;
				ll a=num(C);
				if(a>k) {
					A+=(char)j;
					break;
				}
				k-=a;
				C[j]++;
			}
		}
		
		
		W=A;
		reverse(ALL(W));
		return A+B+W;
		
        
    }
};

