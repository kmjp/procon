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

class AuthenticationManager {
public:
	int TL;
	map<string,int> token;
	set<pair<int,string>> S;
    AuthenticationManager(int timeToLive) {
        TL=timeToLive;
        token.clear();
        S.clear();
    }
    
    void generate(string tokenId, int currentTime) {
        token[tokenId]=currentTime+TL;
        S.insert({currentTime+TL,tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
		if(token.count(tokenId)==0) return;
		int c=token[tokenId];
		if(c>currentTime) {
	        S.erase({c,tokenId});
	        token[tokenId]=currentTime+TL;
	        S.insert({currentTime+TL,tokenId});
	    }
    }
    
    int countUnexpiredTokens(int currentTime) {
		while(S.size()&&S.begin()->first<=currentTime) S.erase(*S.begin());
        return S.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */