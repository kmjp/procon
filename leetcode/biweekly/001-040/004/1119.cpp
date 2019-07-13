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
    string removeVowels(string S) {
		string R;
		FORR(c,S) {
			if(c=='a') continue;
			if(c=='i') continue;
			if(c=='u') continue;
			if(c=='e') continue;
			if(c=='o') continue;
			R+=c;
		}
		return R;
        
    }
    
};

