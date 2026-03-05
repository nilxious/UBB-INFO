package domain;

public class FlyingDuck extends Duck implements Zburator{
    public FlyingDuck(long id, String username, String email, String password,
                      TipRata tipRata, double viteza, double rezistenta) {
        super(id, username, email, password, tipRata, viteza, rezistenta);
    }

    @Override
    public void zboara() {
        System.out.println("Rata cu username:" + getUsername() + " si id :" + getId() + " zboara cu viteaza:" +getViteza());
    }

}
