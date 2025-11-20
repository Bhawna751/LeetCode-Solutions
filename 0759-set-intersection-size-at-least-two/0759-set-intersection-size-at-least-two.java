class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a,b)-> Integer.compare(a[1],b[1]));
        List<Integer> myList =new ArrayList<>();
        for(int i=0;i<intervals.length;i++){
            if(myList.isEmpty()){
                myList.add(intervals[i][1]-1);
                myList.add(intervals[i][1]);
            }
            else if(intervals[i][0]==myList.get(myList.size()-1)){
                    myList.add(intervals[i][1]);
                }
            else{
                if(intervals[i][0]>myList.get(myList.size()-1)){
                    myList.add(intervals[i][1]-1);
                    myList.add(intervals[i][1]);
                }else if(intervals[i][0]<myList.get(myList.size()-1) && intervals[i][0]>myList.get(myList.size()-2) ){
                    myList.add(intervals[i][1]);
                }
                }
        }
        return myList.size();
    }
}