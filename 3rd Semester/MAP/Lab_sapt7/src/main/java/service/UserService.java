package service;

import domain.User;
import exceptions.ExceptieValidare;
import repoDB.repoDB;
import repository.UserRepo;
import validator.ValidatorInterface;

import java.util.List;

/**
 * Clasa service pentru gestionarea utilizatorilor.
 * Permite adaugarea, stergerea, cautarea utilizatorilor
 * si gestionarea prietenilor intre utilizatori.
 */
public class UserService {
    //private UserRepo repo;
    private repoDB repo;
    private ValidatorInterface<User> validator;

    /**
     * Creeaza un serviciu de utilizatori cu un repository si un validator.
     *
     * @param repo repository-ul de utilizatori
     * @param validator strategia de validare a utilizatorilor
     */
    public UserService(repoDB repo, ValidatorInterface<User> validator) {
        this.repo = repo;
        this.validator = validator;
    }

    /**
     * Adauga un utilizator in repository dupa ce este validat.
     *
     * @param u utilizatorul de adaugat
     * @throws ExceptieValidare daca utilizatorul nu trece validarea
     */
    public void addUser(User u){
        validator.validare(u);
        repo.add(u);
    }

    /**
     * Sterge un utilizator din repository.
     *
     * @param u utilizatorul de sters
     */
    public void removeUser(User u){
        repo.remove(u);
    }

    /**
     * Adauga o relatie de prietenie intre doi utilizatori.
     *
     * @param u1 primul utilizator
     * @param u2 al doilea utilizator
     * @return true daca prietenia a fost adaugata cu succes pentru ambii utilizatori
     * @throws ExceptieValidare daca utilizatorii sunt aceeasi persoana
     */
    public boolean addFriend(User u1, User u2){
        if(u1.equals(u2)){
            throw new ExceptieValidare("Cannot add yourself as friend");
        }
        boolean added1 = u1.addFriend(u2);
        boolean added2 = u2.addFriend(u1);
        return added1 && added2;
    }


    /**
     * Sterge o relatie de prietenie intre doi utilizatori.
     *
     * @param u1 primul utilizator
     * @param u2 al doilea utilizator
     * @return true daca prietenia a fost stearsa cu succes pentru ambii utilizatori
     * @throws ExceptieValidare daca utilizatorii sunt aceeasi persoana
     */
    public boolean removeFriend(User u1, User u2) {
        if(u1.equals(u2)) {
            throw new ExceptieValidare("Cannot unfriend yourself");
        }
        boolean removed1 = u1.removeFriend(u2);
        boolean removed2 = u2.removeFriend(u1);
        return removed1 && removed2;
    }

    /**
     * Cauta un utilizator dupa ID.
     *
     * @param id ID-ul utilizatorului cautat
     * @return utilizatorul cu ID-ul specificat sau null daca nu exista
     */
    public User findById(long id) {
        return repo.findById(id);
    }

    /**
     * Returneaza lista tuturor utilizatorilor.
     *
     * @return lista utilizatorilor
     */
    public List<User> getAll(){
        return repo.getAll();
    }
}
