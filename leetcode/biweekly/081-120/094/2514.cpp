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



const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

	vector<string> split(const string &str, char delim=' '){
		vector<string> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
			res.push_back(string(str, current, found - current));
			current = found + 1;
		}
		res.push_back(string(str, current, str.size() - current));
		return res;
	}
class Solution {
public:
    int countAnagrams(string s) {
		
		auto v=split(s);
		
		ll p=1;
		FORR(s,v) {
			int C[256]={};
			int S=0;
			FORR(c,s) {
				if(c!=' ') {
					C[c]++;
					S++;
				}
			}
			
			ll q=1;
			int i,j;
			FOR(i,S) p=p*(i+1)%mo;
			FOR(i,256) {
				FOR(j,C[i]) q=q*(j+1)%mo;
			}
			p=p*modpow(q)%mo;
		}
		return p;
		
        
    }
};
