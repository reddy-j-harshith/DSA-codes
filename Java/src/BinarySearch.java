import edu.princeton.cs.algs4.StdOut;

public class BinarySearch {

    int[] arr = {12, 23, 24, 37, 56};
    public int result = 0;
    public BinarySearch(int n){
        int low = 0;
        int high = arr.length - 1;
        int mid = high / 2;
        while (mid != low) {
            if (arr[mid] < n) {
                low = mid;
                mid = (low + high) / 2;
            } else if (arr[mid] > n) {
                high = mid;
                mid = (low + high) / 2;
            } else {
                result = mid;
                break;
            }
        }
    }

    public static void main(String[] args){
        int n = 24;
        BinarySearch search = new BinarySearch(n);
        StdOut.println(search.result);

    }

}
