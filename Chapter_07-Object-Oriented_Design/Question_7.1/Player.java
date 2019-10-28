import java.util.ArrayList;


public class Player {
    private Card[] hand;

    public Player() {
        this.hand = new ArrayList<Card>();
    }

    public void addCard(Card c) {
        this.hand.add(c);
    }

    public int handScore() {
        int sum = 0;

        for (Card c : this.hand) {
            sum += c.getValue();
        }

        return sum;
    }
}
