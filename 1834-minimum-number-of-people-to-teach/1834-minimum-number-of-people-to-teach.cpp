class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sad_users ; 
        for( auto& friends : friendships){
            int u = friends[0] - 1 ;
            int v = friends[1] - 1 ; 

            unordered_set<int>langset(languages[u].begin(),languages[u].end()) ; 
            bool cantalk = false ; 

            for(int lang:languages[v]){
               if(langset.count(lang)){
                cantalk = true ; 
                break; 
               }
            }
            if(!cantalk){
                sad_users.insert(u) ; 
                sad_users.insert(v) ;
            }
        }
        vector<int>language(n+1,0); 
        int mostknownlang = 0 ; 
        for( int users: sad_users){
            for( int lang :languages[users] ){
                language[lang]++; 
                mostknownlang = max(mostknownlang,language[lang]) ; 
            }
        }
        return sad_users.size() -   mostknownlang ; 
    }
};