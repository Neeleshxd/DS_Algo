class Solution {
    public boolean isPalindrome(String s) {
        int i = 0 ;
        int j = s.length()-1 ; 

        while( i < j ){
            if(!Character.isLetterOrDigit(s.charAt(i))){
              i++;
              continue; 
            }
            if(!Character.isLetterOrDigit(s.charAt(j))){
                j--;
                continue;
            }
            char p = Character.toLowerCase(s.charAt(i)) ; 
             char q = Character.toLowerCase(s.charAt(j)) ; 

             if(p != q ) return false ; 
             i++;
             j--;
        }
        return true ; 
    }
}