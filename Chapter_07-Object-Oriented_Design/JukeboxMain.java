/*************************************************
 * Part of solution to question 7.3 - Jukebox
*************************************************/

public class JukeboxMain {
    public static void main(String[] args) {
        Song time = new Song("Time", "Pink Floyd", "The Dark Side of the Moon", 414);
        Song paranoid = new Song("Paranoid", "Black Sabbath", "Paranoid", 168);
        Jukebox jukebox = new Jukebox();

        jukebox.addSong(time);
        jukebox.addSong(paranoid);
        jukebox.start();
    }
}
