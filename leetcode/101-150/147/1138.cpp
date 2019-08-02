
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
    string alphabetBoardPath(string target) {
		int X=0,Y=0;
		string S;
		FORR(c,target) {
			int TX=(c-'a')%5;
			int TY=(c-'a')/5;
			
			if(c=='z') {
				while(X>TX) X--, S+='L';
				while(X<TX) X++, S+='R';
				while(Y>TY) Y--, S+='U';
				while(Y<TY) Y++, S+='D';
			}
			else {
				while(Y>TY) Y--, S+='U';
				while(Y<TY) Y++, S+='D';
				while(X>TX) X--, S+='L';
				while(X<TX) X++, S+='R';
			}
			S+="!";
		}
		return S;
        
    }

};

