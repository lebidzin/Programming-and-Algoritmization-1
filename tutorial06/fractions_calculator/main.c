#include <stdio.h>
#include <stdlib.h>

struct Fraction{
  long long numerator;
  long long denominator;
};

long long find_gcd(long long a, long long b){
  a = llabs(a);
  b = llabs(b);
  while(b!=0){
    long long tmp = a%b;
    a = b;
    b = tmp;
  }

  return a;
}

long long find_lcm(long long a, long long b){
  a = llabs(a);
  b = llabs(b);
  if(a == 0 || b == 0){
    return 0;
  }
  long long gcd = find_gcd(a, b);
  long long result = a/gcd*b;
  return result;
}

int validate(long long den){
  if(den>0){
    return 1;
  }else{
    return 0;
  }
}

struct Fraction normalize_fraction(struct Fraction F){
  if(F.numerator == 0 && F.denominator == 0){
    return F;
  }else if(F.numerator == 0 && F.denominator != 0){
    F.denominator = 1;
    return F;
  }else if(F.denominator < 0){
    F.numerator *= (-1);
    F.denominator *= (-1);
  }
  long long gcd = find_gcd(llabs(F.numerator), llabs(F.denominator));
  F.numerator /= gcd;
  F.denominator /= gcd;
  return F;
}

struct Fraction add(struct Fraction F1, struct Fraction F2){
  struct Fraction F;
  F.numerator = F1.numerator*F2.denominator+F2.numerator*F1.denominator;
  F.denominator = F1.denominator*F2.denominator;
  F = normalize_fraction(F);
  return F;
}
struct Fraction substract(struct Fraction F1, struct Fraction F2){
  struct Fraction F;
  F.numerator = F1.numerator*F2.denominator-F2.numerator*F1.denominator;
  F.denominator = F1.denominator*F2.denominator;
  F = normalize_fraction(F);
  return F;
}
struct Fraction multiply(struct Fraction F1, struct Fraction F2){
  struct Fraction F;
  F.numerator = F1.numerator*F2.numerator;
  F.denominator = F1.denominator*F2.denominator;
  F = normalize_fraction(F);
  return F;
}
struct Fraction divide(struct Fraction F1, struct Fraction F2){
  struct Fraction F;
  if(F2.numerator == 0){
    F.numerator=0;
    F.denominator=0;
    return F;
  }
  F.numerator = F1.numerator*F2.denominator;
  F.denominator = F1.denominator*F2.numerator;
  F = normalize_fraction(F);
  return F;
}
struct Fraction calc_xn_square_multiply(struct Fraction F, int exp){
  struct Fraction F_result;
  F_result.numerator = 1;
  F_result.denominator = 1;
  if(exp < 0){
    if(F.numerator == 0){
      F.numerator = 0;
      F.denominator = 0;
      return F;
    }
    long long tmp = F.numerator;
    F.numerator = F.denominator;
    F.denominator = tmp;
    exp = abs(exp);
  }

  while(exp>0){
    if(exp % 2 != 0){
      F_result.numerator *= F.numerator;
      F_result.denominator *= F.denominator;
      F_result = normalize_fraction(F_result);
    }
    if(exp > 1){
      F.numerator *= F.numerator;
      F.denominator *= F.denominator;
      F = normalize_fraction(F);
    }
    exp /= 2;
  }

  return F_result;
}

struct Fraction read_fraction(){
  struct Fraction F;
  // printf("Zadejte zlomek ve formate x/y:\n");
  if(scanf("%lld/%lld", &F.numerator, &F.denominator)!=2 || F.denominator == 0){
    F.numerator=0;
    F.denominator=0;
    // printf("Neplatny vstup\n");
  };
  F = normalize_fraction(F);
  return F;
}

void print_fraction(struct Fraction F){
  printf(": %lld/%lld\n", F.numerator, F.denominator);
}

int main(){
  char operation;
  struct Fraction F1;
  struct Fraction F2;
  struct Fraction F_result;
  while(1){
    printf("$ ");
    fflush(stdout);
    if(scanf(" %c", &operation) != 1){
      break;
    }
    switch(operation){
      case '+':
        F1 = read_fraction();
        F2 = read_fraction();
        if(F1.denominator == 0 || F2.denominator == 0){
          printf("Zadane neplatny zlomky\n");
          return 1;
        }
        F_result = add(F1, F2);
        print_fraction(F_result);
        break;
      case '-':
        F1 = read_fraction();
        F2 = read_fraction();
        if(F1.denominator == 0 || F2.denominator == 0){
          printf("Zadane neplatny zlomky\n");
          return 1;
        }
        F_result = substract(F1, F2);
        print_fraction(F_result);
        break;
      case '*':
        F1 = read_fraction();
        F2 = read_fraction();
        if(F1.denominator == 0 || F2.denominator == 0){
          printf("Zadane neplatny zlomky\n");
          return 1;
        }
        F_result = multiply(F1, F2);
        print_fraction(F_result);
        break;
      case '/':
        F1 = read_fraction();
        F2 = read_fraction();
        if(F1.denominator == 0 || F2.denominator == 0){
          printf("Zadane neplatny zlomky\n");
          return 1;
        }
        F_result = divide(F1, F2);
        print_fraction(F_result);
        break;
      case '^':{
        F1 = read_fraction();
        int exp;
        if(scanf("%d", &exp)!=1){
          printf("Neplatny exponent\n");
          return 1;
        }
        F_result = calc_xn_square_multiply(F1, exp);
        print_fraction(F_result);
        break;}
      default:
        printf("Doslo k nezname chybe\n");
        return 1;
    }
  }
  return 0;
}