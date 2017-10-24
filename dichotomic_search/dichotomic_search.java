import java.util.Arrays;

public class dichotomic_search {
  public static void main(String... args) {
    String[] array = {"a", "b", "c"};
    String v = "c";
    boolean res = dichotomicSearch(v, array);
    System.out.println(res);
    
  }
  public static boolean dichotomicSearch(String v, String[] array) {
    int med = array.length/2;
    if(array.length <= 1){
      return array[0] == v ? true: false;
    }else{
      return array[med].compareTo(v) == 1 ? dichotomicSearch(v, Arrays.copyOfRange(array, 0, med)):dichotomicSearch(v, Arrays.copyOfRange(array, med, array.length));
    }
  }
}
