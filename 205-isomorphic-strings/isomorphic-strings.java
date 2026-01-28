class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] mppS=new int [256];
        int[] mppT=new int[256];
        for(int i=0;i<s.length();i++){
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if(mppS[cs]!=mppT[ct])return false;
            mppS[cs] = mppT[ct] = i+1;
        }
        return true;
    }
}