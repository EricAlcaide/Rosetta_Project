
public class Fibonacci {
  public static void main(String... args) {
    fibonacci();
  }

  private static void fibonacci(){
    int prev = 0;
    int actual = 1;
    int aux = 0;

    for (int q = 0; q < 10; ++q) {
      aux = actual;
      actual = prev + aux;
      prev = aux;
      System.out.println(actual);
    }
  }

}

