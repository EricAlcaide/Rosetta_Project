import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class first_hashes {
    public static void main(final String args[]) throws NoSuchAlgorithmException {
        System.out.println("Enter password");
        final Scanner scan = new Scanner(System.in);
        String user_input = scan.nextLine();
        final String hashed_password = hash_it(user_input);

        for (int i = 0; i < 3; i++) {
            System.out.println("Retype password. You've " + (3 - i) + " attempts remaining.");
            user_input = scan.nextLine();
            final String hashed_retyped_password = hash_it(user_input);

            if (hashed_retyped_password.equals(hashed_password)) {
                System.out.println("Good job!");
                scan.close();
                return;
            }
        }
        System.out.println("Passwords didn't match.");
        scan.close();
    }

    public static String hash_it(final String input) throws NoSuchAlgorithmException {
        final MessageDigest md = MessageDigest.getInstance("SHA-512");
        md.update(input.getBytes());

        final byte byteData[] = md.digest();
        final StringBuffer sb = new StringBuffer();
        for (final byte element : byteData) {
            sb.append(Integer.toString((element & 0xff) + 0x100, 16).substring(1));
        }
        return sb.toString();
    }
}