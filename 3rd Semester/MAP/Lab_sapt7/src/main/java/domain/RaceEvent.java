package domain;

import java.util.List;

public class RaceEvent extends Event {
    private List<Double> balize;
    private List<Duck> participanti;

    public RaceEvent(String nume, List<Double> balize, List<Duck> participanti) {
        super(nume);
        this.balize = balize;
        this.participanti = participanti;
    }

    public double calculeazaDurata() {
        double durataMin = 0;
        for(int i = 0; i < participanti.size(); i++) {
            double timp = 2 * balize.get(i) / participanti.get(i).getViteza();
            if(timp > durataMin) durataMin = timp;
        }
        return durataMin;
    }

    public List<Duck> getParticipanti() {
        return participanti;
    }
    public List<Double> getBalize() {
        return balize;
    }
}
