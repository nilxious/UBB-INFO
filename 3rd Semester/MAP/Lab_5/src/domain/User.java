package domain;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public abstract class User {
    private Long id;
    private String username;
    private String email;
    private String password;

    //folosesc lista de prieteni in User pt ca fiecare user sa cunoasca cine sunt prietenii lui
    private List<User> friends =  new ArrayList<>();

    User(long id, String username, String email, String password) {
        this.id = id;
        this.email = email;
        this.username = username;
        this.password = password;

    }

    public long getId() {
        return id;
    }
    public void setId(long id) {
        this.id = id;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }


    @Override
    public String toString() {
        return String.format(
                "@%s [ID:%d, Email:%s, Password:%s]",
                username,
                id,
                email,
                password
        );
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return id == user.id && Objects.equals(username, user.username) && Objects.equals(email, user.email) && Objects.equals(password, user.password);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, username, email, password);
    }

    public boolean addFriend(User u){
        if(!friends.contains(u)) {
            friends.add(u);
            return true;
        }
        return false;
    }

    public List<User> getFriends() {
        return friends;
    }

    public void afiseazaPrieteni() {
        if (friends.isEmpty()) {
            System.out.println("No friends");
            return;
        }
        System.out.println("Friends:");
        for (User prieten : friends) {
            System.out.println("  " + prieten.toString());
        }
    }

    public boolean removeFriend(User u) {
        return friends.remove(u); // remove() deja ret true daca a elim
    }

}
