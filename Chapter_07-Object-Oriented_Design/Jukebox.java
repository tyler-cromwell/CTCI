/*************************************************
 * Part of solution to question 7.3 - Jukebox
*************************************************/

import java.util.ArrayList;

public class Jukebox implements Runnable {
    private ArrayList<Song> songs;

    public Jukebox() {
        this.songs = new ArrayList<Song>();
    }

    @Override
    public String toString() {
        StringBuilder output = new StringBuilder(100);

        for (Song s : this.songs) {
            output.append(s.toString());
            output.append("\n");
        }

        return output.toString();
    }

    @Override
    public void run() {
        try {
            for (Song s : this.songs) {
                int time = s.getLength();

                for (int i = 0; i < time; i++) {
                    System.out.printf("\rPlaying, \"%s\" (%d", s.getTitle(), i);
                    System.out.print("/");
                    System.out.print(time);
                    System.out.print(")");
                    Thread.sleep(1000);
                }

                System.out.println();
            }
        }
        catch (InterruptedException e) {
            System.out.println("I was interrupted!");
            return;
        }
    }

    public void addSong(Song song) {
        this.songs.add(song);
    }

    public Song getSong(int index) {
        return this.songs.get(index);
    }

    public void removeSong(int index) {
        this.songs.remove(index);
    }

    public void skip() {
        this.songs.remove(0);
    }

    public ArrayList<Song> getSongs() {
        return this.songs;
    }
}
