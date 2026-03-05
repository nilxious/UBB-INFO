package repoDB;

import domain.Duck;
import domain.Persoana;
import domain.TipRata;
import domain.User;
import exceptions.ExceptieValidare;

import java.sql.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class repoDB {

    private final String url;
    private final String user;
    private final String password;

    public repoDB(String url, String user, String password) {
        this.url = url;
        this.user = user;
        this.password = password;
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, this.user, this.password);
    }

    public void add(User u) {
        try (Connection con = getConnection()) {
            if (findById(u.getId()) != null) {
                throw new ExceptieValidare("User-ul cu id-ul " + u.getId() + " deja exista");
            }


            String insertUser = "INSERT INTO users(id, username, email, password) VALUES (?, ?, ?, ?)";
            try (PreparedStatement ps = con.prepareStatement(insertUser)) {
                ps.setLong(1, u.getId());
                ps.setString(2, u.getUsername());
                ps.setString(3, u.getEmail());
                ps.setString(4, u.getPassword());
                ps.executeUpdate();
            }


            if (u instanceof Duck d) {
                String insertDuck = "INSERT INTO ducks(id, tip_rata, viteza, rezistenta, fk_duck_user) VALUES (?, ?, ?, ?, ?)";
                try (PreparedStatement ps = con.prepareStatement(insertDuck)) {
                    ps.setLong(1, d.getId());
                    ps.setString(2, d.getTipRata().name());
                    ps.setDouble(3, d.getViteza());
                    ps.setDouble(4, d.getRezistenta());
                    ps.setLong(5, d.getId());
                    ps.executeUpdate();
                }
            }

            else if (u instanceof Persoana p) {
                String insertPersoana = "INSERT INTO persoana(id, nume, prenume, data_nastere, ocupatie, nivel_empatie, fk_person_user) VALUES (?, ?, ?, ?, ?, ?, ?)";
                try (PreparedStatement ps = con.prepareStatement(insertPersoana)) {
                    ps.setLong(1, p.getId());
                    ps.setString(2, p.getNume());
                    ps.setString(3, p.getPrenume());
                    ps.setDate(4, Date.valueOf(p.getDataNastere()));
                    ps.setString(5, p.getOcupatie());
                    ps.setInt(6, p.getNivelEmpatie());
                    ps.setLong(7, p.getId());
                    ps.executeUpdate();
                }
            }

        } catch (SQLException ex) {
            throw new RuntimeException("Eroare la inserare: " + ex.getMessage(), ex);
        }
    }

    public void remove(User u) {
        try (Connection con = getConnection()) {
            String deleteUser = "DELETE FROM users WHERE id = ?";
            try (PreparedStatement ps = con.prepareStatement(deleteUser)) {
                ps.setLong(1, u.getId());
                int affected = ps.executeUpdate();
                if (affected == 0) {
                    throw new ExceptieValidare("User-ul cu id-ul " + u.getId() + " nu exista");
                }
            }
        } catch (SQLException ex) {
            throw new RuntimeException("Eroare la stergere: " + ex.getMessage(), ex);
        }
    }

    public User findById(long id) {
        try (Connection con = getConnection()) {
            String selectUser = "SELECT * FROM users WHERE id = ?";
            try (PreparedStatement ps = con.prepareStatement(selectUser)) {
                ps.setLong(1, id);
                try (ResultSet rs = ps.executeQuery()) {
                    if (!rs.next()) return null;

                    String username = rs.getString("username");
                    String email = rs.getString("email");
                    String password = rs.getString("password");

                    String selectDuck = "SELECT * FROM ducks WHERE id = ?";
                    try (PreparedStatement psDuck = con.prepareStatement(selectDuck)) {
                        psDuck.setLong(1, id);
                        try (ResultSet rsDuck = psDuck.executeQuery()) {
                            if (rsDuck.next()) {
                                TipRata tipRata = TipRata.valueOf(rsDuck.getString("tip_rata"));
                                double viteza = rsDuck.getDouble("viteza");
                                double rezistenta = rsDuck.getDouble("rezistenta");
                                return new Duck(id, username, email, password, tipRata, viteza, rezistenta);
                            }
                        }
                    }


                    String selectPersoana = "SELECT * FROM persoana WHERE id = ?";
                    try (PreparedStatement psPers = con.prepareStatement(selectPersoana)) {
                        psPers.setLong(1, id);
                        try (ResultSet rsPers = psPers.executeQuery()) {
                            if (rsPers.next()) {
                                String nume = rsPers.getString("nume");
                                String prenume = rsPers.getString("prenume");
                                LocalDate data = rsPers.getDate("data_nastere").toLocalDate();
                                String ocupatie = rsPers.getString("ocupatie");
                                int empatie = rsPers.getInt("nivel_empatie");
                                return new Persoana(id, username, email, password, nume, prenume, data, ocupatie, empatie);
                            }
                        }
                    }

                    return null;
                }
            }
        } catch (SQLException ex) {
            throw new RuntimeException("Eroare la findById: " + ex.getMessage(), ex);
        }
    }

    public List<User> getAll() {
        List<User> result = new ArrayList<>();
        try (Connection con = getConnection()) {
            String selectUsers = "SELECT id FROM users";
            try (PreparedStatement ps = con.prepareStatement(selectUsers)) {
                try (ResultSet rs = ps.executeQuery()) {
                    while (rs.next()) {
                        long id = rs.getLong("id");
                        User u = findById(id);
                        if (u != null) result.add(u);
                    }
                }
            }
        } catch (SQLException ex) {
            throw new RuntimeException("Eroare la getAll: " + ex.getMessage(), ex);
        }
        return result;
    }
}