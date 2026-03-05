package validator;

import exceptions.ExceptieValidare;

public interface ValidatorInterface<T> {
    // T = tip generic
    void validare(T t) throws ExceptieValidare;
}