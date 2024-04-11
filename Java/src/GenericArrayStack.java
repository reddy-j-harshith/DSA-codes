import java.util.Iterator;

public class GenericArrayStack<Item> implements Iterable<Item> {

    private int N = 0;
    private Item[] items;

    public GenericArrayStack(int capacity){
        items = (Item[]) new Object[capacity];
    }

    public boolean isEmpty(){ return N == 0; }

    public void push(Item item){
        items[N++] = item;
    }

    public Item pop(){
        Item item = items[--N];
        items[N] = null;
        return item;
    }

    public Iterator<Item> iterator(){
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item>{
        int i = N;

        public boolean hasNext(){
            return i > 0;
        }
        public Item next(){
            return items[--i];
        }
    }
}
