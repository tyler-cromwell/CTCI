public enum Type {
    TWO(2),
    THREE(3),
    FOUR(4),
    FIVE(5),
    SIX(6),
    SEVEN(7),
    EIGHT(8),
    NINE(9),
    TEN(10),
    QUEEN(11),
    KING(11),
    JACK(11),
    ACE(11);

    private int value;

    private Type(int v) {
        this.value = v;
    }

    public int getValue() {
        return this.value;
    }
};
