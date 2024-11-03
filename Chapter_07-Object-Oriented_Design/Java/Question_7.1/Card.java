public abstract class Card {
    protected Suit suit;
    protected Type type;

    public Card(Type type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return this.type +" of "+ this.suit.getName();
    }

    public Suit getSuit() {
        return this.suit;
    }

    public Type getType() {
        return this.type;
    }

    public int getValue() {
        return this.type.value;
    }
}
