package exceptions;

//custom exception
public class ExceptieValidare extends RuntimeException{
    public ExceptieValidare(String message){
        super(message); //apelez contructir din clasa parinte care stocheaza msg
    }
}
