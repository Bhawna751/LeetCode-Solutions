class Solution {
    public static List<Integer> rows(int n){
        long ans=1;
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for(int col=1;col<n;col++){
            ans *= (n-col);
            ans /=col;
            row.add((int)ans);
        }
        return row;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=1;i<=numRows;i++){
            ans.add(rows(i));
        }
        return ans;
    }
}