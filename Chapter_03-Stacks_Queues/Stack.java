public class Stack<T> {
    class Node<T> {
        private T value;
        private Node<T> previous;
        private Node<T> next;


        public Node() {
            this.value = null;
            this.previous = null;
            this.next = null;
        }


        public Node(T value) {
            this.value = value;
            this.previous = null;
            this.next = null;
        }


        public T getValue() {
            return this.value;
        }


        public Node<T> getPrevious() {
            return this.previous;
        }


        public Node<T> getNext() {
            return this.next;
        }


        public void setValue(T value) {
            this.value = value;
        }


        public void setPrevious(Node<T> previous) {
            this.next = next;
        }


        public void setNext(Node<T> next) {
            this.next = next;
        }
    }


    private Node<T> stack;
    private Node<T> top;
    private long size;


    public Stack() {
        this.stack = new Node<T>();
        this.top = this.stack;
        this.size = 0;
    }


    public T peek() {
        return this.top.getValue();
    }


    public T pop() {
        if (this.isEmpty()) {
            return null;
        }
        else if (this.size == 1) {
            T value = this.top.getValue();
            this.top = new Node<T>();
            this.size--;
            return value;
        }
        else {
            T value = this.top.getValue();
            this.top = this.top.previous;
            this.size--;
            return value;
        }
    }


    public void push(T value) {
        if (this.top.getValue() == null) {
            this.top.setValue(value);
        } else {
            Node<T> prev = this.top;
            this.top.next = new Node<T>(value);
            this.top = this.top.next;
            this.top.previous = prev;
        }

        this.size++;
    }


    public long getSize() {
        return this.size;
    }


    public boolean isEmpty() {
        return this.size == 0;
    }
}
