package domain;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Card <T extends Duck> {
    private Long id;
    private String nume;
    private List<Duck> membri =  new ArrayList<Duck>();

    public Card(Long id, String nume) {
        this.id = id;
        this.nume = nume;
    }

    public Long getId() {
        return id;
    }

    public String getNume() {
        return nume;
    }

    public List<Duck> getMembri() {
        return membri;
    }


    public void addDuck(Duck d) {
        membri.add(d);
    }
    public void removeDuck(Duck d) {
        membri.remove(d);
    }

    public double getPerformantaMedie() {
        if (membri.isEmpty()) return 0;
        double suma = 0;
        for (Duck d : membri) {
            suma += (d.getViteza() + d.getRezistenta()) / 2;
        }
        return suma / membri.size();
    }

    @Override
    public String toString() {
        return "Card{id=" + id + ", nume='" + nume + "', nrMembri=" + membri.size() + ", perfMedie=" + getPerformantaMedie() + "}";
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Card<?> card = (Card<?>) o;
        return Objects.equals(id, card.id) && Objects.equals(nume, card.nume) && Objects.equals(membri, card.membri);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, nume, membri);
    }
}
