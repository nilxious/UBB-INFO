package repository;

import domain.Event;

import java.util.ArrayList;
import java.util.List;

public class EventRepo {
    private List<Event> events = new ArrayList<>();

    public void add(Event e) {
        events.add(e);
    }

    public void remove(Event e) {
        events.remove(e);
    }

    public Event findByName(String nume) {
        for (Event e : events) {
            if (e.getNume().equalsIgnoreCase(nume))
                return e;
        }
        return null;
    }

    public List<Event> getAll() {
        return events;
    }
}
