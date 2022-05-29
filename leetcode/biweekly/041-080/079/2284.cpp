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
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
		map<string,int> ret,dict;
		ret[""]=0;
		string ma="";
		int i;
		FOR(i,messages.size()) {
			int c=1;
			FORR(m,messages[i]) if(m==' ') c++;
			ret[senders[i]]+=c;
			if(ret[senders[i]]>ret[ma]) ma=senders[i];
			if(ret[senders[i]]==ret[ma]) ma=max(ma,senders[i]);
		}
		return ma;
        
    }
};
