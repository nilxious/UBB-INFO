package domain;

import java.time.LocalDate;
import java.util.Objects;

public class Persoana extends User{
    private String nume;
    private String prenume;
    private LocalDate dataNastere;
    private String ocupatie;
    private int nivelEmpatie;

    public Persoana(long id, String username, String email, String password, String nume, String prenume, LocalDate dataNastere, String ocupatie, int nivelEmpatie) {
        super(id, username, email, password);
        this.nume = nume;
        this.prenume = prenume;
        this.dataNastere = dataNastere;
        this.ocupatie = ocupatie;
        this.nivelEmpatie = nivelEmpatie;
    }

    public String getNume() {
        return nume;
    }
    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getPrenume() {
        return prenume;
    }

    public void setPrenume(String prenume) {
        this.prenume = prenume;
    }

    public LocalDate getDataNastere() {
        return dataNastere;
    }

    public void setDataNastere(LocalDate dataNastere) {
        this.dataNastere = dataNastere;
    }

    public String getOcupatie() {
        return ocupatie;
    }

    public void setOcupatie(String ocupatie) {
        this.ocupatie = ocupatie;
    }

    public int getNivelEmpatie() {
        return nivelEmpatie;
    }

    public void setNivelEmpatie(int nivelEmpatie) {
        this.nivelEmpatie = nivelEmpatie;
    }

    @Override
    public String toString() {
        return String.format(
                "%s — Name: %s %s, Born: %s, Job: %s, Empathy: %d",
                super.toString(),
                prenume,
                nume,
                dataNastere,
                ocupatie,
                nivelEmpatie
        );
    }

    public String toUserString() {
        return super.toString();
    }// folosește User.toString()


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Persoana persoana = (Persoana) o;
        return nivelEmpatie == persoana.nivelEmpatie && Objects.equals(nume, persoana.nume) && Objects.equals(prenume, persoana.prenume) && Objects.equals(dataNastere, persoana.dataNastere) && Objects.equals(ocupatie, persoana.ocupatie);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), nume, prenume, dataNastere, ocupatie, nivelEmpatie);
    }
}

