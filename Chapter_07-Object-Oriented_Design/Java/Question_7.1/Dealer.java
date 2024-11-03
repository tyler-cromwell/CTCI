public class Dealer extends Player {
    private Deck deck;

    public Dealer(Deck deck) {
        super();
        this.deck = deck;
    }

    public void deal(Player player) {
        Card c = this.deck.draw();
        player.addCard(c);
    }
}
