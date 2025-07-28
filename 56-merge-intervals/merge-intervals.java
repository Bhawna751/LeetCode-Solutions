class Solution {
    public int[][] merge(int[][] intervals) {
        int n=intervals.length;
        List<int[]> ans = new ArrayList<>();
        if(intervals.length!=0 || intervals != null){
            Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
            int start = intervals[0][0];
            int end = intervals[0][1];
            for(int[] it: intervals){
                if(it[0] <= end) end = Math.max(end, it[1]);
                else{
                    ans.add(new int[]{start,end});
                    start = it[0];
                    end = it[1];
                }
            }
            ans.add(new int[]{start, end});
        }
        return ans.toArray(new int[0][]);
    }
}