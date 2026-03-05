package service;

import domain.Card;
import domain.Duck;
import exceptions.ExceptieValidare;
import repository.CardRepo;

import java.util.List;

public class CardService {
    private CardRepo repo;

    public CardService(CardRepo repo) {
        this.repo = repo;
    }

    public void createCard(Long id, String nume) {
        for (Card<Duck> c : repo.getAll()) {
            if (c.getId().equals(id))
                throw new ExceptieValidare("Deja exista un card cu id-ul " + id);
            if (c.getNume().equalsIgnoreCase(nume))
                throw new ExceptieValidare("Deja exista un card cu numele '" + nume + "'");
        }
        repo.add(new Card<>(id, nume));
    }

    public void addDuckToCard(Long cardId, Duck duck) {
        Card<Duck> card = repo.findById(cardId);
        if (card == null)
            throw new ExceptieValidare("Cardul cu id " + cardId + " nu exista");

        if (card.getMembri().contains(duck))
            throw new ExceptieValidare("Aceasta rata este deja in card.");

        card.addDuck(duck);
    }

    public double getPerformantaMedie(Long cardId) {
        Card<Duck> card = repo.findById(cardId);
        if (card != null)
            return card.getPerformantaMedie();
        throw new ExceptieValidare("Card inexistent!");
    }

    public Card<Duck> findCardById(Long id) {
        return repo.findById(id);
    }

    public List<Card<Duck>> getAll() {
        return repo.getAll();
    }
}
