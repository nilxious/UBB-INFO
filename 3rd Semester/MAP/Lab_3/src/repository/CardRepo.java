package repository;

import domain.Card;
import domain.Duck;

import java.util.ArrayList;
import java.util.List;

public class CardRepo {
    private List<Card<Duck>> carduri = new ArrayList<>();

    public void add(Card<Duck> card) {
        carduri.add(card);
    }

    public void remove(Card<Duck> card) {
        carduri.remove(card);
    }

    public Card<Duck> findById(Long id) {
        for (Card<Duck> c : carduri) {
            if (c.getId().equals(id))
                return c;
        }
        return null;
    }

    public List<Card<Duck>> getAll() {
        return carduri;
    }
}
