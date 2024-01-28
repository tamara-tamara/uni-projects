public class Rational {
    //state
    int numerator;
    int denominator;

    //service(behavior)
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw new ArithmeticException(("The denominator cannot be equal to zero."));
        }
        int gcd = MyCommonMath.gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        this.numerator = numerator;
        this.denominator = denominator;

    }

    Rational add(Rational other) {
        int newNumerator = this.numerator * other.denominator + this.denominator * other.numerator;
        int newDenominator = this.denominator * other.denominator;
        return new Rational(newNumerator, newDenominator);

    }

    Rational subtract(Rational other) {
        int newNumerator = this.numerator * other.denominator - this.denominator * other.numerator;
        int newDenominator = this.denominator * other.denominator;
        return new Rational(newNumerator, newDenominator);
    }

    Rational multiply(Rational other) {
        int newNumerator = this.numerator * other.numerator;
        int newDenominator = this.denominator * other.denominator;
        return new Rational(newNumerator, newDenominator);
    }

    Rational divide(Rational other) {
        int newNumerator = this.numerator * other.denominator;
        int newDenominator = this.denominator * other.numerator;
        return new Rational(newNumerator, newDenominator);
    }

    int compareTo(Rational other, String operator) {
        int isTrue = -1;
        int first = this.numerator / this.denominator;
        int second = other.numerator / other.denominator;
        switch (operator) {
            case ">":
                if (first > second) {
                    isTrue = 0;
                }
                break;
            case "<":
                if (first < second) {
                    isTrue = 0;
                }
                break;
            case "=":
                if (first == second) {
                    isTrue = 0;
                }
                break;
            case "!=":
                if (first != second) {
                    isTrue = 0;
                }
                break;
            case "<=":
                if (first <= second) {
                    isTrue = 0;
                }
                break;
            case ">=":
                if (first >= second) {
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

    static Rational parseRational(String input) {
        int index = input.indexOf('/');

        if (index == -1) {
            return new Rational(Integer.parseInt(input), 1);
        }
        String numString = input.substring(0, index);
        String denString = input.substring(index + 1);
        return new Rational(Integer.parseInt(numString), Integer.parseInt(denString));
    }
}
