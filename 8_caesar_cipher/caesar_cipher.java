import java.util.*;
import java.io.*;

class CaesarCipher {

    public static void main(String[] args) {
    
        String input="";        
        char choice='e';
        int key=0;
        String output="";
        int i;
        
        System.out.println("----- CAESAR CIPHER -----");
        System.out.print("Enter string :- ");
        Scanner sc = new Scanner(System.in);
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            input = br.readLine();
        }
        catch(Exception e) { }        
        
        System.out.print("\nEnter key :- ");
        key = sc.nextInt();
        
        System.out.print("\nEnter e for encrypt; d for decrypt :- ");
        choice = sc.next().charAt(0);
        
        switch(choice) {
        
            case 'e': 
            case 'E':               
                for(i=0;i<input.length();i++) {
                
                    // shift the character forward by key and retain case
                    
                    if(Character.isLowerCase(input.charAt(i))) output += Character.toString((char)((input.charAt(i)+key-97)%26+97));   
                    else if(Character.isUpperCase(input.charAt(i))) output += Character.toString((char)((input.charAt(i)+key-65)%26+65));     
                    else output += Character.toString(input.charAt(i));            
                    
                }
                System.out.println("\nEncrypted string with key "+key+" is :- "+output);
                break;
            
            case 'd':
            case 'D':
                for(i=0;i<input.length();i++) {           
                
                    // shift the character backward by key and retain case
                             
                    if(Character.isLowerCase(input.charAt(i))) output += Character.toString((char)((input.charAt(i)-key-97+26)%26+97));   
                    else if(Character.isUpperCase(input.charAt(i))) output += Character.toString((char)((input.charAt(i)-key-65+26)%26+65)); 
                    else output += Character.toString(input.charAt(i));                 
                }
                System.out.println("\nEncrypted string with key "+key+" is :- "+output);
                break;                
                        
        }
    
    }

}
