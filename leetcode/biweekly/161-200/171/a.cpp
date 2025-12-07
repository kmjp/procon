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


bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

class Solution {
public:
    bool completePrime(int num) {
		string s=to_string(num);
		int i,N=s.size();
		FOR(i,N) {
			if(isprime(atoll(s.substr(0,i+1).c_str()))==0) return 0;
			if(isprime(atoll(s.substr(N-i-1).c_str()))==0) return 0;
        }
        return 1;
    }
};
