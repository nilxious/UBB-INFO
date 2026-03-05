package domain;

import observer.Observable;

import java.util.ArrayList;
import java.util.List;

public class Event implements Observable {
    private String nume;
    private List<User> subscribers = new ArrayList<>();
    private List<String> messages = new ArrayList<>();

    public Event(String nume) {
        this.nume = nume;
    }
    public String getNume() {
        return nume;
    }

    @Override
    public void subscribe(User u) {
        subscribers.add(u);
    }

    @Override
    public void unsubscribe(User u) {
        subscribers.remove(u);
    }

    @Override
    public void notifySubscribers(String mesaj) {
        messages.add(mesaj);
        for (User u : subscribers) {
            u.update(this, mesaj);
        }
    }

    // returneaza istoricul mesajelor
    public List<String> getMessages() {
        return new ArrayList<>(messages); // returnam o copie ca sa nu poata fi modificata din exterior
    }

    public List<User> getSubscribers() {
        return subscribers;
    }
}
