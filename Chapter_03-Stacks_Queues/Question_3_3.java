/*************************************************
 * Solution to question 3.3 - Stack of Plates
 *
 * Status: COMPLETE
*************************************************/

import java.util.ArrayList;


public class Question_3_3 {
    class SetOfStacks<T> {
        private final long limit;
        private ArrayList<Stack<T>> set;
        private int index;


        public SetOfStacks(long limit) {
            this.set = new ArrayList<Stack<T>>();
            this.set.add(new Stack<T>());
            this.limit = limit;
            this.index = 0;
        }


        public T peek() {
            return this.set.get(index).peek();
        }


        public T pop() {
            if (this.index >= this.getSize() || (this.index == 0 && this.set.get(this.index).getSize() == 1)) {
                return null;
            }

            Stack<T> stack = this.set.get(this.index);

            if (this.index > 0 && stack.getSize() == 1) {
                T value = stack.pop();
                this.set.remove(this.index);
                this.index--;
                return value;
            } else {
                return stack.pop();
            }
        }


        // Follow up
        public T popAt(int index) {
            if (this.index >= this.getSize()) {
                return null;
            } else {
                return this.set.get(index).pop();
            }
        }
         

        public void push(T value) {
            Stack<T> stack = this.set.get(index);

            if (stack.getSize() == this.limit) {
                this.index++;
                this.set.add(new Stack<T>());
                this.set.get(index).push(value);
            } else {
                stack.push(value);
            }
        }


        public int getSize() {
            return this.set.size();
        }
    }


    public static void main(String[] args) {
        SetOfStacks<Integer> set = new Question_3_3().new SetOfStacks<Integer>(4);
        System.out.printf("Top: %d, %d\n", set.peek(), set.getSize());
        set.push(1337);
        set.push(2018);
        set.pop();
        set.push(2018);
        set.push(1234);
        set.push(1010);
        System.out.printf("Top: %d, %d\n", set.peek(), set.getSize());
        set.push(5555); // Placed on new stack
        System.out.printf("Top: %d, %d\n", set.peek(), set.getSize());
        set.pop();
        set.pop();
        System.out.printf("Top: %d, %d\n", set.peek(), set.getSize());
        set.popAt(0);
        System.out.printf("Top: %d, %d\n", set.peek(), set.getSize());
    }
}
