class LongestSubstring{

    public static void longestSubstring(String s){
        int start = 0, end =1;
        int l=0, r=0;
        for(int i=0; i<s.length(); i++){
            l=i; 
            r=i+1;
            while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
                if(r-l+1>end){
                    start = l;
                    end = r-l+1;
                }
                l--;
                r++;
            }
            l = i-1;
            r = i+1;
            while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
                if(r-l+1>end){
                    start = l;
                    end = r-l+1;
                }
                l--;
                r--;
            }
        }
        for(int i=start; i<end; i++){
            System.out.print(s.charAt(i));
        }
    }
    public static void main(String args[]){
        String s = "babad";
        longestSubstring(s);
    }
}