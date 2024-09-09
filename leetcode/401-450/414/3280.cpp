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


class Solution {
public:
    string convertDateToBinary(string date) {
		int h=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0')*1;
		int m=(date[5]-'0')*10+(date[6]-'0')*1;
		int d=(date[8]-'0')*10+(date[9]-'0')*1;
		string S;
		while(d) {
			S+='0'+(d%2);
			d/=2;
		}
		S+="-";
		while(m) {
			S+='0'+(m%2);
			m/=2;
		}
		S+="-";
		while(h) {
			S+='0'+(h%2);
			h/=2;
		}
		reverse(ALL(S));
		return S;
        
    }
};
