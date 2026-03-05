package ui;

import domain.*;
import service.CardService;
import service.CommunityService;
import service.EventService;
import service.UserService;
import exceptions.ExceptieValidare;

import java.time.LocalDate;
import java.util.*;
import java.util.stream.Collectors;

public class UI {
    private final UserService userService;
    private final CardService cardService;
    private final EventService eventService;
    private CommunityService network;
    private final Scanner in = new Scanner(System.in);

    public UI(UserService userService, CardService cardService, EventService eventService) {
        this.userService = userService;
        this.cardService = cardService;
        this.eventService = eventService;
        this.network = new CommunityService(userService.getAll());
    }

    public void launch() {
        boolean active = true;
        while (active) {
            printMainMenu();
            String option = in.nextLine().trim();
            switch (option) {
                case "1" -> registerAccount();
                case "2" -> deleteAccount();
                case "3" -> linkUsers();
                case "4" -> unlinkUsers();
                case "5" -> printUsers();
                case "6" -> printFriendsOf();
                case "7" -> showStats();
                case "8" -> createCard();
                case "9" -> addDucksToCard();
                case "10" -> showCardPerformance();
                case "11" -> createSimpleEvent();
                case "12" -> createRaceEvent();
                case "13" -> subscribeUserToEvent();
                case "14" -> unsubscribeUserFromEvent();
                case "15" -> sendMessageToEvent();
                case "16" -> showEventMessages();
                case "17" -> showRaceDuration();
                case "18" -> showCardMembers();
                case "19" -> showEventSubscribers();
                case "0" -> {
                    System.out.println("Shutting down FeathrNet...");
                    active = false;
                }
                default -> System.out.println("Invalid option, try again.");
            }
        }
    }

    private void printMainMenu() {
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
        System.out.println("8. Create Card");
        System.out.println("9. Add ducks to Card");
        System.out.println("10. Show Card performance");
        System.out.println("11. Create simple Event");
        System.out.println("12. Create RaceEvent");
        System.out.println("13. Subscribe user to Event");
        System.out.println("14. Unsubscribe user from Event");
        System.out.println("15. Send message to Event");
        System.out.println("16. Show Event messages");
        System.out.println("17. Show RaceEvent duration");
        System.out.println("18. Show members of a Card");
        System.out.println("19. Show subscribers of an Event");
        System.out.println("0. Exit");
        System.out.print(">> ");
    }

    // ----- existing functions (unchanged) -----
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

                user = new Duck(id, username, email, pass, kind, spd, stam);
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
        network = new CommunityService(userService.getAll());
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

    // ----- new features -----
    private void createCard() {
        try {
            System.out.print("Card ID: ");
            Long id = Long.parseLong(in.nextLine());
            System.out.print("Card name: ");
            String name = in.nextLine();

            cardService.createCard(id, name);
            System.out.println("✔ Card created.");
        } catch (ExceptieValidare ev) {
            System.out.println("Validation error: " + ev.getMessage());
        } catch (Exception e) {
            System.out.println("Error creating card: " + e.getMessage());
        }
    }

    private void addDucksToCard() {
        try {
            System.out.print("Card ID: ");
            Long cardId = Long.parseLong(in.nextLine());
            System.out.print("Duck IDs to add (comma separated): ");
            String line = in.nextLine().trim();
            if (line.isEmpty()) {
                System.out.println("No duck IDs provided.");
                return;
            }
            String[] parts = line.split(",");
            for (String p : parts) {
                long duckId = Long.parseLong(p.trim());
                User u = userService.findById(duckId);
                if (u == null) {
                    System.out.println("No user with id " + duckId + " — skipping.");
                    continue;
                }
                if (!(u instanceof Duck)) {
                    System.out.println("User " + duckId + " is not a Duck — skipping.");
                    continue;
                }
                cardService.addDuckToCard(cardId, (Duck) u);
                System.out.println("Added duck " + duckId + " to card " + cardId);
            }
        } catch (ExceptieValidare ev) {
            System.out.println("Validation: " + ev.getMessage());
        } catch (Exception e) {
            System.out.println("Error adding ducks: " + e.getMessage());
        }
    }

    private void showCardPerformance() {
        try {
            System.out.print("Card ID: ");
            Long cardId = Long.parseLong(in.nextLine());
            double perf = cardService.getPerformantaMedie(cardId);
            System.out.printf("Card %d performance (average): %.3f%n", cardId, perf);
        } catch (ExceptieValidare ev) {
            System.out.println("Validation: " + ev.getMessage());
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private void createSimpleEvent() {
        try {
            System.out.print("Event name: ");
            String name = in.nextLine().trim();
            eventService.createEvent(name);
            System.out.println("✔ Event created: " + name);
        } catch (ExceptieValidare ev) {
            System.out.println("Validation: " + ev.getMessage());
        } catch (Exception e) {
            System.out.println("Error creating event: " + e.getMessage());
        }
    }

    private void createRaceEvent() {
        try {
            System.out.print("RaceEvent name: ");
            String name = in.nextLine().trim();

            System.out.print("Enter duck participant IDs (comma separated): ");
            String ducksLine = in.nextLine().trim();
            List<Duck> ducks = new ArrayList<>();
            if (!ducksLine.isEmpty()) {
                for (String s : ducksLine.split(",")) {
                    long id = Long.parseLong(s.trim());
                    User u = userService.findById(id);
                    if (u == null) {
                        System.out.println("No user " + id + " — skipping.");
                        continue;
                    }
                    if (!(u instanceof Duck)) {
                        System.out.println("User " + id + " is not a Duck — skipping.");
                        continue;
                    }
                    ducks.add((Duck) u);
                }
            }

            System.out.print("Enter balize distances (comma separated, one per participant): ");
            String balizeLine = in.nextLine().trim();
            List<Double> balize = Arrays.stream(balizeLine.split(","))
                    .map(String::trim)
                    .filter(s -> !s.isEmpty())
                    .map(Double::parseDouble)
                    .collect(Collectors.toList());

            eventService.createRaceEvent(name, balize, ducks);
            System.out.println("✔ RaceEvent created: " + name);
        } catch (ExceptieValidare ev) {
            System.out.println("Validation: " + ev.getMessage());
        } catch (Exception e) {
            System.out.println("Error creating RaceEvent: " + e.getMessage());
        }
    }

    private void subscribeUserToEvent() {
        try {
            System.out.print("Event name: ");
            String name = in.nextLine().trim();
            Event e = eventService.findEventByName(name);
            if (e == null) {
                System.out.println("Event not found.");
                return;
            }
            System.out.print("User ID to subscribe: ");
            long id = Long.parseLong(in.nextLine());
            User u = userService.findById(id);
            if (u == null) {
                System.out.println("User not found.");
                return;
            }
            eventService.subscribeUser(e, u);
            System.out.println("✔ User " + id + " subscribed to " + name);
        } catch (Exception ex) {
            System.out.println("Error subscribing: " + ex.getMessage());
        }
    }

    private void unsubscribeUserFromEvent() {
        try {
            System.out.print("Event name: ");
            String name = in.nextLine().trim();
            Event e = eventService.findEventByName(name);
            if (e == null) {
                System.out.println("Event not found.");
                return;
            }
            System.out.print("User ID to unsubscribe: ");
            long id = Long.parseLong(in.nextLine());
            User u = userService.findById(id);
            if (u == null) {
                System.out.println("User not found.");
                return;
            }
            eventService.unsubscribeUser(e, u);
            System.out.println("✔ User " + id + " unsubscribed from " + name);
        } catch (Exception ex) {
            System.out.println("Error unsubscribing: " + ex.getMessage());
        }
    }

    private void sendMessageToEvent() {
        try {
            System.out.print("Event name: ");
            String name = in.nextLine().trim();
            Event e = eventService.findEventByName(name);
            if (e == null) {
                System.out.println("Event not found.");
                return;
            }
            System.out.print("Message to send: ");
            String msg = in.nextLine();
            eventService.sendMessage(e, msg);
            System.out.println("✔ Message sent to subscribers of " + name);
        } catch (Exception ex) {
            System.out.println("Error sending message: " + ex.getMessage());
        }
    }

    private void showEventMessages() {
        try {
            System.out.print("Event name: ");
            String name = in.nextLine().trim();
            Event e = eventService.findEventByName(name);
            if (e == null) {
                System.out.println("Event not found.");
                return;
            }
            System.out.println("\nMessages for event " + name + ":");
            List<String> msgs = e.getMessages();
            if (msgs.isEmpty()) {
                System.out.println("  (no messages)");
            } else {
                for (String m : msgs) System.out.println(" - " + m);
            }
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }

    private void showRaceDuration() {
        try {
            System.out.print("RaceEvent name: ");
            String name = in.nextLine().trim();
            Event e = eventService.findEventByName(name);
            if (e == null) {
                System.out.println("Event not found.");
                return;
            }
            if (!(e instanceof RaceEvent re)) {
                System.out.println("Event is not a RaceEvent.");
                return;
            }
            double dur = re.calculeazaDurata();
            System.out.printf("Estimated race duration: %.3f%n", dur);
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }

    private void showCardMembers() {
        try {
            System.out.print("Card ID: ");
            Long cardId = Long.parseLong(in.nextLine());
            Card<Duck> c = cardService.findCardById(cardId);
            if (c == null) {
                System.out.println("Card not found.");
                return;
            }
            System.out.println("Members of card " + c.getNume() + " (id=" + c.getId() + "):");
            if (c.getMembri().isEmpty()) {
                System.out.println("  (no members)");
            } else {
                for (Duck d : c.getMembri()) {
                    System.out.println(" - " + d);
                }
            }
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }

    private void showEventSubscribers() {
        try {
            System.out.print("Event name: ");
            String name = in.nextLine().trim();
            Event e = eventService.findEventByName(name);
            if (e == null) {
                System.out.println("Event not found.");
                return;
            }
            System.out.println("Subscribers of event " + name + ":");
            List<User> subs = e.getSubscribers();
            if (subs.isEmpty()) {
                System.out.println("  (no subscribers)");
            } else {
                for (User u : subs) {
                    System.out.println(" - " + u);
                }
            }
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }
}
