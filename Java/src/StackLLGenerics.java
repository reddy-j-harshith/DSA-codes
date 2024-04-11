import java.util.Iterator;

public class StackLLGenerics<Item> implements Iterable<Item> {

    Node first = null;
    private int count = 0;
    class Node{
        Item item;
        Node next;
    }

    public boolean isEmpty(){ return first == null; }

    public void push(Item item){
        Node oldFirst = new Node();
        oldFirst = first;
        first.item = item;
        first.next = oldFirst;
        count++;
    }

    public Item pop(){
        Item item = first.item;
        first = first.next;
        count--;
        return item;
    }

    public int size(){
        return count;
    }

    public Iterator<Item> iterator(){ return new ListIterator(); }

    private class ListIterator implements Iterator<Item>{

        private Node current = first;

        public boolean hasNext() {
            return current == null;
        }

        public Item next(){
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

}
