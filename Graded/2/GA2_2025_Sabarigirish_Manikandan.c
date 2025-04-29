#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct btreenode {
    char name;
    struct btreenode *left;
    struct btreenode *right;
} BTreeNode;

BTreeNode *create_node(char name) {
    if (name == 'X')
        return NULL;
    BTreeNode *newNode = malloc(sizeof(BTreeNode));
    newNode->name = name;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BTreeNode *search_element(char element, BTreeNode *root) {
    if (root == NULL)
        return NULL;
    if (root->name == element)
        return root;
    BTreeNode *result_left = search_element(element, root->left);
    BTreeNode *result_right = search_element(element, root->right);
    if (result_left != NULL)
        return result_left;
    if (result_right != NULL)
        return result_right;
    return NULL;
}

BTreeNode *find_manager(BTreeNode *current, char name) {
    if (current == NULL)
        return NULL;
    if ((current->left && current->left->name == name) ||
        (current->right && current->right->name == name))
        return current;
    BTreeNode *left = find_manager(current->left, name);
    if (left)
        return left;
    return find_manager(current->right, name);
}

void inorder(BTreeNode *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->name);
    inorder(root->right);
}

void preorder(BTreeNode *root) {
    if (root == NULL)
        return;
    printf("%c ", root->name);
    preorder(root->left);
    preorder(root->right);
}

BTreeNode *build_org_tree(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }
    char line[100];
    if (!fgets(line, sizeof(line), fptr)) {
        printf("Error reading file or file is empty\n");
        fclose(fptr);
        return NULL;
    }
    fclose(fptr);
    char managers[100], left_emp[100], right_emp[100];
    int count = 0;
    char *ptr = line + 5;
    while (*ptr != '\0' && *ptr != '\n') {
        sscanf(ptr, "%c %c %c", &managers[count], &left_emp[count],
               &right_emp[count]);
        count++;
        ptr += 5;
        while (*ptr == ' ')
            ptr++;
    }
    char ceo_name = '\0';
    for (int i = 0; i < count; i++) {
        char manager = managers[i];
        int is_employee = 0;
        for (int j = 0; j < count; j++) {
            if (left_emp[j] == manager || right_emp[j] == manager) {
                is_employee = 1;
                break;
            }
        }
        if (!is_employee) {
            ceo_name = manager;
            break;
        }
    }
    BTreeNode *ceo = create_node(ceo_name);
    int changes_made;
    do {
        changes_made = 0;
        for (int i = 0; i < count; i++) {
            char manager = managers[i];
            char left = left_emp[i];
            char right = right_emp[i];
            BTreeNode *manager_node = search_element(manager, ceo);
            if (manager_node != NULL) {
                if (manager_node->left == NULL && left != 'X') {
                    manager_node->left = create_node(left);
                    changes_made = 1;
                }
                if (manager_node->right == NULL && right != 'X') {
                    manager_node->right = create_node(right);
                    changes_made = 1;
                }
            }
        }
    } while (changes_made);
    return ceo;
}

int tree_height(BTreeNode *root) {
    if (root == NULL)
        return 0;
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int bosses(BTreeNode *root) {
    if (root == NULL)
        return 0;
    return (root->left != NULL || root->right != NULL) + bosses(root->left) +
           bosses(root->right);
}

int is_binary_search_tree(BTreeNode *root) {
    if (root == NULL)
        return 1;
    if (root->left != NULL && root->left->name > root->name)
        return 0;
    if (root->right != NULL && root->right->name < root->name)
        return 0;
    return is_binary_search_tree(root->left) &&
           is_binary_search_tree(root->right);
}

BTreeNode *special(BTreeNode *root) {
    BTreeNode *alpha;
    BTreeNode *omicron;
    alpha = root;
    omicron = alpha->right;
    alpha->right = omicron->left;
    omicron->left = alpha;
    return omicron;
}

void check_employee_status(BTreeNode *root, char employee) {
    if (root == NULL)
        return;
    if (root->name == employee) {
        printf("Confirmed that %c is an employee.\n", employee);
        printf("%c is the CEO and has no team mate.\n", employee);
        return;
    }
    if (root->left != NULL && root->left->name == employee) {
        printf("Confirmed that %c is an employee.\n", employee);
        if (root->right != NULL)
            printf("Teammate of %c: %c\n", employee, root->right->name);
        else
            printf("%c is sole team member.\n", employee);
        return;
    }
    if (root->right != NULL && root->right->name == employee) {
        printf("Confirmed that %c is an employee.\n", employee);
        if (root->left != NULL)
            printf("Teammate of %c: %c\n", employee, root->left->name);
        else
            printf("%c is sole team member.\n", employee);
        return;
    }
    check_employee_status(root->left, employee);
    check_employee_status(root->right, employee);
}

int main() {
    BTreeNode *root = build_org_tree("employee.txt");
    FILE *fptr = fopen("employee.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file %s\n", "employee.txt");
        return 1;
    }
    char line[100];
    fgets(line, 100, fptr);
    char test1, test2;
    sscanf(line, "%c %c  ", &test1, &test2);
    if (root != NULL) {
        printf("Inorder Traversal: ");
        inorder(root);
        printf("\nTree Height: %d\n", tree_height(root));
        printf("Number of Bosses: %d\n", bosses(root));
        printf("It is %sa BST with CEO: %c\n",
               (is_binary_search_tree(root)) ? "" : "not ", root->name);
        root = special(root);
        printf("Preorder after shuffling: ");
        preorder(root);
        printf("\n");
        check_employee_status(root, test1);
        check_employee_status(root, test2);
    } else
        printf("Failed to build tree.");
    return 0;
}
