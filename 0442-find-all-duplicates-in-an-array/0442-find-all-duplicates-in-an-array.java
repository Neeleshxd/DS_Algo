class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        ArrayList<Integer>arr = new ArrayList<>() ; 
        HashMap<Integer,Integer>mp = new HashMap<>() ; 
        for( int x : nums){
           mp.put(x,mp.getOrDefault(x,0)+1) ; 
        }
        for( int key : mp.keySet()){
            if(mp.get(key) > 1 ){
                arr.add(key) ; 
            }
        }
        return arr ;
    }
}