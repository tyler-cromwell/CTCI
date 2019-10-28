public enum Suit {
    HEARTS(0),
    DIAMONDS(1),
    SPADES(2),
    CLUBS(3);

    private int value;

    private Suit(int v) {
        this.value = v;
    }

    public String getName() {
        switch (this.value) {
            case 0: return "Hearts";
            case 1: return "Diamonds";
            case 2: return "Spades";
            case 3: return "Clubs";
            default:    break;
        }
    }

    public int getValue() {
        return this.value;
    }
};
