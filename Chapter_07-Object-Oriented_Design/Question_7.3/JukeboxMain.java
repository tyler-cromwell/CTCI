/*************************************************
 * Part of solution to question 7.3 - Jukebox
 *
 * Status: INCOMPLETE
*************************************************/

public class JukeboxMain {
    public static void main(String[] args) {
        Song time = new Song("Time", "Pink Floyd", "The Dark Side of the Moon", 414);
        Song paranoid = new Song("Paranoid", "Black Sabbath", "Paranoid", 168);
        Jukebox jukebox = new Jukebox();

        jukebox.addSong(time);
        jukebox.addSong(paranoid);
        Thread music = new Thread(jukebox);

        music.start();
        System.out.println("Threads!");

        try {
            Thread.sleep(2000);
            music.interrupt();
        } catch (InterruptedException e) {
        }
    }
}
