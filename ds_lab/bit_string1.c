#include <stdio.h>
#define MAX_SIZE 32
const int universal_set = (1 < MAX_SIZE) - 1;

void display(int set) {
    printf("{ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

void add(int *set, int element) {
    *set |= (1 << element); 
}

void remove_element(int *set, int element) {
    *set &= ~(1 << element);
}

int set_union(int set1, int set2) {
    return set1 | set2;
}

int set_intersection(int set1, int set2) {
    return set1 & set2;
}

int set_difference(int set1, int set2) {
    return set1 & ~set2;
}

int set_complement(int set) {
    return ~set & universal_set; 
}

int main() {
    int set1 = 0, set2 = 0, n1, n2, element, operation, data;

    
    printf("Enter the size of set1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &element);
        add(&set1, element);
    }

    
    printf("Enter the size of set2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &element);
        add(&set2, element);
    }

    
    printf("\nSet1: ");
    display(set1);
    printf("Set2: ");
    display(set2);

    do {
        printf("\n1. Add element to set1\n2. Remove element from set1\n3. Union of set1 and set2\n");
        printf("4. Intersection of set1 and set2\n5. Difference of set1 and set2\n");
        printf("6. Complement of set1\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                printf("Enter the element to be added to set1: ");
                scanf("%d", &data);
                add(&set1, data);
                printf("Modified Set1: ");
                display(set1);
                break;

            case 2:
                printf("Enter the element to be removed from set1: ");
                scanf("%d", &data);
                remove_element(&set1, data);
                printf("Modified Set1: ");
                display(set1);
                break;

            case 3:
                printf("Union of Set1 and Set2: ");
                display(set_union(set1, set2));
                break;

            case 4:
                printf("Intersection of Set1 and Set2: ");
                display(set_intersection(set1, set2));
                break;

            case 5:
                printf("Difference of Set1 and Set2: ");
                display(set_difference(set1, set2));
                break;

            case 6:
                printf("Complement of Set1: ");
                display(set_complement(set1));
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (operation != 7);

    return 0;
}
