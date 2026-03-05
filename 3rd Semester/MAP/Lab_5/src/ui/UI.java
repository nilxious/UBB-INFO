package ui;

import domain.Persoana;
import domain.User;
import domain.TipRata;
import service.Comunitati;
import service.UserService;

import java.time.LocalDate;
import java.util.Scanner;
import java.util.Set;

public class UI {
    private final UserService userService;
    private Comunitati network;
    private final Scanner in = new Scanner(System.in);

    public UI(UserService userService) {
        this.userService = userService;
        this.network = new Comunitati(userService.getAll());
    }

    public void launch() {
        boolean active = true;
        while (active) {
            System.out.println("\n==============================");
            System.out.println("      FeatherNet System");
            System.out.println("==============================");
            System.out.println("1. Register new account");
            System.out.println("2. Remove account");
            System.out.println("3. Link users (add friend)");
            System.out.println("4. Unlink users");
            System.out.println("5. Show all users");
            System.out.println("6. Show someone's friends");
            System.out.println("7. Network stats");
            System.out.println("0. Exit");
            System.out.print(">> ");

            String option = in.nextLine().trim();
            switch (option) {
                case "1" -> registerAccount();
                case "2" -> deleteAccount();
                case "3" -> linkUsers();
                case "4" -> unlinkUsers();
                case "5" -> printUsers();
                case "6" -> printFriendsOf();
                case "7" -> showStats();
                case "0" -> {
                    System.out.println("Shutting down FeathrNet...");
                    active = false;
                }
                default -> System.out.println("Invalid option, try again.");
            }
        }
    }

    private void registerAccount() {
        try {
            System.out.print("Type (person/duck): ");
            String type = in.nextLine().trim().toLowerCase();

            System.out.print("ID: ");
            long id = Long.parseLong(in.nextLine());
            System.out.print("Username: ");
            String username = in.nextLine();
            System.out.print("Email: ");
            String email = in.nextLine();
            System.out.print("Password: ");
            String pass = in.nextLine();

            User user;

            if (type.equals("person")) {
                System.out.print("First name: ");
                String first = in.nextLine();
                System.out.print("Last name: ");
                String last = in.nextLine();
                System.out.print("Birth date (yyyy-mm-dd): ");
                LocalDate date = LocalDate.parse(in.nextLine());
                System.out.print("Occupation: ");
                String job = in.nextLine();
                System.out.print("Empathy (1-10): ");
                int emp = Integer.parseInt(in.nextLine());

                user = new Persoana(id, username, email, pass, first, last, date, job, emp);
            } else if (type.equals("duck")) {
                System.out.print("Duck type (FLYING, SWIMMING, FLYING_AND_SWIMMING): ");
                TipRata kind = TipRata.valueOf(in.nextLine().trim().toUpperCase());
                System.out.print("Speed: ");
                double spd = Double.parseDouble(in.nextLine());
                System.out.print("Stamina: ");
                double stam = Double.parseDouble(in.nextLine());

                user = new domain.Duck(id, username, email, pass, kind, spd, stam);
            } else {
                System.out.println("Invalid user type.");
                return;
            }

            userService.addUser(user);
            System.out.println("✔ Account successfully registered.");
        } catch (Exception e) {
            System.out.println("Error while creating user: " + e.getMessage());
        }
    }

    private void deleteAccount() {
        try {
            System.out.print("User ID to delete: ");
            long id = Long.parseLong(in.nextLine());
            User u = userService.findById(id);
            if (u == null) {
                System.out.println("No such user found.");
                return;
            }
            userService.removeUser(u);
            System.out.println("✔ Account removed.");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private void linkUsers() {
        try {
            System.out.print("First user ID: ");
            long id1 = Long.parseLong(in.nextLine());
            System.out.print("Second user ID: ");
            long id2 = Long.parseLong(in.nextLine());

            User u1 = userService.findById(id1);
            User u2 = userService.findById(id2);

            if (u1 == null || u2 == null) {
                System.out.println("Invalid user(s).");
                return;
            }

            if (userService.addFriend(u1, u2))
                System.out.println("Users linked!");
            else
                System.out.println("Already linked.");
        } catch (Exception e) {
            System.out.println("Error linking users: " + e.getMessage());
        }
    }

    private void unlinkUsers() {
        try {
            System.out.print("First user ID: ");
            long id1 = Long.parseLong(in.nextLine());
            System.out.print("Second user ID: ");
            long id2 = Long.parseLong(in.nextLine());

            User u1 = userService.findById(id1);
            User u2 = userService.findById(id2);

            if (u1 == null || u2 == null) {
                System.out.println("Invalid user(s).");
                return;
            }

            if (userService.removeFriend(u1, u2))
                System.out.println("Connection removed.");
            else
                System.out.println("These users weren’t connected.");
        } catch (Exception e) {
            System.out.println("Error unlinking users: " + e.getMessage());
        }
    }

    private void printUsers() {
        System.out.println("\n--- Current Users ---");
        for (User u : userService.getAll()) {
            System.out.println(u);
        }
    }

    private void printFriendsOf() {
        try {
            System.out.print("Enter user ID: ");
            long id = Long.parseLong(in.nextLine());
            User u = userService.findById(id);

            if (u == null) {
                System.out.println("User not found.");
                return;
            }

            System.out.println("\nFriends of " + u.getUsername() + ":");
            u.afiseazaPrieteni();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private void showStats() {
        network = new Comunitati(userService.getAll());
        System.out.println("\n--- Network Overview ---");
        System.out.println("1. Count communities");
        System.out.println("2. Most social community");
        System.out.println("0. Back");
        System.out.print(">> ");
        String opt = in.nextLine();

        switch (opt) {
            case "1" -> {
                int num = network.getNumarComunitati();
                System.out.println("Total communities: " + num);
            }
            case "2" -> {
                Set<User> group = network.getCeaMaiSociabilaComunitate();
                System.out.println("Most social community (" + group.size() + " users):");
                group.forEach(u -> System.out.println(" - " + u));
            }
            default -> System.out.println("Returning...");
        }
    }
}
