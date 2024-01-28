import java.math.*;

public class BigRational implements Comparable, MyComparable {

    //state
    private final BigInteger numerator;
    private final BigInteger denominator;

    //service(behavior)
    BigRational(BigInteger numerator, BigInteger denominator) {
        if (denominator.equals(BigInteger.valueOf(0))) {
            throw new ArithmeticException(("The denominator cannot be equal to zero."));
        }
        BigInteger gcd = numerator.gcd(denominator);
        numerator = numerator.divide(gcd);
        denominator = denominator.divide(gcd);
        this.numerator = numerator;
        this.denominator = denominator;

    }

    BigRational add(BigRational other) {
        var newNumerator = this.numerator.multiply(other.denominator).add(this.denominator.multiply(other.numerator));
        var newDenominator = this.denominator.multiply(other.denominator);
        return new BigRational(newNumerator, newDenominator);

    }

    BigRational subtract(BigRational other) {
        var newNumerator = this.numerator.multiply(other.denominator).add(this.denominator.multiply(other.numerator));
        var newDenominator = this.denominator.multiply(other.denominator);
        return new BigRational(newNumerator, newDenominator);
    }

    BigRational multiply(BigRational other) {
        BigInteger newNumerator = this.numerator.multiply(other.numerator);
        var newDenominator = this.denominator.multiply(other.denominator);
        return new BigRational(newNumerator, newDenominator);
    }

    BigRational divide(BigRational other) {
        BigInteger newNumerator = this.numerator.multiply(other.denominator);
        BigInteger newDenominator = this.denominator.multiply(other.numerator);
        return new BigRational(newNumerator, newDenominator);
    }

    public int compareTo(BigRational other, String operator) {
        int isTrue = -1;
        BigInteger first = this.numerator.divide(this.denominator);
        BigInteger second = other.numerator.divide(other.denominator);
        switch (operator) {
            case ">":
                if (first.compareTo(second) > 0) {
                    isTrue = 0;
                }
                break;
            case "<":
                if (first.compareTo(second) < 0) {
                    isTrue = 0;
                }
                break;
            case "=":
                if (first.compareTo(second) == 0) {
                    isTrue = 0;
                }
                break;
            case "!=":
                if (first.compareTo(second) != 0) {
                    isTrue = 0;
                }
                break;
            case "<=":
                if (first.compareTo(second) == 0 || first.compareTo(second) < 0) {
                    isTrue = 0;
                }
                break;
            case ">=":
                if (first.compareTo(second) == 0 || first.compareTo(second) > 0) {
                    isTrue = 0;
                }
                break;
        }
        return isTrue;

    }

    @Override
    public String toString() {
        return this.numerator + "/" + this.denominator;
    }

    public static BigRational parseBigRational(String input) {
        int index = input.indexOf('/');

        if (index == -1) {
            return new BigRational(new BigInteger(input), new BigInteger(String.valueOf(1)));
        }
        String numString = input.substring(0, index);
        String denString = input.substring(index + 1);
        return new BigRational(new BigInteger(numString), new BigInteger(denString));
    }


    @Override
    public int compareTo(BigRational o) {
        return numerator.multiply(o.denominator).compareTo(denominator.multiply(o.numerator));
    }

    @Override
    public int compareTo(Object other) {
        return compareTo((BigRational) other);
    }
}
