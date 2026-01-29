class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        String concat=s+s;
        return concat.contains(goal);
    }
}