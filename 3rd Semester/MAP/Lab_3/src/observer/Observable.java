package observer;

import domain.User;

public interface Observable {
    void subscribe(User u);
    void unsubscribe(User u);
    void notifySubscribers(String mesaj);
}

