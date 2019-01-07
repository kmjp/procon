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
	string parse(string S) {
		string T;
		
		if(S.find('.')==string::npos) {
			T=S+"."+string(1000,'0');
		}
		else if(S.find('(')==string::npos) {
			T=S+string(1000,'0');
		}
		else {
			int i=S.find('(');
			T=S.substr(0,i);
			string U=S.substr(i+1,S.size()-1-(i+1));
			
			if(count(ALL(U),'9')==U.size()) {
				for(i=T.size()-1;i>=0;i--) {
					if(T[i]=='.') continue;
					if(T[i]!='9') {
						T[i]++;
						break;
					}
					T[i]='0';
				}
				if(i==-1) T="1"+T;
				T+=string(1000,'0');
			}
			else {
				while(T.size()<1000) T+=U;
			}
			
		}
		T.resize(1000);
		cout<<T<<endl;
		return T;
		
		
	}
	
	
    bool isRationalEqual(string S, string T) {
        return parse(S)==parse(T);
    }
};
