#include <stdio.h>
#define MAX_SIZE 32

void add(int *set, int element) {
    if (element >= 0 && element < MAX_SIZE) {
        *set |= (1 << element);
    } else {
        printf(" Element %d is out of valid range (0-31).\n", element);
    }
}

void remove_element(int *set, int element) {
    if (element >= 0 && element < MAX_SIZE) {
        *set &= ~(1 << element);
    } else {
        printf(" Element %d is out of valid range (0-31).\n", element);
    }
}

int union_set(int set1, int set2) {
    return set1 | set2;
}

int intersection_set(int set1, int set2) {
    return set1 & set2;
}

int difference_set(int set1, int set2) {
    return set1 & ~set2;
}
int difference_setA(int set1, int set2) {
    return set2 & ~set1;
}


int complement_set(int set, int universal_set) {
    return ~set & universal_set;
}

void display_bitstring(int set) {
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        printf("%d", (set & (1 << i)) ? 1 : 0);
    }
}

void display_set(int set) {
    printf("{ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (set & (1 << i)) {
 printf("%d ", i);
        }
    }
    printf("}\n");
    printf("Bitstring: ");
    display_bitstring(set);
    printf("\n");
}

int read_set() {
    int n, element, set = 0;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements (0-%d): ", MAX_SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        add(&set, element);
    }
    return set;
}

int main() {
    printf(" Universal Set:\n");
    int universal_set = read_set();
    
    printf("Universal Set: ");
    display_set(universal_set);

    int set1 = 0, set2 = 0, operation;

    printf("\nEnter elements for Set 1:\n");
    set1 = read_set();
    printf("Set 1: ");
    display_set(set1);

    printf("\nEnter elements for Set 2:\n");
    set2 = read_set();
    printf("Set 2: ");
    display_set(set2);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Union of Set 1 and Set 2\n");
        printf("2. Intersection of Set 1 and Set 2\n");
        printf("3. Difference of Set 1 and Set 2\n");
        printf("4. Difference  of Set 2 and Set 1\n");
        printf("5. Complement of Set 1\n");
        printf("6.complement of set 2\n");
        printf("7. Exit\n");
 scanf("%d", &operation);

        switch (operation) {
            case 1: {
                int union_result = union_set(set1, set2);
                printf("Union of Set 1 and Set 2: ");
                display_set(union_result);
                break;
            }
            case 2: {
                int intersection_result = intersection_set(set1, set2);
                printf("Intersection of Set 1 and Set 2: ");
                display_set(intersection_result);
                break;
            }
            case 3: {
                int difference_result = difference_set(set1, set2);
                printf("Difference (Set 1 - Set 2): ");
                display_set(difference_result);
                break;
            }
            case 4: {
                int difference_result = difference_setA(set1, set2);
                printf("Difference (Set 2 - Set 1): ");
                display_set(difference_result);
                break;
            }
            case 5: {
                int complement_result = complement_set(set1, universal_set);
                printf("Complement of Set 1: ");
                display_set(complement_result);
                break;
            }
            case 6: {
                int complement_result = complement_set(set2, universal_set);
                printf("Complement of Set 2: ");
                display_set(complement_result);
                break;
            }
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (operation != 7);

    return 0;
}
