class Solution {
    public int minOperations(int[][] grid, int x) {
        List<Integer> values = new ArrayList<>();
        for(int [] i:grid){
            for(int it:i){
                values.add(it);
            }
        }
        Collections.sort(values);
        for(int it:values){
            if(Math.abs(it-values.get(0)) % x !=0) return -1;
        }
        int median = values.get(values.size()/2);
        int ans=0;
        for(int it:values){
            ans += Math.abs(it-median)/x;
        }
        return ans;
    }
}