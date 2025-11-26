class Solution {
    public String reverseWords(String s) {
        String []words = s.trim().split("\\s+");
        String k = "";
        for(int i=words.length-1;i>=0;i--){
            k += words[i];
            if(i!=0) k+= " ";
        }
        return k.trim();
    }
}