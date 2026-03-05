package repository;
import domain.Duck;
import domain.Persoana;
import domain.TipRata;
import domain.User;
import exceptions.ExceptieValidare;

import java.io.File;
import java.io.PrintWriter;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class UserRepo {
    private List<User> users=new ArrayList<>();

    private String fileName;

    /**
     * Creeaza un repository de utilizatori asociat unui fișier.
     *
     * @param fileName numele fișierului unde se stochează utilizatorii
     */
    public UserRepo(String fileName) {
        this.fileName=fileName;
        loadFromFile();
    }

    /**
     * Adauga un utilizator în repository
     *
     * @param user utilizatorul de adaugat
     * @throws ExceptieValidare daca utilizatorul exista deja
     */
    public void add(User user) {
        if (users.contains(user) || findById(user.getId()) != null) {
            throw new ExceptieValidare("User already exists");
        }
        users.add(user);
        saveToFile();
    }

    /**
     * Sterge un utilizator din repository.
     *
     * @param user utilizatorul de sters
     * @throws ExceptieValidare daca utilizatorul nu exista
     */
    public void remove(User user) {
        if (findById(user.getId()) == null || !users.contains(user)) {
            throw new ExceptieValidare("User doesn't exist");
        }
        users.remove(user);
        saveToFile();
    }

    /**
     * Returneaza lista tuturor utilizatorilor din repository.
     *
     * @return lista utilizatorilor
     */
    public List<User> getAll(){
        return users;
    }

    /**
     * Cauta un utilizator dupa ID.
     *
     * @param id ID-ul utilizatorului cautat
     * @return utilizatorul cu ID-ul specificat sau null daca nu exista
     */
    public User findById(long id) {
        for (User u : users) {
            if (u.getId() == id) {
                return u;
            }
        }
        return null;
    }

    /**
     * Incarca utilizatorii din fisier in repository.
     * Suporta obiectele Persoana si Duck.
     */
    private void loadFromFile() {
        try(Scanner sc = new Scanner(new File(fileName))) {
            while(sc.hasNextLine()) {
                String linie = sc.nextLine();
                String[] parts = linie.split(",");
                String tip = parts[0];
                long id = Long.parseLong(parts[1]);
                String username = parts[2];
                String email = parts[3];
                String password = parts[4];

                if(tip.equalsIgnoreCase("persoana")) {
                    String nume = parts[5];
                    String prenume = parts[6];
                    LocalDate data = LocalDate.parse(parts[7]);
                    String ocupatie = parts[8];
                    int empatie = Integer.parseInt(parts[9]);
                    users.add(new Persoana(id, username, email, password, nume, prenume, data, ocupatie, empatie));
                } else if(tip.equalsIgnoreCase("duck")) {
                    TipRata tipRata = TipRata.valueOf(parts[5]);
                    double viteza = Double.parseDouble(parts[6]);
                    double rezistenta = Double.parseDouble(parts[7]);
                    users.add(new Duck(id, username, email, password, tipRata, viteza, rezistenta));
                }
            }
        } catch(Exception e) {
            System.out.println("Eroare la citirea din fisier: " + e.getMessage());
        }
    }

    /**
     * Salveaza utilizatorii din repository in fisier.
     * Obiectele Persoana si Duck sunt salvate in format CSV.
     */
    private void saveToFile() {
        try(PrintWriter pw = new PrintWriter(new File(fileName))) {
            for(User u : users) {
                if(u instanceof Persoana p) {
                    pw.println("Persoana," + p.getId() + "," + p.getUsername() + "," + p.getEmail() + "," + p.getPassword() + "," +
                            p.getNume() + "," + p.getPrenume() + "," + p.getDataNastere() + "," + p.getOcupatie() + "," + p.getNivelEmpatie());
                } else if(u instanceof Duck d) {
                    pw.println("Duck," + d.getId() + "," + d.getUsername() + "," + d.getEmail() + "," + d.getPassword() + "," +
                            d.getTipRata() + "," + d.getViteza() + "," + d.getRezistenta());
                }
            }
        } catch(Exception e) {
            System.out.println("Eroare la salvarea fisierului: " + e.getMessage());
        }
    }


}
