public class FixedCapacityStackOfStrings {

    private String[] items;
    private int n = 0;

    public FixedCapacityStackOfStrings(int N){
        items = new String[N];
    }

    public boolean isEmpty(){ return n == 0; }

    public void push(String item){ items[n++] = item; }


//  public String pop(){ return items[n--]; } -> This version of pop() holds a reference to an object when it is no longer needed.

    public String pop(){
        String item = items[--n];
        items[n] = null;
        return item;
    }
}
