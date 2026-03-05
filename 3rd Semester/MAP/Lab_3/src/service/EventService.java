package service;

import domain.*;
import exceptions.ExceptieValidare;
import repository.EventRepo;

import java.util.ArrayList;
import java.util.List;

public class EventService {
    private EventRepo repo;

    public EventService(EventRepo repo) {
        this.repo = repo;
    }

    public void createEvent(String nume) {
        if (nume == null || nume.isEmpty()) {
            throw new ExceptieValidare("Numele event-ului nu poate fi gol.");
        }

        if (repo.findByName(nume) != null) {
            throw new ExceptieValidare("Deja exista event-ul cu numele '" + nume + "'");
        }

        repo.add(new Event(nume));
    }

    public void createRaceEvent(String nume, List<Double> balize, List<Duck> participanti) {
        if (nume == null || nume.isEmpty()) {
            throw new ExceptieValidare("Numele nu poate fi gol.");
        }

        if (repo.findByName(nume) != null) {
            throw new ExceptieValidare("Deja exista raceEvent-ul cu numele '" + nume + "'");
        }

        if (participanti == null || participanti.isEmpty()) {
            throw new ExceptieValidare("Trebuie sa existe cel putin un participant.");
        }

        if (balize == null || balize.size() != participanti.size()) {
            throw new ExceptieValidare("Numarul balizelor trebuie sa fie egal cu numarul participantilor.");
        }

        for (int i = 1; i < balize.size(); i++) {
            if (balize.get(i) <= balize.get(i - 1)) {
                throw new ExceptieValidare("Distantele balizelor trebuie sa fie strict crescatoare.");
            }
        }

        repo.add(new RaceEvent(nume, balize, participanti));
    }

    public Event findEventByName(String nume) {
        return repo.findByName(nume);
    }

    public List<Event> getAll() {
        return repo.getAll();
    }

    public void subscribeUser(Event e, User u) {
        e.subscribe(u);
    }

    public void unsubscribeUser(Event e, User u) {
        e.unsubscribe(u);
    }

    public void sendMessage(Event e, String mesaj) {
        e.notifySubscribers(mesaj);
    }

    public List<RaceEvent> getAllRaceEvents() {
        List<RaceEvent> raceEvents = new ArrayList<>();
        for (Event e : repo.getAll()) {
            if (e instanceof RaceEvent re) {
                raceEvents.add(re);
            }
        }
        return raceEvents;
    }
}
