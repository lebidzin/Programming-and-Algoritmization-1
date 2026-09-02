#include <stdio.h>
#include <math.h>

// E=10^-9
#define E 1e-9

struct vector3D{
  double x;
  double y;
  double z;
};

int clean_buffer(){
  int character;
  while(1){
    character = getchar();
    if(character == '\n'){
      return 0;
    }else if(character == EOF){
      return 2;
    }
  }
  return 0;
}

int read_vector(struct vector3D *vector){
  printf("Zadejte vektor ve formate x y z:\n");
  while(scanf("%lf %lf %lf", &vector->x, &vector->y, &vector->z)!=3){
    printf("Neplatny vstup\n");
    vector->x=0;
    vector->y=0;
    vector->z=0;
    int character;
    int result_clean_buffer = clean_buffer();
    if(result_clean_buffer == 2){
      return 2;
    }
  }
  return 0;
}

void print_vector(struct vector3D vector){
  printf("Vektor ma koordinaty x: %lf, y: %lf, z: %lf\n", vector.x, vector.y, vector.z);
}

double calculate_vector_size(struct vector3D vector){
  return sqrt((vector.x*vector.x+vector.y*vector.y+vector.z*vector.z));
}

struct vector3D add_vectors(struct vector3D vector1, struct vector3D vector2){
  vector1.x += vector2.x;
  vector1.y += vector2.y;
  vector1.z += vector2.z;
  return vector1;
}

// Vektorový součin: Výsledkem je nový vektor kolmý(perpendicular) na oba původní
struct vector3D cross_product(struct vector3D vector1, struct vector3D vector2){
  struct vector3D result_vector;
  result_vector.x = vector1.y*vector2.z - vector1.z*vector2.y;
  result_vector.y = vector1.z*vector2.x - vector1.x*vector2.z;
  result_vector.z = vector1.x*vector2.y - vector1.y*vector2.x;
  return result_vector;
}

// Skalární součin: Výsledkem je jediné číslo (skalár):
double scalar_product(struct vector3D vector1, struct vector3D vector2){
  double result = vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
  return result;
}

struct vector3D vector_multiply_by_constant(struct vector3D vector, double constant){
  vector.x *= constant;
  vector.y *= constant;
  vector.z *= constant;
  return vector;
};

// Protože pracujeme s desetinnými čísly, porovnávame absolutní rozdíl složek s velmi malou tolerancí (1e−9).
int are_vectors_equal(struct vector3D vector1, struct vector3D vector2){
  if(fabs(vector1.x-vector2.x)>E || fabs(vector1.y-vector2.y)>E || fabs(vector1.z-vector2.z)>E){
    return 0;
  }
  return 1;
}

// Stejný směr: Dva vektory mají stejný směr, pokud je jejich vektorový součin nulový (leží na stejné přímce) a zároveň je jejich skalární součin kladný (míří na stejnou stranu).
int do_vectors_point_in_same_direction(struct vector3D vector1, struct vector3D vector2){
  struct vector3D result_vector = cross_product(vector1, vector2);
  double result_scalar_product = scalar_product(vector1, vector2);
  if(fabs(result_vector.x)>E || fabs(result_vector.y)>E || fabs(result_vector.z)>E || result_scalar_product < 0){
    return 0;
  }
  return 1;
}

int do_vectors_have_same_size(struct vector3D vector1, struct vector3D vector2){
  double vector1_size = calculate_vector_size(vector1);
  double vector2_size = calculate_vector_size(vector2);
  if(fabs(vector1_size - vector2_size)>E){
    return 0;
  }
  return 1;
}

int main(){
  char operation;
  struct vector3D vector1;
  struct vector3D vector2;
  struct vector3D result_vector;
  int reading_result1;
  int reading_result2;
  while(1){
    printf("Vyberte operace pro vektor(y): a:vector size\nb: cross product\nc: scalar product\nd: multiply by constant\ne:are equal\nf:do point in same direction\ng: do vectors have the same size\n");
    printf("$ ");
    fflush(stdout);
    if(scanf(" %c", &operation) != 1){
      break;
    }
    int result_clean_buffer = clean_buffer();
    if(result_clean_buffer == 2){
      return 1;
    }
    switch(operation){
      case 'a':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        double vector_size = calculate_vector_size(vector1);
        printf("Velikost vektoru: %lf\n", vector_size);

        break;
      case 'b':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }
        reading_result2 = read_vector(&vector2);
        if(reading_result2 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        result_vector = cross_product(vector1, vector2);
        print_vector(result_vector);

        break;
      case 'c':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }
        reading_result2 = read_vector(&vector2);
        if(reading_result2 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        double result_scalar_product = scalar_product(vector1, vector2);
        printf("Skalarny produkt: %lf\n", result_scalar_product);

        break;
      case 'd':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        double constant;
        printf("Zadejte konstantu:\n");
        while(scanf("%lf", &constant)!=1){
          printf("Neplatny vstup\n");
          int clean_buffer_result = clean_buffer();
          if(clean_buffer_result == 2){
            return 1;
          }
        };
        result_vector = vector_multiply_by_constant(vector1, constant);
        print_vector(result_vector);

        break;
      case 'e':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }
        reading_result2 = read_vector(&vector2);
        if(reading_result2 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        int are_equal = are_vectors_equal(vector1, vector2);
        if(are_equal == 1){
          printf("Vektory s koordinaty <%lf, %lf, %lf>, jsou rovne\n", vector1.x, vector1.y,vector1.z);
        }else{
          printf("Vektory s koordinaty <%lf, %lf, %lf>\n<%lf, %lf, %lf> NEjsou rovne\n", vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z);
        }

        break;
      case 'f':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }
        reading_result2 = read_vector(&vector2);
        if(reading_result2 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        int do_point = do_vectors_point_in_same_direction(vector1, vector2);
        if(do_point == 1){
          printf("Vektory s koordinaty <%lf, %lf, %lf>\n<%lf, %lf, %lf>\n maji stejny smer\n", vector1.x, vector1.y,vector1.z,vector2.x, vector2.y, vector2.z);
        }else{
          printf("Vektory s koordinaty <%lf, %lf, %lf>\n<%lf, %lf, %lf>\nNEmaji stejny smer\n", vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z);
        }

        break;
      case 'g':
        reading_result1 = read_vector(&vector1);
        if(reading_result1 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }
        reading_result2 = read_vector(&vector2);
        if(reading_result2 == 2){
          printf("Zakonceni programu\n");
          return 1;
        }

        int do_have_same_size = do_vectors_have_same_size(vector1, vector2);
        if(do_have_same_size == 1){
          printf("Vektory s koordinaty <%lf, %lf, %lf>\n<%lf, %lf, %lf>\n maji stejnou velikost\n", vector1.x, vector1.y,vector1.z,vector2.x, vector2.y, vector2.z);
        }else{
          printf("Vektory s koordinaty <%lf, %lf, %lf>\n<%lf, %lf, %lf>\n NEmaji stejnou velikost\n", vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z);
        }

        break;
      default:
        printf("Doslo k nezname chybe\n");
        return 1;
    }
  }
  return 0;
}