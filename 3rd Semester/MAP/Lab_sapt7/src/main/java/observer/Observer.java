package observer;

import domain.Event;

public interface Observer {
        void update(Event event, String mesaj);
}
