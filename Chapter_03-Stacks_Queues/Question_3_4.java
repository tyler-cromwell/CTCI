/*************************************************
 * Solution to question 3.4 - Queue via Stacks
 *
 * Status: COMPLETE
*************************************************/

import java.util.ArrayList;


public class Question_3_4 {
    class Queue<T> {
        private Stack<T> enqstack;
        private Stack<T> deqstack;


        public Queue() {
            this.enqstack = new Stack<T>();
        }


        public void enqueue(T value) {
            this.enqstack.push(value);
        }


        public T dequeue() {
            if (this.deqstack == null || this.deqstack.isEmpty()) {
                this.deqstack = new Stack<T>();

                while (!this.enqstack.isEmpty()) {
                    this.deqstack.push(this.enqstack.pop());
                }

                this.enqstack = new Stack<T>();
            }

            return this.deqstack.pop();
        }


        public long getSize() {
            long size = 0;

            if (!this.enqstack.isEmpty()) {
                size += this.enqstack.getSize();
            }

            if (this.deqstack != null && !this.deqstack.isEmpty()) {
                size += this.deqstack.getSize();
            }

            return size;
        }


        public T peekFront() {
            if (this.deqstack != null) {
                return this.deqstack.peek();
            } else {
                return null;
            }
        }


        public T peekBack() {
            return this.enqstack.peek();
        }
    }


    public static void main(String[] args) {
        Queue<Integer> q = new Question_3_4().new Queue<Integer>();
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        q.enqueue(1);
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        q.enqueue(2);
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        q.enqueue(3);
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        q.enqueue(4);
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        System.out.printf("Dequeued: %d\n", q.dequeue());
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        q.enqueue(5);
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        System.out.printf("Dequeued: %d\n", q.dequeue());
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        System.out.printf("Dequeued: %d\n", q.dequeue());
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        System.out.printf("Dequeued: %d\n", q.dequeue());
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
        System.out.printf("Dequeued: %d\n", q.dequeue());
        System.out.printf("Size = %d, Front = %d, End = %d\n", q.getSize(), q.peekFront(), q.peekBack());
    }
}
