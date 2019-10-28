import java.util.ArrayList;
import java.util.Collections;


public class Deck {
    private ArrayList<Card> cards;

    public Deck() {
        this.cards = new ArrayList<Card>(52);
        int i = 0;

        for (Type t : Type.values()) {
            if (t == Type.QUEEN || t == Type.KING || t == Type.JACK) {
                this.cards.set(i++, new HeartsCard(t));
                this.cards.set(i++, new DiamondsCard(t));
                this.cards.set(i++, new ClubsCard(t));
                this.cards.set(i++, new SpadesCard(t));
            }
            else if (t == Type.ACE) {
                // Value can change
                this.cards.set(i++, new HeartsCard(t));
                this.cards.set(i++, new DiamondsCard(t));
                this.cards.set(i++, new ClubsCard(t));
                this.cards.set(i++, new SpadesCard(t));
            }
            else {
                this.cards.set(i++, new HeartsCard(t));
                this.cards.set(i++, new DiamondsCard(t));
                this.cards.set(i++, new ClubsCard(t));
                this.cards.set(i++, new SpadesCard(t));
            }
        }
    }

    public Card draw() {
        return this.cards.remove(0);
    }

    public void shuffle() {
        Collections.shuffle(this.cards);
    }
}
