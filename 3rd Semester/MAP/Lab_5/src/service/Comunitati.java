package service;

import domain.User;

import java.util.*;


/**
 * Clasa pentru gestionarea comunitatilor de utilizatori.
 * Permite determinarea numarului de comunitati si a comunitatii
 * celei mai sociabile (cu diametru maxim intre membri).
 */
public class Comunitati {

    private List<User> utilizatori;

    /**
     * Creeaza un obiect Comunitati pe baza unei liste de utilizatori.
     *
     * @param utilizatori lista de utilizatori din retea
     */
    public Comunitati(List<User> utilizatori) {
        this.utilizatori = utilizatori;
    }

    /**
     * Determina numarul de comunitati (componente conexe) din retea.
     *
     * @return numarul de comunitati
     */
    public int getNumarComunitati() {
        Set<User> vizitati = new HashSet<>(); //folosesc un set de vizitati pt a marca useri deja vizitati
        int numarComunitati = 0;

        for (User u : utilizatori) {
            if (!vizitati.contains(u)) {
                parcurgereDFS(u, vizitati);
                numarComunitati++;
            }
        }

        return numarComunitati;
    }

    /**
     * Returneaza comunitatea cea mai sociabila (cu diametru maxim intre membri).
     *
     * @return setul de utilizatori din comunitatea cea mai sociabila
     */
    public Set<User> getCeaMaiSociabilaComunitate() {
        Set<User> vizitatiGlobal = new HashSet<>();
        Set<User> comunitateMax = new HashSet<>();
        int diametruMax = -1;

        for (User u : utilizatori) {
            if (!vizitatiGlobal.contains(u)) { //pt fiecare user nevizitat identifica comunitatea lui prin DFS
                Set<User> comunitate = new HashSet<>();
                parcurgereDFS(u, comunitate);
                vizitatiGlobal.addAll(comunitate);

                int diametru = calculeazaDiametru(comunitate); // calculam diametru
                if (diametru > diametruMax) { // pastram diametrul si comunitatea cea mai mare
                    diametruMax = diametru;
                    comunitateMax = comunitate; //schimbam referinta lui comunitatemax
                }
            }
        }

        return comunitateMax;
    }

    /**
     * Parcurgere DFS recursiva pentru a marca toti utilizatorii dintr-o comunitate.
     *
     * @param u utilizatorul curent
     * @param vizitati setul de utilizatori deja vizitati
     */
    private void parcurgereDFS(User u, Set<User> vizitati) {
        vizitati.add(u);
        for (User prieten : u.getFriends()) {
            if (!vizitati.contains(prieten)) {
                parcurgereDFS(prieten, vizitati);
            }
        }
    }

    /**
     * Calculeaza diametrul unei comunitati (lungimea celui mai lung drum intre doi utilizatori).
     *
     * @param comunitate setul de utilizatori din comunitate
     * @return diametrul comunitatii
     */
    private int calculeazaDiametru(Set<User> comunitate) {
        int diametru = 0;

        // pentru fiecare membru calculez distanta fata de ceilalti membri
        for (User u : comunitate) {
            Map<User, Integer> distante = calculeazaDistanteBFS(u, comunitate);
            int maxDist = distante.values().stream().max(Integer::compare).orElse(0);
            if (maxDist > diametru) diametru = maxDist;
        }

        return diametru;
    }

    /**
     * Calculeaza distantele dintre un utilizator si ceilalti membri ai comunitatii folosind BFS.
     *
     * @param start utilizatorul de la care se porneste calculul
     * @param comunitate setul de utilizatori din comunitate
     * @return un Map care asociaza fiecarui utilizator distanta fata de utilizatorul start
     */
    private Map<User, Integer> calculeazaDistanteBFS(User start, Set<User> comunitate) {
        Map<User, Integer> distante = new HashMap<>(); //distantele le pun intr un dictionar intre useri si restul din comunitate
        Queue<User> coada = new LinkedList<>();
        coada.add(start);
        distante.put(start, 0);

        while (!coada.isEmpty()) {
            User curent = coada.poll();
            int d = distante.get(curent);

            for (User prieten : curent.getFriends()) {
                if (comunitate.contains(prieten) && !distante.containsKey(prieten)) {
                    distante.put(prieten, d + 1);
                    coada.add(prieten);
                }
            }
        }

        return distante;
    }
}
