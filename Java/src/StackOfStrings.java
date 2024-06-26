public class StackOfStrings{

    class Node{
        String item;
        Node next;
    }

    private Node first = null;

    public boolean isEmpty(){ return first == null; }

    public void push(String item){
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
    }

    public String pop(){
        if (!isEmpty()){
            String item = first.item;
            first = first.next;
            return item;
        }
        else{
            return "Stack Empty.";
        }
    }

}