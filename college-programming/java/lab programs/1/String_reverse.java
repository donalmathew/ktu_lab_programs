import java.util.*;

class Reverse{
    public static void main(String args []){
        Scanner s =  new Scanner(System.in);
        String str;
        String rev = "";
        System.out.print("enter the string");
        str = s.next();
        int l=str.length();
        for(int i = 0; i<l; i++){
            rev+=str.charAt(l-i-1);
        }
        System.out.print("the reversed string is :" +rev);

    }
}
