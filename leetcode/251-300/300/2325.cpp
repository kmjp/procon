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



class Solution {
public:
    string decodeMessage(string key, string message) {
		set<char> S;
		string T;
		char table[256];
		char cc='a';
		FORR(c,key) if(S.count(c)==0&&c!=' ') {
			S.insert(c);
			table[c]=cc++;
		}
		FORR(c,message) if(c!=' '){
			c=table[c];
		}
		return message;
        
    }
};
